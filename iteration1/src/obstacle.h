/**
 * @file obstacle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_OBSTACLE_H_
#define SRC_OBSTACLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/arena_immobile_entity.h"
#include "src/position.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing an immobile obstacle within the Arena.
 *
 * Since obstacles are immobile, the Obstacle class is very simple.
 */
class Obstacle : public ArenaImmobileEntity {
 public:
  /**
   * @brief Constructor.
   *
   * @param radius The radius of the Obstacle.
   * @param pos The permanent position of the Obstacle.
   * @param color The color of the Obstacle.
   */
  Obstacle(double radius, const Position &pos,
           const Color &color);

  /**
   * @brief Get the name of the Obstacle for visualization purposes, and to
   * aid in debugging.
   *
   * @return Name of the Obstacle.
   */
  std::string get_name() const override {
    return "Obstacle" + std::to_string(id_);
  }

 private:
  static uint next_id_;

  int id_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_OBSTACLE_H_
