/**
 * @file robot_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_PARAMS_H_
#define SRC_ROBOT_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @brief Inherits from arena_mobile_entity_params to set various
 * properties of the Robot.
 */
struct robot_params : public arena_mobile_entity_params {
  robot_params() :
      arena_mobile_entity_params(),
      battery_max_charge(),
      angle_delta(),
      speed_delta(),
      max_speed() {}

  double battery_max_charge;
  uint angle_delta;
  double speed_delta;
  double max_speed;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ROBOT_PARAMS_H_
