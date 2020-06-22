cmake_minimum_required(VERSION 2.8.9)
project(mahsan_project)

include_directories(include)

set(SOURCES_1 src/client/FilePreSending.cpp
	      src/client/MainClient.cpp )
set(SOURCES_2 src/server/FilePostSending.cpp
	      src/server/MainServer.cpp )

ADD_LIBRARY(LibModule "src/client/FilePreSending.cpp")

target_link_libraries(LibModule stdc++fs)
target_link_libraries(LibModule -lzip)

add_executable(client ${SOURCES_1})
add_executable(server ${SOURCES_2})

target_link_libraries(client LibModule)
target_link_libraries(server LibModule)
