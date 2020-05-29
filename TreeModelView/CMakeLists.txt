cmake_minimum_required(VERSION 3.5)

project(TreeModelView LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)
include_directories(Headers/)

file(GLOB HEADER
      "Headers/*.h"
)
file(GLOB SOURCE
  "Sources/*.cpp"
  )

    add_executable(TreeModelView ${HEADER}
     ${SOURCE}
    )
  target_include_directories(TreeModelView
      PRIVATE
          ${PROJECT_SOURCE_DIR}/Header
  )

  target_link_libraries(TreeModelView PUBLIC Qt5::Widgets Qt5::Core)
