


cmake_minimum_required(VERSION 3.5)
project(random_checker)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
add_executable(random_number_publisher src/random_number_publisher.cpp)
ament_target_dependencies(random_number_publisher rclcpp std_msgs)
add_executable(number_checker_subscriber src/number_checker_subscriber.cpp)
ament_target_dependencies(number_checker_subscriber rclcpp std_msgs)
install(TARGETS
  random_number_publisher
  number_checker_subscriber
  DESTINATION lib/${PROJECT_NAME}
)
ament_package()
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/
)
