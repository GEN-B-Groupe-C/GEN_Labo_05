cmake_minimum_required(VERSION 3.16)
project(GEN_Labo05)

set(CMAKE_CXX_STANDARD 14)

add_executable(GEN_Labo05 main.cpp Customer.cpp Customer.h Movie.cpp Movie.h Rental.h test/BillTest.cpp Bill.h Bill.cpp Rental.cpp Children.h Regular.h NewRelease.h test/mockMovie.h test/RentalTest.h test/mockRental.h test/typeTest.h test/mockState.h)

add_subdirectory(lib test)

include_directories(lib/googletest/include)

include_directories(lib/googlemock/include)

target_link_libraries(GEN_Labo05 gtest gtest_main gmock gmock_main)