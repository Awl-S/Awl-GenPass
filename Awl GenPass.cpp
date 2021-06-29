// Author Nikita Batnikov <designAwl@bk.ru>
#include "libs.h"

struct userData
{
public:
    string url;
    string login;
    uint32_t N;
};

int main() {
    setlocale(0, "");

    system("title AWL-S Password manager");
    setlocale(0, "");

    cout << "Менеджер паролей от AWL-S \t \t https://github.com/Awl-S" << "\n";
    userData userData;

    cout << "Адрес сайта: "; cin >> userData.url;
    cout << "Логин: "; cin >> userData.login;
    cout << "Длина пароля: ";  cin >> userData.N;

    srand(time(NULL));
    char* password = new  char[userData.N + 1];

    for (uint32_t i = 0; i < userData.N; ++i) {
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
    password[userData.N] = 0;

    save(userData.N, password, userData.url, userData.login);

    data(password);

    delete[] password;
    system("pause");
}
