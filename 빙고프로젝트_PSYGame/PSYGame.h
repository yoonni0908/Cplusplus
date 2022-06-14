#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
#include <iomanip>

using namespace std;

class PSYGame
{
private:
	int menuNum = 1; //메뉴
	int** UserBoard; //사용자 보드판
	int** PCBoard; //PC 보드판
	int boardSize; //ex)25
	int boardsize; //ex)5
	int x = 8; 
	int y = 2;
	int Gameover = 0; //게임 판정
public:
	PSYGame();
	~PSYGame();
	void play();
private:
	void printMenu();
	void setBoard();
	void loadBoard();
	void printBoard();
	void shuffle(int mNum);
	void checkBoard();
	int bingoCheckCount(int** board);
	int victoryAlgo();
	void setCursorView(bool visible);
	void gameRefree();
	void saveGame();
	void loadData();
	void saveReplay();
	void loadReplay();
	void printReplayBoard();
	void resetReplay();
	void printBingoBoard();
	void saveLastReplay();
};

void gotoxy(int x, int y);
