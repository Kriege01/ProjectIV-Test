#ifndef TESTFUNCTIONS_H
#define TESTFUNCTIONS_H


#include <QtTest/QtTest>
#include "../ServerTTT/gamelogic.h"
#include "../ServerTTT/server.h"

class TestFunctions : public QObject {
    Q_OBJECT

public:
    TestFunctions() {}

private slots:
      
   
    void testWinConditions();
    void testWinConditionsRow();
    void testWinConditionsColumn();
    void testWinConditionsDiagonal();
    void testDrawCondition();
    void testGameReset();
    void testSetCross();
    void testCheckWinNoWin();
    void testSetCrossNoWin();
    void testGameResetMultipleGames();
    void testCheckWinEmptyBoard();

};


#endif // TESTFUNCTIONS_H