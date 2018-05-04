/**
 * @file event_command.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_COMMAND_H_
#define SRC_EVENT_COMMAND_H_

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
 * @brief An event representing a keypress command from the user that should be
 * sent to the robot.
 */
class EventCommand : public EventBaseClass {
 public:
  /**
   * @brief Constructor.
   *
   * @param cmd The command extracted from a EventKeypress.
   */
  explicit EventCommand(enum event_commands cmd) : cmd_(cmd) {}

  /**
   * @brief Each event, upon its firing/processing, should emit a message to
   * the user on `stdout` saying what happened, in order to
   * aid debugging.
   *
   * Reports the command received.
   */
  void EmitMessage() const override {
    printf("Motion cmd %d received\n",
           cmd_);
  }

  /**
   * @brief Getter method for the underlying command.
   *
   * @return The keypress command.
   */
  enum event_commands cmd() const { return cmd_; }

 private:
  enum event_commands cmd_;
};

NAMESPACE_END(csci3081);

#endif /* SRC_EVENT_COMMAND_H_ */
