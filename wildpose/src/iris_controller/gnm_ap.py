import rclpy
from rclpy.node import Node
from wildpose_interfaces.msg import FrameBrightness  # Assuming this import works
from wildpose_interfaces.msg import LensAperture  # Assuming this import works
import csv

class BrightnessLogger(Node):

    def __init__(self):
        super().__init__('brightness_logger')
        self.subscription = self.create_subscription(
            LensAperture,
            '/arduino_position',
            self.brightness_callback,
            10)  # Adjust callback frequency (optional)

    def brightness_callback(self, msg):
        """Callback function to receive and record brightness data."""
        timestamp = str(msg.header.stamp.sec)+"."+str(msg.header.stamp.nanosec)  # Convert ROS time to seconds
        print(timestamp)
        brightness = msg.position

        # Open CSV file in append mode (create if not existing)
        with open('brightness2_data.csv', 'a', newline='') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow([timestamp, brightness])

        print(f"Timestamp: {timestamp}, Brightness: {brightness}")  # Optional: Print to console

def main():
    rclpy.init()
    node = BrightnessLogger()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
