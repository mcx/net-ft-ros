#ifndef NETFT_RDT_BIAS_H_
#define NETFT_RDT_BIAS_H_

#include <ros/ros.h>

#include <geometry_msgs/Wrench.h>
#include <std_msgs/Bool.h>
#include "netft_rdt_driver/String_cmd.h"
#include <tf/LinearMath/Matrix3x3.h>



namespace netft_rdt_driver
{

class NetFTRDTDriverBias{

public:

    NetFTRDTDriverBias(ros::NodeHandle& nh, double rot,std::size_t num_points=50);

    void update(geometry_msgs::Wrench& wrench);

    void compute_bias(const geometry_msgs::Wrench& wrench);

  void set_compute_bias(bool val=true);

private:

    void print_bias() const;

    bool service_callback(netft_rdt_driver::String_cmd::Request& request, netft_rdt_driver::String_cmd::Response& response);

private:


    geometry_msgs::Vector3  force_b,  force_b_tmp;
    geometry_msgs::Vector3  torque_b, torque_b_tmp;

    ros::ServiceServer    service_server;
    ros::Publisher        pub_bias_status;
    std_msgs::Bool        bias_status;

    tf::Matrix3x3         Rot;
    tf::Vector3           tmp;

    std::size_t           num_points;
    std::size_t           count;
    bool                  bComputeBias;

};

}


#endif
