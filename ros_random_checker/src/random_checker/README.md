# Random Checker ROS 2 Package


This package contains two ROS 2 nodes:
- `random_number_publisher`: Publishes random numbers to the `/random_number` topic.
- `number_checker_subscriber`: Subscribes to `/random_number` and checks whether the number is even or odd.



## Build and Run
```bash
colcon build --packages-select random_checker
source install/setup.bash
ros2 launch random_checker random_number_launch.py
```