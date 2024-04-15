import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import serial

class BrightnessCalculator(Node):
    def __init__(self):
        super().__init__('brightness_node')
        self.bridge = CvBridge()
        self.subscription = self.create_subscription(Image, '/ximea/image_raw', self.image_callback, 10)
        self.subscription

        self.serial_port = serial.Serial('/dev/ttyACM1', 9600)  # Change '/dev/ttyUSB0' to your Arduino's serial port
        self.serial_port.timeout = 1  # Set timeout to 1 second

    def image_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")

            brightness = self.calculate_brightness_hsv(cv_image)
            self.get_logger().info("Brightness level: {}".format(brightness))
            self.send_brightness_to_arduino(brightness)
        except Exception as e:
            self.get_logger().error("Error processing image: {}".format(e))

    def calculate_brightness(self, image):
        gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        brightness = int(round(cv2.mean(gray_image)[0]))
        return brightness
    def calculate_brightness_hsv(self,
                                 image):
        # Convert the image to the HSV color space
        hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

        # Extract the Value (brightness) channel
        value_channel = hsv_image[:,:,2]

        # Calculate the average brightness
        average_brightness = value_channel.mean()

        return average_brightness

    def send_brightness_to_arduino(self, brightness):
        self.serial_port.write(str(brightness).encode()+ b'\n')

def main(args=None):
    rclpy.init(args=args)
    brightness_calculator = BrightnessCalculator()
    rclpy.spin(brightness_calculator)
    brightness_calculator.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
