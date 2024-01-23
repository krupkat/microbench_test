
#include <iostream>
#include <boost/unordered_map.hpp>
#include <benchmark/benchmark.h>
#include <cstdlib>
#include <string>

// https://gist.github.com/camolezi/a5a39539a8c7252d74ec8e6f17f6aa37

using keyType = uint32_t;
using countingType = uint32_t;

static const countingType numberOfElementes = 10000;

static void boost_unordered(benchmark::State& state){
    boost::unordered_map<keyType, std::string> boost_map;

    for(uint32_t key = 0; key < numberOfElementes; key++){
        auto result = boost_map.emplace(key, "testing std maps" + std::to_string(key));
        benchmark::DoNotOptimize(result);
    }

    for(auto _ : state){

        state.PauseTiming();
            std::string variable;
            uint32_t key  = rand() % numberOfElementes;
        state.ResumeTiming();

        benchmark::DoNotOptimize(variable = boost_map.at(key));

        auto erase_result = boost_map.erase(key);
        benchmark::DoNotOptimize(erase_result);

        auto emplace_result = boost_map.emplace(key,variable);
        benchmark::DoNotOptimize(emplace_result);
        benchmark::ClobberMemory();
    }
}

BENCHMARK(boost_unordered);