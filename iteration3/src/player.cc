/**
 * @file player.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/player.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Player::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Player::Player(const struct player_params *const params) :
    ArenaMobileEntity(params->radius, params->collision_delta,
                      params->pos, params->color),
    id_(-1),
    freeze_(false),
    freeze_time_(10),
    heading_angle_(0.0),  // int->double
    angle_delta_(params->angle_delta),
    speed_delta_(params->speed_delta),
    battery_(params->battery_max_charge),
    motion_handler_(),
    motion_behavior_(),
    sensor_touch_(),
    initial_pos_(params->pos) {
  motion_handler_.set_speed(5);
  motion_handler_.set_heading_angle(270.0);  // int->double
  motion_handler_.max_speed(params->max_speed);
  motion_handler_.max_angle(360.0);  // int->double
  motion_handler_.set_speed_delta(params->speed_delta);
  motion_handler_.set_angle_delta(params->angle_delta);
  id_ = next_id_++;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Player::TimestepUpdate(uint dt) {
  if (freeze_) {
    if (freeze_time_ != 0) {
      freeze_time_ -= 1;
    } else {
      not_freeze();
      freeze_time_ = 10;
    }
  } else {
    Position old_pos = get_pos();
    // double old_heading_angle = heading_angle();

    // Update heading and speed as indicated by touch sensor
    motion_handler_.UpdateVelocity(sensor_touch_);
    // Use velocity and position to update position
    motion_behavior_.UpdatePosition(this, dt);

    // double vel = std::sqrt(std::pow(get_pos().x() - old_pos.x(), 2) +
    //     std::pow(get_pos().y() - old_pos.y(), 2)) / static_cast<double>(dt);
    // double angular_vel = std::abs(heading_angle() - old_heading_angle) /
    //     static_cast<double>(dt);
    // battery_.Deplete(vel, angular_vel);

    battery_.Deplete(old_pos, get_pos(), static_cast<double>(dt));
  }
} /* TimestepUpdate() */

void Player::Accept(__unused const EventRecharge *const e) {
  battery_.EventRecharge();
}

void Player::Accept(const EventCollision *const e) {
  sensor_touch_.Accept(e);
  battery_.Accept(e);
}

void Player::Accept(const EventCommand *const e) {
  motion_handler_.AcceptCommand(e->cmd());
} /* event_cmd() */

void Player::Reset() {
  set_pos(initial_pos_);
  battery_.Reset();
  motion_handler_.Reset();
  motion_handler_.set_heading_angle(270.0);  // int->double
  motion_handler_.set_speed(5);
  motion_handler_.max_speed(10);
  sensor_touch_.Reset();
} /* Reset() */

void Player::ResetBattery() {
  battery_.Reset();
}

NAMESPACE_END(csci3081);
