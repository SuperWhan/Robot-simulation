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

  // Initialize default properties for various arena entities
  csci3081::robot_params rparams;

  rparams.battery_max_charge = 100.0;
  rparams.angle_delta = 10.0;  // int->double
  rparams.speed_delta = 1;
  rparams.max_speed = 10;
  rparams.collision_delta = 1.0;  // int->double
  rparams.radius = 20.0;
  rparams.pos = csci3081::Position(500, 500);
  rparams.color = csci3081::Color(0, 0, 255, 255); /* blue */

  csci3081::arena_params aparams;

  aparams.n_obstacles = 5;
  aparams.x_dim = X_DIM_;
  aparams.y_dim = Y_DIM_;

  aparams.robot = rparams;

  aparams.recharge_station.radius = 20.0;
  aparams.recharge_station.pos = {500, 300};
  aparams.recharge_station.color =
      csci3081::Color(0, 128, 128, 255); /* green */

  aparams.home_base.radius = 20.0;
  aparams.home_base.collision_delta = 1;
  aparams.home_base.pos = {400, 400};
  aparams.home_base.color = csci3081::Color(255, 0, 0, 255); /* red */

  for (uint i = 0; i < aparams.n_obstacles; i++) {
    // initialize obstacles' radii randomly
    //
    // +1 because random_num uses uniform_real_distribution(),
    // which generates random numbers on the interval [a,b)
    aparams.obstacles[i].radius =
        random_num(MIN_OBSTACLE_RADIUS_, MAX_OBSTACLE_RADIUS_ + 1);

    // initialize obstacles' positions randomly is tricky
    //
    // aparams.obstacles[i].pos =
    //     {random_num(0 + aparams.obstacles[i].radius,
    //                 aparams.x_dim - aparams.obstacles[i].radius),
    //      random_num(0 + aparams.obstacles[i].radius,
    //                 aparams.y_dim - aparams.obstacles[i].radius)};
    aparams.obstacles[i].pos = {
        aparams.obstacles[i].radius + aparams.x_dim/aparams.n_obstacles * i,
        aparams.obstacles[i].radius + aparams.y_dim/aparams.n_obstacles * i
    };

    aparams.obstacles[i].color =
        csci3081::Color(255, 255, 255, 255); /* white */
  }

  // Start up the graphics (which creates the arena).
  // Run() will enter the nanogui::mainloop().
  auto *app = new csci3081::GraphicsArenaViewer(&aparams);
  app->Run();
  csci3081::ShutdownGraphics();
  return 0;
}
