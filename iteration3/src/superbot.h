/**
 * @file super_bot.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
#ifndef PROJECT_ITERATION3_SRC_SUPERBOT_H_
#define PROJECT_ITERATION3_SRC_SUPERBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/superbot_params.h"
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
 * HomeBase is the goal of the game. Once the superbot of the superbot has touched
 * the HomeBase, the superbot has won and the Arena is reset.
 *
 * HomeBase have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 * HomeBase differs from superbot mainly in that 1) it does not have a battery
 * (so it can keep moving forever) AND 2) it does not take keypress commands
 * from the superbot.
 */
class SuperBot : public ArenaMobileEntity {
 public:
  /**
   * @brief Constructor.
   *
   * @param params A home_base_params passed down from main.cc for the
   * initialization of the HomeBase.
   */
  explicit SuperBot(const struct super_bot_params *const params);

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
  double get_heading_angle() const override {
    return motion_handler_.get_heading_angle();
  }

  /**
   * @brief Setter method for the HomeBase's heading angle.
   *
   * @param ha The new heading angle of the HomeBase.
   */
  void set_heading_angle(double ha) override {
                                      motion_handler_.set_heading_angle(ha); }

  /**
   * @brief Getter method for the HomeBase's speed.
   *
   * @return The current speed of the HomeBase.
   */
  double get_speed() const override { return motion_handler_.get_speed(); }

  /**
   * @brief Setter method for the HomeBase's speed.
   *
   * @param speed The new speed of the HomeBase.
   */
  void set_speed(double speed) override { motion_handler_.set_speed(speed); }

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
  std::string get_name() const override { return "SuperBot"; }


 private:
  Position initial_pos_;  // initial position of the superbot, used by Reset()
  RobotMotionHandler motion_handler_;
  RobotMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION3_SRC_SUPERBOT_H_
