#pragma once
#include "pluginshared/component.hpp"
#include "pluginshared/preset_panel.hpp"

class EmptyAudioProcessor;

class PluginUi : public juce::Component {
public:
    static constexpr int kWidth = 480;
    static constexpr int kHeight = 320;

    explicit PluginUi(EmptyAudioProcessor& p);

    void resized() override;
    void paint(juce::Graphics& g) override;
private:
    void TrySetSize(int width, int height);

    pluginshared::PresetPanel preset_;
};
