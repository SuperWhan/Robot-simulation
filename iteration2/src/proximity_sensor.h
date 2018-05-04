/**
 * @file proximity_sensor.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_PROXIMITY_SENSOR_H_
#define PROJECT_ITERATION2_SRC_PROXIMITY_SENSOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>
#include <cmath>
#include <string>

#include "src/common.h"
#include "src/event_proximity.h"
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
 * @brief Class representing a proximity sensor.
 *
 */
class ProximitySensor : public Sensor {
 public:
  /**
   * @brief Default constructor.
   */
  ProximitySensor();

  /**ctivated.
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
    std::string result_str = "Proximity Sensor.";
    return result_str;
  }
  void Accept(const EventProximity *const e);

  void set_fov(double fv) {field_of_view_ = fv;}

  double get_fov(void) {return field_of_view_;}

  double get_range_left(void) {return left_range_;}

  double get_range_right(void) {return right_range_;}

  double get_detect_range(void) {return detect_range_;}

  void set_detect_range(double dr) {detect_range_ = dr;}

  double heading_angle(void) {return heading_angle_;}

  void set_heading_angle(double ha) {heading_angle_ = ha;}

  double radius(void) {return radius_;}

  void set_radius(double rs) {radius_ = rs;}

  void set_range(double l, double r) {
      left_range_ = l;
      right_range_ = r;
    }

  double get_distance(Position p1, Position p2) {
    double distancex = (p1.x() - p2.x())*(p1.x() - p2.x());
    double distancey = (p1.y() - p2.y())*(p1.y() - p2.y());
    distance_ = sqrt(distancex + distancey);
    return distance_;
  }

  Position get_sensing_position(void) {return ing_p;}

  void set_sensing_position(Position ingpos) {ing_p = ingpos;}

  Position get_sensed_position(void) {return ed_p;}

  void set_sensed_position(Position edpos) {ed_p = edpos;}

  double sensor_reading(const EventProximity *const e);

  /**
   * @brief Reset the proximity_sensor--deactivate it.
   */
  void Reset() override;

 private:
  Position point_of_contact_;
  double radius_;
  double heading_angle_;
  double left_range_;
  double right_range_;
  double field_of_view_;  // using for avoiding collison
  double detect_range_;  // using for detecting (return the distance)
  Position ing_p;
  Position ed_p;
  double distance_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_PROXIMITY_SENSOR_H_
