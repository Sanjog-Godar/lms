#include <iostream>
using namespace std;

float CelsiusToFahrenheit(float celsius)
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

float FahrenheitToCelsius(float fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float CelsiusToKelvin(float celsius)
{
    return celsius + 273.15;
}

float KelvinToCelsius(float kelvin)
{
    return kelvin - 273.15;
}

int main()
{
    int choice;
    float temperature, convertedTemperature;

    cout << "Temperature Converter" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "3. Celsius to Kelvin" << endl;
    cout << "4. Kelvin to Celsius" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    cout << "Enter the temperature: ";
    cin >> temperature;

    switch (choice)
    {
    case 1:
        convertedTemperature = CelsiusToFahrenheit(temperature);
        break;
    case 2:
        convertedTemperature = FahrenheitToCelsius(temperature);
        break;
    case 3:
        convertedTemperature = CelsiusToKelvin(temperature);
        break;
    case 4:
        convertedTemperature = KelvinToCelsius(temperature);
        break;
    default:
        cout << "Invalid choice." << endl;
        return 1;
    }

    cout << "Converted Temperature: " << convertedTemperature << endl;

    return 0;
}
