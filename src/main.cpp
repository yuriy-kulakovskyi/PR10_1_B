#include "../include/functions.h"
#include "../include/structures.h"
#include <iostream>

using namespace std;

int main() {
  int N;

  cout << "Введіть N: "; cin >> N;

  Student *s = new Student[N];

  Create(s, N);
  Print(s, N);

  cout << "Кількість оцінок \"відмінно\" = " << Count(s, N) << endl;
  cout << "Кількість учнів, котрі отримали \"відмінно\" з математики та фізики = " << CountStudents(s, N) << endl;

  return 0;
}