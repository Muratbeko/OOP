#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>

using namespace std;

class Soft {
private:
    string program;
    string developer;
    double size;
    string date;
    chrono::system_clock::time_point licenseDate;

public:
    // Исправленный конструктор с правильным порядком инициализации
    Soft(string prog, string dev, double size, string date, chrono::system_clock::time_point license)
        : program(prog), developer(dev), size(size), date(date), licenseDate(license) {}

    ~Soft() {
        cout << "Информация удалена!" << endl;
    }

    int dayscount() const {
        auto now = chrono::system_clock::now();
        auto duration = chrono::duration_cast<chrono::hours>(licenseDate - now);
        return duration.count() / 24;
    }

    void display() {
        struct tm tm = {};
        sscanf(date.c_str(), "%2d-%2d-%4d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year);
        tm.tm_mon--;
        tm.tm_year -= 1900;
        licenseDate = chrono::system_clock::from_time_t(mktime(&tm));
        cout << "Название программы: " << program << endl;
        cout << "Разработчик: " << developer << endl;
        cout << "Занимаемый объем: " << size << " MB" << endl;
        cout << "Дата завершения лицензии: " << date << endl;
        cout << "Осталось дней: " << dayscount() << endl;
    }
};

int main() {
    string prog;
    string dev;
    double size;
    string date;

    cout << "Введите название программы: ";
    cin >> prog;

    cout << "Введите разработчика: ";
    cin >> dev;

    cout << "Введите занимаемый объем (в MB): ";
    cin >> size;

    cout << "Введите дату завершения лицензии (дд-мм-гггг): ";
    cin >> date;

    Soft soft1(prog, dev, size, date, chrono::system_clock::now());

    soft1.display();

    return 0;
}