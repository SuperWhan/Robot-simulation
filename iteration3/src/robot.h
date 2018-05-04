/**
 * @file robot.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_ROBOT_H_
#define PROJECT_ITERATION3_SRC_ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/robot_motion_handler.h"
#include "src/robot_motion_behavior.h"
#include "src/sensor_touch.h"
#include "src/robot_params.h"
#include "src/arena_mobile_entity.h"
#include "src/distress_call_sensor.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a mobile robot within the arena.
 *
 * Robots have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 * Robots can take command from the player through keypress. They also have
 * batteries that will get depleted as they move or collide with other
 * entities.
 */
class Robot : public ArenaMobileEntity {
 public:
  /**
   * @brief Constructor.
   *
   * @param params A robot_params passed down from main.cc for the
   * initialization of the Robot.
   */
  explicit Robot(const struct robot_params *const params);

  /**
   * @brief Reset the Robot's battery to full after an encounter with the
   * RechargeStation.
   */
  // void ResetBattery();
  //
  // /**
  //  * @brief Reset the Robot to a newly constructed state (needed for reset
  //  * button to work in GUI).
  //  */
  void Reset() override;

  /**
   * @brief Update the Robot's position and velocity after the specified
   * duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override;

  /**
   * @brief Accept a recharge event.
   *
   * This causes the robot's battery to become fully charged.
   *
   * @param e The recharge event.
   */
  // void Accept(__unused const EventRecharge *const e);

  /**
   * @brief Pass along a collision event (from Arena) to the touch sensor.
   *
   * This method provides a framework in which sensors can get different types
   * of information from different sources. The Robot's heading will be updated
   * to move it away from the incident angle at the point of contact.
   *
   * @param e The collision event.
   */
  void Accept(const EventCollision *const e) override;

  void Accept(const EventDistressCall *const e);

  /**
   * @brief Handle user input commands to change the Robot's heading or speed.
   *
   * @param e The command to process.
   */
  // void Accept(const EventCommand *const e);

  /**
   * @brief Getter method for the Robot's heading angle.
   *
   * @return The current heading angle of the Robot.
   */
  double get_heading_angle() const override {
    return motion_handler_.get_heading_angle();
  }

  /**
   * @brief Setter method for the Robot's heading angle.
   *
   * @param ha The new heading angle of the Robot.
   */
  void set_heading_angle(double ha) override {
                                      motion_handler_.set_heading_angle(ha); }

  /**
   * @brief Getter method for the Robot's speed.
   *
   * @return The current speed of the Robot.
   */
  double get_speed() const override { return motion_handler_.get_speed(); }

  /**
   * @brief Setter method for the Robot's speed.
   *
   * @param sp The new speed of the Robot.
   */
  void set_speed(double sp) override { motion_handler_.set_speed(sp); }

  /**
   * @brief check method for checking if this robot is superbot or not.
   *
   */
  bool get_super(void) { return super_bot_;}

  /**
   * @brief set method for making the robot to superbot.
   *
   */
  void set_super(bool b) { super_bot_ = b;}

  /**
   * @brief Get the name of the Robot for visualization purposes, and to
   * aid in debugging.
   *
   * @return Name of the Robot.
   */
  std::string get_name() const override {
    if (super_bot_ == true) {
      return "SUPER" + std::to_string(id_);
    } else {
      return "Robot" + std::to_string(id_);
    }
  }

 private:
  int id_;
  bool super_bot_;
  static unsigned int next_id_;
  RobotMotionHandler motion_handler_;
  RobotMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
  Position initial_pos_;  // initial position of the Robot, used by Reset()
  // DistressCallSensor distress_sensor_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION3_SRC_ROBOT_H_
