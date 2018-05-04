/**
 * @file event_recharge.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_RECHARGE_H_
#define SRC_EVENT_RECHARGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cstdio>
#include "src/event_base_class.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An event representing an encounter (really a collision) that a Robot
 * has with a RechargeStation.
 */
class EventRecharge : public EventBaseClass {
 public:
  /**
   * @brief Default constructor.
   */
  EventRecharge() = default;

  /**
   * @brief Each event, upon its firing/processing, should emit a message to
   * the user on `stdout` saying what happened, in order to
   * aid debugging.
   *
   * Simply reports that the Robot's battery is recharged.
   */
  void EmitMessage() const override { printf("Robot Battery recharged!\n"); }
};

NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_RECHARGE_H_
