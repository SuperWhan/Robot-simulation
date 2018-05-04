/**
 * @file robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"
#include "src/initialize.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Robot::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Robot::Robot(const struct robot_params *const params) :
    ArenaMobileEntity(params->radius, params->collision_delta,
                      params->pos, params->color),
    id_(-1),
    super_bot_(false),
    motion_handler_(),
    motion_behavior_(),
    sensor_touch_(),
    initial_pos_(params->pos) {
  motion_handler_.set_heading_angle(100.0);  // int->double
  motion_handler_.max_speed(10.0);
  motion_handler_.set_speed(5);
  // distress_sensor_.set_detect_range(200.0);
  id_ = next_id_++;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Robot::TimestepUpdate(uint dt) {
  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateHeading(sensor_touch_);

  // motion_handler_.UpdateHeading(distress_sensor_);
  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);
  if (random_num(0, 50 + 1) == 0) {
    motion_handler_.set_heading_angle(
                          random_num(0.0, motion_handler_.max_angle()));
    }
} /* TimestepUpdate() */


void Robot::Accept(const EventCollision *const e) {
  sensor_touch_.Accept(e);
  // battery_.Accept(e);
}

// void Robot::Accept(const EventDistressCall *const e) {
// distress_sensor_.Accept(e);
// }


void Robot::Reset() {
  set_pos(initial_pos_);
  motion_handler_.Reset();
  motion_handler_.set_heading_angle(100.0);  // int->double
  motion_handler_.set_speed(5);
  motion_handler_.max_speed(10);
  set_super(false);
  set_color(ROBOT_COLOR);
  sensor_touch_.Reset();
} /* Reset() */


NAMESPACE_END(csci3081);
