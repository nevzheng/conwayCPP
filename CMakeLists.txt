cmake_minimum_required(VERSION 3.7.2)


set(PROJECT_SOURCE_DIR "/Users/nevinzheng/conwayCPP")

# Use our modified FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(INC_DIR ${PROJECT_SOURCE_DIR}/include)

# Bump up warning levels appropriately for clang, gcc & msvc and build in debug mode
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=gnu++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -Ofast")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(include)

add_subdirectory(src)
# add_subdirectory(u_test)

#add testing (to do)
enable_testing()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})
file(GLOB TST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} u_tst/*.cpp)

#Run through each source
foreach(tstSrc ${TST_SRCS})
        #Extract the filename without an extension (NAME_WE)
        get_filename_component(tstName ${tstSrc} NAME_WE)

        #Add compile target
        add_executable(${tstName} ${tstSrc})

        #link to Boost libraries AND your targets and dependencies
        target_link_libraries(${tstName} LINK_PUBLIC ${Boost_LIBRARIES} GameOfLife)
		# target_link_libraries (${tstName} LINK_PUBLIC GameOfLife)

        #I like to move testing binaries into a testBin directory
        set_target_properties(${tstName} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/tstBin)

        #Finally add it to test execution -
        #Notice the WORKING_DIRECTORY and COMMAND
        add_test(NAME ${tstName}
                 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tstBin
                 COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tstBin/${tstName} )
endforeach(tstSrc)
