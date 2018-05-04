/**
 * @file event_distress.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_distress_call.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
 /*******************************************************************************
  * Constructor
  ******************************************************************************/

  EventDistressCall::EventDistressCall() :
        heading_(0),
        point_in_range_(0, 0),
        in_range_(false) {
  }
  void EventDistressCall::EmitMessage() const {
    printf("Object received, coming to get you\n");
  }
  NAMESPACE_END(csci3081);
