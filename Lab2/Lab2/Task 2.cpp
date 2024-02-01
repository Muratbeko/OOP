#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Student
{
public:
    string Surname;
    string Name;
    string DateOfBirth;
    string PhoneNumber;

    void setStudent(string SN, string N, string DB, string PN)
    {
        Surname = SN;
        Name = N;
        DateOfBirth = DB;
        PhoneNumber = PN;
    }

    void showStudent() const
    {
        cout << left << setw(20) << Surname
            << left << setw(15) << Name
            << left << setw(20) << DateOfBirth
            << left << setw(15) << PhoneNumber << endl;
    }
};

class StudentGroup
{
private:
    const int maxSize = 100;
    Student students[100];
    int numberOfStudents;

public:
    StudentGroup() : numberOfStudents(0) {}

    void addStudent(const Student& newStudent)
    {
        if (numberOfStudents < maxSize)
        {
            students[numberOfStudents++] = newStudent;
        }
        else
        {
            cout << "Группа полна, невозможно добавить нового студента." << endl;
        }
    }

    void removeStudent(const string& surname)
    {
        Student* it = nullptr;

        for (Student* i = students; i != students + numberOfStudents; ++i)
        {
            if (i->Surname == surname)
            {
                it = i;
                break;
            }
        }

        if (it != nullptr)
        {
            *it = students[--numberOfStudents];
        }
        else
        {
            cout << "Студент с фамилией " << surname << " не найден." << endl;
        }
    }

    Student findStudentBySurname(const string& surname) const
    {
        const Student* it = nullptr;

        for (const Student* i = students; i != students + numberOfStudents; ++i)
        {
            if (i->Surname == surname)
            {
                it = i;
                break;
            }
        }

        if (it != nullptr)
        {
            return *it;
        }
        else
        {
            return Student{};
        }
    }

    void sortStudentsBySurname()
    {
        sort(students, students + numberOfStudents,
            [](const Student& a, const Student& b) {
                return a.Surname < b.Surname;
            });
    }

    void displayAllStudents() const
    {
        cout << left << setw(20) << "Фамилия"
            << left << setw(15) << "Имя"
            << left << setw(20) << "Дата рождения "
            << left << setw(15) << " Номер телефона" << endl;

        for (int i = 0; i < numberOfStudents; ++i)
        {
            students[i].showStudent();
        }
    }
};

void printMenu()
{
    cout << "Меню:" << endl;
    cout << "1. Добавить студента" << endl;
    cout << "2. Удалить студента" << endl;
    cout << "3. Поиск студента по фамилии" << endl;
    cout << "4. Сортировка студентов по фамилии" << endl;
    cout << "5. Показать всех студентов" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите действие: ";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    StudentGroup group;

    while (true)
    {
        printMenu();

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Введите информацию о студенте:" << endl;
            string surname, name, dateOfBirth, phoneNumber;
            cout << "Фамилия: ";
            cin >> surname;
            cout << "Имя: ";
            cin >> name;
            cout << "Дата рождения: ";
            cin >> dateOfBirth;
            cout << "Номер телефона: ";
            cin >> phoneNumber;

            Student newStudent;
            newStudent.setStudent(surname, name, dateOfBirth, phoneNumber);
            group.addStudent(newStudent);
            break;
        }
        case 2:
        {
            cout << "Введите фамилию студента для удаления: ";
            string surname;
            cin >> surname;
            group.removeStudent(surname);
            break;
        }
        case 3:
        {
            cout << "Введите фамилию студента для поиска: ";
            string surname;
            cin >> surname;

            Student foundStudent = group.findStudentBySurname(surname);
            if (!foundStudent.Surname.empty())
            {
                cout << "\nНайден студент:\n";
                foundStudent.showStudent();
            }
            else
            {
                cout << "Студент с фамилией " << surname << " не найден." << endl;
            }
            break;
        }
        case 4:
            group.sortStudentsBySurname();
            cout << "Студенты отсортированы по фамилии." << endl;
            break;
        case 5:
            group.displayAllStudents();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            return 0;
        default:
            cout << "Некорректный ввод. Попробуйте снова." << endl;
            break;
        }
    }

    return 0;
}
