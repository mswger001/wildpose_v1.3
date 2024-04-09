import os
from datetime import datetime

from ament_index_python.packages import get_package_share_directory
import launch
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

################### Livox TELE-15 user-defined parameters start ###################
xfer_format   = 0    # 0-Pointcloud2(PointXYZRTL), 1-customized pointcloud format
multi_topic   = 0    # 0-All LiDARs share the same topic, 1-One LiDAR one topic
data_src      = 0    # 0-lidar,1-hub
publish_freq  = 100 # freqency of publish,1.0,2.0,5.0,10.0,etc
return_mode = 2 # 2-dual return
output_type   = 0
frame_id      = 'livox_frame'
lvx_file_path = '/home/livox/livox_test.lvx'
cmdline_bd_code = 'livox0000000001'


config_path = '/home/m2s2/WildPose_v1.2-main/wildpose/src/livox_lidar_ROS2_driver/livox_ros2_driver/config'
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

  # Get path to xiCam_config.yaml file
ximea_ros2_cam_share_dir = get_package_share_directory('ximea_ros2_cam')
xiCam_config_yaml = os.path.join(ximea_ros2_cam_share_dir, 'config', 'xiCam_config.yaml')

ximea_cam_parameters = {
    ################### XIMEA camera user-defined parameters start ###################
    ####################
    # General Configuration Parameters Go Here!
    ####################

    ####################
    # General Configuration Parameters Go Here!
    ####################

    # directory to save images (make sure that directory exists and that it is an absolute path).
    "image_directory": "/home/dev/" , # must be absolute path, not relative path (i.e. '~')

    # save images to the disk
    "save_disk": False,

    # save images on trigger (calibration only)
    "calib_mode": False,

    #########################
    # Diagnostics Parameters
    #########################

    "enable_diagnostics": True,
    "data_age_max": 0.1,
    "pub_frequency": 10.0,
    "pub_frequency_tolerance": 1.0,

    #########################################
    # Camera Configuration Parameters Go Here!
    ##########################################

    # image_transport compressed image parameters
    "image_transport_compressed_format": "png",
    "image_transport_compressed_jpeg_quality": 100,
    "image_transport_compressed_png_level": 5,

    # colour format
    "format": "XI_MONO8" ,             # Recommended to set to RAW for ARM processors and do offline processing later
                                    #  some options: mono8, rgb24, raw8

    # triggering (0 - none, 1 - software trigger (NOT IMPLMENTED YET),
    # 2 - hardware trigger)
    "cam_trigger_mode": 0,
    "hw_trigger_edge": 0  ,            # if hw trigger, 0/1 = rising/falling edge trigger

    # for camera frame rate
    "frame_rate_control": True ,       # enable or disable frame razte control
                                    # (works if no triggering is enabled)
    "frame_rate_set": 120 ,            # for trigger mode, fps limiter (0 for none)
    "img_capture_timeout": 1000 ,      # timeout in milliseconds for xiGetImage()

    # exposure settings
    "auto_exposure":  True ,           # auto exposure on or off
    "exposure_time": 3000  ,           # manual exposure time in microseconds
    "manual_gain": 9.0 ,               # manual exposure gain
    "auto_exposure_priority": 0.8  ,   # auto exposure to gain ratio (1 = use only exposure)
    "auto_time_limit": 30000  ,        # auto exposure time limit in microseconds
    "auto_gain_limit": 2.0  ,          # auto exposure gain limit

    # camera coloring 
    # white balance mode: 0 - none, 1 - use coefficients, 2 = auto
    "white_balance_mode": 2,
    "white_balance_coef_red": 3.0 ,    # white balance red coefficient (0 to 8)
    "white_balance_coef_green": 0.0 ,  # white balance green coefficient (0 to 8)
    "white_balance_coef_blue": 4.0 ,   # white balance blue coefficient (0 to 8)

    # region of interest
    "roi_left": 384  ,                 # top left corner in pixels
    "roi_top": 184,
    "roi_width": 1280 ,                # width height in pixels (2048)
    "roi_height": 720 ,                # up to (1088)

    #roi_left: 0                    # top left corner in pixels
    #roi_top: 0
    #roi_width: 2048                # width height in pixels (2048)
    #roi_height: 1088               # up to (1088)

    # CV resizing
    # alternative to roi, maintains FOV with an expected performance tradeoff
    #"cv_resize_enable": False,
    "cv_height": 512,
    "cv_width": 640,


    # CV inverting for calibration purposes
    
    
    # lens control -> Only works if lens_mode is set to 1 (XI_ON)
    # lens_mode: 0		                #XI_PRM_LENS_MODE or "lens_mode", 1 to enable lens control, else 0
    # lens_aperture_value: 0.0	      #XI_PRM_LENS_APERTURE_VALUE or "lens_aperture_value"
    # lens_aperture_index: 0          #XI_PRM_LENS_APERTURE_INDEX or "lens_aperture_index"
    # lens_focus_movement_value: 0    #XI_PRM_LENS_FOCUS_MOVEMENT_VALUE or "lens_focus_movement_value"
    # lens_focus_move: 0              #XI_PRM_LENS_FOCUS_MOVE or "lens_focus_move"
    # lens_focal_length: 0 	          #XI_PRM_LENS_FOCAL_LENGTH or "lens_focal_length   


     # Define parameters
    "cam_context" : '/home/m2s2/Nutramax_Data/test/cam_context_files/test.bin',
    "serial_no" : '29970951',
    "cam_name" : 'ximea_cam',
    'calib_file' : '',
    'frame_id' : '0',
    'num_cams_in_bus' : 2,
    'bw_safetyratio' : 2.0,
    'publish_xi_image_info' : True,
    'poll_time' : 2.0,
    'poll_time_frame' : 0.001,
    'cam_context_path' : '/home/m2s2/Nutramax_Data/test/cam_context_files/test.bin',

    # Get path to xiCam_config.yaml file
   
    'xiCam_config_yaml' : os.path.join(ximea_ros2_cam_share_dir, 'config', 'xiCam_config.yaml'),

    'cam_context_path': '/home/m2s2/cam_context_{}.bin'.format(datetime.now().strftime('%Y-%m-%d_%H-%M-%S')),

}


