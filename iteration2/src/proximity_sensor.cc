/**
 * @file proximity_sensor.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/proximity_sensor.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
ProximitySensor::ProximitySensor() :
    Sensor(),
    point_of_contact_(0, 0),
    radius_(0.0),
    heading_angle_(0.0),
    left_range_(0.0),
    right_range_(0.0),
    field_of_view_(0.0),
    detect_range_(0.0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void ProximitySensor::Accept(const EventProximity *const e) {
  // Determine if the sensor is activated or deactivated.
  if (e->in_range()) {
    activated(true);
    Position p1 = get_sensed_position();
    Position p2 = get_sensing_position();
    get_distance(p1, p2);
  } else {
    activated(false);
  }
}

double ProximitySensor::sensor_reading(const EventProximity *const e) {
  // Determine if the sensor is activated or deactivated.
  if (!e->in_range()) {
    return -1;
  }
}

void ProximitySensor::Reset() {
  activated(false);
} /* reset() */

NAMESPACE_END(csci3081);
