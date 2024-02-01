#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

// ����� ��� ������������� ������
class Wagon {
public:
    int type;  // ��� ������: 0 ��� 1

    Wagon(int t) : type(t) {}
};

// ����� ��� ������������� �-��������� �������������� ����
class SortingNode {
private:
    stack<Wagon> mainTrack;    // �������� ������
    stack<Wagon> sideTrack;    // ������� ������

public:
    // ����� ��� ���������� ������ �� �������� ������
    void addToMainTrack(const Wagon& wagon) {
        mainTrack.push(wagon);
        cout << "�������� ����� ���� " << wagon.type << " �� �������� ������." << endl;
    }

    // ����� ��� ���������� �������
    void sortWagons() {
        while (!mainTrack.empty()) {
            Wagon currentWagon = mainTrack.top();
            mainTrack.pop();

            if (currentWagon.type == 0) {
                cout << "����� ���� 0 ��������� �� ������� ������." << endl;
                sideTrack.push(currentWagon);
            }
            else {
                cout << "����� ���� 1 ��������� �� �������� ������." << endl;
            }
        }
    }

    // ����� ��� ������ ��������� ������� ������
    void printSideTrack() {
        cout << "��������� ������� ������:" << endl;
        while (!sideTrack.empty()) {
            Wagon currentWagon = sideTrack.top();
            sideTrack.pop();
            cout << "����� ���� " << currentWagon.type << endl;
        }
    }
};

int main() {
    SortingNode sortingNode;

    int numWagons;
    cout << "������� ���������� �������: ";
    cin >> numWagons;

    for (int i = 0; i < numWagons; ++i) {
        int wagonType;
        cout << "������� ��� ������ (0 ��� 1): ";
        cin >> wagonType;

        Wagon wagon(wagonType);
        sortingNode.addToMainTrack(wagon);
    }


    sortingNode.sortWagons();
    sortingNode.printSideTrack();

    return 0;
}