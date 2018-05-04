/**
 * @file robot_motion_behavior.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_MOTION_BEHAVIOR_H_
#define SRC_ROBOT_MOTION_BEHAVIOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <Eigen/Dense>
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class managing an ArenaMobileEntity's position.
 *
 * Update the position based on the current velocity and position. This
 * is simple, but the framework allows for more sophisticated models of
 * motion in which each wheel has different speeds.
 */
class RobotMotionBehavior {
 public:
  /**
   * @brief Default constructor.
   */
  RobotMotionBehavior() = default;

  /**
   * @brief Update the position for an ArenaMobileEntity, based on its current
   * position and velocity.
   *
   * @param[in] ent The entity to update.
   * @param dt # of timesteps elapsed since the last update.
   */
  void UpdatePosition(class ArenaMobileEntity *const ent, unsigned int dt);
};

NAMESPACE_END(csci3081);

#endif  // SRC_ROBOT_MOTION_BEHAVIOR_H_
