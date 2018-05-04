/**
 * @file motion_handler.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_MOTION_HANDLER_H_
#define PROJECT_ITERATION2_SRC_MOTION_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_commands.h"
#include "src/arena_mobile_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief Class managing an ArenaMobileEntity's speed and heading angle based
 * on collisions and (in the case of Robot) user inputs.
 *
 * Currently, both wheels are always going at maximum speed, and
 * cannot be controlled independently.
 */
class MotionHandler {
 public:
  /**
   * @brief Default constructor.
   */
  MotionHandler();


  virtual void Reset() = 0;

  double max_speed() const { return max_speed_; }

  void max_speed(double ms) { max_speed_ = ms; }

  double max_angle() const { return max_angle_; }

  void max_angle(double ma) { max_angle_ = ma; }





 private:
  double max_speed_;
  double max_angle_;
};

NAMESPACE_END(csci3081);

#endif   // PROJECT_ITERATION2_SRC_MOTION_HANDLER_H_
