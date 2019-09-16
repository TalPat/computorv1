cmake_minimum_required(VERSION 3.0)

project(computor)
set(CMAKE_CXX_STANDARD 17)

include_directories(
		Tmaths/include
		app/include
)

add_subdirectory(Tmaths)
add_subdirectory(app)