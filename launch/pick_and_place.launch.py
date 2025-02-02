from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="ur_pick_and_place",
            executable="pick_and_place",
            name="pick_and_place_node",
            output="screen"
        )
    ])
