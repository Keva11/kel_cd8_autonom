#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class NumberCheckerSubscriber : public rclcpp::Node {
public:
    NumberCheckerSubscriber() : Node("number_checker_subscriber") {
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "random_number", 10,
            std::bind(&NumberCheckerSubscriber::check_number, this, std::placeholders::_1));
    }
private:
    void check_number(const std_msgs::msg::Int32::SharedPtr msg) {
        std::string result = (msg->data % 2 == 0) ? "even" : "odd";
        RCLCPP_INFO(this->get_logger(), "Received: %d is %s", msg->data, result.c_str());
    }
    
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
};
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NumberCheckerSubscriber>());
    rclcpp::shutdown();
    return 0;
}