#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int secret = rand() % 100 + 1;
    int guess;
    int tries = 0;

    cout << "Я загадал число от 1 до 100. Попробуй угадать!\n";

    do {
        cout << "Твоя догадка: ";
        cin >> guess;
        tries++;

        if (guess < secret)
            cout << "Загаданное число больше.\n";
        else if (guess > secret)
            cout << "Загаданное число меньше.\n";
        else
            cout << "Поздравляю! Ты угадал за " << tries << " попыток.\n";

    } while (guess != secret);

    return 0;
}
