/**
 * @file arena_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 */

#ifndef SRC_ARENA_PARAMS_H_
#define SRC_ARENA_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_params.h"
#include "src/home_base_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/
#define MAX_OBSTACLES 8

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
* @brief Struct holding parameters for initializing the Arena.
*
* These parameters include the parameters for Arena's geometry as well as the
* parameters for initializing ALL entities within the Arena.
*/
struct arena_params {
  arena_params()
      : robot(),
        recharge_station(),
        home_base(),
        obstacles(),
        n_obstacles(),
        x_dim(),
        y_dim() {}

  struct robot_params robot;
  struct arena_entity_params recharge_station;
  struct home_base_params home_base;
  struct arena_entity_params obstacles[MAX_OBSTACLES];
  size_t n_obstacles;
  uint x_dim;
  uint y_dim;
};

NAMESPACE_END(csci3081);

#endif /* SRC_ARENA_PARAMS_H_ */
