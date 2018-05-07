# Robot- simuation Project

## Method:

	Creat a robot simulation game, which contains all neccessary component for an APP, program part, gaming design, user interface, bug report, documentations ect. Using unittest to test different game methods, warning fix. 
	For the programming part, and design goal is: Plaer and other similar entities live in the arena and are quite oblivious to being viewed by the viewer. The viewer is in control of everything in that it sends a message to the arena to update, meaning move the arena entities the appropriate amount given how much time has passed since the last update. It then gets the appropriate positional information from each entity and draws these to the screen. All the while, the system is listening for keyboard and mouse activity by the user. If any action occurs, the associated callback is executed.

## Applied skills:

	C/C++, UML, unittest, Makefile,documentation, github(bug report, error report, branches, commit messages), gdb, python, warning fix, team works, group representation.

## Hardest Part:

	The design is the most difficult part, especially the sensors design. Having a good algorithmns and having a nice idea is important, which will help us to avoid "detours". Like the super_bot part, when the robot hit the home base, it will change the color and become a super_bot, superbot will have different methods and different features with robot. The TA gave hits that creat a new header, which call superbot, it is different, but still having same moving method with robot, which would take longer and more complex steps, so we did not creat that header, we just implement super_bot's feature into robot header, and give it an private valuble call "is_super_bot", to determine this robot is superbot or not. This design idea reduced a lot of works. It is working perfect, and also has less memory been used while run the game. So I think design ideas are the hardest part.
