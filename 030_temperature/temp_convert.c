#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double convertFahrenheitToCelcius(double inputTemp)
{
    double output_temperature = 0.0;
    output_temperature = (inputTemp - 32) * 5 / 9;
    return output_temperature;
}

double convertCelciusToFahrenheit(double inputTemp)
{
    double output_temperature = 0.0;
    output_temperature = (inputTemp * 9 / 5) + 32;
    return output_temperature;
}

double convertKelvinToCelcius(double inputTemp)
{
    double output_temperature = 0.0;
    output_temperature = inputTemp - 273.15;
    return output_temperature;
}

double convertCelciusToKelvin(double inputTemp)
{
    double output_temperature = 0.0;
    output_temperature = inputTemp + 273.15;
    return output_temperature;
}

double convertKelvinToFahrenheit(double inputTemp)
{
    double output_temperature = 0.0;
    double celciusTemp = convertKelvinToCelcius(inputTemp);
    output_temperature = convertCelciusToFahrenheit(celciusTemp);
    return output_temperature;
}

double convertFahrenheitToKelvin(double inputTemp)
{
    double output_temperature = 0.0;
    double celciusTemp = convertFahrenheitToCelcius(inputTemp);
    output_temperature = convertCelciusToKelvin(celciusTemp);
    return output_temperature;
}

bool isInputValid(int index, int argc, char **argv, int *scale)
{
    char *allowedTemperatureScales[][5] = {{"°C", "c", "C", "celsius", "Celsius"}, {"k", "K", "kelvin", "Kelvin", ""}, {"°F", "f", "F", "fahrenheit", "Fahrenheit"}};
    size_t tempScaleArraySize = sizeof(allowedTemperatureScales) / sizeof(allowedTemperatureScales[0]);
    bool isInputCorrect = false;

    for (int i = 0; i < tempScaleArraySize; i++)
    {
        size_t temperatureUnit = sizeof(allowedTemperatureScales[i]) / sizeof(allowedTemperatureScales[i][0]);
        if (!isInputCorrect)
        {
            for (int j = 0; j < temperatureUnit; j++)
            {
                int result = strcmp(argv[index], allowedTemperatureScales[i][j]);
                if (result == 0)
                {
                    isInputCorrect = true;
                    *scale = i + 1;
                    break;
                }
            }
        }
    }
    if (!isInputCorrect)
    {
        printf("temp_convert: error: Unrecognized temperature scale %s\n", argv[index]);
    }
    return isInputCorrect;
}

bool arebothTemparatureScalesValid(int argc, char **argv, int *inputScale, int *outputScale)
{

    bool isFirstInputValid = false;
    bool isSecondInputValid = false;

    isFirstInputValid = isInputValid(1, argc, argv, inputScale);
    isSecondInputValid = isInputValid(2, argc, argv, outputScale);

    return (isFirstInputValid && isSecondInputValid);
}

calculateTemperature(int argc, char **argv, int input_scale, int output_scale)
{
    // celcius = 1, kelvin = 2, fahrenheit = 3

    if (input_scale == 1 && output_scale == 2)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            double input_temperature = atof(argv[input]);
            output_temperature = convertCelciusToKelvin(input_temperature);
            printf("%f\n", output_temperature);
        }
    }
    else if (input_scale == 1 && output_scale == 3)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            double input_temperature = atof(argv[input]);
            output_temperature = convertCelciusToFahrenheit(input_temperature);
            printf("%f\n", output_temperature);
        }
    }
    else if (input_scale == 2 && output_scale == 1)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            double input_temperature = atof(argv[input]);
            output_temperature = convertKelvinToCelcius(input_temperature);
            printf("%f\n", output_temperature);
        }
    }
    else if (input_scale == 2 && output_scale == 3)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            double input_temperature = atof(argv[input]);
            output_temperature = convertKelvinToFahrenheit(input_temperature);
            printf("%f\n", output_temperature);
        }
    }
    else if (input_scale == 3 && output_scale == 1)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            double input_temperature = atof(argv[input]);
            output_temperature = convertFahrenheitToCelcius(input_temperature);
            printf("%f\n", output_temperature);
        }
    }
    else if (input_scale == 3 && output_scale == 2)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            double input_temperature = atof(argv[input]);
            output_temperature = convertFahrenheitToKelvin(input_temperature);
            printf("%f\n", output_temperature);
        }
    }
}

int main(int argc, char *argv[])
{
    int input_scale = 0;
    int output_scale = 0;

    if (argc == 1 || argc == 2)
    {
        puts("temp_convert: error: Not enough arguments.");
        puts("Usage: temp_convert INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]...");
        return EXIT_FAILURE;
    }
    else if (!(arebothTemparatureScalesValid(argc, argv, &input_scale, &output_scale)))
    {
        return EXIT_FAILURE;
    }
    else if (argc == 3)
    {
        puts("");
        return EXIT_SUCCESS;
    }
    else
    {
        calculateTemperature(argc, argv, input_scale, output_scale);
        return EXIT_SUCCESS;
    }
}