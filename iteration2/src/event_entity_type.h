/**
 * @file event_entity_type.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_EVENT_ENTITY_TYPE_H_
#define PROJECT_ITERATION2_SRC_EVENT_ENTITY_TYPE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cstdio>
#include "src/event_base_class.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An event representing that when entity_type sensor was activated.
 *
 * They are sent from the graphics framework to GraphicsArenaViewer,
 * where they are interpreted further.
 */
class EventEntityType : public EventBaseClass {
 public:
   /**
    * @brief Default constructor.
    */
  EventEntityType();
  /**
   * @brief Each event, upon its firing/processing, should emit a message to
   * the user on `stdout` saying what happened, in order to
   * aid debugging.
   *
   */
  void EmitMessage() const override;

  bool in_range(void) const {return in_range_; }

  void in_range(bool bb) { in_range_ = bb;}

  enum EntityType get_object (void) const {return obj_type_;}



 private:
  bool in_range_;
  enum EntityType obj_type_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_EVENT_ENTITY_TYPE_H_
