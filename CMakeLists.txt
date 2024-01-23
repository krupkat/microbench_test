cmake_minimum_required(VERSION 3.5)
project(BenchmarkTest)

find_package(Boost REQUIRED)
find_package(benchmark REQUIRED)

add_executable(bench benchmark.cc)
target_link_libraries(bench Boost::headers benchmark::benchmark_main)
