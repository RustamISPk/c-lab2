//
// Created by rustam on 15.02.25.
//

#include "Person.h"
#include <vector>
#include "Student.h"

using namespace std;

int main() {
    // Person person = Person("Бекмансуров", "Рустам", "Мхадтисович", "ИСПк-201-51-00", "2003-08-11");
    Person per = Person("Бекмансуров", "Рустам", "Мхадтисович", "2003-08-11");
    Student person = Student("Бекмансуров", "Рустам", "Мхадтисович", "ИСПк-201-51-00", "2003-08-11");
    // Student person = Student("Бекмансуров", "Рустам", "ИСПк-201-51-00", "2003-08-11");
    // Person person = Person("Бекмансуров", "Рустам", "2003-08-11");
    vector<string> data = person.getPersonData();
    // Person per = Person();
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == "") {
            continue;
        }
        cout << data[i] << endl;
    }

    person.pushMarks(5);
    person.pushMarks(4);
    vector<int> marks = person.getMarks();
    for (int i = 0; i < marks.size(); ++i) {
        cout << marks[i] << endl;
    }
    string b = "4.1";
    Costyl a = per.lengthName<int>(4);
    cout << a.result << endl;
    cout << person.avgMarks<double>(0, 0) << endl;

    /**
     * @brief Проверка работы функционала
     * @var Student person Объект студента для тестирования
     */
    person.pushAttendance(0, 0, 19);
    int av = person.getAttendance(0, 0);
    cout << "ads " << av << endl;
    return 0;
}
