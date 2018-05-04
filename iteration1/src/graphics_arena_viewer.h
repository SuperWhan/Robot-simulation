/**
 * @file graphics_arena_viewer.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_GRAPHICS_ARENA_VIEWER_H_
#define SRC_GRAPHICS_ARENA_VIEWER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <simple_graphics/graphics_app.h>
#include "src/arena.h"
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 *  @brief An application that uses the libSimpleGraphics library to open up
 *  a window that includes a few buttons for controlling the simulation and can
 *  be used to draw circles and other computer graphics.
 *
 *  After constructing a new GraphicsArenaViewer, call Run to start and run the
 *  application. Run will not return until the application window is closed.
 *  Make sure that you call cs3081::InitGraphics before creating the
 *  GraphicsArenaViewer app.  Example:
 *
 *  ```
 *  int main(int argc, char **argv) {
 *      cs3081::InitGraphics();
 *      RobotViewer *app = new RobotViewer();
 *      app->Run();
 *      cs3081::ShutdownGraphics();
 *      return 0;
 *  }
 *  ```
 *
 *  While the window is open UpdateSimulation will be called repeatedly,
 *  once per frame. Fill this in to update your simulation or perform any other
 *  processing that should happen over time as the simulation progresses.
 *
 *  Fill in the `On*()` methods as desired to respond to user input events.
 *
 *  Fill in the `Draw*()` methods to draw graphics on the screen using
 *  either the `nanovg` library or raw `OpenGL`.
 */
class GraphicsArenaViewer : public GraphicsApp {
 public:
  /**
   * @brief Constructor.
   *
   * @param params A arena_params passed down from main.cc for the
   * initialization of the Arena and the entities therein.
   */
  explicit GraphicsArenaViewer(const struct arena_params *const params);

  /**
   * @brief Destructor.
   *
   * `delete` the contained Arena.
   */
  ~GraphicsArenaViewer() override { delete arena_; }

  /**
   * @brief Informs the Arena of the new time, so that it can update.
   *
   * @param dt The new timestep.
   */
  void UpdateSimulation(double dt) override;

  /**
   * @brief Handle the user pressing the restart button on the GUI.
   *
   * This will reset the Arena, which will in turn reset its entities.
   */
  void OnRestartBtnPressed();

  /**
   * @brief Handle the user pressing the pause button on the GUI.
   *
   * This will freeze the graphics--no update, until the pause button is
   * pressed again.
   */
  void OnPauseBtnPressed();

  /**
   * @brief Called each time the mouse moves on the screen within the GUI
   * window.
   *
   * Origin is at the lower left of the window.
   *
   * @param[in] x X position of the cursor.
   * @param[in] y Y position of the cursor.
   */
  void OnMouseMove(__unused int x, __unused int y) override;

  /**
   * @brief Called each time the left mouse button is clicked.
   *
   * Origin is at the lower left of the window.
   *
   * @param[in] x The X position of the click.
   * @param[in] y The Y position of the click.
   */
  void OnLeftMouseDown(__unused int x, __unused int y) override;

  /**
   * @brief Called each time the left mouse button is released.
   *
   * Origin is at the lower left of the window.
   *
   * @param[in] x The X position of the release.
   * @param[in] y The Y position of the release.
   */
  void OnLeftMouseUp(__unused int x, __unused int y) override;

  /**
   * @brief Called each time the right mouse button is clicked.
   *
   * Origin is at the lower left of the window.
   *
   * @param[in] x The X position of the click.
   * @param[in] y The Y position of the click.
   */

  void OnRightMouseDown(__unused int x, __unused int y) override;

  /**
   * @brief Called each time the right mouse button is released.
   *
   * Origin is at the lower left of the window.
   *
   * @param[in] x The X position of the release.
   * @param[in] y The Y position of the release.
   */
  void OnRightMouseUp(__unused int x, __unused int y) override;

  /**
   * @brief Called each time a character key is pressed.
   *
   * @param[in] c Character representing a key that was pressed.
   * @param[in] modifiers Any modifier keys that were also pressed.
   */
  void OnKeyDown(__unused const char *c, __unused int modifiers) override;

