/**
 * @file contact_sensor.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/contact_sensor.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
ContactSensor::ContactSensor() :
    Sensor(),
    contact_(false),
    point_of_contact_(0, 0),
    angle_of_contact_(0.0) {  // int to double
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void ContactSensor::Accept(const EventCollision *const e) {
  // Determine if the sensor is activated or deactivated.
  if (e->collided()) {
    activated(true);
    contact(true);
    point_of_contact_ = e->point_of_contact();
    angle_of_contact_ = e->angle_of_contact();
  } else {
    activated(false);
  }
}

void ContactSensor::Reset() {
  activated(false);
} /* reset() */

NAMESPACE_END(csci3081);
