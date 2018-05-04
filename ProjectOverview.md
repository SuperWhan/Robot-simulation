## main.cc

```C++
int main(int argc, \*\*char argv) {

  csci3081::InitGraphics();
  // Initialization of many parameter structs

  csci3081::ArenaViewer \*app = new csci3081::ArenaViewer(&aparams);
  app->Run();

  csci3081::ShutdownGraphics();
  return 0;
}

```

## Arena Viewer ( GraphicsApp )

Associated Files
- graphics\_arena\_viewer.cc
- graphics\_arena\_viewer.h

This creates the graphics window and the GUI. It is controlling the timing of the screen update, performing the drawing, watching for key and mouse events, and it is the keeper of the arena.

Primary member is `Arena * arena_`.

`UpdateSimulation` sends a message to the arena `arena_->advanceTime(1)`. It has methods to draw a robot, obstacle, and the homebase. It holds all the `On<key/mouse>Event()` methods. It also contains a boolean `paused_` (which is associated with the button member which is `nanogui::Button *pause_btn_`.)

## Arena

Associated Files
- arena_params.h
- arena.cc
- arena.h

Class contains all the entities within the arena:
- Robot * robot_
- Recharge_station * recharge\_station_
- HomeBase * home\_base\_
- vector< Obstacles * > obstacles_

All entities are stored in `vector< ArenaEntity * > entities_`

Constructor creates all these entities.

Call to `AdvanceTime(dt)` makes things happen. This sends message to each
entity to update time by 1 for each `dt` with `UpdateEntitiesTimeStep()`, which in turn
for each entity calls `entity->TimeStepUpdate(1)`.
After all entities updated for the 1 time step, checks for events:
- robot at charging station
- robot at home base- collisions with obstacles
- collisions with walls

<hr>

## Entities in the Arena

### Base Classes

- arena\_entity.h  `class ArenaEntity`.
- arena\_immobile\_entity.h   `class ImmobileArenaEntity : ArenaEntity`
- arena\_mobile\_entity.h  class  `MobileArenaEntity : ArenaEntity`
     - arena\_mobile\_entity.cc
     - arena\_mobile\_entity\_params.h : struct used for initializing entity

Entities generally have:
- color, position, size
- if mobile, heading and velocity too
- is_mobile() return True or False
- reset()
- TimeStepUpdate


### Home Base

Associated Files
- home_base.cc
- home_base.h
- home_base_params.h : struct for initializing

```
class Homebase : public MobileArenaEntity
```

This is the target that the robot needs to get to to win. The intent is to
have this moving, and better yet, have it randomly change directions at
unpredictable times to make the game harder.

### Charging Station

Associated Files
- recharge\_station.h

```
class ChargingStation : public ImmobileArenaEntity
```

This is a stationary entity that has the ability to recharge the robot battery.
The robot need only collide with it to get a full charge to its battery.


### Circular Entities (i.e. Obstacles)

Associated Files
- obstacle\_params.h
- obstacle.cc
- obstacle.h

```
class CircularObstacle : public ImmobileArenaEntity
```

Circular stationary objects that get in the way of the robot.

### Robot

This is the primary entity in the arena. It is composed of many of the classes
in the project.

- robot.cc
- robot.h

<hr>

## Robot Members

### Motion Handler for ArenaMobileEntity

Associated Files
- robot\_motion\_handler.cc
- robot\_motion\_handler.h

This manages the setting of velocity for the robot (or for any mobile arena
entity). Velocity (i.e. heading and speed) are initialized at the start, but
will change when either the user inputs a command or the robot collides with
something, which will change the direction of the robot.

### Motion Behavior for ArenaMobileEntity

Associated Files
- robot\_motion\_behavior.cc
- robot\_motion\_behavior.h

This is the crucial update method for mobile arena objects. It uses the velocity of
each mobile entity to calculate a new x,y position using the setter for "this".
In iteration 1, the 2 wheels will always have equal velocity, thus the robot will always move in a straight line in the direction of its heading angle.

```C++
void Robot::TimestepUpdate(uint dt) {
  motion_handler_.UpdateVelocity(sensor_touch_);
  motion_behavior_.UpdatePosition(this, dt);
} /* TimestepUpdate() */
```

#### Battery

The battery is depleted as the robot moves, with extra depletion when running into things. It is recharged at the charging station. Robot has a member `RobotBattery battery_`.

Associated Files
- robot\_battery.cc
- robot\_battery.h

```
class RobotBattery
```

Crucial methods are `event\_recharge()` and `deplete()`.


#### Touch Sensor

Touch sensors activate or signal when touched or bumped. Any time the robot
collides with something (as determined by the Arena), an event is sent to the
sensor to set its activation. Conversely, when collision is no longer detected,
an event is sent to the sensor to deactivate it.

- sensor\_touch.cc
- sensor\_touch.h
