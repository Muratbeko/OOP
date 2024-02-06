#include <iostream>
#include <string>

using namespace std;

class Nomenclature {
private:
    string Product;
    short int Price;
    double RozNas;
    int Quantity;

public:
    Nomenclature(string product, short int price, double roznas, int quantity)
        : Product(product), Price(price), RozNas(roznas), Quantity(quantity) {}

    ~Nomenclature() {
        cout << "����� ������" << endl;
    }

    double calc() {
        return Price * (1 + RozNas / 100.0);
    }

    void display() {
        cout << "�������� ������: " << Product << endl;
        cout << "������� ����: " << Price << " �" << endl;
        cout << "��������� �������: " << RozNas << "%" << endl;
        cout << "���������� ������� �� ������: " << Quantity << endl;
        cout << "�����: " << calc() << " �" << endl;
    }
};

int main() {
    string product;
    short int price;
    double roznas;
    int quantity;

    cout << "������� �������� ������ � ���������: ";
    getline(cin, product);

    cout << "������� ������� ����: ";
    cin >> price;

    cout << "������� ��������� ������� � %: ";
    cin >> roznas;

    cout << "������� ���������� �������: ";
    cin >> quantity;

    if (price <= 0 || roznas <= 0 || quantity <= 0) {
        cout << "��� �������� ������ ���� ������ ����" << endl;
        return 1;
    }

    Nomenclature productObj(product, price, roznas, quantity);

    productObj.display();

    return 0;
}
