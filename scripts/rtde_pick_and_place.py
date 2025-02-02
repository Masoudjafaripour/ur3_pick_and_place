import rtde_control
import rtde_receive
import time

ROBOT_IP = "192.168.1.100"

rtde_c = rtde_control.RTDEControlInterface(ROBOT_IP)
rtde_r = rtde_receive.RTDEReceiveInterface(ROBOT_IP)

pick_pose = [0.4, 0.0, 0.2, 0, 0, 0]
place_pose = [0.6, -0.2, 0.2, 0, 0, 0]

print("Moving to pick position...")
rtde_c.moveL(pick_pose, 0.5, 0.5)
time.sleep(1)

print("Closing gripper...")
# Add gripper command here

print("Moving to place position...")
rtde_c.moveL(place_pose, 0.5, 0.5)
time.sleep(1)

print("Opening gripper...")
# Add gripper command here

rtde_c.stopScript()
