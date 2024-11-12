#include "../include/functions.h"
#include "../include/structures.h"
#include <iostream>
#include <string>
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const Speciality& speciality) {
  switch (speciality) {
    case INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES: os << "INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES"; break;
    case MATHEMATICS: os << "MATHEMATICS"; break;
    case PEDAGOGY: os << "PEDAGOGY"; break;
  }
  return os;
}

std::istream& operator>>(std::istream& is, Speciality& speciality) {
  int value;
  is >> value;
  speciality = static_cast<Speciality>(value);
  return is;
}

using namespace std;

void Create(Student *s, const int N)
{
  int speciality;

  for (int i = 0; i < N; i++)
  {
    cout << "Студент № " << i + 1 << ":" << endl;
    cin.get();
    cin.sync();
    cout << " прізвище: "; getline(cin, s[i].surname);
    cout << " курс: "; cin >> s[i].studying_year;
    cout << " спеціальність: "; cin >> speciality;
    s[i].speciality = (Speciality)speciality;
    cout << " оцінка з фізики: "; cin >> s[i].physics_mark;
    cout << " оцінка з математики: "; cin >> s[i].maths_mark;
    cout << " оцінка з предмету спеціальності(";

    switch (s[i].speciality) {
      case INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES:
        cout << "програмування): "; cin >> s[i].SpecialityGrade.programming_mark;

      break;

      case MATHEMATICS:
        cout << "чисельні методи): "; cin >> s[i].SpecialityGrade.numerical_methods_mark;
      break;

      case PEDAGOGY:
        cout << "педагогіка): "; cin >> s[i].SpecialityGrade.pedagogy_mark;
      break;
    }

    cout << endl;
  }
}

void Print(Student *s, const int N) {
  cout << "===================================================================================================================================================================\n";
  cout << "|   № | Прізвище     | Курс  | Спеціальність                           | Оц(Фізика) | Оц(Математика) | Оц(Програмування) | Оц(Чисельні методи) | Оц(Педагогіка)   |\n";
  cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
  for (int i = 0; i < N; i++) {
    cout << "| " << setw(3) << right << i + 1 << " ";
    cout << "| " << setw(22) << left << s[i].surname
         << " | " << setw(4) << right << s[i].studying_year << " "
         << " | " << setw(40) << left << s[i].speciality
         << "| " << setw(10) << right << s[i].physics_mark << " "
         << "| " << setw(14) << right << s[i].maths_mark << " "
         << "| " << setw(17) << right << (s[i].speciality == INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES ? to_string(s[i].SpecialityGrade.programming_mark) : "-") << " "
         << "| " << setw(19) << right << (s[i].speciality == MATHEMATICS ? to_string(s[i].SpecialityGrade.numerical_methods_mark) : "-") << " "
         << "| " << setw(17) << right << (s[i].speciality == PEDAGOGY ? to_string(s[i].SpecialityGrade.pedagogy_mark) : "-") << "|"
         << endl;
  }
  cout << "===================================================================================================================================================================\n";
}

int Count(Student *s, const int N) {
  int count = 0;

  for (int i = 0; i < N; i++) {
    if (s[i].physics_mark == 5)
      count++;
    if (s[i].maths_mark == 5)
      count++;

    if (s[i].speciality == INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES && s[i].SpecialityGrade.programming_mark == 5)
      count++;
    else if (s[i].speciality == MATHEMATICS && s[i].SpecialityGrade.numerical_methods_mark == 5)
      count++;
    else if (s[i].speciality == PEDAGOGY && s[i].SpecialityGrade.pedagogy_mark == 5)
      count++;
  }

  return count;
}

int CountStudents(Student *s, const int N) {
  int count = 0;

  for (int i = 0; i < N; i++) {
    if (s[i].physics_mark == 5 && s[i].maths_mark == 5)
      count++;
  }

  return count;
}