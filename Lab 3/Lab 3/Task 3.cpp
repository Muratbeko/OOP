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
    // ������������ ����������� � ���������� �������� �������������
    Soft(string prog, string dev, double size, string date, chrono::system_clock::time_point license)
        : program(prog), developer(dev), size(size), date(date), licenseDate(license) {}

    ~Soft() {
        cout << "���������� �������!" << endl;
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
        cout << "�������� ���������: " << program << endl;
        cout << "�����������: " << developer << endl;
        cout << "���������� �����: " << size << " MB" << endl;
        cout << "���� ���������� ��������: " << date << endl;
        cout << "�������� ����: " << dayscount() << endl;
    }
};

int main() {
    string prog;
    string dev;
    double size;
    string date;

    cout << "������� �������� ���������: ";
    cin >> prog;

    cout << "������� ������������: ";
    cin >> dev;

    cout << "������� ���������� ����� (� MB): ";
    cin >> size;

    cout << "������� ���� ���������� �������� (��-��-����): ";
    cin >> date;

    Soft soft1(prog, dev, size, date, chrono::system_clock::now());

    soft1.display();

    return 0;
}