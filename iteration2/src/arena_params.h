/**
 * @file arena_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 */

#ifndef PROJECT_ITERATION2_SRC_ARENA_PARAMS_H_
#define PROJECT_ITERATION2_SRC_ARENA_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_params.h"
#include "src/player_params.h"
#include "src/home_base_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/
#define MAX_OBSTACLES 8
#define MAX_ROBOTS 5  // add max 11/28

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
      : player(),
        robots(),
        super_bot(),
        recharge_station(),
        home_base(),
        obstacles(),
        n_obstacles(),
        n_robots(),  // 11/28
        x_dim(),
        y_dim() {}

  struct player_params player;
  struct arena_entity_params recharge_station;
  struct home_base_params home_base;
  struct super_bot_params super_bot;
  struct arena_entity_params obstacles[MAX_OBSTACLES];
  struct robot_params robots[MAX_ROBOTS];  // 11/28
  size_t n_obstacles;
  size_t n_robots;  // 11/28
  uint x_dim;
  uint y_dim;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_ARENA_PARAMS_H_
