

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include <random>


class RandomNumberPublisher : public rclcpp::Node {
public:
    RandomNumberPublisher() : Node("random_number_publisher"), generator(rd()), distribution(1, 100) {
        publisher_ = this->create_publisher<std_msgs::msg::Int32>("random_number", 10);
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&RandomNumberPublisher::publish_random_number, this));
    }

private:
    void publish_random_number() {
        auto message = std_msgs::msg::Int32();
        message.data = distribution(generator);
        RCLCPP_INFO(this->get_logger(), "Publishing: %d", message.data);
        publisher_->publish(message);
    }


    
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::random_device rd;
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RandomNumberPublisher>());
    rclcpp::shutdown();
    return 0;
}