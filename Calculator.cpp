#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Calculator {
private:
    vector<string> history;

    double performOperation(double a, double b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0) {
                    throw runtime_error("Division by zero!");
                }
                return a / b;
            default:
                throw runtime_error("Invalid operator!");
        }
    }

public:
    void calculate() {
        double num1, num2;
        char op;

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;
        cout << "Enter second number: ";
        cin >> num2;

        try {
            double result = performOperation(num1, num2, op);
            string calc = to_string(num1) + " " + op + " " + to_string(num2) + " = " + to_string(result);
            history.push_back(calc);
            cout << "Result: " << fixed << setprecision(2) << result << endl;
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void showHistory() {
        if (history.empty()) {
            cout << "No calculations in history." << endl;
            return;
        }
        cout << "Calculation History:" << endl;
        for (size_t i = 0; i < history.size(); i++) {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }

    void clearHistory() {
        history.clear();
        cout << "History cleared." << endl;
    }
};

int main() {
    Calculator calc;
    int choice;

    while (true) {
        cout << "\nCalculator Menu:" << endl;
        cout << "1. Perform Calculation" << endl;
        cout << "2. Show History" << endl;
        cout << "3. Clear History" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                calc.calculate();
                break;
            case 2:
                calc.showHistory();
                break;
            case 3:
                calc.clearHistory();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}