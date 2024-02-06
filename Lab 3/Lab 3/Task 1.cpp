#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

class Timer {
private:
    int seconds;

public:
    Timer() : seconds(0) {}
    Timer(int sec) : seconds(sec) {}
    Timer(int min, int sec) : seconds(min * 60 + sec) {}

    void run() {
        time_t startTime = time(NULL);

        cout << "Таймер запущен" << endl;

        while (time(NULL) - startTime < seconds) {
            int remainingTime = seconds - (time(NULL) - startTime);
            cout << "Оставшееся время: " << remainingTime << " секунд" << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }

    ~Timer() {
        cout << "Таймер завершен" << endl;
    }
};

int main() {
    Timer timer;
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
        cout << "Ошибка" << endl;
        return 1;
    }

    timer.run();

    return 0;
}