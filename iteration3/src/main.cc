/**
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/graphics_arena_viewer.h"
#include "src/arena_params.h"
#include "src/initialize.h"

/*******************************************************************************
 * Constants
 ******************************************************************************/
static const uint X_DIM_ = 1024;
static const uint Y_DIM_ = 768;
static const int MIN_OBSTACLE_RADIUS_ = 10;
static const int MAX_OBSTACLE_RADIUS_ = 50;

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main(int, char **) {
  // Essential call to initiate the graphics window
  csci3081::InitGraphics();

  csci3081::player_params pparams;

  pparams.battery_max_charge = BATTERY_MAX_CHARGE;
  pparams.angle_delta = ANGLE_DELTA;
  pparams.speed_delta = SPEED_DELTA;
  pparams.max_speed = MAX_SPEED;
  pparams.collision_delta = COLLISION_DELTA;
  pparams.radius = P_RADIUS;
  pparams.pos = P_POS;
  pparams.color = P_COLOR; /* blue */


  csci3081::arena_params aparams;

  aparams.n_obstacles = N_OBSTACLES;
  aparams.n_robots = N_ROBOTS;
  aparams.x_dim = X_DIM_;
  aparams.y_dim = Y_DIM_;

  // aparams.robot = rparams;
  aparams.player = pparams;


  aparams.recharge_station.radius = RECHARGE_STATION_RADIUS;
  aparams.recharge_station.pos = RECHARGE_STATION_POS;
  aparams.recharge_station.color =
      RECHARGE_STATION_COLOR; /* green */

  aparams.home_base.radius = HOME_BASE_RADIUS;
  aparams.home_base.collision_delta = HOME_BASE_COLLISION_DELTA;
  aparams.home_base.pos = HOME_BASE_POS;
  aparams.home_base.color = HOME_BASE_COLOR; /* red */

  // aparams.super_bot.radius = HOME_BASE_RADIUS;
  // aparams.super_bot.collision_delta = HOME_BASE_COLLISION_DELTA;
  // aparams.super_bot.pos = {312, 312};
  // aparams.super_bot.color = HOME_BASE_COLOR;

  for (uint i = 0; i < aparams.n_obstacles; i++) {
    // initialize obstacles' radii randomly
    //
    // +1 because random_num uses uniform_real_distribution(),
    // which generates random numbers on the interval [a,b)
    aparams.obstacles[i].radius =
        random_num(MIN_OBSTACLE_RADIUS_, MAX_OBSTACLE_RADIUS_ + 1);

    // initialize obstacles' positions randomly is tricky
    aparams.obstacles[i].pos = {
        aparams.obstacles[i].radius + aparams.x_dim/aparams.n_obstacles * i,
        aparams.obstacles[i].radius + aparams.y_dim/aparams.n_obstacles * i
    };

    aparams.obstacles[i].color =
        OBSTACLE_COLOR; /* white */
  }

  for (uint i = 0; i < aparams.n_robots; i++) {
    aparams.robots[i].radius = ROBOT_RADIUS;
    aparams.robots[i].collision_delta = ROBOT_COLLISION_DELTA;
    aparams.robots[i].pos = {150.0 + i*100.0, 105.0 + i*18.0};
    aparams.robots[i].color = ROBOT_COLOR;
  }

  // Start up the graphics (which creates the arena).
  // Run() will enter the nanogui::mainloop().
  auto *app = new csci3081::GraphicsArenaViewer(&aparams);
  app->Run();
  csci3081::ShutdownGraphics();
  return 0;
}
