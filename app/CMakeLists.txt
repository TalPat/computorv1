# add_library(App STATIC
# )

# target_link_libraries(App
#     Tmaths
# )

add_executable(computor 
		src/main.cpp
		src/Computor.cpp
)

target_link_libraries(computor
		Tmaths
)