cmake_minimum_required (VERSION 2.6)
project (cajun-json)

include_directories( 
	${PROJECT_SOURCE_DIR}
)

add_definitions("-std=c++0x")


add_executable( test
	test/test.cpp
)


