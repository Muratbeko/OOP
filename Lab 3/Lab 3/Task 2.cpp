#include <iostream>
#include <string>

using namespace std;

class Nomenclature {
private:
    string Product;
    short int Price;
    float RozNas;
    int Quantity;

public:
    Nomenclature(string product, short int price, float roznas, int quantity)
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
    float roznas;
    int quantity;

    cout << "������� �������� ������: ";
    cin >> product;

    cout << "������� ������� ����: ";
    cin >> price;

    cout << "������� ��������� ������� � %: ";
    cin >> roznas;

    cout << "������� ���������� �������: ";
    cin >> quantity;

    Nomenclature product(product, price, roznas, quantity);

    product.display();

    return 0;
}
