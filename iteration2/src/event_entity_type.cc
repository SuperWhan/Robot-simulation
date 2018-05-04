/**
 * @file event_entity_type.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_entity_type.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/

NAMESPACE_BEGIN(csci3081);

 /*******************************************************************************
  * Constructor
  ******************************************************************************/

  EventEntityType::EventEntityType() :
        obj_type_(kNull),
        in_range_(false) {
  }
  void EventEntityType::EmitMessage() const {
    printf("Object received! who are you!\n");
  }
  NAMESPACE_END(csci3081);
