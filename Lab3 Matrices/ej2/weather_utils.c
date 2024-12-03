#include <stdio.h>
#include "weather_utils.h"
#include "array_helpers.h"


int historycal_min(WeatherTable array) {
    int min = array[0][0][0]._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (array[year][month][day]._min_temp < min) {
                    min = array[year][month][day]._min_temp;
                }
            } // End day.
        } // End month.
    } // End year.
    return min;
}

void max_temp_array(WeatherTable array, int output[YEARS]) {
	for (unsigned int year = 0u; year < YEARS; ++year) {
		int max = array[year][0][0]._max_temp; // Set the maximum temp. on day 1 for each year.
		for (month_t month = january; month <= december; ++month) {
			for (unsigned int day = 0u; day < DAYS; ++day) {
				if (array[year][month][day]._max_temp > max) {
					max = array[year][month][day]._max_temp; // Maximun temperature by (year + 1980).
				}
			} // End day.
		} // End month.
		output[year] = max;
	} // End year.
}

void rainy_month_array(WeatherTable array, month_t output[YEARS]) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        unsigned int max_rainfall = 0; // For each year, reset the maximum rainfall.
        month_t max_rainy_month = january; // Initialize the month with the highest rainfall.
        for (month_t month = january; month <= december; ++month) {
            unsigned int monthly_rainfall = 0; // For each month, reset the monthly rainfall.
            for (unsigned int day = 0u; day < DAYS; ++day) {
                monthly_rainfall += array[year][month][day]._rainfall;
            }
            if (monthly_rainfall > max_rainfall) {
                max_rainfall = monthly_rainfall;
                max_rainy_month = month;
            }
        } // End month.
        output[year] = max_rainy_month; // Store the month with the maximum rainfall for the year.
    } // End year.
}

