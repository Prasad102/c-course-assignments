#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double convertFahrenheitToCelcius(char inputTemp)
{
    double input_temperature = atof(inputTemp);
    double output_temperature = 0.0;
    output_temperature = (input_temperature - 32) * 5 / 9;
    return output_temperature;
}

double convertCelciusToFahrenheit(char inputTemp)
{
    double input_temperature = atof(inputTemp);
    double output_temperature = 0.0;
    output_temperature = (input_temperature * 9 / 5) + 32;
    return output_temperature;
}

double convertKelvinToCelcius(char inputTemp)
{
    double input_temperature = atof(inputTemp);
    double output_temperature = 0.0;
    output_temperature = input_temperature - 273.15;
    return output_temperature;
}

double convertCelciusToKelvin(char inputTemp)
{
    double input_temperature = atof(inputTemp);
    double output_temperature = 0.0;
    output_temperature = input_temperature + 273.15;
    return output_temperature;
}

double convertKelvinToFahrenheit(char inputTemp)
{
    double input_temperature = atof(inputTemp);
    double output_temperature = 0.0;
    double celciusTemp = convertKelvinToCelcius(input_temperature);
    output_temperature = convertCelciusToFahrenheit(celciusTemp);
    return output_temperature;
}

double convertFahrenheitToKelvin(char inputTemp)
{
    double input_temperature = atof(inputTemp);
    double output_temperature = 0.0;
    double celciusTemp = convertFahrenheitToCelcius(input_temperature);
    output_temperature = convertCelciusToKelvin(celciusTemp);
    return output_temperature;
}

bool isInputValid(int argc, char argv[], char temperatureScalesList[])
{
    size_t tempScaleArraySize = sizeof(temperatureScalesList) / sizeof(temperatureScalesList[0]);
    bool isScaleInTheList = false;
    for (int scaleName = 1; scaleName < 3; scaleName++)
    {
        for (int i = 0; i < tempScaleArraySize; i++)
        {
            int result = strcmp(argv[scaleName], temperatureScalesList[i]);
            if (result == 0)
            {
                isScaleInTheList = true;
                break;
            }
        }

        if (!isScaleInTheList)
        {
            printf("temp_convert: error: Unrecognized temperature scale %s\n", scaleName);
        }
    }
    return isScaleInTheList;
}

calculateTemp(int argc, char argv[])
{
    char celcius = {"°C", "c", "C", "celsius", "Celsius"};
    size_t celciusArraySize = sizeof(celcius) / sizeof(celcius[0]);

    char kelvin = {"k", "K", "kelvin", "Kelvin"};
    size_t kelvinArraySize = sizeof(kelvin) / sizeof(kelvin[0]);

    char fahrenheit = {"°F", "f", "F", "fahrenheit", "Fahrenheit"};
    size_t fahrenheitArraySize = sizeof(fahrenheit) / sizeof(fahrenheit[0]);

    int input_scale = 0;
    int output_scale = 0;

    for (int i = 0; i < celciusArraySize; i++)
    {
        int input = strcmp(argv[1], celcius[i]);
        int output = strcmp(argv[2], celcius[i]);
        if (input == 0)
        {
            input_scale = 1;
        }
        if (output == 0)
        {
            output_scale = 1;
        }
    }

    for (int i = 0; i < kelvinArraySize; i++)
    {
        int input = strcmp(argv[1], kelvin[i]);
        int output = strcmp(argv[2], kelvin[i]);
        if (input == 0)
        {
            input_scale = 2;
        }
        if (output == 0)
        {
            output_scale = 2;
        }
    }

    for (int i = 0; i < fahrenheitArraySize; i++)
    {
        int input = strcmp(argv[1], fahrenheit[i]);
        int output = strcmp(argv[2], fahrenheit[i]);
        if (input == 0)
        {
            input_scale = 3;
        }
        if (output == 0)
        {
            output_scale = 3;
        }
    }

    // celcius = 1, kelvin = 2, fahrenheit = 3

    if (input_scale == 1 && output_scale == 2)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            convertCelciusToKelvin(argv[input]);
            printf("%f\n", output_temperature);
        }
    }
    else if (input_scale == 1 && output_scale == 3)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            convertCelciusToFahrenheit(argv[input]);
            printf("%f\n", output_temperature);
        }
    }
    else if (input_scale == 2 && output_scale == 1)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            convertKelvinToCelcius(argv[input]);
            printf("%f\n", output_temperature);
        }
    }
    else if (input_scale == 2 && output_scale == 3)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            convertKelvinToFahrenheit(argv[input]);
            printf("%f\n", output_temperature);
        }
    }
    else if (input_scale == 3 && output_scale == 1)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            convertFahrenheitToCelcius(argv[input]);
            printf("%f\n", output_temperature);
        }
    }
    else if (input_scale == 3 && output_scale == 2)
    {
        for (int input = 3; input < argc; input++)
        {
            double output_temperature = 0.0;
            convertFahrenheitToKelvin(argv[input]);
            printf("%f\n", output_temperature);
        }
    }
}

int main(int argc, char *argv[])
{
    char allowedTemperatureScales = {"°C", "c", "C", "celsius", "Celsius", "°F", "f", "F", "fahrenheit", "Fahrenheit", "k", "K", "kelvin", "Kelvin"};

    if (argc == 1 || argc == 2)
    {
        puts("temp_convert: error: Not enough arguments.");
        puts("Usage: temp_convert INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]...");
        return EXIT_FAILURE;
    }
    else if (argc == 3)
    {
        puts("");
        return EXIT_SUCCESS;
    }
    else if (!(isInputValid(argc, argv, allowedTemperatureScales)))
    {
        return EXIT_FAILURE;
    }
    else
    {
        calculateTemp(argc, argv);
        return EXIT_SUCCESS;
    }
}