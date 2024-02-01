#include<iostream>
#include<iomanip>
using namespace std;
// определение класса Сomponents 
class Aerflot
{
public:
    short int NumOfFlight;
    string DepartP; //Пункт отправления
    string DestinP; //Пункт назначения
    string DestinT;//Время прибытия
    string DepartT;//Время отправления
    int RegistNum;


    void setFlights(short int NOfF, string DpP, string DsP,
        string DsT, string DpT, int RegNum)
    {
        NumOfFlight = NOfF;
        DepartP = DpP;
        DestinP = DsP;
        DestinT = DsT;
        DepartT = DpT;
        RegistNum = RegNum;
    }


    void showFlights()
    {
        cout << left << setw(15) << NumOfFlight
            << left << setw(20) << DepartP
            << left << setw(20) << DestinP
            << left << setw(15) << DestinT
            << left << setw(15) << DepartT
            << left << setw(15) << RegistNum << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int quanOfFlights;
    cout << "Введите количество рейсов: ";
    cin >> quanOfFlights;

    Aerflot* flights = new Aerflot[quanOfFlights];
    for (int i = 0; i < quanOfFlights; ++i)
    {
        cout << "Введите информацию о рейсе #" << i + 1 << endl;
        cout << "Номер рейса: ";
        cin >> flights[i].NumOfFlight;
        cout << "Пункт отправления: ";
        cin >> flights[i].DepartP;
        cout << "Пункт назначения: ";
        cin >> flights[i].DestinP;
        cout << "Время отправления: ";
        cin >> flights[i].DestinT;
        cout << "Время прибытия: ";
        cin >> flights[i].DepartT;
        cout << "Регистрационный номер: ";
        cin >> flights[i].RegistNum;
    }

    // Сортировка
    for (int i = 0; i < quanOfFlights - 1; ++i)
    {
        for (int j = i + 1; j < quanOfFlights; ++j)
        {
            if (flights[i].DestinP > flights[j].DestinP)
            {
                swap(flights[i], flights[j]);
            }
        }
    }

    // Заголовок таблицы
    cout << left << setw(15) << "Номер рейса "
        << left << setw(20) << "Пункт отправления "
        << left << setw(20) << "Пункт назначения "
        << left << setw(15) << "Время отправления "
        << left << setw(15) << "Время прибытия "
        << left << setw(15) << "Регистрационный номер" << endl;

    // Вывод 
    for (int i = 0; i < quanOfFlights; ++i)
    {
        flights[i].showFlights();
    }

    delete[] flights;

    return 0;
}