/**
 * @file sensor_touch.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_TOUCH_H_
#define SRC_SENSOR_TOUCH_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "src/common.h"
#include "src/event_collision.h"
#include "src/sensor.h"
#include "src/position.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief Class representing a touch sensor.
 *
 * Touch or "bump" sensors are "active" when pressed. For our purposes, imagine
 * a series of bump sensors around the perimeter of the Robot. A collision will
 * activate the sensor at a particular point of contact, which translates to an
 * angle of contact.
 */
class SensorTouch : public Sensor {
 public:
  /**
   * @brief Default constructor.
   */
  SensorTouch();

  /**
   * @brief Getter method for the point of contact.
   *
   * Should only be called when the sensor is activated.
   *
   * @return The latest point of contact.
   */
  Position point_of_contact() { return point_of_contact_; }

  /**
   * @brief Setter method for the point of contact.
   *
   * @param p The new point of contact.
   */
  void point_of_contact(Position p) {
    point_of_contact_ = p;
  }

  /**
   * @brief Getter method for the angle of contact.
   *
   * Should only be called when the sensor is activated.
   *
   * @return The latest angle of contact.
   */
  double angle_of_contact() { return angle_of_contact_; }

  /**
   * @brief Setter method for the angle of contact.
   *
   * @param aoc The new angle of contact.
   */
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

  /**
   * @brief Compute a new reading based on a collision event.
   *
   * Note that collision events can report "no collision" which
   * will deactivate the sensor.
   */
  void Accept(const EventCollision *const e);

  /**
   * @brief Reset the touch sensor--deactivate it.
   */
  void Reset() override;

 private:
  Position point_of_contact_;
  double angle_of_contact_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_TOUCH_H_
