#include <std_msgs/msg/string.hpp>
#include <string>

#include "subscriber_node.hpp"

using namespace std::chrono_literals;

void SubscriberNode::help_callback(const std_msgs::msg::String::SharedPtr msg) {
  RCLCPP_INFO_STREAM(this->get_logger(), "Received data: " << msg->data);
}

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  auto subscriber_node = std::make_shared<SubscriberNode>("help_sub_cpp");
  rclcpp::spin(subscriber_node);
  rclcpp::shutdown();
}