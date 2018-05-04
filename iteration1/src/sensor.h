/**
 * @file sensor.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_H_
#define SRC_SENSOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_base_class.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief Base class for sensors. Should be inherited by classes like
 * SensorTouch.
 */
class Sensor {
 public:
  /**
   * @brief Constructor. Creates a deactivated sensor.
   */
  Sensor() : activated_(false) {}

  /**
   * @brief Default destructor.
   */
  virtual ~Sensor() = default;

  /**
   * @brief Getter method for sensor status.
   *
   * @return `true` if sensor is activated. `false` if sensor is deactivated.
   */
  bool activated() const { return activated_; }

  /**
   * @brief Setter method for sensor status.
   *
   * @param value The new sensor activation status.
   */
  void activated(bool value) { activated_ = value; }

  /**
   * @brief Reset the sensor to its newly constructed state.
   */
  virtual void Reset() = 0;

 private:
  bool activated_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_H_
