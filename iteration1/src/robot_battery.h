/**
 * @file robot_battery.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_BATTERY_H_
#define SRC_ROBOT_BATTERY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"
#include "src/event_collision.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief Class representing the battery for a Robot.
 */
class RobotBattery {
 public:
  explicit RobotBattery(double max_charge) : charge_(max_charge),
                                             max_charge_(max_charge) {}

  /**
   * @brief All Robots consume SOME power, even when just sitting there not
   * moving. However, currently kBASE_DEPLETION is 0 to satisfy the project
   * requirement.
   */
  double kBASE_DEPLETION = 0;

  /**
   * @brief The amount of energy consumed by the Robot due to its linear speed
   * is directly proportional to that speed, with a scaling factor.
   */
  double kLINEAR_SCALE_FACTOR = 0.01;

  /**
   * @brief The amount of energy consumed by the Robot due to its angular speed
   * is directly proportional to that speed, with a scaling factor.
   */
  double kANGULAR_SCALE_FACTOR = 0.01;

  /**
   * @brief The amount of energy consumed by the Robot due to a collision event
   * is directly proportional to the maximum battery level, with a scaling
   * factor.
   */
  double kCOLLISION_DEPLETION = 0.01;

  /**
   * @brief Getter method for the battery level.
   *
   * @return The current battery level.
   */
  double level() const { return charge_; }

  /**
   * @brief Getter method for the max battery level.
   *
   * @return The max battery level.
   */
  double max_level() const { return max_charge_; }

  /**
   * @brief Initiate a recharge event by instantly restoring the battery
   * to its maximum charge.
   */
  void EventRecharge() { charge_ = max_charge_; }

  /**
   * @brief Reset the battery to its newly constructed/un-depleted
   * state.
   */
  void Reset() { EventRecharge(); }

  /**
   * @brief Calculate the new battery level based on the current
   * linear/angular speed. Currently unused. Left here in case needed
   * in future iterations.
   *
   * @param linear_vel The current linear speed, in m/s.
   * @param angular_vel The current angular speed, in rad/s.
   *
   * @return The updated battery level.
   */
  double Deplete(double linear_vel, double angular_vel);

  /**
   * @brief Calculate the new battery level based on the current linear speed.
   *
   * @param old_pos The robot's previous position.
   * @param new_pos The robot's current position.
   * @param dt Time taken by the robot to move from old_pos to new_pos.
   *
   * @return The updated battery level.
   */
  double Deplete(Position old_pos, Position new_pos, double dt);

  /**
   * @brief Inform the battery that a collision has occurred. Deplete the
   * battery accordingly.
   *
   * @param e A collision event.
   *
   * Currently 1% of the max battery level will be depleted. For example,
   * if the battery level before the collision is 60, then the new battery
   * level would be 59 (given that the max battery level is 100).
   */
  void Accept(const EventCollision *const e);

 private:
  double charge_;
  double max_charge_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ROBOT_BATTERY_H_
