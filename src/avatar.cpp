#include "avatar.h"
using namespace TOCABI;

AvatarController::AvatarController(RobotData &rd) : rd_(rd)
{
    nh_avatar_.setCallbackQueue(&queue_avatar_);

}

Eigen::VectorQd AvatarController::getControl()
{
    return rd_.torque_desired;
}

void AvatarController::computeSlow()
{

}

void AvatarController::computeFast()
{

}

void AvatarController::computeThread3()
{

}