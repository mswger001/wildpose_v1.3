import os
from datetime import datetime

from ament_index_python.packages import get_package_share_directory
import launch
from launch import LaunchDescription
from launch_ros.actions import Node


WILDPOSE_HOME = '/home/naoya/wildPose_v1.3/wildpose'
################### Livox TELE-15 user-defined parameters start ###################
xfer_format   = 1   # 0-Pointcloud2(PointXYZRTL), 1-customized pointcloud format
multi_topic   = 0    # 0-All LiDARs share the same topic, 1-One LiDAR one topic
data_src      = 0    # 0-lidar,1-hub
publish_freq  = 10.0 # freqency of publish,1.0,2.0,5.0,10.0,etc
return_mode = 2 # 2-dual return
output_type   = 0
frame_id      = 'livox_frame'
lvx_file_path = os.path.join(WILDPOSE_HOME, 'record/livox_test.lvx')
cmdline_bd_code = 'livox0000000001'

config_path = os.path.join(WILDPOSE_HOME, 'src/wildpose_bringup/config')
rviz_config_path = os.path.join(config_path, 'livox_lidar.rviz')
user_config_path = os.path.join(config_path, 'livox_lidar_config.json')
################### Livox TELE-15 user-defined parameters end #####################

livox_ros2_params = [
    {"xfer_format": xfer_format},
    {"multi_topic": multi_topic},
    {"data_src": data_src},
    {"publish_freq": publish_freq},
    {"output_data_type": output_type},
    {"frame_id": frame_id},
    {"lvx_file_path": lvx_file_path},
    {"return_mode": return_mode},
    {"user_config_path": user_config_path},
    {"cmdline_input_bd_code": cmdline_bd_code}
]


def generate_launch_description():

    livox_driver = Node(
        package='livox_ros2_driver',
        executable='livox_ros2_driver_node',
        name='livox_lidar_publisher',
        output='screen',
        parameters=livox_ros2_params,
        arguments=['--ros-args', '--log-level','ERROR']
    )

    return LaunchDescription([livox_driver])

# Launch Description as a function
launch.LaunchDescription = generate_launch_description
