cmake_minimum_required(VERSION 3.13)
project(cplusclass1399)

set(CMAKE_CXX_STANDARD 14)

add_executable(cplusclass1399 main.cpp src/FileSender_Package/FileSender.h src/FileSender_Package/Compression_Package/Compression.h src/FileSender_Package/Encryption_Package/Encryption.h test/UnitTest.cpp test/UnitTest.h)