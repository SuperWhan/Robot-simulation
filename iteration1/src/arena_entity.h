/**
 * @file arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_ENTITY_H_
#define SRC_ARENA_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include <string>
#include "src/common.h"
#include "src/color.h"
#include "src/position.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A base class representing an entity within the Arena. All entities
 * within the Arena know how to:
 *
 * 1. Update themselves at each timestep (i.e. in accordance with current
 * velocity and position).
 *
 * 2. Reset themselves to a newly constructed state. So that the user can
 * click the reset button to restart the game. Alternatively, the game
 * will be reset if the player has won/lost.
 *
 * Please note that here use the upper-left coordinate, which means that the
 * origin point (0.0,0.0) is at the upper left.
 *
 * Also, all arena entities are circular.
 *
 * As this is a base class, most of its methods are `virtual`.
 */
class ArenaEntity {
 public:
  /**
   * @brief ArenaEntity's constructor.
   *
   * @param radius The radius of the entity (as it is circular).
   * @param pos The initial position of the entity.
   * @param color The color of the entity as shown on the screen.
   */
  ArenaEntity(double radius, const Position &pos,
              const Color &color) :
      radius_(radius), pos_(pos), color_(color) {}
  /**
   * ArenaEntity's destructor. `default` implementation.
   */
  virtual ~ArenaEntity() = default;

  /**
   * @brief Perform whatever updates needed for a particular entity after 1
   * timestep (updating position, changing color, etc.).
   *
   * @param dt # of timesteps elapsed after the last update. Unused. Internally
   * things work as if `dt` is always 1.
   */
  virtual void TimestepUpdate(__unused uint dt) {}

  /**
   * @brief Reset the entity to its newly constructed state.
   */
  virtual void Reset() {}

  /**
   * @brief Get the name of an entity for visualization purposes, and to aid in
   * debugging.
   *
   * @return Name of the entity.
   */
  virtual std::string get_name() const = 0;

  /**
   * @brief Getter method for an entity's position.
   *
   * @return The entity's current position.
   */
  const Position &get_pos() const { return pos_; }

  /**
   * @brief Setter method for an entity's position.
   *
   * @param pos The entity's new position.
   */
  void set_pos(const Position &pos) { pos_ = pos; }

  /**
   * @brief Getter method for an entity's color.
   *
   * @return The entity's current color.
   */
  const Color &get_color() const { return color_; }

  /**
   * @brief Setter method for an entity's color.
   *
   * @param color The entity's new color.
   */
  void set_color(const Color &color) { color_ = color; }

  /**
   * @brief Getter method for an entity's radius.
   *
   * @return The entity's radius.
   */
  double radius() const { return radius_; }

 private:
  double radius_;
  Position pos_;
  Color color_;
};

NAMESPACE_END(csci3081);

#endif /* SRC_ARENA_ENTITY_H_ */
