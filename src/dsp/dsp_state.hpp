#pragma once
#include <numbers>
#include <complex>
#include "pluginshared/simd.hpp"
#include "global.hpp"

namespace dsp {
struct ProcessorState {
};

struct Param {
};

struct ProcessorDsp {
    void(*init)(ProcessorState& state, float fs) noexcept;
    void(*reset)(ProcessorState& state) noexcept;
    void(*update)(ProcessorState& state, const Param& p) noexcept;
    void(*process)(ProcessorState& state, float* left, float* right, int num_samples) noexcept;

    bool IsValid() const noexcept {
        return init != nullptr && reset != nullptr && update != nullptr && process != nullptr;
    }
};

ProcessorDsp GetProcessorDsp() noexcept;
}
