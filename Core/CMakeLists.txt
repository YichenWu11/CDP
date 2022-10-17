# Set the project name
project (CDP)

add_library(${PROJECT_NAME} INTERFACE)
add_library(Chen::CDP ALIAS ${PROJECT_NAME})

# INTERFACE: anybody linking to CDP needs to include the 
# current source directory, while CDP itself doesn't.
# find_package(directxtk12 CONFIG REQUIRED)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)
