import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from openpylivox import openpylivox
import subprocess
import os
import time



class LidarControlNode(Node):
    def __init__(self):
        super().__init__('lidar_control_node')

        self.sensor = None
        self.state = "disconnected"
        self.up = True
        self.sleepmode =False
        self.lixpub =False
        self.attempt = 0
         # Default parameter values
        self.xfer_format = 0
        self.multi_topic = 0
        self.data_src = 0
        self.publish_freq = 200
        self.return_mode = 2
        self.output_type = 0
        self.frame_id = 'livox_frame'
        self.lvx_file_path = '/home/livox/livox_test.lvx'
        self.cmdline_bd_code = 'livox0000000001'


        # Initialize the LiDAR sensor
        self.sensor = openpylivox(True)
        self.close_existing_ros_driver_session()
        self.connect()
        self.lidarSpinDown()
        # Subscription to Joy topic
        self.joy_subscription = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            10
        )

    def close_existing_ros_driver_session(self):
        # Check if a tmux session with the name 'ros_driver_session' exists
        check_tmux_cmd = ['tmux', 'has-session', '-t', 'ros_driver_session']
        session_exists = subprocess.run(check_tmux_cmd).returncode == 0

        # If the session exists, kill it
        if session_exists:
            subprocess.run(['tmux', 'kill-session', '-t', 'ros_driver_session'])
            time.sleep(5)  # Adjust the sleep duration as needed

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
            self.attempt = 0
        else:
            #self.get_logger().error("Failed to connect to LiDAR")

            self.attempt +=1
            if self.attempt< 20:
                self.get_logger().info("attempt :"+ str(self.attempt))
                time.sleep(1)
                self.connect()
            else:
                self.get_logger().error("Failed to connect to LiDAR too many times")

    def disconnect(self):
        # Replace with the actual IP address of your LiDAR
        disconnected = self.sensor.disconnect()
        self.state = "disconnected"
                ## TODO: implement callback for erroes and output values
        self.get_logger().info("LiDAR has been disconnected")


    def lidarSpinDown(self):
        down = self.sensor.lidarSpinDown()
        self.sleepmode =True
        
        ## TODO: implement callback for erroes and output values
        self.get_logger().info("LiDAR has been sent to spin down mode")

    def lidarSpinUp(self):
        spinup = self.sensor.lidarSpinUp()
        self.sleepmode =False

        ## TODO: implement callback for erroes and output values
        self.get_logger().info("LiDAR has been sent to spin up mode")
    # Inside the LidarControlNode class
        
        # Inside the LidarControlNode class
    def start_livox_driver(self):
        config_path = '/home/naoya/ros2_ws/livox_ros2_driver/src/livox_ros2_driver/config'
        rviz_config_path = os.path.join(config_path, 'livox_lidar.rviz')
        user_config_path = os.path.join(config_path, 'livox_lidar_config.json')
        
        livox_ros2_params = [
            {"xfer_format": self.xfer_format},
            {"multi_topic": self.multi_topic},
            {"data_src": self.data_src},
            {"publish_freq": self.publish_freq},
            {"output_data_type": self.output_type},
            {"frame_id": self.frame_id},
            {"lvx_file_path": self.lvx_file_path},
            {"return_mode": self.return_mode},
            {"user_config_path": user_config_path},
            {"cmdline_input_bd_code": self.cmdline_bd_code}
        ]

        livox_driver_cmd = [
            'ros2', 'run', 'livox_ros2_driver', 'livox_ros2_driver_node',
            '--ros-args', '--log-level', 'ERROR'
        ]

        for param in livox_ros2_params:
            key, value = list(param.items())[0]
            livox_driver_cmd.extend(['--', key, str(value)])

        self.livox_driver_process = subprocess.Popen(livox_driver_cmd)

    # Inside the LidarControlNode __init__ method or wherever you initialize your parameters
    def start_ros_driver_in_tmux(self):
        # Define the ROS launch command to start the driver
        ros_launch_command = ['ros2', 'launch', 'livox_ros2_driver', 'livox_lidar_launch.py']
        
        # Execute the ROS launch command within a new tmux session
        tmux_cmd = ['tmux', 'new-session', '-d', '-s', 'ros_driver_session', '--'] + ros_launch_command
        subprocess.run(tmux_cmd)
        self.lixpub =True

    def stop_ros_driver_in_tmux(self):
        # Kill the tmux session where the ROS driver is running
        subprocess.run(['tmux', 'kill-session', '-t', 'ros_driver_session'])
        self.lixpub =False
        time.sleep(5)  # Adjust the sleep duration as needed

    def stop_livox_driver(self):
        if hasattr(self, 'livox_driver_process'):
            self.livox_driver_process.terminate()
            del self.livox_driver_process
        self.lixpub =False

    def joy_callback(self, msg):
        buttons, axes = self.joymsg2f510(msg)
        self.xfer_format = 0
        self.multi_topic = 0
        self.data_src = 0
        self.publish_freq = 10.0
        self.return_mode = 2
        self.output_type = 0
        self.frame_id = 'livox_frame'
        self.lvx_file_path = '/home/livox/livox_test.lvx'
        self.cmdline_bd_code = 'livox0000000001'
        # Inside the joy_callback method
        if buttons['START'] == 1 and self.lixpub== False:
            if self.sleepmode == True:
                if self.state == "disconnected" :
                    self.connect()
                    self.lidarSpinUp()
                    self.disconnect()
                    self.start_ros_driver_in_tmux()
                else:
                    self.lidarSpinUp()
                    self.disconnect()
                    self.start_ros_driver_in_tmux()
            else:    
                if self.state == "disconnected" :
                    self.start_ros_driver_in_tmux()
                else:
                    self.disconnect()
                    self.start_ros_driver_in_tmux()
        elif buttons['BACK'] == 1:
                self.stop_ros_driver_in_tmux()
                self.connect()
                self.lidarSpinDown()

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
