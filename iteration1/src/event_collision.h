/**
 * @file event_collision.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_COLLISION_H_
#define SRC_EVENT_COLLISION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cstdlib>
#include "src/event_base_class.h"
#include "src/position.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A collision event class, which is used after a ArenaMobileEntity
 * gets within a specified distance of another entity in the Arena.
 */
class EventCollision : public EventBaseClass {
 public:
  /**
   * @brief Default constructor.
   */
  EventCollision();

  /**
   * @brief Each event, upon its firing/processing, should emit a message to
   * the user on `stdout` saying what happened, in order to
   * aid debugging.
   *
   * Reports the point of contact (on the perimeter of the ArenaMobileEntity)
   * and the angle of contact (relative to the ArenaMobileEntity).
   */
  void EmitMessage() const override;

  /**
   * @brief Getter method for collision status.
   *
   * @return `true` when this instance represents an active collision
   * event. `false` when it represents a previous collision event that has
   * been resolved.
   */
  bool collided() const { return collided_; }

  /**
   * @brief Setter method for collision status.
   *
   * @param c The new collision status.
   */
  void collided(bool c) { collided_ = c; }

  /**
   * @brief Getter method for the point of contact.
   *
   * @return The point in the Arena at which the entities have collided/touched.
   */
  Position point_of_contact() const { return point_of_contact_; }

  /**
   * @brief Setter method for the point of contact.
   *
   * @param p The point in the Arena at which the entities have collided.
   *
   * Should only be used by the class handling collision detection (that is,
   * Arena).
   */
  void point_of_contact(Position p) { point_of_contact_ = p; }

  /**
   * @brief Getter method for the angle of contact.
   *
   * @return The angle, in degrees, as specified on the unit circle, that the
   * collision occurred at. Needed to calculate the bounce angle.
   */
  double angle_of_contact() const { return angle_of_contact_; }

  /**
   * @brief Setter method for the angle of contact.
   *
   * @param aoc The angle, in degrees, as specified on the unit circle, that the
   * collision occurred at. Needed to calculate the bounce angle.
   *
   * Should only be used by the class handling collision detection (that is,
   * Arena).
   */
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

 private:
  bool collided_;
  Position point_of_contact_;
  double angle_of_contact_;
};

NAMESPACE_END(csci3081);

#endif /* SRC_EVENT_COLLISION_H_ */
