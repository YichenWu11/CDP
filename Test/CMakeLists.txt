cmake_minimum_required(VERSION 3.5)

project(Test)

# Create the executable
add_executable(${PROJECT_NAME} test.cpp)

target_link_libraries(${PROJECT_NAME}
    Singleton
)
