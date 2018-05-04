/**
 * @file contact_sensor.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_CONTACT_SENSOR_H_
#define PROJECT_ITERATION3_SRC_CONTACT_SENSOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>
#include <string>

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
 * @brief Class representing a Contact sensor.
 *
 */
class ContactSensor : public Sensor {
 public:
  /**
   * @brief Default constructor.
   */
  ContactSensor();

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

  std::string get_name() {
    std::string result_str = "Contact Sensor.";
    return result_str;
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
   * @brief Reset the Contact sensor--deactivate it.
   */
  void Reset() override;

  bool contact() {return contact_;}
  void contact(bool a) {contact_ = a;}

 private:
  bool contact_;
  Position point_of_contact_;
  double angle_of_contact_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION3_SRC_CONTACT_SENSOR_H_
