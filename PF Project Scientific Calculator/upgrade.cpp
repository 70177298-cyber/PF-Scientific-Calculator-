#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstring> 
using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "~ Division by zero! ~\n";
        return 0;
    }
}
int mod(int a, int b) { 
if (b != 0) {
        return a % b;
    } else {
        cout << "~Invalid! Division by zero not possible! ~\n";
        return 0;
    }
return a % b; }

double log_custom(double x) { return log(x); }
double square(double x) { return x * x; }
double cube(double x) { return x * x * x; }
double power(double base, double exp) { return pow(base, exp); }
double square_root(double x) { return sqrt(x); }
double factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
double antilog(double x) { return pow(10, x); }

double to_radians(double degrees) { return degrees * M_PI / 180.0; }
double calculate_sin(double x) { return sin(to_radians(x)); }
double calculate_cos(double x) { return cos(to_radians(x)); }
double calculate_tan(double x) {
    if (fmod(fabs(x), 180.0) == 90.0) {
        cout << "~ Tangent undefined at " << x << " degrees ~\n";
        return 0;
    }
    return tan(to_radians(x));
}

double coth(double x) {
    double tanh_x = tanh(x);
    if (tanh_x == 0) {
        cout << "~ Coth undefined at x = " << x << " ~\n";
        return 0;
    }
    return 1 / tanh_x;
}

double sinh_custom(double x) { return sinh(x); }
double cosh_custom(double x) { return cosh(x); }
double tanh_custom(double x) { return tanh(x); }

double perform_operation(char op, double num1, double num2 = 0) {
    switch (op) {
        case '+': return add(num1, num2);
        case '-': return subtract(num1, num2);
        case '*': return multiply(num1, num2);
        case '/': return divide(num1, num2);
        case 'm': return mod((int)num1, (int)num2);
        case 'L': return log_custom(num1);
        case 'S': return square(num1);
        case 'C': return cube(num1);
        case 'p': return power(num1, num2);
        case 'r': return square_root(num1);
        case 's': return calculate_sin(num1);
        case 'c': return calculate_cos(num1);
        case 't': return calculate_tan(num1);
        case 'D': return sin(to_radians(num1));
        case '!': return factorial((int)num1);
        case 'e': return pow(M_E, num1);
        case 'E': return exp(num1);
        case 'A': return antilog(num1);
        case 'h': return ceil(num1);
        case 'H': return sinh_custom(num1);
        case 'I': return cosh_custom(num1);
        case 'O': return tanh_custom(num1);
        case 'T': return coth(num1);
        default:
            setColor(12);
            cout << "~ Invalid input! ~\n";
            setColor(15);
            return 0;
    }
}

void show_calculator() {
    setColor(11);
    cout << "\t\t==============================================\n";
    setColor(14);
    cout << "\t\t             SCIENTIFIC CALCULATOR            \n";
    setColor(11);
    cout << "\t\t==============================================\n";
    setColor(10);
    cout <<
        "\t\t|   +    |   -    |   *    |   /    |   m    |\n"
        "\t\t|  Add   |  Sub   |  Mul   |  Div   |  Mod   |\n";
    cout << "\t\t==============================================\n";
    cout <<
        "\t\t|   L    |   S    |   C    |   p    |   r    |\n"
        "\t\t|  Log   | Square |  Cube  | Power  | Sqrt   |\n";
    cout <<"\t\t==============================================\n";

    cout <<
        "\t\t|   s    |   c    |   t    |   D    |   !    |\n"
        "\t\t|  sin   |  cos   |  tan   |  Deg   | Fact   |\n";
    cout << "\t\t==============================================\n";

    cout <<
        "\t\t|   e    |   E    |   h    |   T    |   A    |\n"
        "\t\t|  e^x   | exp()  |  ceil  | Coth   |Antilog |\n";
    cout << "\t\t==============================================\n";

    cout <<
        "\t\t|   H    |   I    |   O    |   k    |   .    |\n"
        "\t\t| sinh   |  cosh  |  tanh  | Clear  | Exit   |\n";
    setColor(11);
    cout << "\t\t==============================================\n";

    cout <<
        "\t\t|   1    |   2    |   3    |   4    |   5    |\n";
    cout << "\t\t==============================================\n";
    cout <<
        "\t\t|   6    |   7    |   8    |   9    |   0    |\n";
    cout << "\t\t==============================================\n";
    setColor(15);
}

void display_output(double answer) {
    setColor(13);
    cout << "\t\t------------- Current Result: " << answer << " -------------\n";
    setColor(15);
}

int main() {
    double num1 = 0.0, num2 = 0.0, answer = 0.0;
    char inp = '\0';
    bool converter = false;

    while (inp != '.') {
        if (converter) {
            display_output(answer);
            show_calculator();
            cout << "Enter Operation: ";
            cin >> inp;

           
            if (inp == 'k') {
                num1 = num2 = answer = 0.0;
                converter = false;
                system("cls");
                setColor(10);
                cout << "--- Calculator Cleared ---"<<endl;
                setColor(15);
                system("pause");
                system("cls");
                continue;
            }

            if (inp == '.') break;

            if (strchr("+-*/mp", inp)) {
                num1 = answer;
                cout << "Enter num 2: ";
                cin >> num2;
            } else {
                num1 = answer;
            }
        } else {
            show_calculator();
            cout << "Enter Operation: ";
            cin >> inp;

            if (inp == 'k') {
                num1 = num2 = answer = 0.0;
                converter = false;
                system("cls");
                setColor(10);
                cout << "--- Calculator Cleared ---\n";
                setColor(15);
                system("pause");
                system("cls");
                continue;
            }

            if (inp == '.') break;

            if (strchr("+-*/mp", inp)) {
                cout << "Enter num 1: ";
                cin >> num1;
                cout << "Enter num 2: ";
                cin >> num2;
            } else {
                cout << "Enter num 1: ";
                cin >> num1;
            }

            converter = true;
        }

        if (inp != '.' && inp != 'k') {
            answer = perform_operation(inp, num1, num2);
        }

        system("pause");
        system("cls");
    }

    setColor(10);
    cout << "\t\t---- Thanks For Using the Calculator ----\n";
    setColor(14);
    cout << "\t\tMubashar Mehboob:70178060\n";
    cout << "\t\tNouman Ali     :70177191\n";
    cout << "\t\tFaraz Ahmad    :70177298\n";
    cout << "\t\tShahwaiz Sheraz:70177352\n";
    setColor(15);
    return 0;
}