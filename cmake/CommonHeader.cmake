set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)

set (PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR}/../..)

# adapted from
# https://github.com/RLovelett/eigen/blob/master/CMakeLists.txt

# guard against in-source builds
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message (FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

# guard against bad build-type strings
if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE "Release")
endif (NOT CMAKE_BUILD_TYPE)

string (TOLOWER "${CMAKE_BUILD_TYPE}" cmake_build_type_tolower)
if (    NOT cmake_build_type_tolower STREQUAL "debug"
    AND NOT cmake_build_type_tolower STREQUAL "release"
    AND NOT cmake_build_type_tolower STREQUAL "relwithdebinfo")
	message(FATAL_ERROR "Unknown build type \"${CMAKE_BUILD_TYPE}\". Allowed values are Debug, Release, RelWithDebInfo (case-insensitive).")
endif ()

# Don't make any install rules
set (CMAKE_SKIP_INSTALL_RULES TRUE)

#
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include (CheckCXXCompilerFlag)
if (MSVC)
	list (APPEND COMPILER_FLAGS_TO_CHECK /W4 /w44640)
else ()
	list (APPEND COMPILER_FLAGS_TO_CHECK -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wno-gnu-statement-expression -pipe)
	if (cmake_build_type_tolower STREQUAL "debug")
		list (APPEND COMPILER_FLAGS_TO_CHECK -g -Og)
	else ()
		list (APPEND COMPILER_FLAGS_TO_CHECK -Ofast -mtune=native)
	endif ()
endif ()

foreach (i IN LISTS COMPILER_FLAGS_TO_CHECK)
	message (STATUS "Checking compiler support for ${i}")
	check_cxx_compiler_flag (${i} SUPPORTS_i)

	if (SUPPORTS_i)
		message (STATUS "Checking compiler support for ${i} - Success")
		add_compile_options (${i})
	else ()
		message (STATUS "Checking compiler support for ${i} - Failed")
	endif ()
endforeach ()

if (MSVC)
	# So that Visual Studio will define M_PI
	add_definitions (-D_USE_MATH_DEFINES)
endif (MSVC)

