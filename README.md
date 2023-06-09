# RDR2-Animation-Finder
Simple took using ScripthookRDR2 that queries a library with all known and more animations to provide you with animation just performed. The purpose of this is so that you can find specific animations that are used and the dictionaries so that you can use this within RedM 


# Description
This script for Red Dead Redemption 2 uses the ScriptHookRDR2 SDK to search for and identify when the player character is performing a specific animation from a pre-defined list of animations. Once a matching animation is identified, a message is displayed on the screen indicating that the animation has been copied to the clipboard.

The list of animations can be provided as a URL to a text file containing the data, or as a Lua file that can be bundled with the mod.

# Pre Installation
* Download the LuaBridge library from the official GitHub repository: https://github.com/vinniefalco/LuaBridge
* Extract the contents of the downloaded archive to a local directory
* Open the Visual Studio solution file located in the `build\msvc` directory of the extracted archive
* Select the appropriate build configuration (e.g. Debug, Release) and build the solution
* Once the build is complete, copy the `luabridge.lib` and `luabridge.dll` files to your project directory or a directory where your project can find them
* In your project settings, add the directory containing the `luabridge.lib` file to the "Library Directories" option
* In your project settings, add "luabridge.lib" to the "Additional Dependencies" option under the "Linker" settings
* In your code, include the LuaBridge header file by adding `#include "LuaBridge/LuaBridge.h"` at the top of your file

# Installation
* Install the ScriptHookRDR2 SDK (https://www.dev-c.com/rdr2/scripthookrdr2/)
* Download or clone the mod source code from the GitHub repo
* Extract the contents of the downloaded archive to a local directory
* Copy the `ScriptHookRDR2.dll` and `dinput8.dl`l files to the game's root directory (the same directory where the RDR2.exe file is located)
* Copy the mod files to the `scripts` subdirectory of the game's root directory
* If using a URL to a text file for the animation list, modify the `animationListUrl` constant in `main.cpp` to point to the correct URL
* If using a Lua file for the animation list, make sure the `animations.lua` file is located in the same directory as the mod DLL file
* Build the mod using your preferred build tool (e.g. Visual Studio)
* Launch the game and the mod should be loaded automatically


# Usage
Press the `F5 key` to search for and identify when the player character is performing a specific animation from the pre-defined list of animations. If a matching animation is identified, a message is displayed on the screen indicating that the animation has been copied to the clipboard. The copied animation name can be pasted into another application, such as a text editor or script editor.


# License
```
MIT License

Copyright (c) 2023 Sup3820

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. BY ME PROVIDING THIS NO COMPANY, 3RD PARTY BUSINESS OR END-USERS SHALL BE ALLOWED TO SUE
BRING LEGAL ACTION AGAINST ME IN ANY FORM. 
```
