[![GitHub license](https://img.shields.io/github/license/Tim-Kaiser/OpenGL_Boilerplate.svg)](https://github.com/Tim-Kaiser/OpenGL_Boilerplate/blob/main/LICENSE)
[![GitHub issues](https://img.shields.io/github/issues/Tim-Kaiser/OpenGL_Boilerplate.svg)](https://github.com/Tim-Kaiser/OpenGL_Boilerplate/issues)


# Table of Contents
- [Getting started](#getting-started)
  - [Quick start guide](#quick-start-guide)
  - [Controls](#controls)
  - [Renaming the project](#renaming-the-project)
- [Project showcase](#project-showcase)
- [Features](#features)
- [Libraries](#dependencies)




# Getting started

This template currently only runs on windows with OpenGL 4.6. Support for Linux and older OpenGL versions is planned.

## Quick start guide

1. Install [Visual Studio](https://visualstudio.microsoft.com/de/downloads/)
2. Create a new repository based on this template
3. Clone the new repository
4. Open ```OpenGL-Boilerplate.sln``` with Visual Studio


This creates a fullscreen window (Exit with ESC) and renders a quad with a basic shader. 

## Controls

ESC - Close the window. In fullscreen mode (standard) this is currently the only way to close the application.

Space - Take a screenshot. It's saved in `Screenshots` and named `frame_{frame_number}`.

## Renaming the project

1. Open the project in Visual Studio and rename it
2. Close Visual Studio
3. Rename ALL folders and files that include the original project name (.sln, .vcxproj, etc...)
4. Open the .sln file in an editor and rename the project path
5. Open the project in Visual Studio, fix any reference errors


# Project Showcase

[Slime mold simulation](https://github.com/Tim-Kaiser/Slime_Mold)

https://github.com/user-attachments/assets/4386fa00-a964-4518-8b0d-0b2c21905f6c

[Cell growth simulation](https://github.com/Tim-Kaiser/cellular-forms)

https://github.com/user-attachments/assets/88107231-6a9d-4613-b98a-508e18864188


[Cellular automata](https://github.com/Tim-Kaiser/Image_Transition)

https://github.com/user-attachments/assets/660e0b14-40c1-438d-ba57-70702daf3ce1

# Features

TODO - Details


- deferred shading
- compute shaders



# Dependencies

This project uses the following libraries

- [GLFW](https://www.glfw.org/)
- [GLM](https://github.com/g-truc/glm)
- [glad](https://glad.dav1d.de/)
