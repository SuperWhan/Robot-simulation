## Description of tests

Resources:
- https://github.com/google/googletest/blob/master/googletest/docs/Primer.md#beware-of-the-nomenclature
- https://github.com/google/googletest


## Where to Begin?

Start with the initialization of your class (unless it is purely virtual, in which case you cannot create an instance of the class). Try all the different forms of the constructor and use getters to check values. Then you can test all your setters. After that, move on to the primary methods within the class.

The first section below discusses test set-up in general. The next section starts to outline specific tests for specific functionality organized.

<hr>

## Test Setup Generally

There are 2 types of checks: assert and expect, the former is fatal (it will stop all following tests). For each, you can perform relational tests (e.g. ==, <, >, ...) and string comparison tests. See documentation.

Here is an example of an empty test from tests directory. We will approach in this way, but look below, because we might want to set it up as test suites.

```C++
TEST(FeedbackTests, SimpleRobotMovement) {
  RobotLand rl;
  double initx, inity;
  rl.get_robot_pos(0, &initx, &inity);

  rl.advance_time(0.5);

  double nextx, nexty;
  rl.get_robot_pos(0, &nextx, &nexty);

  EXPECT_NE(initx, nextx);
  EXPECT_NE(inity, nexty);
}
```

From documentation:
>TEST() arguments go from general to specific. The first argument is the name of the test case, and the second argument is the test's name within the test case. Both names must be valid C++ identifiers, and they should not contain underscore (\_). A test's full name consists of its containing test case and its individual name. Tests from different test cases can have the same individual name.

Notice there is the set-up, then there is the testing condition. In this example,
it is simply testing that the robot has moved. This is a test that is calling robot through robotLand, therefore it is a robotLand unit test, but not a robot unit test.

A robot unit test might set the speed and heading of the robot and check for a specific value for the robot to move to. The robot declared independent of the robotLand - which makes sense because it is a robot test that can move with the code regardless of how the robot class is used.

**__To do test suites, looks like this__** (as discussed in documentation):

```C++
class QueueTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    q1_.Enqueue(1);
    q2_.Enqueue(2);
    q2_.Enqueue(3);
  }
  // virtual void TearDown() {}
public:
  Queue<int> q0_;
  Queue<int> q1_;
};
```

In which we define both setup and teardown (if relevant) for the collection of tests. The individual tests become methods of that test class (or maybe subclass ??), like this:

```C++
TEST_F(QueueTest, IsEmptyInitially) {
  EXPECT_EQ(0, q0_.size());
}

TEST_F(QueueTest, DequeueWorks) {
  int* n = q0_.Dequeue();
  EXPECT_EQ(NULL, n);

  n = q1_.Dequeue();
  ASSERT_TRUE(n != NULL);
  EXPECT_EQ(1, *n);
  EXPECT_EQ(0, q1_.size());
  delete n;
}
```

_Will add some documentation here on how this is used. In general, test frameworks
create a main() with all the tests and generate output that uses the names to
report the results of each test._

<hr>

## Specific Tests

We need a set of tests for the various classes that have been created. John distributed the workload on this. Below, I have outlined the type of tests I would like to see for each class. I might not think of everything or might be thinking about things incorrectly, so please use your judgement or ask me if things seem incomplete or incorrect. The tests are organized by the priorities of code development as outlined in the requirements - so far, I only have priority level 1. 

### Priority Level 1

- Implement the arrow keypress handlers.
- Translate the keypress into appropriate command for the robot arena and send the command to the arena, which will send the command to robot_motion_handler_.
  - Up arrow increases speed, up to a defined limit
  - Down arrow decreases speed, down to 0 (no negative speeds)
  - Right arrow changes the heading clockwise by some delta of your choosing
  - Left arrow changes the heading counter-clockwise by some defined delta
- Bounce robot off of other entities (at angle of incidence).
- Deplete battery as robot moves.
- Recharge battery if robot collides with recharge station.
- Home base is mobile.

<hr>

#### KeyPresses Up, Down, Left, and Right

This involves the graphics application and user input, therefore you cannot
create a traditional unit test for OnSpecialKeyDown, except by calling it
directly with some key value. It just passes the keypress event to the arena, so we can start there with our unit tests.

Relevant Classes
- Arena
- Robot
- MotionHandler
- EventKeypress
- EventCommand

Relevant Methods
- Arena::Accept(EventKeypress e)
- Robot::Accept(EventCommand e)
- MotionHandler::Accept(EventCommand e)

Functionality
- Test Up increases the speed, but not beyond a threshold.
- Test Down decreases the speed, but not beyond 0.
- Test Right changes the heading clockwise (I think this is a positive change??)
- Test Left changes the heading counter-clockwise (I think negative change??)

The up/down/right/left events get converted to commands and passed to Robot, which passes the command to MotionHandler.

**Arena** - call Accept with an EventKeypress, then getters of Arena for robot speed or heading, as appropriate.

**Robot** - call Accept with an EventCommand, then getters of motionhandler to test values of speed or heading, as appropriate.

**MotionHandler** - call Accept with an EventCommand, then getters to test values of speed or heading, as appropriate.

<hr>

#### Collision Detection - all forms!

Relevant Classes:
- Arena
- Robot
- Obstacles
- RechargeStation
- Homebase
- EventCollision

Relevant Methods:
- Arena::CheckForEntityCollision
- Arena::CheckForEntityOutOfBounds

Functionality:
- Position robot at each of the 4 walls (in the center).
- Position robot at each corner (touching 2 walls at a time).
- Position robot next to obstacle, homebase, rechargestation, at a contact point in each of the 4 quadrants.
- Check data in collision event.

**Arena** - call CheckForEntityCollision with various objects listed above in various configurations. Use getters of EventCollision to see if populated correctly.

**Arena** - call CheckforEntityOutOfBounds at each wall. Use getters of EventCollision to see if populated correctly.

<hr>

#### Bounce Robot off of obstacles (walls are different)

Relevant Classes:
- Robot
- EventCollision
- MotionHandler

Relevant Methods:
- Robot::Accept(EventCollision)
- MotionHandler::Accept(EventCollision)

Functionality:
- Bumps at a contact point in each of the 4 quadrants
- Bumps at a contact point at the crossovers (0,90,180,270,360)
- Heading should change relative to angle of incidence

A collision event detected in Arena sends collision event to Robot, which passes it along to MotionHandler.

**Robot** - call Accept(EventColision) with various values as indicated above. Call getters of Robot to check if heading change is appropriate.

**MotionHandler** - call Accept(EventCollision) with various values as indicated above. Call getters of MotionHandler to check if heading change is appropriate.

<hr>

#### Deplete Battery (based on movement)

When robot moves, the battery should be depleted based on the speed and distance it travelled. It is left up to the user to determine how much, therefore we can only check for change. Battery should not go below 0.

Relevant Classes:
- RobotBattery

Relevant Methods:
-  RobotBattery::Deplete(old_pos, pos_, dt)

Functionality:
- Battery at 3 levels: empty, goes to 0 with single move, leaves some charge
- Technically, it should never be empty when this is called, because that is checked before the robot moves.

#### Homebase mobile

We should talk about this a little bit. It seems like homebase should make use of the motionHandler and motionBehavior of the robot, so should it derive from robot with the only difference being that it's battery is never depleted??
