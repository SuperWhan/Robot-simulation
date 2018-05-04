/**
 * @file player_battery.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include "src/player_battery.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double PlayerBattery::Deplete(double linear_vel, double angular_vel) {
  charge_ -= (kBASE_DEPLETION +
      (kLINEAR_SCALE_FACTOR * linear_vel) +
      (kANGULAR_SCALE_FACTOR * angular_vel));
  return charge_;
} /* deplete() */

double PlayerBattery::Deplete(Position old_pos, Position new_pos, double dt) {
  double dist = std::sqrt(
      std::pow(old_pos.x() - new_pos.x(), 2) +
          std::pow(old_pos.y() - new_pos.y(), 2));

  if (dt == 0)  // division by 0...
    return charge_;
  else
    charge_ -= (kBASE_DEPLETION + (kLINEAR_SCALE_FACTOR * (dist / dt)));

  if (charge_ < 0)  // no negative charge
    charge_ = 0;

  return charge_;
} /* deplete() */

void PlayerBattery::Accept(const EventCollision *const e) {
  if (e->collided()) {
    charge_ -= (max_charge_ * kCOLLISION_DEPLETION);
  }
}

NAMESPACE_END(csci3081);
