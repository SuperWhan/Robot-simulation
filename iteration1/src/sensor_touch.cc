/**
 * @file sensor_touch.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorTouch::SensorTouch() :
    Sensor(),
    point_of_contact_(0, 0),
    angle_of_contact_(0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorTouch::Accept(const EventCollision *const e) {
  // Determine if the sensor is activated or deactivated.
  if (e->collided()) {
    activated(true);
    point_of_contact_ = e->point_of_contact();
    angle_of_contact_ = e->angle_of_contact();
  } else {
    activated(false);
  }
}

void SensorTouch::Reset() {
  activated(false);
} /* reset() */

NAMESPACE_END(csci3081);
