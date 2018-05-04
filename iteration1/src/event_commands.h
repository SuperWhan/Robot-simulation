/**
 * @file event_commands.h
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 */

#ifndef SRC_EVENT_COMMANDS_H_
#define SRC_EVENT_COMMANDS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * @brief The commands that the Robot supports: speed up, slow down, turn left a
 * little bit, turn right a little bit. Doesn't get much simpler than that!
 */
enum event_commands {
  COM_TURN_LEFT,
  COM_TURN_RIGHT,
  COM_SPEED_UP,
  COM_SLOW_DOWN,
  COM_UNKNOWN
};
NAMESPACE_END(csci3081);

#endif /* SRC_EVENT_COMMANDS_H_ */
