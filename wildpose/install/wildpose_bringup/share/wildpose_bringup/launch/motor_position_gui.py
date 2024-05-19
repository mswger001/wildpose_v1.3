import sys
import os
import subprocess
import rclpy
from rclpy.node import Node
from PyQt5.QtWidgets import QApplication, QWidget, QGridLayout, QLabel, QTextEdit, QPushButton
from sensor_msgs.msg import Image, Joy, Imu, PointCloud2
from std_msgs.msg import String
from wildpose_interfaces.msg import MotorPositions
from livox_interfaces.msg import CustomMsg


# Define parameters for Livox Lidar
WILDPOSE_HOME = '/home/naoya/wildPose_v1.3/wildpose'
lvx_file_path = os.path.join(WILDPOSE_HOME, 'record/livox_test.lvx')
config_path = os.path.join(WILDPOSE_HOME, 'src/wildpose_bringup/config')
rviz_config_path = os.path.join(config_path, 'livox_lidar.rviz')
user_config_path = os.path.join(config_path, 'livox_lidar_config.json')

livox_ros2_params = [
    {"xfer_format": 1},
    {"multi_topic": 0},
    {"data_src": 0},
    {"publish_freq": 10.0},
    {"output_data_type": 0},
    {"frame_id": 'livox_frame'},
    {"lvx_file_path": lvx_file_path},
    {"return_mode": 2},
    {"user_config_path": user_config_path},
    {"cmdline_input_bd_code": 'livox0000000001'}
]


