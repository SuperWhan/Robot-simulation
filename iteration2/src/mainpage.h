/**
 * @file mainpage.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_MAINPAGE_H_
#define PROJECT_ITERATION2_SRC_MAINPAGE_H_

/*! \mainpage CSCI3081 Robot Simulator Project
 *
 * \section intro_sec Introduction
 *
 * This is RobotSim v2.0. It is a mini video game allowing the player to
 * control a player in an arena. The goal of the game is for the player_ to
 * stop all robots. The player has a battery, which is depleted as the player_
 * moves. When the battery level goes to 0, the player lose the game. The
 * player can control the palyer_ through the 4 arrow keys, but be
 * careful--bumping into obstacles will both deplete some battery and slow
 * down the robot.
 *
 * On the right of the arena are some control buttons and (potentially)
 * useful game stats for the player to use.
 *
 * \section design_sec Overall Design (A Top-down Description)
 *
 * At the highest level, class GraphicsArenaViewer controls everything--from
 * rendering graphics to asking all relevant parties to update themselves at
 * each frame, but its main responsibility is the graphics--not the game
 * state or data.
 *
 * The real place where most of the "actions" take place is the
 * Arena. Arena is also a large class, containing many "arena entities," such
 * as the player-controlled player_ and the home base. Arena provides an
 * interface for GraphicsArenaViewer to query the status of itself (and the
 * entities within), so that all the data can be visualized on the screen.
 *
 * Going one level deeper, we have several different types of arena entities.
 * The simplest ones are obstacles, represented by the Obstacle class. Since
 * they can't move, all we need to know about them are their position and
 * color. On the other end of the complexity spectrum are classes like Robot
 * and HomeBase. Since the robot and the home base are mobile, they need
 * components such as a motion handler (i.e. RobotMotionHandler) to function
 * correctly.
 *
 * Entities naturally have properties, and they are not initialized randomly.
 * `struct`s like robot_params, for example, are set up and passed down to
 * Robot's constructor to initialize the robot. Similar operation is done for
 * Arena and HomeBase. The setup of these parameters takes place in main.cc,
 * so entities' default properties can be controlled independently of the
 * simulation code.
 *
 * Since they "live" in the same space (Arena), entities will also have to
 * interact with each other. For example, they can collide with one another.
 * In such cases, events such as EventCollision will be generated and passed
 * down to the relevant parties, so that these parties can update their
 * states accordingly.
 *
 * \section div_sec Class Classifications
 *
 * From what is described in the \ref design_sec section, it is easy to see
 * that we can classify the classes into 5 types.
 *
 * 1. **Control**, including GraphicsArenaViewer and Arena.
 * 2. **Entity**, including Player, ArenaEntity, ArenaImmobileEntity,
 * ArenaMobileEntity, HomeBase, Obstacle, RechargeStation, and Robot, SuperBot
 * 3. **Event**, including EventBaseClass, EventCollision, EventCommand,
 * EventKeypress, and EventRecharge, EventDistressCall, EventEntityType,
 * EventProximity.
 * 4. **Data**, including arena_entity_params, arena_mobile_entity_params,
 * arena_params, Color, home_base_params, Position, and robot_params,
 * player_params, superbot_params.
 * 5. **Entity Component**, including PlayerBattery, RobotMotionBehavior,
 * RobotMotionHandler, Sensor, and SensorTouch, PlayerMotionBehavior,
 * PlayerMotionHandler.
 *
 * \section bug_sec Known Bugs
 *
 * NOTE TO TA: There is a `BugReport.md` file containing the same content as
 * this section. However, in real life, documentation usually have such a
 * "Known Bugs" section embedded within itself, instead of putting it in a
 * separate document, so I'm replicating the `BugReport.md` file below.
 *
 * \subsection major_bug Major Bug
 *
 * 1. It is possible for the player_ (and less often the home base/robots) to
 * get stuck or run into an obstacle. However, the majority of the time the
 * mobile entities are able to bounce off the obstacles. I think this has to do
 * with how collision is handled. Currently, I simply change the heading angle
 * of the mobile entity when a collision occurs. However, if the mobile entity
 * has *already* moved into the obstacle, only changing the heading angle is
 * apparently not enough. In that case we would have to move the mobile entity
 * back a little bit (back-off distance). I have tried to implement that, but
 * with the current code it is very hard to get it work correctly;
 * specifically, since collision detection is performed multiple times for each
 * entity in every frame, moving mobile entities back can create weird behavior
 * (However, this might not be a bug, given what the professor said
 * [here](https://ay17.moodle.umn.edu/mod/forum/discuss.php?d=128184)).
 *
 *
 * \section caution_fixed Caution different with v1.0 
 * Caution: Most bugs should be in the BugReport.
 * The different with RobotSim v1.0, 2.0 change the cotrol of robot to control
 * player, so the robot acturally become some "enemy" we need to stop them
 * for the winnin, we are not trying to hit the homebase anymore, we are
 * trying to hit all robot, and stop them. Homebase now is only for the robot,
 * that's means when the robots are hitting the homebase, they should become
 * superbot, which ou will never want to touch them. v2.0 has more fun than v1.0
 * but the code become more complex. There're still many bugs or some
 * functionalities are stil not added. They should report in the BugRport.
 *
 */

#endif  // PROJECT_ITERATION2_SRC_MAINPAGE_H_
