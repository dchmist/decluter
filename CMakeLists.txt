project(Declutter)
cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 17)

set(HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${HOME_DIR})

add_library(declutter SHARED
    Declutter.cpp
    data/DataConverter.cpp
    data/Coordinates.cpp
    helpers/ErrorHandler.cpp
    helpers/FileHandler.cpp
    transformation/Matrice.cpp
)

add_executable(mainDeclutter
	main.cpp
)

target_link_libraries(mainDeclutter declutter)

add_subdirectory(tests)