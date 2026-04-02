#include "dsp_state.hpp"

namespace dsp {

// ----------------------------------------
// dsp processor
// ----------------------------------------

static void Init(DspState& state, float fs) noexcept {
}

static void Reset(DspState& state) noexcept {

}

static void Update(DspState& state, const DspParam& p) noexcept {
}

static void Process(DspState& state, float* left, float* right, int num_samples) noexcept {
}

// ----------------------------------------
// export
// ----------------------------------------

#ifndef DSP_EXPORT_NAME
#error "不应该编译这个文件,在其他cpp包含这个cpp并定义DSP_EXPORT_NAME=`dsp_dispatch.cpp里的变量`"
#endif

DspProcessor DSP_EXPORT_NAME{Init, Reset, Update, Process, DSP_INST_NAME};
}
