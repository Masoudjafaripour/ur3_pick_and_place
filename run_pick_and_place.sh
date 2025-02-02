#!/bin/bash
source install/setup.bash

# Start MoveIt! and the UR robot driver
ros2 launch ur_pick_and_place ur_moveit.launch.py &

# Wait for MoveIt! and driver to start
sleep 5  

# Run the Pick and Place task
ros2 launch ur_pick_and_place pick_and_place.launch.py
