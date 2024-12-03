#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include <stdio.h>
#include "array_helpers.h"
#include "weather.h"

int historycal_min(WeatherTable array);
// Returns minimum temperature in the history of Córdoba city.

void max_temp_array(WeatherTable array, int output[YEARS]);
// For each year in range [1980 - 2016] returns maximum temp.

void rainy_month_array(WeatherTable array, month_t out[YEARS]);
// For each year in range [1980 - 2016] the rainiest corresponding to the year.

#endif
