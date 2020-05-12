cmake_minimum_required(VERSION 3.10)

project(iter8)

add_executable(tests
    ./test/main.cpp
    ./test/doctest.h
)
set_target_properties(tests PROPERTIES EXCLUDE_FROM_ALL True)
target_compile_features(tests PRIVATE cxx_std_17)
target_include_directories(tests PRIVATE ./test)

add_test(
    NAME iter8_tests
    COMMAND ./tests
)
