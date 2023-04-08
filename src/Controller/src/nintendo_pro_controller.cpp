#include "rclcpp/rclcpp.hpp"
#include <sensor_msgs/msg/joy.hpp>
#include <geometry_msgs/msg/twist.hpp>

class Controller : public rclcpp::Node
{
    public:
        Controller():Node("pro_controller_node")
        {
            subscriber_ = this->create_subscription<sensor_msgs::msg::Joy>("joy",10,std::bind(&Controller::controller_callback,this,std::placeholders::_1));
            publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",10);
        }

    private:
        void controller_callback(const sensor_msgs::msg::Joy::SharedPtr joy_msg)const
        {
            auto message = geometry_msgs::msg::Twist();
            message.linear.x = -5*joy_msg->axes[1];
            message.linear.y = -5*joy_msg->axes[0];
            message.angular.z = 5*joy_msg->buttons[5] -5*joy_msg->buttons[6];
            publisher_->publish(message);
            printf("%f\n",joy_msg->axes[1]);
            //RCLCPP_INFO(this->get_logger(),"%f",joy_msg.buttons(0));
        }
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscriber_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc,char *argv[])
{
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<Controller>());
    rclcpp::shutdown();
    return 0;
}