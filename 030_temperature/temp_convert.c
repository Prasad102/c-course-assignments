#include <stdbool.h>
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

bool isInputValid(int argc, char **argv)
{
    char *allowedTemperatureScales[] = {"°C", "c", "C", "celsius", "Celsius", "°F", "f", "F", "fahrenheit", "Fahrenheit", "k", "K", "kelvin", "Kelvin"};
    size_t tempScaleArraySize = sizeof(allowedTemperatureScales) / sizeof(allowedTemperatureScales[0]);
    bool isFirstInputCorrect = false;
    bool isSecondInputCorrect = false;

    for (int i = 0; i < tempScaleArraySize; i++)
    {
        int resultFirstInput = strcmp(argv[1], allowedTemperatureScales[i]);
        int resultSecondInput = strcmp(argv[2], allowedTemperatureScales[i]);
        if (resultFirstInput == 0)
        {
            isFirstInputCorrect = true;
        }
        if (resultSecondInput == 0)
        {
            isSecondInputCorrect = true;
        }
        if (isFirstInputCorrect && isSecondInputCorrect)
        {
            break;
        }
    }
    if (!isFirstInputCorrect)
    {
        printf("temp_convert: error: Unrecognized temperature scale %s\n", argv[1]);
    }
    if (!isSecondInputCorrect)
    {
        printf("temp_convert: error: Unrecognized temperature scale %s\n", argv[2]);
    }
    return (isFirstInputCorrect && isSecondInputCorrect);
}

calculateTemp(int argc, char **argv)
{
    char *celcius[] = {"°C", "c", "C", "celsius", "Celsius"};
    size_t celciusArraySize = sizeof(celcius) / sizeof(celcius[0]);

    char *kelvin[] = {"k", "K", "kelvin", "Kelvin"};
    size_t kelvinArraySize = sizeof(kelvin) / sizeof(kelvin[0]);

    char *fahrenheit[] = {"°F", "f", "F", "fahrenheit", "Fahrenheit"};
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
    if (argc == 1 || argc == 2)
    {
        puts("temp_convert: error: Not enough arguments.");
        puts("Usage: temp_convert INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]...");
        return EXIT_FAILURE;
    }
    else if (!(isInputValid(argc, argv)))
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
        calculateTemp(argc, argv);
        return EXIT_SUCCESS;
    }
}