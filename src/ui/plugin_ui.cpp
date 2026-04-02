#include "plugin_ui.hpp"

#include "../PluginProcessor.h"

PluginUi::PluginUi(EmptyAudioProcessor& p)
    : preset_(*p.preset_manager_) {
    preset_.SetDspInstName(p.dsp_processor_.name);
    addAndMakeVisible(preset_);
    setSize(400, 300);
}

void PluginUi::resized() {
    auto b = getLocalBounds();
    preset_.setBounds(b.removeFromTop(30));
}

void PluginUi::paint(juce::Graphics& g) {
    g.drawText("Plugin UI", getLocalBounds(), juce::Justification::centred);
}
