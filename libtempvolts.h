#pragma once

#define NUM_VOLTAGE_READINGS 10

/**
 * Returns the voltage (in V) read from the temperature sensor
 * Every time you call the function, it will return the next voltage reading
 */
float get_voltage();