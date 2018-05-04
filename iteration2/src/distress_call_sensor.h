/**
 * @file distress_call_sensor.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_DISTRESS_CALL_SENSOR_H_
#define PROJECT_ITERATION2_SRC_DISTRESS_CALL_SENSOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>
#include <string>

#include "src/common.h"
#include "src/event_distress_call.h"
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
 * @brief Class representing a distress call sensor.
 *
 */
class DistressCallSensor : public Sensor {
 public:
  /**
   * @brief Default constructor.
   */
  DistressCallSensor();

  /**
   * @brief Getter method for the point of contact.
   *
   * Should only be called when the sensor is activated.
   *
   * @return The latest point of contact.
   */

  std::string get_name() {
    std::string result_str = "Distress Call Sensor.";
    return result_str;
  }

  void Accept(const EventDistressCall *const e);

  void set_detect_range(double dr) { detect_range_ = dr;}

  double get_detect_range(void) {return detect_range_;}

  Position get_position(void) {return point_in_range_;}

  double heading(void) {return heading_;}

  void heading(double hd) {heading_ = hd;}

  void set_position(Position p) {point_in_range_ = p;}

  /**
   * @brief Reset the distress_call sensor--deactivate it.
   */
  void Reset() override;

 private:
  double detect_range_;
  Position point_in_range_;
  double heading_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_DISTRESS_CALL_SENSOR_H_
