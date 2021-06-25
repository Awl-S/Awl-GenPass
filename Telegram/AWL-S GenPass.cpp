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

    cout << "������������ ��� Softers & Neyton-Devs" << "\n";
    cout << "�������� �������" << "\n";

    userData userData;

    cout << "����� �����: "; cin >> userData.url;

    cout << "�����: "; cin >> userData.login;

    cout << "����� ������: ";  cin >> userData.N;

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

    cout << "\n";
    cout << "��������� ������ � Telegram? " << "\n";

    cout << "0 - ���������; " << "\n" << "1 - ��������� �������;" << "\n";

    cout << "������� �����: ";

    int sendTg; cin >> sendTg;
    if (sendTg == 0)
        telegramSend(password, userData.url, userData.login);

    delete[] password;

    system("pause");
}
