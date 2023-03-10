#include <Arduino.h>
#include <driver/i2s.h>
#include "def.h"

const i2s_port_t I2S_PORT = I2S_NUM_0;
const int BLOCK_SIZE = 128;
const int bufferLen = 128;

void setupMic()
{
    Serial.println("------------------------------------------------------------");
    Serial.println("Setting up i2s INMP441 Microphone ...");
    esp_err_t err;

    // The I2S config as per the example
    const i2s_config_t i2s_config = {
        .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX), // Receive, not transfer
        .sample_rate = 16000,                              // 16KHz
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,      // could only get it to work with 32bits
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,       // although the SEL config should be left, it seems to transmit on right
        .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // Interrupt level 1
        .dma_buf_count = 4,                       // number of buffers
        .dma_buf_len = BLOCK_SIZE                 // samples per buffer
    };

    // The pin config as per the setup
    const i2s_pin_config_t pin_config = {
        .bck_io_num = I2S_SCK, // BCKL
        .ws_io_num = I2S_WS,   // LRCL
        .data_out_num = -1,    // not used (only for speakers)
        .data_in_num = I2S_SD  // DOUT
    };

    // Configuring the I2S driver and pins.
    // This function must be called before any I2S driver read/write operations.
    err = i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
    if (err != ESP_OK)
    {
        Serial.printf("Failed installing driver: %d\n", err);
        while (true)
            ;
    }
    err = i2s_set_pin(I2S_PORT, &pin_config);
    if (err != ESP_OK)
    {
        Serial.printf("Failed setting pin: %d\n", err);
        while (true)
            ;
    }
    Serial.println("------------------------------------------------------------");
}

// uint16_t readMic()
// {
//     uint16_t height = 0;
//     // Read multiple samples at once and calculate the sound pressure
//     int32_t samples[BLOCK_SIZE];
//     int num_bytes_read = i2s_read_bytes(I2S_PORT,
//                                         &samples,
//                                         BLOCK_SIZE,
//                                         portMAX_DELAY); // no timeout
//     int samples_read = num_bytes_read / 8;
//     if (samples_read > 0)
//     {
//         float mean = 0;
//         for (int i = 0; i < samples_read; ++i)
//         {
//             mean += (samples[i] >> 14);
//         }
//         mean /= samples_read;
//         float maxsample = -1e8, minsample = 1e8;
//         for (int i = 0; i < samples_read; ++i)
//         {
//             minsample = min(minsample, samples[i] - mean);
//             maxsample = max(maxsample, samples[i] - mean);
//         }
//         float vol1 = (maxsample - minsample) / 100000;
//         height = map(abs(vol1), 0, 1000, 0, 72);
//         }
//     return height * sensitivity;
// }

uint16_t readMic()
{
    int32_t samples[BLOCK_SIZE];
    int16_t mean = 0;

    // ***************************************************************************************
    size_t bytesIn = 0;
    esp_err_t result = i2s_read(I2S_PORT, &samples, bufferLen, &bytesIn, portMAX_DELAY);
    if (result == ESP_OK)
    {
        // Read I2S data buffer
        int16_t samples_read = bytesIn / 8;
        if (samples_read > 0)
        {
            for (int16_t i = 0; i < samples_read; ++i)
            {
                mean += (samples[i]);
            }
            // Average the data reading
            mean /= samples_read;
        }
        // float maxsample = -1e4, minsample = 1e4;
        // for (int i = 0; i < samples_read; ++i)
        // {
        //     minsample = min(minsample, samples[i] - mean);
        //     maxsample = max(maxsample, samples[i] - mean);
        // }

        // float vol1 = (maxsample - minsample) / 100000;
    }

    int height = map(abs(mean), 0, 10000, 0, 72);
    Serial.println(height);

    return height;
}