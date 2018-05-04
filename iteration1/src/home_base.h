/**
 * @file home_base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_HOME_BASE_H_
#define SRC_HOME_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/home_base_params.h"
#include "src/arena_mobile_entity.h"
#include "src/robot_motion_handler.h"
#include "src/robot_motion_behavior.h"
#include "src/sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a mobile home base within the Arena.
 *
 * HomeBase is the goal of the game. Once the Robot of the player has touched
 * the HomeBase, the player has won and the Arena is reset.
 *
 * HomeBase have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 * HomeBase differs from Robot mainly in that 1) it does not have a battery
 * (so it can keep moving forever) AND 2) it does not take keypress commands
 * from the player.
 */
class HomeBase : public ArenaMobileEntity {
 public:
  /**
   * @brief Constructor.
   *
   * @param params A home_base_params passed down from main.cc for the
   * initialization of the HomeBase.
   */
  explicit HomeBase(const struct home_base_params *const params);

  /**
   * @brief Reset the HomeBase using the initialization parameters received
   * by the constructor.
   */
  void Reset() override;

  /**
   * @brief Update the HomeBase's position and velocity after the specified
   * duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(uint dt) override;

  /**
   * @brief Getter method for the HomeBase's heading angle.
   *
   * @return The current heading angle of the HomeBase.
   */
  double heading_angle() const override {
    return motion_handler_.heading_angle();
  }

  /**
   * @brief Setter method for the HomeBase's heading angle.
   *
   * @param ha The new heading angle of the HomeBase.
   */
  void heading_angle(double ha) override { motion_handler_.heading_angle(ha); }

  /**
   * @brief Getter method for the HomeBase's speed.
   *
   * @return The current speed of the HomeBase.
   */
  double get_speed() const override { return motion_handler_.speed(); }

  /**
   * @brief Setter method for the HomeBase's speed.
   *
   * @param speed The new speed of the HomeBase.
   */
  void set_speed(double speed) override { motion_handler_.speed(speed); }

  /**
   * @brief Accept a EventCollision and update the HomeBase appropriately.
   *
   * @param e The collision event.
   */
  void Accept(const EventCollision *const e) override;

  /**
   * @brief Get the name of the HomeBase for visualization purposes, and to
   * aid in debugging.
   *
   * @return Name of the HomeBase.
   */
  std::string get_name() const override { return "Home Base"; }

  /**
   * @brief Duplicate getter method for the HomeBase's speed. Added to pass
   * unit tests.
   *
   * @return The current speed of the HomeBase.
   *
   * @todo remove at iteration 2, only keep get_speed
   */
  double speed() const override { return motion_handler_.speed(); }

  /**
   * @brief Duplicate setter method for the HomeBase's speed. Added to pass
   * unit tests.
   *
   * @param sp The new speed of the HomeBase.
   *
   * @todo remove at iteration 2, only keep set_speed
   */
  void speed(double sp) override { motion_handler_.speed(sp); }

 private:
  Position initial_pos_;  // initial position of the Robot, used by Reset()
  RobotMotionHandler motion_handler_;
  RobotMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_HOME_BASE_H_
