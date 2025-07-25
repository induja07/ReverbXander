addAndMakeVisible(delaySlider);
delaySlider.setSliderStyle(Slider::LinearHorizontal);
delaySlider.setRange(0.0, 1000.0);
delaySlider.setTextBoxStyle(Slider::TextBoxRight, false, 50, 20);
delaySlider.setValue(100.0);
delaySliderAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(processor.parameters, "delay", delaySlider));

addAndMakeVisible(decaySlider);
decaySlider.setSliderStyle(Slider::LinearHorizontal);
decaySlider.setRange(0.0, 1.0);
decaySlider.setTextBoxStyle(Slider::TextBoxRight, false, 50, 20);
decaySlider.setValue(0.5);
decaySliderAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(processor.parameters, "decay", decaySlider));
