import os
from datetime import datetime

from ament_index_python.packages import get_package_share_directory
import launch
from launch import LaunchDescription
from launch_ros.actions import Node


WILDPOSE_HOME = '/home/naoya/wildPose_v1.3/wildpose'
def generate_launch_description():

    motor_control_node = Node(
        package='motor_controller_pkg',
        executable='motor_control_node',
        name='motor_control_node',
        parameters=[
            {'motor_speed', '500'},
        ],
        arguments=['--ros-args',
            '--log-level','INFO'
        ]
    )

    return LaunchDescription([motor_control_node])

# Launch Description as a function
launch.LaunchDescription = generate_launch_description
