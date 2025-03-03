#include "tocabi_lib/robot_data.h"
#include "wholebody_functions.h"
#include <std_msgs/String.h>

#include "math_type_define.h"
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Bool.h>
#include "tocabi_msgs/matrix_3_4.h"
#include <geometry_msgs/PoseArray.h>
#include <visualization_msgs/MarkerArray.h>
#include <std_msgs/String.h>
#include <sstream>
#include <fstream>

//lexls
// #include <lexls/lexlsi.h>
// #include <lexls/tools.h>
// #include <lexls>

#include <iomanip>
#include <iostream>

// pedal
#include <ros/ros.h>
#include "tocabi_msgs/WalkingCommand.h"
#include <std_msgs/Float32.h>

#include <eigen_conversions/eigen_msg.h>

const int FILE_CNT = 0;

const std::string FILE_NAMES[FILE_CNT] =
{
  ///change this directory when you use this code on the other computer///
    // "/home/dyros/data/dg/0_flag_.txt",
    // "/home/dyros/data/dg/1_com_.txt",
    // "/home/dyros/data/dg/2_zmp_.txt",
    // "/home/dyros/data/dg/3_foot_.txt",
    // "/home/dyros/data/dg/4_torque_.txt",
    // "/home/dyros/data/dg/5_joint_.txt",
    // "/home/dyros/data/dg/6_hand_.txt",
    // "/home/dyros/data/dg/7_elbow_.txt",
    // "/home/dyros/data/dg/8_shoulder_.txt",
    // "/home/dyros/data/dg/9_acromion_.txt",
    // "/home/dyros/data/dg/10_hmd_.txt",
    // "/home/dyros/data/dg/11_tracker_.txt",
    // "/home/dyros/data/dg/12_qpik_.txt",
    // "/home/dyros/data/dg/13_tracker_vel_.txt"
};

const std::string calibration_folder_dir_ = "/home/dyros/data/vive_tracker/calibration_log/dh";  //tocabi 
// const std::string calibration_folder_dir_ = "/home/dg/data/vive_tracker/calibration_log/kaleem";    //dg pc
//const std::string calibration_folder_dir_ = "/home/dh-sung/data/avatar/calibration_log/dg";  //master ubuntu 

class AvatarController
{
public:
    AvatarController(RobotData &rd);
    // ~AvatarController();
    Eigen::VectorQd getControl();

    void computeSlow();
    void computeFast();
    void computeThread3();
    void computePlanner();

    RobotData &rd_;
    RobotData rd_cc_;

    ros::NodeHandle nh_avatar_;
    ros::CallbackQueue queue_avatar_;
    void avatar_callback(const std_msgs::StringConstPtr& msg);
    ros::Subscriber sub_1;
};
