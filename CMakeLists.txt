cmake_minimum_required(VERSION 3.5)
project(ur_pick_and_place)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)

add_executable(pick_and_place src/pick_and_place.cpp)
ament_target_dependencies(pick_and_place rclcpp moveit_ros_planning_interface)

install(TARGETS pick_and_place DESTINATION lib/${PROJECT_NAME})

ament_package()
