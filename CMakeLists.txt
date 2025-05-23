cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME EditableTableDelegate)
project(${PROJECT_NAME})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/StyledWidgets)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/TableDelegate)

add_subdirectory(./NavyComponents)

set(HDRS
     ./include/StyledWidgets/StyledTable.h 
     ./include/StyledWidgets/StylePropDefines.h 
     ./include/TableDelegate/TableDelegate.h
)
set(SRC
    ./src/TableDelegate/TableDelegate.cpp
    ./src/StyledWidgets/StyledTable.cpp
)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

message("Building " ${TARGET})

add_library(${PROJECT_NAME} STATIC ${HDRS} ${SRC})
target_link_libraries(${PROJECT_NAME} Qt6::Widgets CoordinateEdit)

set(dirTarget 
    ./include/StyledWidgets 
    ./include/TableDelegate
)

target_include_directories(${PROJECT_NAME} PUBLIC ${dirTarget})