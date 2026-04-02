#pragma once
#include <numbers>
#include <complex>
#include "pluginshared/simd.hpp"
#include "global.hpp"

namespace dsp {
struct DspState {
};

struct DspParam {
};

struct DspProcessor {
    void(*init)(DspState& state, float fs) noexcept;
    void(*reset)(DspState& state) noexcept;
    void(*update)(DspState& state, const DspParam& p) noexcept;
    void(*process)(DspState& state, float* left, float* right, int num_samples) noexcept;

    const char* name;

    bool IsValid() const noexcept {
        return init != nullptr;
    }
};

DspProcessor GetProcessorDsp() noexcept;
}
