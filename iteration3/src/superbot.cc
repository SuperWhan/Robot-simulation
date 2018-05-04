/**
 * @file super_bot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/superbot.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SuperBot::SuperBot(const struct super_bot_params *const params) :
    ArenaMobileEntity(params->radius, params->collision_delta,
                      params->pos, params->color),
    initial_pos_(params->pos),
    motion_handler_(),
    motion_behavior_(),
    sensor_touch_() {
  motion_handler_.set_heading_angle(180.0);
  motion_handler_.set_speed(5);
  motion_handler_.max_speed(10);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void SuperBot::Reset() {
  set_pos(initial_pos_);
  motion_handler_.Reset();
  motion_handler_.set_heading_angle(180.0);
  motion_handler_.set_speed(5);
  motion_handler_.max_speed(10);
  sensor_touch_.Reset();
} /* Reset */

void SuperBot::TimestepUpdate(uint dt) {
  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateHeading(sensor_touch_);
  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);

  // 2% chance of change direction (per frame)
  // NOTE: by default, frame rate ~20 fps
  //
  // +1 because random_num uses uniform_real_distribution(),
  // which generates random numbers on the interval [a,b)
  //
  // for angle we can just use max_angle() directly because 360
  // degree = 0 degree
  if (random_num(0, 50 + 1) == 0) {
    motion_handler_.set_heading_angle(
                                random_num(0.0, motion_handler_.max_angle()));
  }
} /* TimestepUpdate */

void SuperBot::Accept(const EventCollision *const e) {
  sensor_touch_.Accept(e);
} /* Accept */


NAMESPACE_END(csci3081);
