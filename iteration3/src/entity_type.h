/**
 * @file actuator_commands.h
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 */

#ifndef PROJECT_ITERATION3_SRC_ENTITY_TYPE_H_
#define PROJECT_ITERATION3_SRC_ENTITY_TYPE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * @brief The supported commands that the robot supports: forward, turn left a
 * little bit, turn right a little bit. Doesn't get much simpler than that!
 */
enum EntityType {
  kRobot,
  kSuperBot,
  kPlayer,
  kHomeBase,
  kRechargeStation,
  kWall,
  kNull
};
NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION3_SRC_ENTITY_TYPE_H_
