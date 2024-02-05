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
    float roznas;
    int quantity;

    cout << "Введите название товара: ";
    cin >> product;

    cout << "Введите оптовую цену: ";
    cin >> price;

    cout << "Введите розничную наценку в %: ";
    cin >> roznas;

    cout << "Введите количество товаров: ";
    cin >> quantity;

    Nomenclature product(product, price, roznas, quantity);

    product.display();

    return 0;
}
