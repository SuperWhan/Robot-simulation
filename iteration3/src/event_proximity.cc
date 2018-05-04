/**
 * @file event_proximity.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_proximity.h"
#include <cmath>


/*******************************************************************************
 * Namespaces
 ******************************************************************************/

NAMESPACE_BEGIN(csci3081);

 /*******************************************************************************
  * Constructor
  ******************************************************************************/

  EventProximity::EventProximity() :
        in_range_(false) {
  }



  void EventProximity::EmitMessage() const {
    printf("Object received! how far are you!\n");
  }
  NAMESPACE_END(csci3081);
