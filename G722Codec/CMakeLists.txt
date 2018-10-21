cmake_minimum_required(VERSION 2.6)
project(G722Codec)

#Linuxª∑æ≥C++11±‡“Î
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

SET(CMAKE_CXX_FLAGS         "-g3 -Wall -std=c++11")
SET(CMAKE_CXX_FLAGS_DEBUG   "-g3 -Wall -std=c++11")
SET(CMAKE_CXX_FLAGS_RELEASE "-o2 -Wall -DNDEBUG -std=c++11")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


aux_source_directory(project/src/Startup/ FILE)
aux_source_directory(project/src/Public/ FILE)
aux_source_directory(project/src/Codec/ FILE)
aux_source_directory(project/src/Codec/G722 FILE)


ADD_EXECUTABLE(G722Codec ${FILE})
