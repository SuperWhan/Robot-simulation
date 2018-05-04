/**
 * @file initializ.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_INITIALIZE_H_
#define PROJECT_ITERATION3_SRC_INITIALIZE_H_

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * initializing main
 ******************************************************************************/
#define BATTERY_MAX_CHARGE 100
#define ANGLE_DELTA 10
#define SPEED_DELTA 1
#define MAX_SPEED 10
#define COLLISION_DELTA 1
#define P_RADIUS 20.0
#define P_POS csci3081::Position(500.0, 500.0);
#define P_COLOR csci3081::Color(0, 0, 255, 255); /* blue */

#define N_OBSTACLES 5
#define N_ROBOTS 5

#define OBSTACLE_COLOR csci3081::Color(255, 255, 255, 255);

#define RECHARGE_STATION_RADIUS 20.0
#define RECHARGE_STATION_POS {500, 300};
#define RECHARGE_STATION_COLOR csci3081::Color(0, 128, 128, 255);

#define HOME_BASE_RADIUS 20.0
#define HOME_BASE_COLLISION_DELTA 1
#define HOME_BASE_POS {400, 400};
#define HOME_BASE_COLOR csci3081::Color(255, 0, 0, 255); /* red */

#define ROBOT_RADIUS 20.0
#define ROBOT_COLLISION_DELTA 1
#define ROBOT_COLOR csci3081::Color(100, 100, 100, 100) /* red */

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION3_SRC_INITIALIZE_H_
