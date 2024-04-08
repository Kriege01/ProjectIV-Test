#include "TestFunctions.h"
#include "../ServerTTT/gamelogic.h"
#include "../ServerTTT/server.h"


// Test for win conditions
void TestFunctions::testWinConditions() {
    QVector<QVector<char>> board(3, QVector<char>(3, '.'));
    GameLogic logic(board);

    // Set up a winning condition (e.g., a row)
    board[0] = { 'X', 'X', 'X' };
    QCOMPARE(logic.checkWin(), 1); // Assuming 1 indicates a win
    qDebug() << "Test case testWinConditions passed";
}

// Test for draw condition
void TestFunctions::testDrawCondition() {
    QVector<QVector<char>> board = { {'X', 'O', 'X'}, {'X', 'X', 'O'}, {'O', 'X', 'O'} };
    GameLogic logic(board);

    QCOMPARE(logic.checkWin(), 2); // Assuming 2 indicates a draw
    qDebug() << "Test case testWinConditionsRow passed";
    
}

// Test for game reset functionality
void TestFunctions::testGameReset() {
    QVector<QVector<char>> board(3, QVector<char>(3, 'X')); // Initially fill the board
    GameLogic logic(board);

    int gamesPlayed = 0, turn = 0, win = 0;
    std::unordered_map<int, int> rematch;
    logic.resetGame(gamesPlayed, turn, win, rematch);

    QVERIFY(board[0][0] == '.'); // Check if the board is reset
    QCOMPARE(gamesPlayed, 1); // Check if gamesPlayed is incremented
    qDebug() << "Test case testGameReset passed";
}

void TestFunctions::testWinConditionsRow() {
    QVector<QVector<char>> board = { {'X', 'X', 'X'}, {'.', '.', '.'}, {'.', '.', '.'} };
    GameLogic logic(board);
    QCOMPARE(logic.checkWin(), 1); // Assuming 1 indicates a win
}

void TestFunctions::testWinConditionsColumn() {
    QVector<QVector<char>> board = { {'X', '.', '.'}, {'X', '.', '.'}, {'X', '.', '.'} };
    GameLogic logic(board);
    QCOMPARE(logic.checkWin(), 1); // Assuming 1 indicates a win
}

void TestFunctions::testWinConditionsDiagonal() {
    QVector<QVector<char>> board = { {'X', '.', '.'}, {'.', 'X', '.'}, {'.', '.', 'X'} };
    GameLogic logic(board);
    QCOMPARE(logic.checkWin(), 1); // Assuming 1 indicates a win
}

void TestFunctions::testSetCross() {
    QVector<QVector<char>> board = { {'X', '.', '.'}, {'.', 'X', '.'}, {'.', '.', 'X'} };
    GameLogic logic(board);
    int cross = 0;
    logic.setCross(cross);
    QCOMPARE(cross, 7); // Assuming 7 indicates a winning diagonal
}

void TestFunctions::testCheckWinNoWin() {
    QVector<QVector<char>> board = { {'X', 'O', 'X'}, {'O', '.', 'O'}, {'X', 'X', 'O'} };
    GameLogic logic(board);
    QCOMPARE(logic.checkWin(), 0); // Assuming 0 indicates no win yet
}

void TestFunctions::testSetCrossNoWin() {
    QVector<QVector<char>> board = { {'X', 'O', 'X'}, {'O', '.', 'O'}, {'X', 'X', 'O'} };
    GameLogic logic(board);
    int cross = 0;
    logic.setCross(cross);
    QCOMPARE(cross, 0); // Assuming 0 indicates no winning condition
}

void TestFunctions::testGameResetMultipleGames() {
    QVector<QVector<char>> board(3, QVector<char>(3, 'X')); // Initially fill the board
    GameLogic logic(board);

    int gamesPlayed = 0, turn = 0, win = 0;
    std::unordered_map<int, int> rematch;

    // Play a game
    logic.resetGame(gamesPlayed, turn, win, rematch);

    // Play another game
    logic.resetGame(gamesPlayed, turn, win, rematch);

    QVERIFY(board[0][0] == '.'); // Check if the board is reset
    QCOMPARE(gamesPlayed, 2); // Check if gamesPlayed is incremented
}

void TestFunctions::testCheckWinEmptyBoard() {
    QVector<QVector<char>> board = { {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'} };
    GameLogic logic(board);
    QCOMPARE(logic.checkWin(), 0); // Assuming 0 indicates no win yet
}

