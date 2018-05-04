/**
 * @file home_base_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_HOME_BASE_PARAMS_H_
#define PROJECT_ITERATION3_SRC_HOME_BASE_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @brief Inherits from arena_mobile_entity_params to set various
 * properties of the HomeBase.
 *
 * Currently, it is the same as arena_mobile_entity_params.
 */
struct home_base_params : public arena_mobile_entity_params {
  home_base_params() : arena_mobile_entity_params() {}
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION3_SRC_HOME_BASE_PARAMS_H_
