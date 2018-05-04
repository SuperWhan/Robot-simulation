/**
 * @file distress_call_sensor.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/distress_call_sensor.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
DistressCallSensor::DistressCallSensor() :
    Sensor(),
    point_in_range_(0, 0),
    heading_(0),
    detect_range_(200.0) {  // int to double
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void DistressCallSensor::Accept(const EventDistressCall *const e) {
  // Determine if the sensor is activated or deactivated.
    if (e->in_range()) {
      activated(true);
      heading_ = this ->heading();
  } else {
    activated(false);
  }
}

void DistressCallSensor::Reset() {
  activated(false);
} /* reset() */

NAMESPACE_END(csci3081);
