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
import time
from PyQt5.QtCore import QTimer  # Import QTimer



class ROS2MonitorWidget(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()


    def initUI(self):
        self.setWindowTitle('ROS2 Nodes Monitor')

        self.layout = QGridLayout()

        # Labels for column headers
        self.layout.addWidget(QLabel("Node"), 0, 0)
        self.layout.addWidget(QLabel("Status"), 0, 1)
        self.layout.addWidget(QLabel("Topics"), 0, 2)


        # Camera Section
        self.camera_label = QLabel("Unknown")
        self.camera_topics_label = QLabel("/image_raw")
        self.layout.addWidget(QLabel("Camera"), 1, 0)
        self.layout.addWidget(self.camera_label, 1, 1)
        self.layout.addWidget(self.camera_topics_label, 1, 2)


        # Lens Section
        self.lens_label = QLabel("Unknown")
        self.lens_topics_label = QLabel("/motor_positions")
        self.layout.addWidget(QLabel("Lens"), 2, 0)
        self.layout.addWidget(self.lens_label, 2, 1)
        self.layout.addWidget(self.lens_topics_label, 2, 2)


        # Joystick Section
        self.joystick_label = QLabel("Unknown")
        self.joystick_topics_label = QLabel("/joystick/control")
        self.joystick_start_button = QPushButton("Start Joystick Node")
        self.layout.addWidget(QLabel("Joystick"), 3, 0)
        self.layout.addWidget(self.joystick_label, 3, 1)
        self.layout.addWidget(self.joystick_topics_label, 3, 2)


        # Lidar Section
        self.lidar_label = QLabel("Unknown")
        self.lidar_topics_label = QLabel(" /livox/lidar")
        self.layout.addWidget(QLabel("Lidar"), 4, 0)
        self.layout.addWidget(self.lidar_label, 4, 1)
        self.layout.addWidget(self.lidar_topics_label, 4, 2)


        # IMU Section
        self.imu_label = QLabel("Unknown")
        self.imu_topics_label = QLabel("/livox/imu")
        self.layout.addWidget(QLabel("IMU"), 5, 0)
        self.layout.addWidget(self.imu_label, 5, 1)
        self.layout.addWidget(self.imu_topics_label, 5, 2)

        # Log Section
        self.log_text_edit = QTextEdit()
        self.log_text_edit.setReadOnly(True)
        self.layout.addWidget(self.log_text_edit, 7, 0, 1, 5)
        self.layout.addWidget(QLabel("Log"), 6, 0)

        self.setLayout(self.layout)

          # Start the timer to periodically check for active nodes
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.check_active_nodes)
        self.timer.start(500)  # Check every 500 milliseconds

    def check_active_nodes(self):
        # Execute the 'ros2 node list' command
        result = subprocess.run(['ros2', 'node', 'list'], capture_output=True, text=True)
        active_nodes = result.stdout.splitlines()

        # Update labels or UI elements based on the active nodes
        if '/ximea_cam_node' in active_nodes:
            self.camera_label.setText("Active")
        else:
            self.camera_label.setText("Inactive")

        if '/motor_control_node' in active_nodes:
            self.lens_label.setText("Active")
        else:
            self.lens_label.setText("Inactive")

        if '/livox_lidar_publisher' in active_nodes:
            self.lidar_label.setText("Active")
        else:
            self.lidar_label.setText("Inactive")

        if '/gamepad_f710_publisher' in active_nodes:
            self.joystick_label.setText("Active")
        else:
            self.joystick_label.setText("Inactive")



    def run(self):
        while rclpy.ok():
            rclpy.spin_once(self.node, timeout_sec=0.1)
            QApplication.processEvents()




if __name__ == '__main__':
    app = QApplication(sys.argv)
    widget = ROS2MonitorWidget()
    widget.show()
    widget.run()
    sys.exit(app.exec_())
