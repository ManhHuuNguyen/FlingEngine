set ( MODULE_NAME "TestModule" )
set ( MODULE_INC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/inc" )

# include the files so that this module can use them inside itself
include_directories( ${MODULE_INC_PATH} )

# Add all source files to this module
file( GLOB_RECURSE _source_list
    *.cpp* src/*.h* src/*.hpp* *.h* *.inl
)

message( STATUS "Module Added: ${MODULE_NAME}" )
message( STATUS "Module Added: ${MODULE_INC_PATH}" )
message( STATUS "Module Sources: ${_source_list}" )

add_library ( ${MODULE_NAME} ${_source_list} )

# Expose the include files to other shit linking against this
target_include_directories ( ${MODULE_NAME} PUBLIC ${MODULE_INC_PATH} )