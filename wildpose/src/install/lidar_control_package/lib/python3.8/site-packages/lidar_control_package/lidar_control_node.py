import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from openpylivox import openpylivox

class LidarControlNode(Node):
    def __init__(self):
        super().__init__('lidar_control_node')

        self.sensor = None
        self.state = "disconnected"
        self.up = True

        # Initialize the LiDAR sensor
        self.sensor = openpylivox(True)
        
        # Subscription to Joy topic
        self.joy_subscription = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            10
        )

    def joymsg2f510(self, msg):
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

    def connect(self):
        # Replace with the actual IP address of your LiDAR
        connected = self.sensor.auto_connect("192.168.1.50")
        if connected:
            self.state = "connected"
            self.get_logger().info("LiDAR has been connected")
        else:
            self.get_logger().error("Failed to connect to LiDAR")

    def disconnect(self):
        # Replace with the actual IP address of your LiDAR
        disconnected = self.sensor.disconnect()
        self.state = "disconnected"
                ## TODO: implement callback for erroes and output values
        self.get_logger().info("LiDAR has been disconnected")


    def lidarSpinDown(self):
        down = self.sensor.lidarSpinDown()
        
        ## TODO: implement callback for erroes and output values
        self.get_logger().info("LiDAR has been sent to spin down mode")

    def lidarSpinUp(self):
        spinup = self.sensor.lidarSpinUp()

        ## TODO: implement callback for erroes and output values
        self.get_logger().info("LiDAR has been sent to spin up mode")
   
    def joy_callback(self, msg):
        buttons, axes = self.joymsg2f510(msg)

    
        if buttons['A'] == 1:
            if self.state != "disconnected":
                self.lidarSpinUp()
            else:
                self.get_logger().error("Failed to spin up LiDAR, LiDAR is disconnected")

        if buttons['B'] == 1:
            if self.state != "disconnected":
                self.lidarSpinDown()
            else:
                self.get_logger().error("Failed to spin down LiDAR, LiDAR is disconnected")

        if buttons['X'] == 1:
            if self.state == "disconnected":
                self.connect()
            else:
                self.get_logger().error("Failed to connect to LiDAR, LiDAR is disconnected")

        if buttons['Y'] == 1:
            if self.state != "disconnected":
                self.disconnect()
            else:
                self.get_logger().error("Failed to disconnect LiDAR, LiDAR is already disconnected")

def main(args=None):
    rclpy.init(args=args)
    lidar_control_node = LidarControlNode()
    rclpy.spin(lidar_control_node)
    lidar_control_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