class ROS2MonitorWidget(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
        rclpy.init()
        self.node = ROS2Node(self)
        self.executor = rclpy.executors.SingleThreadedExecutor()
        self.executor.add_node(self.node)

    def initUI(self):
        self.setWindowTitle('ROS2 Nodes Monitor')

        self.layout = QGridLayout()

        # Labels for column headers
        self.layout.addWidget(QLabel("Node"), 0, 0)
        self.layout.addWidget(QLabel("Status"), 0, 1)
        self.layout.addWidget(QLabel("Topics"), 0, 2)
        self.layout.addWidget(QLabel("Action"), 0, 3)

        # Camera Section
        self.camera_label = QLabel("Unknown")
        self.camera_topics_label = QLabel("/image_raw")
        self.camera_button = QPushButton("Start Camera Node")
        self.camera_button.clicked.connect(self.start_camera_node)
        self.layout.addWidget(QLabel("Camera"), 1, 0)
        self.layout.addWidget(self.camera_label, 1, 1)
        self.layout.addWidget(self.camera_topics_label, 1, 2)
        self.layout.addWidget(self.camera_button, 1, 3)

        # Lens Section
        self.lens_label = QLabel("Unknown")
        self.lens_topics_label = QLabel("/motor_positions")
        self.lens_button = QPushButton("Start Lens Node")
        self.lens_button.clicked.connect(self.start_lens_node)
        self.layout.addWidget(QLabel("Lens"), 2, 0)
        self.layout.addWidget(self.lens_label, 2, 1)
        self.layout.addWidget(self.lens_topics_label, 2, 2)
        self.layout.addWidget(self.lens_button, 2, 3)

        # Joystick Section
        self.joystick_label = QLabel("Unknown")
        self.joystick_topics_label = QLabel("/joystick/control")
        self.joystick_button = QPushButton("Start Joystick Node")
        self.joystick_button.clicked.connect(self.start_joystick_node)
        self.layout.addWidget(QLabel("Joystick"), 3, 0)
        self.layout.addWidget(self.joystick_label, 3, 1)
        self.layout.addWidget(self.joystick_topics_label, 3, 2)
        self.layout.addWidget(self.joystick_button, 3, 3)

        # Lidar Section
        self.lidar_label = QLabel("Unknown")
        self.lidar_topics_label = QLabel("/lidar/pointcloud, /livox/lidar")
        self.lidar_button = QPushButton("Start Lidar Node")
        self.lidar_button.clicked.connect(self.start_lidar_node)
        self.layout.addWidget(QLabel("Lidar"), 4, 0)
        self.layout.addWidget(self.lidar_label, 4, 1)
        self.layout.addWidget(self.lidar_topics_label, 4, 2)
        self.layout.addWidget(self.lidar_button, 4, 3)

        # IMU Section
        self.imu_label = QLabel("Unknown")
        self.imu_topics_label = QLabel("/livox/imu")
        self.imu_button = QPushButton("Start IMU Node")
        self.imu_button.clicked.connect(self.start_imu_node)
        self.layout.addWidget(QLabel("IMU"), 5, 0)
        self.layout.addWidget(self.imu_label, 5, 1)
        self.layout.addWidget(self.imu_topics_label, 5, 2)
        self.layout.addWidget(self.imu_button, 5, 3)

        # Log Section
        self.log_text_edit = QTextEdit()
        self.log_text_edit.setReadOnly(True)
        self.layout.addWidget(self.log_text_edit, 6, 0, 1, 4)

        self.setLayout(self.layout)

    def start_camera_node(self):
        self.log_text_edit.append("Starting Camera Node...")
        subprocess.Popen(['ros2', 'launch', 'ximea_ros2_cam', 'xiCam.launch.xml'])

    def start_lens_node(self):
        self.log_text_edit.append("Starting Lens Node...")
        motor_control_node = Node(
            package='motor_controller_pkg',
            executable='motor_control_node',
            name='motor_control_node',
            parameters=[
                {'motor_speed': '500'},
            ],
            arguments=['--ros-args', '--log-level', 'INFO']
        )
        subprocess.Popen(['ros2', 'run', 'motor_controller_pkg', 'motor_control_node', '--ros-args', '--log-level', 'INFO'])

    def start_joystick_node(self):
        self.log_text_edit.append("Starting Joystick Node...")
        gamepad_node = Node(
            package='joy_linux',
            executable='joy_linux_node',
            name='gamepad_f710_publisher',
            parameters=[
                {'dev': '/dev/input/js0'},
                {'dev_name': 'Wireless Gamepad F710'},
                {'autorepeat_rate': '0.1'}
            ],
            arguments=['--ros-args', '--log-level', 'ERROR']
        )
    def start_lens_node(self):
        self.log_text_edit.append("Starting Lens Node...")
        motor_control_node = Node(
            package='motor_controller_pkg',
            executable='motor_control_node',
            name='motor_control_node',
            parameters=[
                {'motor_speed': '500'},
            ],
            arguments=['--ros-args', '--log-level', 'INFO']
        )
        subprocess.Popen(['ros2', 'run', 'motor_controller_pkg', 'motor_control_node', '--ros-args', '--log-level', 'INFO'])

    def start_joystick_node(self):
        self.log_text_edit.append("Starting Joystick Node...")
        gamepad_node = Node(
            executable='joy_linux_node',
            name='gamepad_f710_publisher',
            parameters=[
                {'dev': '/dev/input/js0'},
                {'dev_name': 'Wireless Gamepad F710'},
                {'autorepeat_rate': '0.1'}
            ],
            arguments=['--ros-args', '--log-level', 'ERROR']
        )
        gamepad_node.get_logger().info("Starting gamepad_f710_publisher node")
        gamepad_node.spin()  # Spins the node to keep it running
    def start_lidar_node(self):
        self.log_text_edit.append("Starting Lidar Node...")
        livox_driver = Node(
            package='livox_ros2_driver',
            executable='livox_ros2_driver_node',
            name='livox_lidar_publisher',
            output='screen',
            parameters=livox_ros2_params,
            arguments=['--ros-args', '--log-level', 'ERROR']
        )
        subprocess.Popen(['ros2', 'launch', 'livox_ros2_driver', 'livox_lidar.launch.py'])

    def start_lidar_node(self):
        self.log_text_edit.append("Starting Lidar Node...")
        livox_driver = Node(
            package='livox_ros2_driver',
            executable='livox_ros2_driver_node',
            name='livox_lidar_publisher',
            output='screen',
            parameters=livox_ros2_params,
            arguments=['--ros-args', '--log-level', 'ERROR']
        )
        subprocess.Popen(['ros2', 'launch', 'livox_ros2_driver', 'livox_lidar.launch.py'])

    def start_imu_node(self):
        self.log_text_edit.append("Starting IMU Node...")
        # Adjust the command as needed
        subprocess.Popen(['ros2', 'launch', 'imu_package', 'imu_node.launch.py'])

    def update_camera(self, data):
        self.camera_label.setText("Active")
        self.log_text_edit.append("Received image data from /image_raw")

    def update_lens(self, data):
        self.lens_label.setText("Active")
        self.log_text_edit.append("Received lens data from /motor_positions")

    def update_joystick(self, data):
        self.joystick_label.setText("Active")
        self.log_text_edit.append("Received joystick data from /joystick/control")

    def update_lidar(self, data):
        self.lidar_label.setText("Active")
        self.log_text_edit.append("Received lidar data from /lidar/pointcloud")

    def update_custom_lidar(self, data):
        self.log_text_edit.append("Received Livox CustomMsg data from /livox/lidar")

    def update_imu(self, data):
        self.imu_label.setText("Active")
        self.log_text_edit.append("Received IMU data from /livox/imu")

    def run(self):
        while rclpy.ok():
            rclpy.spin_once(self.node, timeout_sec=0.1)
            QApplication.processEvents()

class ROS2Node(Node):
    def __init__(self, widget):
        super().__init__('ros2_monitor_widget')
        self.widget = widget
        self.camera_sub = self.create_subscription(Image, '/image_raw', self.widget.update_camera, 10)
        self.lens_sub = self.create_subscription(MotorPositions, '/motor_positions', self.widget.update_lens, 10)
        self.joystick_sub = self.create_subscription(Joy, '/joystick/control', self.widget.update_joystick, 10)
        self.lidar_sub = self.create_subscription(PointCloud2, '/lidar/pointcloud', self.widget.update_lidar, 10)
        self.imu_sub = self.create_subscription(Imu, '/livox/imu', self.widget.update_imu, 10)
        self.custom_lidar_sub = self.create_subscription(CustomMsg, '/livox/lidar', self.widget.update_custom_lidar, 10)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    widget = ROS2MonitorWidget()
    widget.show()
    widget.run()
    sys.exit(app.exec_())
