#include <stdio.h>
#include "weater_utils.h"
#include "array_helpers.h"


int historycal_min(WeatherTable array) {
    int min = array[0][0][0]._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (array[year][month][day]._min_temp < min)) {
                    min = array[year][month][day];
                }
            } // End day.
        } // End month.
    } // End year.
    return min;
}

void max_temp_array(WeatherTable array, int output[YEARS]) {
// Working...

}


void rainy_month_array(WeatherTable array, month_t out[YEARS]) {
// Working...
}

