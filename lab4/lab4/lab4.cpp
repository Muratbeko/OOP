#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Tatra;

class Kamaz {
private:
    string name;
    int speed;

public:
    Kamaz(string n, int s) {
        name = n;
        speed = s;
    }
    friend int FrCreater(Kamaz& k, Tatra& t);
};

class Tatra {
private:
    string name;
    int speed;

public:
    Tatra(string n, int s) {
        name = n;
        speed = s;
    }
    friend int FrCreater(Kamaz& k, Tatra& t);
};

int FrCreater(Kamaz& k, Tatra& t) {
    if (k.speed > t.speed) return 1;
    else if (k.speed == t.speed) return 0;
    else return -1;
}

int main() {
    string kamazName, tatraName;
    int kamazSpeed, tatraSpeed;

    cout << "Enter Kamaz name: ";
    cin >> kamazName;
    cout << "Enter Kamaz speed: ";
    cin >> kamazSpeed;

    cout << "Enter Tatra name: ";
    cin >> tatraName;
    cout << "Enter Tatra speed: ";
    cin >> tatraSpeed;

    Kamaz kamaz(kamazName, kamazSpeed);
    Tatra tatra(tatraName, tatraSpeed);

    cout << setw(7) << left << "Name:" << setw(10) << right << "Speed:" << endl;
    cout << setw(7) << left << kamazName << setw(10) << right << kamazSpeed << endl;
    cout << setw(7) << left << tatraName << setw(10) << right << tatraSpeed << endl;

    int result = FrCreater(kamaz, tatra);
    if (result == 1) {
        cout << "Kamaz is faster" << endl;
    }
    else if (result == 0) {
        cout << "Speeds are equal" << endl;
    }
    else {
        cout << "Tatra is faster" << endl;
    }

    return 0;
}