## Exercise to Engage the Code

These are questions that ask you to explore the code in a specific way. They highlight important functionality and flow-of-control. You might want to jot down the answers for your own use as you spend time learning the code. It will probably take you a minimum of 2 hours just to understand how all the pieces fit together. We highly recommend you spend time understanding the framework before adding a single line of code.

# Answer the Following Questions Based on Iteration1 Code

1. What does GraphicsArenaViewer::DrawUsingNanoVG() do?
2. When does this get called?
3. How is it that the Recharge Station is being drawn - there is no command to draw it?
4. What entities exist in the Arena?
    - For each entity, what is it's base (parent) class?

5. Where does the system check for collisions (look in Arena.cc)?
6. When does this happen (i.e. where is it in flow-of-control)?
7. What is the logic for checking for colliding with walls?
8. What is the logic for checking for colliding with other entities?
9. Trace the EventCollision from the point at which it is created in Arena to
the robot sensor. What does the sensor record when a collision happens?
10. The RobotMotionHandler reads the touch sensor. What does it do with this information?
11. Identify the method (function) that updates the robot position. Trace flow-of-control
from the call UpdateSimulation in GraphicsArenaViewer.
12. What is the equation used to calculate the deltaX and deltaY for the robot
and update the position?
