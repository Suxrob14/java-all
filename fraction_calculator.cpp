#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct Fraction {
    int numerator;
    int denominator;

    void reduce() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
};

Fraction inputFraction() {
    string frac;
    cin >> frac;
    size_t slashPos = frac.find('/');
    int num = stoi(frac.substr(0, slashPos));
    int den = stoi(frac.substr(slashPos + 1));
    return {num, den};
}

Fraction add(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    result.reduce();
    return result;
}

Fraction subtract(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    result.reduce();
    return result;
}

Fraction multiply(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    result.reduce();
    return result;
}

Fraction divide(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    result.reduce();
    return result;
}

int main() {
    cout << "Введите первую дробь (в формате a/b): ";
    Fraction a = inputFraction();
    cout << "Введите вторую дробь (в формате a/b): ";
    Fraction b = inputFraction();
    cout << "Выберите операцию (+, -, *, /): ";
    char op;
    cin >> op;

    Fraction result;
    if (op == '+') result = add(a, b);
    else if (op == '-') result = subtract(a, b);
    else if (op == '*') result = multiply(a, b);
    else if (op == '/') result = divide(a, b);
    else {
        cout << "Ошибка: неверная операция" << endl;
        return 1;
    }

    cout << "Результат: " << result.numerator << "/" << result.denominator << endl;
    return 0;
}
