/**
 * @file robot_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
RobotMotionHandler::RobotMotionHandler() :
    heading_angle_(0),
    speed_(0),
    max_speed_(100),
    max_angle_(360),
    speed_delta_(30),
    angle_delta_(30) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void RobotMotionHandler::AcceptCommand(enum event_commands cmd) {
  switch (cmd) {
    case COM_TURN_LEFT:
      heading_angle_ -= (angle_delta_);
      if (heading_angle_ < 0) { heading_angle_ += max_angle_; }
      break;
    case COM_TURN_RIGHT:
      heading_angle_ += (angle_delta_);
      if (heading_angle_ > max_angle_) { heading_angle_ -= max_angle_; }
      break;
    case COM_SPEED_UP:
      speed_ += (speed_delta_);
      if (speed_ > max_speed_) { speed_ = max_speed_; }
      break;
    case COM_SLOW_DOWN:
      speed_ -= (speed_delta_);
      if (speed_ < 0) { speed_ = 0; }
      break;
    default:
      std::cerr << "FATAL: bad actuator command" << std::endl;
      assert(false);
      break;
  } /* switch() */
} /* accept_command() */

void RobotMotionHandler::UpdateVelocity(SensorTouch st) {
  if (st.activated()) {
    heading_angle_ = -st.angle_of_contact();
    speed_ *= 0.9;  // decrease speed 10% if collided
    st.Reset();
  }
}

NAMESPACE_END(csci3081);
