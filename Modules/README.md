# Modules in Fling Engine

Modules are meant to be individual parts of the engine that shouldn't 
depend on the engine itself. This will improve scalability of compile times 
as the project grows, and allow for better code coverage. Modules can depend
on one another, but shouldn't depend cyclicaly.

If you want to add a new module, then simply create a new folder with a CMakeLists.txt
in it and use the `add_subdirectory` CMake command to add it to this list.