## NOT CURRENTLY WORKING 

```
Systems is doing an upgrade Friday, Oct 6. We are hoping this resolves remote access issues.
```

<hr>

#### Remotely running the Project using Windows

This guide will teach you how to run the project remotely when using the Windows operating system. I've only tested this on Windows 10, so you may encounter issues when on older versions of Windows. This uses the X11 window system, which is a way of remotely rendering graphics via SSH.

#### Setup

1. Compile the project on the CSE lab machines. See the other guides on how to compile and run the project. This guide will assume you have successfully run the project when physically on the lab machines

2. Install [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html). Get the Windows installer for your preferred number of bits.

3. Install [VcXSrv](https://sourceforge.net/projects/vcxsrv/). This is a server which provides the rendering on your physical machine. *Note: the popular X11 server `Xming` does not work for this project. VcXSrv is required*

4. Set-up a PuTTY connection. Pick a [CSE Labs machine](https://cseit.umn.edu/computer-classrooms/cse-labs-unix-machine-listings) as the target for your connection and put its address in the address field. Any CSE Labs machine should do (I've been using kh1260). While setting up the connection, go to `Connection->SSH->X11` and check *Enable X11 Forwarding*. You can save this setup for future use.

#### Running the Project

1. Start VcXSrv on your machine. This sets up a server which will render the graphics of the project on your current machine.

2. Open PuTTY and connect to the CSE Labs machine, using a connection with X11 Fowarding enabled.

3. Run the project via the PuTTY terminal. A window containing project's rendered output will be created on your local machine.

#### Troubleshooting

After connecting, you can use a different graphical application to test whether or not the X11 system is working. Running the command `firefox` should open a firefox window.

If Firefox X11 forwarding is working and the application is still generating errors, please verify they are not related to changes you have made in the code (and thus unrelated to the X11 forwarding). You can verify you have correct versions of X11 forwarding and OpenGL by running the command `glxinfo | grep version` in the PuTTY terminal. The X11 Server and X11 Client need to be version >1.3 and OpenGL needs to be >3.0. If any of these versions are not high enough, try a different lab machine (or lab all together).
