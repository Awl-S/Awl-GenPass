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


#include <iostream>
#include <fstream>
#include <ctime> 
#include <Windows.h>
#define BOOST_DATE_TIME_NO_LIB
#include <boost/date_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>

using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(0, "");
    uint64_t N;

    cout << "Подготовлено для Softers & Neyton-Devs" << "\n";
    SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | 15));
    system("color F0");

    cout << "Генератор паролей" << "\n";
    char Path[16] = "Awl GenPass.txt";
    string url;  cout << "Адрес сайта: "; cin >> url;
    string login;  cout << "Логин: "; cin >> login;
    cout << "Длина пароля: "; cin >> N;

    srand(time(NULL));
    char* password = new char[N + 1];
    boost::posix_time::ptime utcCur = boost::posix_time::second_clock::local_time();



    for (uint64_t i = 0; i < N; ++i)
    {
        switch (rand() % 3)
        {
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
    ofstream out(Path, ios::app);
    if (out.is_open())
    {
        out << utcCur << "\n";
        out << "Website URL: " << url << "\n";
        out << "Login: " << login << "\n";
        out << "Password: " << password << "\n";
        out << login << ":" << password << "\n";
        out << "\n";
    }

    out.close();
    cout << "\n";
    system("pause");
}
