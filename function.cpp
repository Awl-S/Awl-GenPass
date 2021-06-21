#include "libs.h"

void data(char *password) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  int pass_length = strlen(password);

  int point_upper = 0;
  int point_lower = 0;
  int point_digit = 0;
  int point_symbol = 0;
 
  int point = 0;

  for (int i = 0; i < pass_length; i++) {
    if (password[i] >= 48 && password[i] <= 57) {
      point_digit++;
    } else if (password[i] >= 97 && password[i] <= 125) {
      point_lower++;
    } else if (password[i] >= 65 && password[i] <= 90) {
      point_upper++;
    } else {
      point_symbol++;
    }
  }

  if (point_digit > 0) {
    point += 50;
  }

  if (point_lower > 0) {
    point += 50;
  }

  if (point_upper > 0) {
    point += 50;
  }

  if (point_symbol > 0) {
    point += 50;
  }

  cout << "Анализатор пароля: ";
  if (point_digit > 0 && point_lower > 0 && point_upper > 0 &&
      point_symbol > 0) {
    point += 100;
  }

  if (point <= 50 || pass_length < 8) {
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
    cout << "~Пароль Слабый" << endl;

  }

  else if (point > 50 && point <= 100) {
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

    cout << "Ну такое" << endl;

  }

  else if (point >= 150 && point <= 200) {
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));

    cout << "Сильный" << endl;
  }

  else if (point > 200) {
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
    cout << "Вы в безопастности" << endl;
  }
}
