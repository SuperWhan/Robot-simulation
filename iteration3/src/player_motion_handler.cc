/**
 * @file player_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/player_motion_handler.h"
#include "src/initialize.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
PlayerMotionHandler::PlayerMotionHandler() :
    heading_angle_(0.0),
    speed_(0),
    speed_delta_(30),
    angle_delta_(30.0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void PlayerMotionHandler::AcceptCommand(enum event_commands cmd) {
  switch (cmd) {
    case COM_TURN_LEFT:
      heading_angle_ -= (angle_delta_);
      if (heading_angle_ < 0) { heading_angle_ += max_angle(); }
      break;
    case COM_TURN_RIGHT:
      heading_angle_ += (angle_delta_);
      if (heading_angle_ > max_angle()) { heading_angle_ -= max_angle(); }
      break;
    case COM_SPEED_UP:
      speed_ += (speed_delta_);
      if (speed_ > max_speed()) { speed_ = max_speed(); }
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
} /* Accept_command() */

void PlayerMotionHandler::UpdateVelocity(SensorTouch st) {
  if (st.activated()) {
    heading_angle_ = -st.angle_of_contact();
    speed_ *= 0.9;  // decrease speed 10% if collided
    st.Reset();
  }
}

void PlayerMotionHandler::Reset() {
  set_speed(0);
  set_speed_delta(SPEED_DELTA);
  set_angle_delta(ANGLE_DELTA);
  set_heading_angle(0.0);
}

NAMESPACE_END(csci3081);
