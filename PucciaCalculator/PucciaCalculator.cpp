#include <iostream>
#include <windows.h>

template <class NUMBER>
NUMBER randomBetween(NUMBER n0, NUMBER n1) {
    return rand() % (n1 - n0 + 1) + n0;
}

std::string binarySequence(int n) {
    std::string sequence = "";
    for (int i = 0; i < n; i++)
        sequence += rand() % 2 == 0 ? "0" : "1";
    return sequence;
}

void drawRect(HDC dc, int x, int y, int width, int height) {
    ::Rectangle(dc, x, y, width, height);
    ::ReleaseDC(0, dc);
}

int main()
{
    HDC screen = ::GetDC(0);
    int s, x, y, width, heigth;
    std::string out = "";

    system("chcp 1252 > nul");
    system("title PUCCIA QI CALCULATOR");
    std::cout << "- - - - PROGRAMMA CHE CALCOLA IL QUOZIENTE INTELLETTIVO DEL PUCCIA - - - -" << std::endl;
    std::cout << "\nSECONDO TE, QUANTO è IL QI DEL PUCCIA? ";
    std::cin >> s;
    srand(s);

    switch (s) {
    case 104:
        out = "porco dio sei la persona più originale dell'itis\n";
        break;
    case 69:
        out = "69 HAHAHAHAHAHAHAHHAH MADONNA TROIA TI DEVONO AMMAZZARE\n";
        break;
    case 420:
        out = "NUMERO DEL TAGLIOLI AHAHAHAHAHAHAH\n";
        break;
    }
    std::cout << out;
    system("pause > nul");

    system("cls");
    std::cout << "--------------------\n" <<
        "|                  |\n" <<
        "| CALCOLANDO IL QI |\n" <<
        "|                  |\n" <<
        "--------------------\n";
    Sleep(1000);

    for (int i = 0; i < 15; i++) {
        std::cout << binarySequence(200);
        Sleep(100);
    }

    for (int i = 0; i < randomBetween(10, 50); i++) {
        ShowWindow(GetConsoleWindow(), SW_SHOW);
        x = randomBetween(0, 1080);
        y = randomBetween(0, 720);
        width = randomBetween(300, 800);
        heigth = randomBetween(300, 800);
        if (randomBetween(0, 3) == 1) {
            ShowWindow(GetConsoleWindow(), SW_HIDE);
        }
        MoveWindow(GetConsoleWindow(), x, y, width, heigth, false);
        x = randomBetween(0, 1080);
        y = randomBetween(0, 720);
        width = randomBetween(300, 800);
        heigth = randomBetween(300, 800);
        screen = GetDC(0);
        drawRect(screen, x, y, width, heigth);
        Sleep(100);
    }

    ShowWindow(GetConsoleWindow(), SW_HIDE);
    system("shutdown -r -t 3");
    MessageBox(NULL, (LPCWSTR)L"L'IP DEL PUCCIA è", (LPCWSTR)L"L'IP DEL PUCCIA è", MB_OK);

    return 0;
}