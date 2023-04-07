from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package = 'joy',
            executable = 'joy_node',
        ),
        Node(
            package = 'Controller',
            executable = 'nintendo_pro_controller',
        )
    ])