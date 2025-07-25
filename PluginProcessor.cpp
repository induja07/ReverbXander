void ReverbXanderAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer&)
{
    const int numSamples = buffer.getNumSamples();
    const int numChannels = buffer.getNumChannels();
    const float delayMs = *parameters.getRawParameterValue("delay");
    const float decay = *parameters.getRawParameterValue("decay");

    const int sampleRate = getSampleRate();
    const int delaySamples = (int)(sampleRate * delayMs / 1000.0f);

    for (int channel = 0; channel < numChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);

        for (int i = delaySamples; i < numSamples; ++i)
        {
            channelData[i] += decay * channelData[i - delaySamples];
        }
    }
}
parameters(*this, nullptr, "PARAMETERS",
{
    std::make_unique<AudioParameterFloat>("delay", "Delay", 0.0f, 1000.0f, 100.0f),
    std::make_unique<AudioParameterFloat>("decay", "Decay", 0.0f, 1.0f, 0.5f),
})
