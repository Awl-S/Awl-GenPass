#pragma once
#include <iostream>
#include <string>
#include <ctime>  
#include <random> 
#include <fstream>
#include <Windows.h>

#define BOOST_DATE_TIME_NO_LIB
#include <boost/date_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>

using namespace std;

void save(int N, char* password, string url, string login);
void data(char* password);
