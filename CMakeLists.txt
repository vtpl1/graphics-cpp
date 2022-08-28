# *****************************************************
#    Copyright 2022 Videonetics Technology Pvt Ltd
# *****************************************************
cmake_minimum_required(VERSION 3.15)

set(VERSION 0.0.1)

project(graphics-cpp
	VERSION ${VERSION}
	DESCRIPTION "graphics cpp"
	HOMEPAGE_URL "https://github.com/vtpl1/graphics-cpp"
	LANGUAGES CXX)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
add_subdirectory(Walnut)
add_subdirectory(WalnutApp)
