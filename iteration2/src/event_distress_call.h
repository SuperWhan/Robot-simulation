/**
 * @file event_distress.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_EVENT_DISTRESS_CALL_H_
#define PROJECT_ITERATION2_SRC_EVENT_DISTRESS_CALL_H_

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
 * @brief An event representing that a distress call sensor has been activated.
 *
 * They are sent from the graphics framework to GraphicsArenaViewer,
 * where they are interpreted further.
 */
class EventDistressCall : public EventBaseClass {
 public:
   /**
    * @brief Default constructor.
    */
  EventDistressCall();
  /**
   * @brief Each event, upon its firing/processing, should emit a message to
   * the user on `stdout` saying what happened, in order to
   * aid debugging.
   *
   */
  void EmitMessage() const override;

  int in_range() const {return in_range_; }

  void in_range(int bb) { in_range_ = bb;}

  Position get_position(void) {return point_in_range_;}

  void set_position(Position p) {point_in_range_ = p;}

  void heading(double hd) {heading_ = hd;}

  double heading(void) {return heading_;}


 private:
  int in_range_;
  double heading_;
  Position point_in_range_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_EVENT_DISTRESS_CALL_H_
