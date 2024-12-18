#include <iostream>
#include <resid/sid.h>
#include <SDL2/SDL.h>

const int SAMPLE_RATE = 44100; // Sampling rate for audio output
const int TONE_FREQUENCY = 262; // Middle C ~261.63 Hz
const int DURATION_SECONDS = 1;

class AudioContext {
public:
    SID sid;
    Uint32 samplePos = 0;
    Uint8 audioBuffer[2048];

    AudioContext() {
        // Initialize SID with the sampling rate
        sid.set_sampling_parameters(SAMPLE_RATE, SID::OUTPUT_SAMPLE);
        sid.set_chip_model(MOS6581);
        sid.reset();
        setupTone();
    }

    void setupTone() {
        // Setup a basic square wave on Voice 1
        sid.write(0x05, 0x41); // Voice 1 Control Register: Gate Bit on, Square Wave
        sid.write(0x00, TONE_FREQUENCY & 0xFF); // Frequency Low Byte
        sid.write(0x01, (TONE_FREQUENCY >> 8) & 0xFF); // Frequency High Byte
        sid.write(0x06, 0x0F); // Volume of envelope (sustain level)
        sid.write(0x04, 0x10); // Attack/Decay: Fast attack
    }

    void fillAudioBuffer(Uint8 *stream, int len) {
        for (int i = 0; i < len; i += 2) {
            int sample = sid.output();
            stream[i] = stream[i + 1] = static_cast<Uint8>(sample >> 8);
        }
    }
};

void audioCallback(void *userdata, Uint8 *stream, int len) {
    auto *ctx = reinterpret_cast<AudioContext *>(userdata);
    ctx->fillAudioBuffer(stream, len);
}

int main() {
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_AudioSpec spec{};
    spec.freq = SAMPLE_RATE;
    spec.format = AUDIO_U8;
    spec.channels = 1;
    spec.samples = 1024;
    spec.callback = audioCallback;

    AudioContext audioContext;
    spec.userdata = &audioContext;

    if (SDL_OpenAudio(&spec, nullptr) != 0) {
        std::cerr << "Failed to open audio: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    std::cout << "Playing C tone for " << DURATION_SECONDS << " second(s)..." << std::endl;
    SDL_PauseAudio(0);
    SDL_Delay(DURATION_SECONDS * 1000);
    SDL_CloseAudio();
    SDL_Quit();

    std::cout << "Playback complete." << std::endl;
    return 0;
}
