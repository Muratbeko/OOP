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
        cout << "Товар удален" << endl;
    }

    double calc() {
        return Price * (1 + RozNas / 100.0);
    }

    void display() {
        cout << "Название товара: " << Product << endl;
        cout << "Оптовая цена: " << Price << " с" << endl;
        cout << "Розничная наценка: " << RozNas << "%" << endl;
        cout << "Количество товаров на складе: " << Quantity << endl;
        cout << "Доход: " << calc() << " с" << endl;
    }
};

int main() {
    string product;
    short int price;
    double roznas;
    int quantity;

    cout << "Введите название товара с пробелами: ";
    getline(cin, product);

    cout << "Введите оптовую цену: ";
    cin >> price;

    cout << "Введите розничную наценку в %: ";
    cin >> roznas;

    cout << "Введите количество товаров: ";
    cin >> quantity;

    if (price <= 0 || roznas <= 0 || quantity <= 0) {
        cout << "Все значения должны быть больше нуля" << endl;
        return 1;
    }

    Nomenclature productObj(product, price, roznas, quantity);

    productObj.display();

    return 0;
}
