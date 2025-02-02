from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="moveit_ros_move_group",
            executable="move_group",
            name="move_group",
            output="screen"
        ),
        Node(
            package="ur_robot_driver",
            executable="ur_control",
            name="ur_driver",
            output="screen"
        )
    ])
