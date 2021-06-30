// Author Nikita Batnikov <designAwl@bk.ru>

#pragma once
#include <iostream>
#include <string>
#include <ctime>  
#include <fstream>
#include <Windows.h>
#include <cstdio>

#define BOOST_DATE_TIME_NO_LIB
#include <boost/date_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>

using namespace std;

void save(uint32_t N, char* password, string url, string login);
void data(char* password);
void telegramSend(char* password, string url, string login, uint16_t N);

const char PathTemp[] = "2C0EA.txt";
const char Path[] = "AWL-S GenPass.txt";
const uint16_t limit = {3072};

struct userData
{
public:
    string url;
    string login;
    uint32_t N;
};
