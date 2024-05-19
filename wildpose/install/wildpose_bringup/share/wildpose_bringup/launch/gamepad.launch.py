import os
from datetime import datetime

from ament_index_python.packages import get_package_share_directory
import launch
from launch import LaunchDescription
from launch_ros.actions import Node


WILDPOSE_HOME = '/home/naoya/wildPose_v1.3/wildpose'

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='joy_linux',
            executable='joy_linux_node',
            name='gamepad_f710_publisher',
            parameters=[
                {'dev': '/dev/input/js0'},
                {'dev_name': 'Wireless Gamepad F710'},
                {'autorepeat_rate': 0.1}
            ],
            arguments=[
                '--ros-args',
                '--log-level', 'ERROR'
            ]
        )
    ])

