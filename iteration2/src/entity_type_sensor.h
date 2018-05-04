/**
 * @file entity_type_sensor.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_ENTITY_TYPE_SENSOR_H_
#define PROJECT_ITERATION2_SRC_ENTITY_TYPE_SENSOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>
#include <string>

#include "src/common.h"
#include "src/entity_type.h"
#include "src/event_entity_type.h"
#include "src/sensor.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief Class representing a EntityType sensor.
 *
 */
class EntityTypeSensor : public Sensor {
 public:
  /**
   * @brief Default constructor.
   */
  EntityTypeSensor();


  std::string get_name() {
    std::string result_str = "Entity Type Sensor.";
    return result_str;
  }


  enum EntityType get_Entity_Type(void) {return entity_type_;}

  void set_detect_range(double dr) {detect_range_ = dr;}

  double get_detect_range(void) {return detect_range_;}

  void Accept(const EventEntityType *const e);

  void Accept(EntityType e) {entity_type_ = e;}


  /**
   * @brief Reset the touch sensor--deactivate it.
   */
  void Reset() override;

 private:
  enum EntityType entity_type_;
  double detect_range_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_ENTITY_TYPE_SENSOR_H_
