#include "libs.h"

void save(int N, char* password, string url, string login) {
    cout << "\n";

    if (N <= 100)
        cout << password << "\n";
    else
        cout << "\n" << "А вам оно надо? Пароль сохранился сразу в файл." << "\n";

    char Path[19] = "AWL-S GenPass.txt";
    boost::posix_time::ptime localTIME = boost::posix_time::second_clock::local_time();

    ofstream save(Path, ios::app);
    if (save.is_open()) {
        save << "\n";
        save << localTIME << "\n";
        save << "Website URL: " << url << "\n";
        save << "Login: " << login << "\n";
        save << "Password: " << password << "\n";
        save << login << ":" << password << "\n";
    }
    save.close();

    cout << "\n";
};

void data(char* password) {

    int pass_length = strlen(password), point_upper = 0, point_lower = 0, point_digit = 0, point_symbol = 0, point = 0;

    for (int i = 0; i < pass_length; i++) {
        if (password[i] >= 48 && password[i] <= 57) 
            point_digit++;
        else if (password[i] >= 97 && password[i] <= 125) 
            point_lower++;
        else if (password[i] >= 65 && password[i] <= 90) 
            point_upper++;
        else 
            point_symbol++;
    }

    if (point_digit > 0)
        point += 50;
   
    if (point_lower > 0) 
        point += 50;

    if (point_upper > 0) 
        point += 50;
   
    if (point_symbol > 0) 
        point += 50;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Анализатор пароля: ";
    if (point_digit > 0 && point_lower > 0 && point_upper > 0 &&
        point_symbol > 0) 
        point += 100;

    if (point <= 50 || pass_length < 8) {
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
        cout << "~Пароль Слабый" << endl;
    }
    else if (point > 50 && point <= 100) {
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
        cout << "~Ну такое" << endl;
    }
    else if (point >= 150 && point <= 200) {
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
        cout << "~Сильный" << endl;
    }
    else if (point > 200) {
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
        cout << "~Вы в безопастности" << endl;
    }

    delete[] password;
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
}
