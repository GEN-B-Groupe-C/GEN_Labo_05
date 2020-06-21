cmake_minimum_required(VERSION 3.16)
project(GEN_Labo05)

set(CMAKE_CXX_STANDARD 14)

add_executable(GEN_Labo05 main.cpp Customer.cpp Customer.h Movie.cpp Movie.h Rental.h test/CustomerTest.cpp Bill.h Bill.cpp Rental.cpp)

add_subdirectory(lib test)

include_directories(lib/googletest/include)

include_directories(lib/googlemock/include)

target_link_libraries(GEN_Labo05 gtest gtest_main)