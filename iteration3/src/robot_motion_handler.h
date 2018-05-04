/**
 * @file robot_motion_handler.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_ROBOT_MOTION_HANDLER_H_
#define PROJECT_ITERATION3_SRC_ROBOT_MOTION_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_commands.h"
#include "src/robot_params.h"
#include "src/arena_mobile_entity.h"
#include "src/motion_handler.h"
#include "src/sensor_touch.h"
#include "src/distress_call_sensor.h"

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
class RobotMotionHandler : public MotionHandler{
 public:
  /**
   * @brief Default constructor.
   */
  RobotMotionHandler();

  /**
   * @brief Reset the actuators to their newly constructed/un-commanded state.
   *
   * Currently does nothing.
   */
  void Reset() override;

  void AcceptCommand(enum event_commands cmd);


  /**
  * @brief Update the heading angle according to the sensor
  * readings.
  *
  * Currently does not change speed.
  *
  * @param st A SensorTouch to be read.
  */
  void UpdateHeading(SensorTouch st);

  void UpdateHeading(DistressCallSensor dcs);
  //
  // /**
  //  * @brief Duplicate getter method for speed. Added to pass unit tests.
  //  *
  //  * @return The current speed.
  //  *
  //  * @todo remove at iteration 2, only keep get_speed
  //  */
  // double speed() const { return speed_; }
  //
  // /**
  //  * @brief Duplicate setter method for speed. Added to pass unit tests.
  //  *
  //  * @return The new speed.
  //  *
  //  * @todo remove at iteration 2, only keep set_speed
  //  */
  // void speed(double sp) { speed_ = sp; }
  //
  // /**
  //  * @brief Getter method for speed.
  //  *
  //  * @return The current speed.
  //  */
  double get_speed() const { return speed_; }

  /**
   * @brief Setter method for speed.
   *
   * @param sp The new speed.
   */
  void set_speed(double sp) { speed_ = sp; }

  /**
   * @brief Getter method for heading angle.
   *
   * @return The current heading angle.
   */
  double get_heading_angle() const { return heading_angle_; }

  /**
   * @brief Setter method for heading angle.
   *
   * @param ha The new heading angle.
   */
  void set_heading_angle(double ha) { heading_angle_ = ha; }

  /**
   * @brief Getter method for the maximum speed.
   *
   * @return The current maximum speed.
   */

  double get_speed_delta() const { return speed_delta_; }

  /**
   * @brief Setter method for the speed delta.
   *
   * @param sd The new speed delta.
   */
  void set_speed_delta(double sd) { speed_delta_ = sd; }

  /**
   * @brief Getter method for the angle delta.
   *
   * @return The current angle delta.
   */
  double get_angle_delta() const { return angle_delta_; }

  /**
   * @brief Setter method for the angle delta.
   *
   * @param ad The new angle delta.
   */
  void set_angle_delta(double ad) { angle_delta_ = ad; }

 private:
  double heading_angle_;
  double speed_;
  double speed_delta_;
  double angle_delta_;
};

NAMESPACE_END(csci3081);

#endif   // PROJECT_ITERATION3_SRC_ROBOT_MOTION_HANDLER_H_