def generate_launch_description():

    xiCam_launch_file = os.path.join(get_package_share_directory('ximea_ros2_cam'), 'launch', 'xiCam.launch.xml')
    now = datetime.now()


    ximea_cam_driver = Node(
        package='ximea_ros2_cam',
        executable='ximea_ros2_cam_node',
        name='ximea_cam_node',
        output='screen',
        parameters=[{k: v} for k, v in ximea_cam_parameters.items()],
        arguments=['--ros-args', '--log-level','ERROR']
    )

    

    livox_driver = Node(
        package='livox_ros2_driver',
        executable='livox_ros2_driver_node',
        name='livox_lidar_publisher',
        output='screen',
        parameters=livox_ros2_params,
        arguments=['--ros-args', '--log-level','ERROR']
    )

    livox_rviz = Node(
        package='rviz2',
        executable='rviz2',
        output='screen',
        arguments=['--display-config', rviz_config_path]
    )
    
    gamepad_node = Node(
        package='joy_linux',
        executable='joy_linux_node',
        name='gamepad_f710_publisher',
        parameters=[
            {'dev', '/dev/input/js0'},
            {'dev_name', 'Wireless Gamepad F710'},
            {'autorepeat_rate', '0.1'}
        ],
        arguments=['--ros-args',
            '--log-level','ERROR'
        ]
    )

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

    lidar_control_node = Node(
        package='lidar_control_package',
        executable='lidar_control_node',
        name='lidar_control_node',
        output='screen',
        arguments=['--log-level', 'info']
    )

      # Add rqt_gui node
    rqt_gui_node = Node(
        package='rqt_gui',
        executable='rqt_gui',
        name='rqt_gui_node',
        output='screen',
    )


    return LaunchDescription([
        #ximea_cam_driver,
       #image_viewer,
       # dji_rs3_node,
        gamepad_node,
        motor_control_node,
        lidar_control_node,
        #livox_driver,
        livox_rviz,
        rqt_gui_node,
        # rosbag,
    ])
