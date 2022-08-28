cmake_minimum_required(VERSION 3.15)

add_executable(walnut-app
    src/WalnutApp/main.cpp
)
target_link_libraries(walnut-app
    PRIVATE walnut
)