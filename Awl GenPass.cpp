/*
 * Copyright (c) 2021 Nikita Batnikov <designAwl@bk.ru>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "libs.h"

using namespace std;
typedef unsigned int ull;

void data(char* password) {
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
      SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) |15 ));

      cout << "Ну такое" << endl;

    }

    else if (point >= 150 && point <= 200) {
              SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) |10 ));

      cout << "Сильный" << endl;
    }
    
    else if (point > 200) {
      SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2 ));
      cout << "Вы в безопастности" << endl;
    }
  
}

int main() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  setlocale(0, "");


  cout << "Подготовлено для Softers & Neyton-Devs" << "\n";

  cout << "Менеджер паролей" << "\n";

  string url;
  cout << "Адрес сайта: ";
  cin >> url;

  string login;
  cout << "Логин: ";
  cin >> login;

  ull N;
  cout << "Длина пароля: ";
  cin >> N;

  srand(time(NULL));
 
  char *password = new char[N + 1];
  boost::posix_time::ptime utcCur =
      boost::posix_time::second_clock::local_time();

  for (ull i = 0; i < N; ++i) {
    switch (rand() % 3) {
    case 0:
      password[i] = rand() % 32 + '!';
      break;
    case 1:
      password[i] = rand() % 26 + 'A';
      break;
    case 2:
      password[i] = rand() % 26 + 'a';
    }
  }

  cout << "\n";
  password[N] = 0;
  cout << password << "\n";
  ofstream out("AWL-S Password", ios::app);

  if (out.is_open()) {
    out << utcCur << "\n";
    out << "Website URL: " << url << "\n";
    out << "Login: " << login << "\n";
    out << "Password: " << password << "\n";
    out << login << ":" << password << "\n";
    out << "\n";
  }
  out.close();
  data(password);

  delete[] password;

  SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));

  cout << "\n";
  system("pause");
}
