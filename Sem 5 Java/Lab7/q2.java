class InvalidTemperatureException extends Exception {
    public InvalidTemperatureException(String message) {
        super(message);
    }
}

class TemperatureConverter {
    public static double fahrenheitToCelsius(double fahrenheit) throws InvalidTemperatureException {
        if (fahrenheit < -459.67) {
            throw new InvalidTemperatureException("Temps below 0K(Absolute zero) does not exist!");
        }
        return (fahrenheit - 32) * 5.0 / 9.0;
    }

    public static double celsiusToFahrenheit(double celsius) throws InvalidTemperatureException {
        if (celsius < -273.15) {
            throw new InvalidTemperatureException("Temps below 0K(Absolute zero) does not exist!");
        }
        return celsius * 9.0 / 5.0 + 32;
    }
}

public class q2 {
    public static void main(String[] args) {
        try {
            double fahrenheit = 212; 
            double celsius = TemperatureConverter.fahrenheitToCelsius(fahrenheit);
            System.out.println(fahrenheit + " F = " + celsius + " C.");

            double celsiusValue = -72; 
            double fahrenheitValue = TemperatureConverter.celsiusToFahrenheit(celsiusValue);
            System.out.println(celsiusValue + " C = " + fahrenheitValue + " F.");

            double invalidTemperature = -496; 
            celsius = TemperatureConverter.fahrenheitToCelsius(invalidTemperature);
        } catch (InvalidTemperatureException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}