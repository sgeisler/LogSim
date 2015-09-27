LogSim
======

Dependencies:
-------------

* SFML
* nlohmann/json (as git module)
* The font /usr/share/fonts/truetype/freefont/FreeSans.ttf (you can change the font path [here](https://github.com/sgeisler/LogSim/blob/master/LogWindow.cpp#L12))

How to use:
-----------

* Hold 'A' to create a new gate. Scroll while pressing 'A' changes the type of gate.
* By pressing left mouse and dragging you can drag a gate or connect an output to an input.
* By right-clicking a input-gate you can change its state.
* By holding the right mouse button and dragging you can drag the whole workspace.
* By scrolling you can zoom in and out.
* Press 'D' to delete a gate or remove all connections from an in-/output.
* 'W' changes the connection style.

Screenshot:
-----------

![Screenshot](https://raw.githubusercontent.com/sgeisler/LogSim/master/screenshot.png)