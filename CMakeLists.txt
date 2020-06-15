cmake_minimum_required(VERSION 3.13)
project(cplusclass1399)

set(CMAKE_CXX_STANDARD 14)

add_executable(cplusclass1399 main.cpp src/file-sender/FileSender.h src/file-sender/compression/Compression.h src/file-sender/encryption/Encryption.h test/UnitTest.cpp test/UnitTest.h)