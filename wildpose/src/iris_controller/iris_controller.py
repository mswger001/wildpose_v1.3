import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from sensor_msgs.msg import Image
from wildpose_interfaces.msg import LensAperture
from wildpose_interfaces.msg import FrameBrightness
import serial
import cv2
from cv_bridge import CvBridge
import time


def joymsg2f510(msg):
    # Logitech F510
    # Button: [A, B, X, Y, LB, RB, BACK, START, Logitech, Right joy, Left joy]
    # Axes: [JoyL LR(+-), JoyL UB(+-), LT(-1~1), JoyR LR(+-), JoyR UB(+-), RT(-1~1), D-pad LR(+-), D-pad UB(+-)]
    buttons = {
        'A': msg.buttons[0],
        'B': msg.buttons[1],
        'X': msg.buttons[2],
        'Y': msg.buttons[3],
        'LB': msg.buttons[4],
        'RB': msg.buttons[5],
        'BACK': msg.buttons[6],
        'START': msg.buttons[7],
        'Logitech': msg.buttons[8],
        'joy_left': msg.buttons[9],
        'joy_right': msg.buttons[10],
    }
    axes = {
        'joy_left': [msg.axes[0], msg.axes[1]],
        'LT': msg.axes[2],
        'joy_right': [msg.axes[3], msg.axes[4]],
        'RT': msg.axes[5],
        'dpad': [-msg.axes[6], msg.axes[7]],
    }

    return buttons, axes

class BrightnessCalculator(Node):

    def __init__(self):
        super().__init__('brightness_node')
        self.bridge = CvBridge()
        self.serial_port2 = serial.Serial('/dev/ttyACM1', 9600)  # Change '/dev/ttyUSB0' to your Arduino's serial port
        self.serial_port2.timeout = 1  # Set timeout to 1 second
        self.count1 = 0
        self.count2 = 0
        self.command_queue = []

        # Fill up the command queue with 25 "g" commands followed by 25 "f" commands
        self.command_queue.extend(["g\n"] * 1)

        # Create a publisher for position data
        self.position_pub = self.create_publisher(LensAperture, 'arduino_position', 10)
        self.position_pub2 = self.create_publisher(FrameBrightness, 'frame_lumisence', 10)
        self.position = 0

        self.subscription = self.create_subscription(Image, '/ximea/image_raw', self.image_callback, 10)

        self.joy_sub = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            10
        )

    def publish_position(self, position):
        # Publish the received position data
        msg = LensAperture()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.position = int(position)
        self.position_pub.publish(msg)

    def publish_brightness(self, brightness):
        # Publish the received position data
        msg = FrameBrightness()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.brightness = brightness
        self.position_pub2.publish(msg)

    def read_serial(self):
        # Read serial data from Arduino
        serial_data = self.serial_port2.readline().decode().strip()  # Read a line and decode bytes to string
        return serial_data

    def calculate_brightness_hsv(self,image):
        # Convert the image to the HSV color space


        # Extract the Value (brightness) channel
        value_channel = image[:,:,2]

        # Calculate the average brightness
        average_brightness = value_channel.mean()

        return average_brightness

    def image_callback(self, msg):
        # Process the image (convert to BGR if needed)
        image = self.bridge.imgmsg_to_cv2(msg)

        # If the image has only one channel, it's grayscale
        if len(image.shape) == 2:
            # Convert grayscale to BGR
            image = cv2.cvtColor(image, cv2.COLOR_GRAY2BGR)

        # Convert the image to the HSV color space
        hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

        # Extract the Value (brightness) channel
        value_channel = hsv_image[:,:,2]

        # Calculate the average brightness
        brightness = value_channel.mean()
        brightness = self.calculate_brightness_hsv(hsv_image)
        self.publish_position(self.position)
        self.publish_brightness(brightness)

    def execute_commands(self):
        if self.command_queue:
            command = self.command_queue.pop(0)
            self.serial_port2.write(command.encode())
            print(command)
            serial_data = self.read_serial()
            if serial_data.startswith("Position:"):
                self.position = serial_data.split(":")[1]

    def joy_callback(self, msg):
        buttons, axes = joymsg2f510(msg)        # Motor 3

        if axes['joy_left'][1] == -1 :
            self.count1 += 1
            if self.count1 == 2:
                self.command_queue.append("g\n")
                self.count1 = 0

        if axes['joy_left'][1] == 1 :
            self.count2 += 1
            if self.count2 == 2:
                self.command_queue.append("f\n")
                self.count2 = 0

    def timer_callback(self):
        self.execute_commands()

    def destroy_node(self):
        self.serial_port2.close()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    brightness_calculator = BrightnessCalculator()
    timer_period = 2  # seconds
    brightness_calculator.create_timer(timer_period, brightness_calculator.timer_callback)
    rclpy.spin(brightness_calculator)
    brightness_calculator.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
