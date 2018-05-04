/**
 * @file color.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_COLOR_H_
#define PROJECT_ITERATION2_SRC_COLOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/common.h>
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/
/**
 * @brief Struct representing a color.
 *
 * Internally uses RGBA values to represent the color.
 */
struct Color {
  /**
   * @brief Default constructor.
   *
   * Initialize RGBA all to 0.
   */
  Color() : r(0), g(0), b(0), a(0) {}

  /**
   * @brief Constructor for Color.
   *
   * @param r_in The R component of the color.
   * @param g_in The G component of the color.
   * @param b_in The B component of the color.
   * @param a_in The A component of the color.
   */
  Color(unsigned char r_in,
        unsigned char g_in,
        unsigned char b_in,
        unsigned char a_in) : r(r_in), g(g_in), b(b_in), a(a_in) {}

  /**
   * @brief Convert this Color to nanogui::Color.
   *
   * @return The equivalent nanogui::Color.
   */
  nanogui::Color toNanoColor() {
    return {r, g, b, a};
  }

  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_COLOR_H_
