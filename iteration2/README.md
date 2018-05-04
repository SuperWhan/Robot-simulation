# CSCI3081: Robot Simulator

The robot simulator consists of 2 primary components: the _graphics\_area\_viewer_ and _arena_. Robots and other similar entities live in the arena and are quite oblivious to being viewed by the viewer. The viewer is in control of everything in that it sends a message to the arena to update, meaning move the arena entities the appropriate amount given how much time has passed since the last update. It then gets the appropriate positional information from each entity and draws these to the screen. All the while, the system is listening for keyboard and mouse activity by the user. If any action occurs, the associated callback is executed.

<hr>
#### EDITS:

- Arrow keys handles with OnSpecialKeyDown not OnKeyDown.

<hr>

Iteration 1 Requirements are in a separate document. This is a general overview
of the framework.

An overview of classes is provided in _ProjectClassOverview.md_

<hr>

## Mechanics of the System

### Resources

- libsimple_graphics : https://github.umn.edu/umn-csci-3081F17/libSimpleGraphics/
- nanogui : https://github.com/wjakob/nanogui
- nanogui documentation: https://nanogui.readthedocs.io/en/latest/
- nanovg : https://github.com/memononen/NanoVG
- Google Style Guide : https://google.github.io/styleguide/cppguide.html
- cpplint : https://github.com/google/styleguide/tree/gh-pages/cpplint
- doxygen : http://www.stack.nl/~dimitri/doxygen/
- Google Test : https://github.com/google/googletest

### libSimpleGraphics and /project/f17c3081

The arena viewer is a subclass of GraphicsApp, which can be found in the libSimpleGraphics repo. When building the simulator, the local object files are linked with libSimpleGraphics located at `/project/f17c3081`, which is publicly accessible on all cselabs machines. If you want to compile on your own platform, you will have to create a similar directory and change the makefile to reflect your local drive (i.e. edit the CS3081DIR variable in src/Makefile to point to the directory where libSimpleGraphics has been installed.)

> **Do not submit to your repo any of the code from libSimpleGraphics. Also, do not submit a makefile in which you are linking to your personal local directory - it must refer to the cselabs directory.**

### Directory Structure

Makefile:
- make all and make clean for the whole project (calls make recursively in subdirs).
- good place for students to add a Doxygen rule for make doc later on in the course.

src/:
- the main source code where you will find robot_viewer.h/cc and robot_land.h/cc

src/Makefile:
- builds the project source, assumes it should build all .cc and .cpp files in the current directory
- **creates an executable in build/bin/exename**
- uses auto dependency generation to get dependencies from #includes

tests/:
- directory for all unit tests

tests/Makefile:
- builds an Google Test executabe in build/bin/unittest
- (re)compiles all of the .cc and .cpp files in src/ (EXECPT FOR main.cc AND/OR main.cpp) to be part of this exe so that functionality from any of them can be called within the tests.
- also compiles all of the .cc and .ccp files in tests/
- links with the Google Test framework, set the path to the Google Test install using the GTEST_DIR Makefile variable

tests/student-tests1.cc:
- a file for students to fill in
- they can rename this or add to it or do whatever they want
- really, the only reason to include this file is to encourage them to create their own tests somewhere, since we actively discourage them from editing the next file

tests/feedback-tests-iter1.cc:
- a file for the CS3081W staff.
- when the project goes out, this file should contain the series of feedback tests that will run automatically via the github webhooks auto grader.
- this is important to setup correctly -- see more detail below on best practices

build/:
- created by the Makefiles

build/bin:
- **all exes generated for the project go in here**

build/obj:
- all .o's and .d's (from make depend) go in here
- they are intentionally put in subdirs for src/ and tests/ to keep the .o's separate for each exe
- to keep it simple, the tests exe actually recompiles everything in src/ even if it has already been built as part of compiling the exe inside src

<hr>

## Getting Started

1. _pull_ the class repo.
2. cp the project to your personal repo
3. If you are working from your local machine, modify the `CS3081DIR` variable in `src/Makefile` so that it points to your local installation of libSimpleGraphics. Ignore this step if working on a CSE labs machine.
4. At the top level from the OS command prompt: `make`
5. Navigate to `build/bin`
6. At command prompt: `./arenaviewer`

If you have trouble compiling, it might be that your account is behind on the gcc version. At the prompt, type `gcc --version` and if it says 4.x, you need to load gcc: `module load /soft/gcc/7.1`. Check your ~/.bashrc file.
If you see a load for gcc, remove this. Then when you login, gcc 5.x will be the default.

There are more directions in libSimpleGraphics about getting things configured for
your personal platform. Systems is working on a potential solution for remote access through vole.

<hr>

## Code explanation

### class GraphicsApp

The GraphicsApp makes use of the nanogui, nanovg, and openGL libraries to create a window with 2D graphics and a GUI. As with most graphics applications, there is a main loop in which keyboard and mouse events are handled, then all objects in the graphics window are drawn. The loop is executed at the frame rate until the application is closed. The actual loop is hidden inside the library code, but it behaves something like this:

