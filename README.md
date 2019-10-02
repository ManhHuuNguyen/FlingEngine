![Fling Engine Logo](docs/Fling-Engine-logo/cover.png)


The Fling Engine aims to be a cross platform Vulkan game engine that will experiment with the following:

* Low-level engine systems such as render API abstraction, file systems, and custom allocators.
* Multithreaded engine architecture
* The Vulkan graphics API for real time rendering

[![Build Status](https://travis-ci.com/flingengine/FlingEngine.svg?branch=master)](https://travis-ci.com/flingengine/FlingEngine)
[![Gitter](https://badges.gitter.im/fling-engine/community.svg)](https://gitter.im/fling-engine/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
[![Open Source Helpers](https://www.codetriage.com/flingengine/flingengine/badges/users.svg)](https://www.codetriage.com/flingengine/flingengine)
[![GitHub license](https://img.shields.io/github/license/flingengine/FlingEngine)](https://github.com/flingengine/FlingEngine/blob/master/LICENSE)
[![Work in progress badge](https://img.shields.io/badge/this%20is-a%20work%20in%20progress!-yellow)](https://img.shields.io/badge/this%20is-a%20work%20in%20progress!-yellow)

# Getting Started

There are a few basic steps to compiling Fling on your platform. 

## [CMake 3.13](https://cmake.org/download/) or higher!
This project requires CMake 3.13 or higher, you can install it [here](https://cmake.org/download/).

## For Linux
This project uses GLFW, so you will need to install those libraries to your machine.
GLFW also depends on having Doxygen, so you may want to have that as well.

Ubuntu:
```
sudo apt-get update
sudo apt-get install doxygen
sudo apt-get install -y libglm-dev libxcb-dri3-0 libxcb-present0
sudo apt-get install -y libpciaccess0 libpng-dev libxcb-keysyms1-dev
sudo apt-get install -y libxcb-dri3-dev libx11-dev libmirclient-dev
sudo apt-get install -y libwayland-dev libxrandr-dev
sudo apt-get install -y libglfw3-dev
sudo apt-get install -y xorg-dev
```

## Vulkan SDK
Obviously this project is build using Vulkan, so you will need to install it before compiling 
or running the program. 

You can download the SDK from the LunarG website [here](https://www.lunarg.com/vulkan-sdk/). 

If you are having trouble with the Vulkan SDK then check out some of these resources: 
* [Vulkan Verify Install](https://vulkan.lunarg.com/doc/view/1.1.106.0/windows/getting_started.html#user-content-verify-the-installation)
* [Vulkan Tutorial FAQ](https://vulkan-tutorial.com/FAQ)

## `Init.bat` and `Init.sh`
After installing the SDK, you can simply run one of the provided scripts. 

Running either one of these scripts will simply get all submodules and external libraries
that the engine uses and create a folder called `build`. The `build` folder will have your
platform specific build files (Visual Studio, Makefiles, etc). 

#### Packaging a project

For ease of development and iteration the file paths to Assets (shaders, textures, models, etc) are all 
absolute paths generated by CMake. If you want to have a copy of your executeable with asset paths relative
to the program, then generate your project files with CMake with this flag: 

```
cmake -DDEFINE_SHIPPING=ON -B build .
```

Notice the `-DDEFINE_SHIPPING` option is set to `ON`. This sets a definiton that you can use in C++: 

```C
#ifdef FLING_SHIPPING
// Do some nice stuff
#else
// Do non-shipping code, perhaps with a lot of log messages
#endif
```

### Wanna contribute?

If you have any contributions or fixes that you want to contribute, then feel free to open 
an issue or a pull request! I'm happy to talk about the project, so feel free to reach out
to me on [Twitter](https://twitter.com/BenjaFriend?lang=en) or here on GitHub. Eventually a
goal is to have some more specific PR templates/coding standards but for now that is not a 
priority. 

The `master` branch is where we keep our stable releases only. For the most up to date development
see the `staging` branch

### Cool Resources

Some great resources are the 
[Vulkan Tutorial](https://vulkan-tutorial.com/Drawing_a_triangle/Setup/Validation_layers) and 
[SaschaWillems](https://github.com/SaschaWillems/Vulkan)'s repo with different Vulkan examples
