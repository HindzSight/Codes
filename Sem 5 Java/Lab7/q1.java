class InvalidOperatorException extends Exception {
    public InvalidOperatorException(String message) {
        super(message);
    }
}

class DivisionByZeroException extends Exception {
    public DivisionByZeroException(String message) {
        super(message);
    }
}

class Calculator {
    public static int calculate(int num1, int num2, String operator) 
            throws InvalidOperatorException, DivisionByZeroException {
        int result = 0;
        switch (operator) {
            case "+":
                result = num1 + num2;
                break;
            case "-":
                result = num1 - num2;
                break;
            case "*":
                result = num1 * num2;
                break;
            case "/":
                if (num2 == 0) {
                    throw new DivisionByZeroException("Division By zero, you sure you wanna do that?");
                }
                result = num1 / num2;
                break;
            default:
                throw new InvalidOperatorException("Operator not found in calculator " + operator);
        }
        return result;
    }
}

public class q1 {
    public static void main(String[] args) {
        try {
            int num1 = 12312;
            int num2 = 132;
            String operator = "+";
            
            int result = Calculator.calculate(num1, num2, operator);
            System.out.println("Result: " + result);
            
            
            operator = "#";
            result = Calculator.calculate(num1, num2, operator);
        } catch (InvalidOperatorException e) {
            System.out.println("Error Occured: " + e.getMessage());
        } catch (DivisionByZeroException e) {
            System.out.println("Error Occured: " + e.getMessage());
        }
    }
}
