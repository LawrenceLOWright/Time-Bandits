# CMakeList.txt : CMake project for Time Bandits, include source and define
# project specific logic here.


# Add source to this project's executable.
add_executable (hourglass
"Time Bandits.cpp" 
"Time Bandits.h"
"color.h"
"action.h"
"actionListener.h"
"character.h"
"fileMessagesToString.h"
"fileToString.h"
"gameEngine.cpp"
"message.h"
"timer.h"
"color.cpp"
"action.cpp"
"actionListener.cpp"
"character.cpp"
"fileMessagesToString.cpp"
"fileToString.cpp"
"message.cpp"
"timer.cpp"
"fileActionsToString.cpp"
"fileActionsToString.h"
"gameTools.cpp"
"gameTools.h")
#"loadGame.cpp"
#"loadGame.h"
#"error.cpp"
#"error.h"
#"fileTextToString.cpp"
#"fileTextToString.h"
#"fileAssetsToString.cpp"
#"fileAssetsToString.h"
#"File.cpp"
#"FileRetrival.cpp"
#"FileRetrival.h")


# Include directories for header files
target_include_directories(hourglass PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}   # Include the current source directory
)
#file(GLOB SOURCES 
#"src/*.txt"
#"src/*.color"
#"src/*.txt"
#)

# Collect all files in the Backgrounds directory
file(GLOB BACKGROUND_FILES "${CMAKE_CURRENT_SOURCE_DIR}/Backgrounds/*")
file(GLOB MESSAGE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/Text-Messages/*")
file(GLOB SETTING_FILES "${CMAKE_CURRENT_SOURCE_DIR}/Game-Engine-Settings/*")


# Copy all collected files to the build directory
file(COPY ${BACKGROUND_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${MESSAGE_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${SETTING_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET hourglass PROPERTY CXX_STANDARD 20)
endif()

#file(COPY mainMenu.background DESTINATION ${CMAKE_BINARY_DIR}/test)
#file(COPY mainMenu.color DESTINATION ${CMAKE_BINARY_DIR}/test)
#file(COPY mainMenu.txt DESTINATION ${CMAKE_BINARY_DIR}/test)
# TODO: Add tests and install targets if needed.


enable_testing()

add_executable(
  hello_test
  hello_test.cc
  action.cpp
  actionListener.cpp
  character.cpp
  fileMessagesToString.cpp
  message.cpp
  fileToString.cpp
  fileActionsToString.cpp
  fileActionsToString.h
  "gameTools.cpp"
  "gameTools.h"
  "loadGame.cpp"
  "loadGame.h"
  "error.cpp"
  "error.h"
  "color.h"
  "color.cpp"
  "fileTextToString.cpp" "fileTextToString.h" "fileAssetsToString.cpp" "fileAssetsToString.h" "File.cpp" "FileRetrival.cpp" "FileRetrival.h")

target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
