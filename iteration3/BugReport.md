### Bug1:

Robot may stick on the wall and can't change back it's heading angle.(which Amy said is fine)

### Bug2:

When you win the game, the "WIN" will show up on the Simulation Control. and the game will reset, but the "You win" will always show on there, and won't change it back to "playing..."

### Bug3:

(Fixed)
can't have a correct collision angle for obstacle collision.

### Bug4:

When you pause it, you can't modify the speed, but you are still able to change the heading angle.(This part is done for us, we did not change anything)

### Bug5:

I just make the top bond to 100, but we didn't actually hit the gui, or the simulation Control. 

### Bug6:

Robot sensor's heading angle is not as same as robot's heading angle. (Means somethin like when robot is move up, but the sensor is heading to tail may happen.)

### BUg7:

Player's battery and speed will reduce when it hit robots, or even recharge station. we only need reduce speed when hit the obstacles.

### Bug8:

(Fixed)
Win condistion is not for stopping all robots, when player hit the homebase, it will count 1 win. we are looking for it will only win when player stop all robots.

### Bug9:
(Fixed)
Superbot is appear in the arena at first, we don't want any superbot since rbots did not hit the homebase. we only want superbot when robot hit the homebase.

### Bug10:

player did not stop when it hit the superbot.

### Bug11:

The heading angle is not as same as our knowledge about angle. (so 360 degree will shows like heading to 2 o'clock direction, we want it be 3 o'clock direction.)

### Bug12:

Except the sensor_touch, other sensors are all did not work correctly, or they just did no work. 

### Bug13:

When robot hit stop palyer, they will stick together and player's battery will just going down really fast.

### Bug14:

Sensor dose not work still. All sensors just have an interfacem but without any functionalities.

### Bug 15:

when the robot was frozed, but meanwhile, it hit by homebase and changing into super_bot, unless other robots hit it again, it is not movable.
