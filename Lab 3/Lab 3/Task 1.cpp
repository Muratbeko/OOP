#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Timer {
private:
    int seconds;

public:
    Timer() : seconds(0) {}  
    Timer(int sec) : seconds(sec) {}
    Timer(int min, int sec) : seconds(min * 60 + sec) {}

    void run() {
        clock_t start = clock();
        double duration;
        cout << "Таймер запущен" << endl;

        do {
            clock_t time = clock();
            duration = (time - start) / static_cast<double>(CLOCKS_PER_SEC);
        } while (duration < seconds);

    }

    ~Timer() {
        cout << "Таймер stop" << endl;
    }
};

int main() {
    Timer timer;
    cout << "Выберите формат ввода времени:\n";
    cout << "1. В секундах\n";
    cout << "2. В минутах и секундах\n";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        int sec;
        cout << "Введите время в секундах: ";
        cin >> sec;
        timer = Timer(sec);
        break;
    }
    case 2: {
        int min, sec;
        cout << "Введите минуты и секунды: ";
        cin >> min >> sec;
        timer = Timer(min, sec);
        break;
    }
    default:
        cout << "Error" << endl;
        return 1;
    }

    timer.run();

    return 0;
}
