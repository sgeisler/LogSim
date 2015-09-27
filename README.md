LogSim
======

LogSim is a little program to simulate binary logic. It was a school project and I won't maintain it any longer (since I don't think it has any real use for someone). I publish it under the MIT license (you can find it in the LICENSE file).

Dependencies:
-------------

* SFML
* nlohmann/json (as git module)
* The font `/usr/share/fonts/truetype/freefont/FreeSans.ttf` (you can change the font path [here](https://github.com/sgeisler/LogSim/blob/master/LogWindow.cpp#L12))

How to use:
-----------

* Hold 'A' to create a new gate. Scroll while pressing 'A' changes the type of gate.
* By pressing left mouse and dragging you can drag a gate or connect an output to an input.
* By right-clicking a input-gate you can change its state.
* By holding the right mouse button and dragging you can drag the whole workspace.
* By scrolling you can zoom in and out.
* Press 'D' to delete a gate or remove all connections from an in-/output.
* 'W' changes the connection style.
* Press 'S' or 'L' and enter a file name to save or load your/a previously saved workspace (thanks to nlohmann for his easy to use json-library).

Screenshot:
-----------

![Screenshot](https://raw.githubusercontent.com/sgeisler/LogSim/master/screenshot.png)
