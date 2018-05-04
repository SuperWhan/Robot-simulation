/**
 * @file sensor_touch.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/entity_type_sensor.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
EntityTypeSensor::EntityTypeSensor() :
    Sensor(),
    entity_type_(kNull),
    detect_range_(200.0) {  // int to double
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void EntityTypeSensor::Accept(const EventEntityType *const e) {
  // Determine if the sensor is activated or deactivated.
if (e->in_range()) {
  activated(true);
    switch (e->get_object()) {
      case kWall: entity_type_ = kWall;
      case kRobot: entity_type_ = kRobot;
      case kPlayer: entity_type_ = kPlayer;
      case kHomeBase: entity_type_ = kHomeBase;
      case kRechargeStation: entity_type_ = kRechargeStation;
      case kSuperBot: entity_type_ = kSuperBot;
      case kNull: entity_type_ = kNull;
    }
  } else {
    activated(false);
  }
}
void EntityTypeSensor::Reset() {
  activated(false);
} /* reset() */

NAMESPACE_END(csci3081);
