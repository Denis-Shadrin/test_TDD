#include <QCoreApplication>
#include <QTest>
#include "game.h"
#include <clocale>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS 1

#include "card_test.h"
#include "player_test.h"
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "PL_pl.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);


    QCoreApplication a(argc, argv);
    srand(time(0));

    QTest::qExec(new Card_test, argc, argv);
    QTest::qExec(new Player_test, argc, argv);


    Game game;
    game.StartGame();

    return a.exec();
}
