/**
 * @file position.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_POSITION_H_
#define PROJECT_ITERATION2_SRC_POSITION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A simple representation of the position of an entity within the Arena.
 *
 * NOTE: Origin (0,0) is at the upper left corner of the Arena.
 *
 * @todo Add Position to the csci3081 namespace.
 */
struct Position {
 public:
  /**
   * @brief Default constructor. Initialize the position to (0,0)
   */
  Position() : x_(0.0), y_(0.0) {}  // int->double

  /**
   * @brief Constructor
   *
   * @param in_x The X component of the Position.
   * @param in_y The Y component of the Position.
   */
  Position(double in_x, double in_y) : x_(in_x), y_(in_y) {}

  bool operator==(const csci3081::Position &coord) const {
    if (this->x_ == coord.x_ && this->y_ == coord.y_) {
      return true;
    } else {
      return false;
    }
  }



  /**
   * @brief Getter method for the X component.
   *
   * @return The X component of the Position.
   */
  double x() const { return x_; }

  /**
   * @brief Getter method for the Y component.
   *
   * @return The Y component of the Position.
   */
  double y() const { return y_; }

  /**
   * @brief Setter method for the X component.
   *
   * @return The new X component of the Position.
   */
  void x(double x) { x_ = x; }

  /**
   * @brief Setter method for the Y component.
   *
   * @return The new Y component of the Position.
   */
  void y(double y) { y_ = y; }

  /**
   * @brief Default assignment operator. Simply copies the (x,y) values of
   * another Position.
   *
   * @param other The Position object to copy from.
   *
   * @return The left-hand-side Position object that is now identical (in value)
   * to `other`.
   */
  Position &operator=(const Position &other) = default;


 private:
  double x_;
  double y_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_POSITION_H_
