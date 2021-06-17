﻿/*
 * Copyright (c) 2021 Batnikov Nikita <designAwl@bk.ru>
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
#define BOOST_DATE_TIME_NO_LIB
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;

int main()
{
	setlocale(0, "");
	uint64_t N;
	cout << "Генератор паролей" << "\n";
	char Path[9] = "pass.txt";
	string url;  cout << "Адрес сайта: "; cin >> url;
	string login;  cout << "Логин: "; cin >> login;
	cout << "Длина пароля: "; cin >> N;
	srand(time(NULL));
	char* pass = new char[N + 1];
	boost::posix_time::ptime utcCur = boost::posix_time::second_clock::local_time();



	for (uint64_t i = 0; i < N; ++i)
	{
		switch (rand() % 3)
		{
		case 0:
			pass[i] = rand() % 32 + '!';
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';

		}
	}

	pass[N] = 0;
	cout << pass << "\n";


	ofstream out(Path, ios::app);
	if (out.is_open())
	{
		out << utcCur << "\n";
		out << "Website URL: " << url << "\n";
		out << "Login: " << login << "\n";
		out << "Password: " << pass << "\n";
		out << "\n";

	}

	out.close();
	system("pause");
}