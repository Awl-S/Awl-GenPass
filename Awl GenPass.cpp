// Author Nikita Batnikov <designAwl@bk.ru>
#include "libs.h"

int main() {
    setlocale(0, "");

    cout << "Подготовлено для Softers & Neyton-Devs" << "\n";
    cout << "Менеджер паролей" << "\n";

    string url;
    cout << "Адрес сайта: "; cin >> url;

    string login;
    cout << "Логин: "; cin >> login;

    uint32_t N;
    cout << "Длина пароля: ";  cin >> N;

    srand(time(NULL));
    char* password = new  char[N+1];

    for (uint32_t i = 0; i < N; ++i) {
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
    password[N] = 0;

    if (N < 100) {
        cout << password << "\n";
    }
    else
    {
        cout <<"\n" << "А вам оно надо? Пароль сохранился сразу в файл." << "\n";
    }

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

    delete[] password;

    system("pause");
}
