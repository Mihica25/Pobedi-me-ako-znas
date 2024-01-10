cmake_minimum_required(VERSION 3.16.3)

project(ServerApplication)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra --coverage")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt5")

find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)

file(GLOB SERVER_SOURCES "*.cpp")
file(GLOB SERVER_HEADERS "*.h")
file(GLOB SERVER_RESOURCES "*.qrc")

add_executable(ServerApplication ${SERVER_SOURCES} ${SERVER_HEADERS} ${SERVER_RESOURCES})

target_link_libraries(ServerApplication
    Qt5::Core
    Qt5::Widgets
    Qt5::Network
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/pitanja
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/pitanja)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/podrunda_pitanja
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/podrunda_pitanja)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources)

set(RESULTS_TXT ${CMAKE_CURRENT_BINARY_DIR}/resources/results.txt)
if(NOT EXISTS ${RESULTS_TXT})
  file(WRITE ${RESULTS_TXT} "")
endif()

set_target_properties(ServerApplication PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
)

install(TARGETS ServerApplication DESTINATION "/opt/ServerApplication/bin")
