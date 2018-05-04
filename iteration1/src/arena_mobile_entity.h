/**
 * @file arena_mobile_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_MOBILE_ENTITY_H_
#define SRC_ARENA_MOBILE_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include "src/arena_entity.h"
#include "src/event_base_class.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A mobile entity in the Arena, capable of updating its own position
 * and/or velocity when asked by the simulation.
 *
 * All mobile entities must have a heading angle so that their orientation can
 * be properly drawn by the GraphicsArenaViewer.
 *
 * Since this is also a base class, many of its methods are intuitively
 * `virtual`.
 */
class ArenaMobileEntity : public ArenaEntity {
 public:
  /**
   * @brief ArenaMobileEntity's constructor.
   *
   * @param radius The radius of the entity (as it is circular).
   * @param collision_delta The collision delta of the entity. Used in
   * Arena::UpdateEntitiesTimestep and Arena::CheckForEntityCollision for
   * collision detection.
   * @param pos The initial position of the entity.
   * @param color The color of the entity as shown on the screen.
   */
  ArenaMobileEntity(double radius, double collision_delta,
                    const Position &pos, const Color &color) :
      ArenaEntity(radius, pos, color),
      collision_delta_(collision_delta) {}

  /**
   * @brief Getter method for the entity's heading angle.
   *
   * @return The current heading angle of the entity.
   */
  virtual double heading_angle() const = 0;

  /**
   * @brief Setter method for the entity's heading angle.
   *
   * @param heading_angle The new heading angle of the entity.
   */
  virtual void heading_angle(double heading_angle) = 0;

  /**
   * @brief Getter method for the entity's speed.
   *
   * @return The current speed of the entity.
   */
  virtual double get_speed() const = 0;

  /**
   * @brief Setter method for the entity's speed.
   *
   * @param sp The new speed of the entity.
   */
  virtual void set_speed(double sp) = 0;

  /**
   * @brief Accept a EventCollision and update the entity's state appropriately.
   *
   * @param e The collision event.
   */
  virtual void Accept(const EventCollision *const e) = 0;

  /**
   * @brief Getter method for the entity's collision delta.
   *
   * @return The minimum distance between 2 Arena entities before collision
   * occurs.
   */
  double collision_delta() const { return collision_delta_; }

  /**
   * @brief Duplicate getter method for the entity's speed. Added to pass
   * unit tests.
   *
   * @return The current speed of the entity.
   *
   * @todo remove at iteration 2, only keep get_speed
   */
  virtual double speed() const = 0;

  /**
   * @brief Duplicate setter method for the entity's speed. Added to pass
   * unit tests.
   *
   * @param sp The new speed of the entity.
   *
   * @todo remove at iteration 2, only keep set_speed
   */
  virtual void speed(double sp) = 0;

 private:
  double collision_delta_;
};

NAMESPACE_END(csci3081);

#endif /* SRC_ARENA_MOBILE_ENTITY_H_ */
