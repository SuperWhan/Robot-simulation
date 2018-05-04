/**
 * @file event_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_EVENT_PROXIMITY_H_
#define PROJECT_ITERATION2_SRC_EVENT_PROXIMITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cstdio>
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
 * @brief An event representing that when proximity sensor was activated.
 *
 * They are sent from the graphics framework to GraphicsArenaViewer,
 * where they are interpreted further.
 */
class EventProximity : public EventBaseClass {
 public:
   /**
    * @brief Default constructor.
    */
  EventProximity();
  /**
   * @brief Each event, upon its firing/processing, should emit a message to
   * the user on `stdout` saying what happened, in order to
   * aid debugging.
   *
   */
  void EmitMessage() const override;

  bool in_range(void) const {return in_range_; }



 private:
  bool in_range_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_EVENT_PROXIMITY_H_
