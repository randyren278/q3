#include <stdio.h>
#include "libtempvolts.h"

float io_read_temperature() {
    // Use the TMP235 conversion formula to calculate the temperature from the voltage
    float voltage = get_voltage();
    return (voltage - 0.5) / 0.01;
}

float calculate_average_temperature() {
    float sum = 0.0;
    
    // Loop to accumulate temperature readings
    for (int i = 0; i < NUM_VOLTAGE_READINGS; i++) {
        float temperature = io_read_temperature();
        sum += temperature;
    }
    
    // Calculate the average temperature
    return sum / NUM_VOLTAGE_READINGS;
}

int main() {
    // Calculate and print the average temperature
    float avg_temperature = calculate_average_temperature();
    printf("Average Temperature: %.2f°C\n", avg_temperature);
    
    return 0;
}
