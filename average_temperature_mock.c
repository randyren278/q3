#include <stdio.h>

#define NUM_VOLTAGE_READINGS 10

// Mock function to simulate get_voltage()
float get_voltage() {
    static float voltages[] = {0.51, 0.52, 0.53, 0.54, 0.55, 0.56, 0.57, 0.58, 0.59, 0.60};
    static int index = 0;
    return voltages[index++ % NUM_VOLTAGE_READINGS];
}

float io_read_temperature() {
    float voltage = get_voltage();
    return (voltage - 0.5) / 0.01;
}

float calculate_average_temperature() {
    float sum = 0.0;

    for (int i = 0; i < NUM_VOLTAGE_READINGS; i++) {
        float temperature = io_read_temperature();
        sum += temperature;
    }

    return sum / NUM_VOLTAGE_READINGS;
}

int main() {
    float avg_temperature = calculate_average_temperature();
    printf("Average Temperature: %.2f°C\n", avg_temperature);
    return 0;
}