  /**
   * @brief Called each time a character key is released.
   *
   * @param[in] c Character representing a key that was released.
   * @param[in] modifiers Any modifier keys that were held with the key.
   */
  void OnKeyUp(__unused const char *c, __unused int modifiers) override;

  /**
   * @brief Called each time a special (non-alphabetic) key is pressed.
   *
   * @param[in] key The key that was pressed.
   * @param[in] scancode The scancode corresponding to the key.
   * @param[in] modifiers Any modifier keys that were also pressed.
   */
  void OnSpecialKeyDown(int key,
                        __unused int scancode,
                        __unused int modifiers) override;

  /**
   * @brief Called each time a special (non-alphabetic) key is released.
   *
   * @param[in] key The key that was released.
   * @param[in] scancode The scancode corresponding to the key.
   * @param[in] modifiers Any modifier keys that were also pressed.
   */
  void OnSpecialKeyUp(__unused int key,
                      __unused int scancode,
                      __unused int modifiers) override;

  /**
   * @brief Draw the Arena with all of its entities using `nanogui`.
   *
   * This is the primary driver for drawing all entities in the Arena. It is
   * called at each iteration of `nanogui::mainloop()`.
   *
   * @param[in] ctx Context for nanogui.
   */
  void DrawUsingNanoVG(NVGcontext *ctx) override;

  /**
   * @brief Draw using `OpenGL`. This method is unimplemented, as currently
   * we are doing all drawing with `nanovg` in this application, so it is empty.
   */
  void DrawUsingOpenGL() override {}

  /**
   * @brief Getter method for the contained Arena.
   *
   * @return The underlying Arena.
   */
  Arena *arena() const { return arena_; }

 private:
  /**
   * @brief Draw a robot using `nanogui`.
   *
   * This function requires an active `nanovg` drawing context (`ctx`), so it
   * should probably only be called from with DrawUsingNanoVG.
   *
   * @param[in] ctx The `nanovg` context.
   * @param[in] robot The Robot handle.
   */
  void DrawRobot(NVGcontext *ctx, const class Robot *const robot);

  /**
   * @brief Draw an Obstacle in the Arena using `nanogui`.
   *
   * This function requires an active `nanovg` drawing context (`ctx`), so it
   * should probably only be called from with DrawUsingNanoVG.
   *
   * @param[in] ctx The `nanovg` context.
   * @param[in] obstacle The Obstacle handle.
   */
  void DrawObstacle(NVGcontext *ctx, const class Obstacle *const obstacle);

  /**
   * @brief Draw the HomeBase using `nanogui`.
   *
   * This function requires an active `nanovg` drawing context (`ctx`), so it
   * should probably only be called from with DrawUsingNanoVG.
   *
   * @param[in] ctx The `nanovg` context.
   * @param[in] home The HomeBase handle.
   */
  void DrawHomeBase(NVGcontext *ctx, const class HomeBase *const home);

  /**
   * Under certain circumstance, the compiler requires that the assignment
   * operator is not defined. This `deletes` the default assignment operator.
   */
  GraphicsArenaViewer &operator=(const GraphicsArenaViewer &other) = delete;

  /**
   * Under certain circumstance, the compiler requires that the copy
   * constructor is not defined. This `deletes` the default copy constructor.
   */
  GraphicsArenaViewer(const GraphicsArenaViewer &other) = delete;

  Arena *arena_;
  bool paused_;
  nanogui::Button *pause_btn_;
  double last_dt;

  // text fields showing game/simulation stats
  nanogui::IntBox<int> *win_;
  nanogui::IntBox<int> *lose_;
  nanogui::IntBox<int> *robot_pos_x_;
  nanogui::IntBox<int> *robot_pos_y_;
  nanogui::IntBox<int> *robot_speed_;
  nanogui::IntBox<int> *robot_angle_;
  nanogui::IntBox<int> *robot_battery_text_;
  nanogui::IntBox<int> *home_pos_x_;
  nanogui::IntBox<int> *home_pos_y_;
  nanogui::IntBox<int> *home_speed_;
  nanogui::IntBox<int> *home_angle_;
  nanogui::ProgressBar *robot_battery_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_GRAPHICS_ARENA_VIEWER_H_
