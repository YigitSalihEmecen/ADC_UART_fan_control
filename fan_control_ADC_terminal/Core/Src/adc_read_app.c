#include "adc_read_app.h"
#include "main.h" // Include main.h for ADC handle definition

extern ADC_HandleTypeDef hadc1; // Declare hadc1 as an external variable

/**
 * @brief Reads a value from the ADC.
 *
 * This function starts an ADC conversion, waits for it to complete,
 * retrieves the converted value, and then stops the ADC conversion.
 * If any of the steps fail, it returns -1 to indicate an error.
 *
 * @return The digital value read from the ADC, or -1 if an error occurred.
 */
int adc_read(void)
{
    int adc_value = 0;

    if (HAL_ADC_Start(&hadc1) != HAL_OK)
    {
        return -1;
    }

    if (HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) != HAL_OK)
    {
        return -1;
    }

    // Read ADC value
    adc_value = HAL_ADC_GetValue(&hadc1);

    if (HAL_ADC_Stop(&hadc1) != HAL_OK)
    {

        return -1;
    }

    return adc_value;
}