```C++
while (Active(window)) {  // ie user has not clicked 'x' to close the window
  handleKeyMouseEvents();
  clearScreen()   // start with a fresh screen/buffer
  drawContents();
  swapBuffers(window);    // double-buffered system
}
```

This loop is initiated by a call to nanogui::mainloop(), which you can find in GraphicsApp::Run().

```C++
void GraphicsApp::Run() {
  glfwSetTime(0.0);
  nanogui::mainloop();
}
```

Once that mainloop() is initiated, at the frame rate, GraphicsApp::draw() will be called. Notice the **two very important function calls `UpdateSimulation()` and `DrawUsingNanoVG()`**.

```C++
void GraphicsApp::draw(NVGcontext *ctx) {

  double now = glfwGetTime();
  UpdateSimulation(now - last_draw_time_);
  last_draw_time_ = now;

  // Draw the user interface using the nanogui library, which is built upon nanovg
  Screen::draw(ctx);

  // Draw other vector graphics using the nanovg library
  DrawUsingNanoVG(ctx);
}
```

### class GraphicsArenaViewer in graphics_arena_viewer.h / .cc

RobotViewer is a subclass of GraphicsApp. In this application, it is instantiated in main() with the name _app_. Notice in the constructor of RobotViewer, you see the instantiation of robot land. The simulator gets started with a call to app->Run(), which calls nanogui::mainloop():

```C++
int main(int argc, char **argv) {

  csci3081::InitGraphics();

  csci3081::GraphicsArenaViewer \*app = new csci3081::GraphicsArenaViewer();
  app->Run();

  csci3081::ShutdownGraphics();
  return 0;
}
```

Recall that in the draw() function of the GraphicsApp, there is a call to UpdateSimulation() and DrawUsingNanoVG(). **Look at these function definitions in _graphics\_arena\_viewer.cc._** All that is happening in Update is a call to the arena to update based on how much time has passed. In the draw function, each entity is being drawn. Notice that the graphics commands for drawing each of the objects begins with `nvg` for nanovg. The header file `https://github.com/memononen/nanovg/blob/master/src/nanovg.h` is pretty well documented. Take a moment to look at this header file and read about some of the function calls that you see in drawing the various graphics objects (e.g. DrawRobot, DrawObstacle).

(The keyboard and mouse event processing is discussed below.)

### The Classes

Arena has no awareness of the viewer, despite the fact that it was instantiated inside of the viewer. You can think about robots in the arena constantly moving around (even though they move in discrete steps), but periodically the  viewer takes a snapshot of the situation and displays it on the screen. The viewer interacts with the arena through getters, which get information from each robot and each obstacle that is relevant to drawing them in the graphics window. It also sends commands from the user to control the robot.

Currently, the arena has a stationary obstacle, home base, recharging station, and a mobile robot.
All of these entities are subclasses of either ArenaMobileEntity or ArenaImmobileEntity, which in turn is
a subclass of ArenaEntity. The robot contains a battery, touch sensor, a motion handler for setting velocity, and motion behavior for calculating a new position at each update. These are all instantiations of distinct
classes. There are parameter structures for the various entities for initialization. Finally, there
are different types of event classes, including collision, keypress, recharge, and command. While not
a true implementation of the Visitor pattern, these events are accepted by the arena or entities
in the arena. All event classes are subclasses of the EventBaseClass.


### Keyboard and Mouse Event Handling

Events are handled inside the viewer, because this manages all aspects of the GUI. Look in graphics\_area\_viewer.cc to see the various events to be handled (e.g. OnKeyDown(), which handles the down arrow key). The name gives an indication of which event it is responding to. When that event occurs, this is the function that is called. You never see the call to this function, but know that it does happen. Currently, for the most part, events are handled by printing messages to a terminal, but they really come in handy when you want the user to interact with the graphics window. For example, you might want the functionality that wherever the user clicks the mouse, a robot is created at that position.

The menu you see in the application with a reset and pause button was a custom menu made for this application. If you downloaded the nanogui examples, you saw how complex these menus can be. It is quite easy to add buttons with various functionality to the menu. Let's trace that process through the code ...

It starts in the viewer constructor:

```C++
nanogui::FormHelper *gui = new nanogui::FormHelper(this);

nanogui::ref<nanogui::Window> window =
    gui->addWindow(Eigen::Vector2i(10, 10), "Simulation Controls");
pause_btn_ =
    gui->addButton("Pause", std::bind(&RobotViewer::OnPauseBtnPressed, this));
gui->addButton("Restart", std::bind(&RobotViewer::OnRestartBtnPressed, this));
```

You start with the instantiation of FormHelper, then add the various components.
The parameters being passed to the `addButton` are the name that appears on the
button and the _callback_ function, meaning the one that is called when the button
is pressed (which is registered via a mouse click). Again, all of this is going
on behind the scenes and you will not see an explicit call to the callback function.

> Notice the special form of the comments. They are following doxygen formatting,
which when compiled for doxygen, generates the documentation in the form of a
pdf or web pages.
