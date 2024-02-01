#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

// Класс для представления вагона
class Wagon {
public:
    int type;  // Тип вагона: 0 или 1

    Wagon(int t) : type(t) {}
};

// Класс для моделирования Т-образного сортировочного узла
class SortingNode {
private:
    stack<Wagon> mainTrack;    // Основная дорога
    stack<Wagon> sideTrack;    // Боковая дорога

public:
    // Метод для добавления вагона на основную дорогу
    void addToMainTrack(const Wagon& wagon) {
        mainTrack.push(wagon);
        cout << "Добавлен вагон типа " << wagon.type << " на основную дорогу." << endl;
    }

    // Метод для сортировки вагонов
    void sortWagons() {
        while (!mainTrack.empty()) {
            Wagon currentWagon = mainTrack.top();
            mainTrack.pop();

            if (currentWagon.type == 0) {
                cout << "Вагон типа 0 отправлен на боковую дорогу." << endl;
                sideTrack.push(currentWagon);
            }
            else {
                cout << "Вагон типа 1 отправлен на основную дорогу." << endl;
            }
        }
    }

    // Метод для вывода состояния боковой дороги
    void printSideTrack() {
        cout << "Состояние боковой дороги:" << endl;
        while (!sideTrack.empty()) {
            Wagon currentWagon = sideTrack.top();
            sideTrack.pop();
            cout << "Вагон типа " << currentWagon.type << endl;
        }
    }
};

int main() {
    SortingNode sortingNode;

    int numWagons;
    cout << "Введите количество вагонов: ";
    cin >> numWagons;

    for (int i = 0; i < numWagons; ++i) {
        int wagonType;
        cout << "Введите тип вагона (0 или 1): ";
        cin >> wagonType;

        Wagon wagon(wagonType);
        sortingNode.addToMainTrack(wagon);
    }


    sortingNode.sortWagons();
    sortingNode.printSideTrack();

    return 0;
}