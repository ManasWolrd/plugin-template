#include "plugin_ui.hpp"

#include "../PluginProcessor.h"
#include "../PluginEditor.h"

PluginUi::PluginUi(EmptyAudioProcessor& p)
    : preset_(*p.preset_manager_) {
    preset_.SetDspInstName(p.dsp_processor_.name);
    addAndMakeVisible(preset_);
    setSize(1280, 720);
}

void PluginUi::resized() {
    auto b = getLocalBounds();
    preset_.setBounds(b.removeFromTop(30));
}

void PluginUi::paint(juce::Graphics& g) {
    g.drawText("Plugin UI", getLocalBounds(), juce::Justification::centred);
}

void PluginUi::TrySetSize(int width, int height) {
    auto* p = findParentComponentOfClass<EmptyAudioProcessorEditor>();
    jassert(p != nullptr);
    p->SetChildSize(width, height);
}
