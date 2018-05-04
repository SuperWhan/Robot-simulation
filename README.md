### Incorporating the Update

This update addresses 2 issues:
- Controlling the timing of the update of the simulation so that it doesn't speed up when events occur
- Addressing the problem of Robot::pos_ overriding that of ArenaEntity::pos_

The fixes were, respectively:
- Check for a minimum passing of time before advancing the simulation.
- Removing pos_ from Robot and using setters and getters instead of direct access.

There are a limited number of files with small changes that were modified relative to the initial release.
If we were using git as intended, the branch would be created to work on the update, the updates would be made
and tested, then the branch would be merged into the master. However, here you are copying the contents of
the repo to another.

There are 2 ways to go about incorporating. The first is to make a branch on your student repo that contains the 
updates and then merge into your master. The second is to find the differences and make the changes yourself by hand.

The files that contain changes are:
- graphics_arena_viewer.h : UpdateSimulation
- graphics_arena_viewer.cc : UpdateSimulation
- arena.h : AdvanceTime
- arena.cc : AdvanceTime
- robot.h : removing _pos
- robot.cc : TimeStepUpdate

