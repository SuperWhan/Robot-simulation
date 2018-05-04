/**
 * @file event_keypress.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_EVENT_KEYPRESS_H_
#define PROJECT_ITERATION2_SRC_EVENT_KEYPRESS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cstdio>
#include "src/event_base_class.h"
#include "src/event_commands.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An event representing that a key on the keyboard has been
 * pressed.
 *
 * They are sent from the graphics framework to GraphicsArenaViewer,
 * where they are interpreted further.
 */
class EventKeypress : public EventBaseClass {
 public:
  /**
   * @brief Constructor.
   *
   * @param key The key pressed. Value mappings can be found at
   * http://www.glfw.org/docs/latest/group__keys.html.
   */
  explicit EventKeypress(int key) : key_(key) {}

  /**
   * @brief Each event, upon its firing/processing, should emit a message to
   * the user on `stdout` saying what happened, in order to
   * aid debugging.
   *
   * Simply says that a key is pressed.
   */
  void EmitMessage() const override { printf("Keypress command received\n"); }

  /**
   * @brief Getter method for the underlying command, which is
   * generated from the pressed key.
   *
   * Again, mappings found at http://www.glfw.org/docs/latest/group__keys
   * .html are used.
   */
  enum event_commands GetCmd() const { return keypress_to_cmd(key_); }

 private:
  /**
   * @brief Convert `GLFW` key values to event_commands values.
   *
   * @param key A `GLFW` key value.
   *
   * @return The corresponding event_commands value.
   */
  enum event_commands keypress_to_cmd(int key) const;

  int key_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_EVENT_KEYPRESS_H_
