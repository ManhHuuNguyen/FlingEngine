#pragma once

/************************************************************************/
/* STD library Functionality                                            */
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <functional>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <map>
#include <cstring>
#include <set>
#include <array>

/************************************************************************/
/* Fling Engine Functionality                                           */
/************************************************************************/

// Enable Fling Logging (even applies in release)
#define F_ENABLE_LOGGING

// If defined then Fling will export functions to the DLL/Shared lib
#define FLING_EXPORT

#include "Platform.h"
#include "FlingTypes.h" 
#include "Random.h"
#include "Logger.h"
#include "FlingPaths.h"
#include "FlingMath.h"

#define FLING_DEFAULT_WINDOW_WIDTH		800
#define FLING_DEFAULT_WINDOW_HEIGHT		600