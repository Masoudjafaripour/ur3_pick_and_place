#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>

class PickAndPlace : public rclcpp::Node {
public:
    PickAndPlace() : Node("pick_and_place") {
        move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(this, "manipulator");

        RCLCPP_INFO(this->get_logger(), "Moving to pick position...");
        move_to_pose(0.4, 0.0, 0.2);

        RCLCPP_INFO(this->get_logger(), "Closing gripper...");
        // Add gripper command here

        RCLCPP_INFO(this->get_logger(), "Moving to place position...");
        move_to_pose(0.6, -0.2, 0.2);

        RCLCPP_INFO(this->get_logger(), "Opening gripper...");
        // Add gripper command here
    }

    void move_to_pose(double x, double y, double z) {
        geometry_msgs::msg::Pose target_pose;
        target_pose.position.x = x;
        target_pose.position.y = y;
        target_pose.position.z = z;

        move_group_->setPoseTarget(target_pose);
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        if (move_group_->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS) {
            move_group_->execute(plan);
        } else {
            RCLCPP_ERROR(this->get_logger(), "Motion planning failed!");
        }
    }

private:
    std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PickAndPlace>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
