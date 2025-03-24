
from random_number_launch import LaunchDescription
from random_number_launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='random_checker',
            executable='random_number_publisher',
            name='random_number_publisher'
        ),
        Node(
            package='random_checker',
            executable='number_checker_subscriber',
            name='number_checker_subscriber'
        )
    ])
