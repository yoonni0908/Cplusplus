#include "PSYGame.h"


namespace PSY {
	void printName() {
		cout << "202014182 박상윤" << endl << endl;
	}
}

PSYGame::PSYGame() :menuNum(1)
{

}

PSYGame::~PSYGame()
{
	//소멸자
	if (UserBoard != nullptr) {
		for (int i = 0; i < boardsize; i++) {
			delete[] UserBoard[i];
		}
		delete[] UserBoard;
	}
	UserBoard = nullptr;

	if (PCBoard != nullptr) {
		for (int i = 0; i < boardsize; i++) {
			delete[] PCBoard[i];
		}
		delete[] PCBoard;
	}
	PCBoard = nullptr;
}

void PSYGame::play() //빙고게임 시작
{
	printMenu();
	switch (this->menuNum) {
	case 1:
		system("cls");
		PSY::printName();
		cout << "\n ex) 보드판의 크기 = 5" << endl;
		cout << "보드판의 크기를 입력해주세요.(3부터 9까지 가능) : ";
		int tempSize;
		cin >> tempSize;
		while (cin.fail() || tempSize < 3 || tempSize > 9) {
			cout << "\n잘못 입력하셨습니다. 다시 입력해주세요.(3에서 9까지 선택 가능)" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "보드판의 크기를 입력해주세요.(3에서 9까지 가능)";
			cin >> tempSize;
		}
		this->boardsize = tempSize;
		this->boardsize = this->boardsize;
		this->boardSize = boardsize * boardsize;

		system("pause");

		setBoard();

		shuffle(menuNum);
		break;
	case 2:
		loadData();
		this->boardsize = this->boardsize;
		this->boardSize = boardsize * boardsize;

		setBoard();

		loadBoard();
		printBoard();
		shuffle(menuNum);
		break;
	case 3:
		break;
	}
}

void PSYGame::printMenu()
{
	int point_y = 5;
	PSY::printName();
	cout << "\n\n빙고 게임\n\n" << endl;
	cout << endl << endl << endl;
	gotoxy(3, 5);
	cout << "1) 새 게임";
	gotoxy(3, 6);
	cout << "2) 이어하기";
	gotoxy(3, 7);
	cout << "3) 종료";
	gotoxy(1, 5);
	cout << "→";
	while (true) {
		if (_kbhit()) {
			int keycode = _getch();
			if (keycode == 224) {
				keycode = _getch();
				switch (keycode) {
				case 72:
				{
					if (point_y > 5) {
						gotoxy(1, point_y);
						cout << "  ";
						menuNum -= 1; point_y -= 1;
					}
					break;
				}
				case 80:
				{
					if (point_y < 7) {
						gotoxy(1, point_y);
						cout << "  ";
						menuNum += 1; point_y += 1;
					}
					break;
				}
				}
				gotoxy(1, point_y);
				cout << "→";
			}
			else if (keycode == 13) {
				break;
			}
		}
	}
}

void PSYGame::setBoard()
{
	//보드판 생성
	if (this->boardSize > 0) {
		this->UserBoard = new int* [boardsize];
		this->PCBoard = new int* [boardsize];
		for (int i = 0; i < boardsize; i++) {
			this->UserBoard[i] = new int[boardsize];
			this->PCBoard[i] = new int[boardsize];
		}
		srand((unsigned int)time(NULL)); //무작위로 숫자 배치하여 보드판 생성
		int* temp = new int[boardSize];
		for (int i = 0; i < boardSize; i++) {
			int RandVal = (rand() % boardSize) + 1; 
			temp[i] = RandVal;
			for (int j = 0; j < i; j++) {
				if (temp[j] == temp[i]) { //중복된 랜덤값이 있으면 빼기
					i--;
					break;
				}
			}
		}
		int count = 0;
		for (int m = 0; m < boardsize; m++) {
			for (int n = 0; n < boardsize; n++) {
				UserBoard[m][n] = temp[count++];
			}
		}

		int* temp1 = new int[boardSize];
		for (int i = 0; i < boardSize; i++) {
			int RandVal = (rand() % boardSize) + 1;
			temp1[i] = RandVal;
			for (int j = 0; j < i; j++) {
				if (temp1[j] == temp1[i]) {
					i--;
					break;
				}
			}
		}
		int count1 = 0;
		for (int m = 0; m < boardsize; m++) {
			for (int n = 0; n < boardsize; n++) {
				PCBoard[m][n] = temp1[count1++];
			}
		}
	}
	else {
		this->UserBoard = nullptr;
		this->PCBoard = nullptr;
	}

	printBoard();
}

void PSYGame::loadBoard() //지난 게임 불러와서 board 초기화
{
	ifstream fin("lastgame.txt");
	if (!fin) {
		cout << "저장된 데이터가 없습니다." << endl;
	}
	fin >> boardsize;

	for (int i = 0; i < this->boardsize; i++) {
		for (int j = 0; j < this->boardsize; j++) {
			fin >> UserBoard[i][j];
		}
	}

	for (int i = 0; i < this->boardsize; i++) {
		for (int j = 0; j < this->boardsize; j++) {
			fin >> PCBoard[i][j];
		}
	}

	fin.close();
}

void PSYGame::printBoard() //보드판 출력
{
	system("cls");
	PSY::printName();
	for (int i = 0; i < boardsize; i++) {
		cout << "\t";
		for (int j = 0; j < boardsize; j++) {
			if (UserBoard[i][j] == 0) {
				cout << setw(2) << "○ ";
			}
			else if (UserBoard[i][j] == -1) {
				cout << setw(2) << "● ";
			}
			else {
				cout << setw(2) << UserBoard[i][j] << " ";
			}
		}
		cout << "\t";

		for (int j = 0; j < boardsize; j++) {
			if (PCBoard[i][j] == 0) {
				cout << setw(2) << "○ ";
			}
			else if (PCBoard[i][j] == -1) {
				cout << setw(2) << "● ";
			}
			else {
				cout << setw(2) << PCBoard[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl << endl;

	if (Gameover == 1) {
		cout << "컴퓨터가 이겼습니다" << endl;
		system("pause");
	}
	else if (Gameover == 2) {
		cout << "사용자가 이겼습니다." << endl;
		system("pause");
	}
	else if (Gameover == 3) {
		cout << "빙고게임에서 비겼습니다" << endl;
	}
	else if (Gameover == 4) { //Q입력해서 종료한 경우
		cout << "++++현황++++" << endl;
	}
	else {
		cout << "==============조작=============" << endl;
		cout << "선택 : Enter" << endl;
		cout << "상하좌우 이동 : 방향키↑↓←→ " << endl;
		cout << "__" << endl;
		cout << "종료 : Q" << endl;
	}
}

void PSYGame::shuffle(int mNum)
{
	if (mNum == 1) {  //새 게임
		resetReplay();
	}
	else if (mNum == 2) { //이어하기
		saveLastReplay();
	}
	gotoxy(x, y);
	setCursorView(true);
	//cout << "__";
	while (true) {
		if (Gameover == 1) { //PC가 이긴경우
			system("cls");
			PSY::printName();
			printBingoBoard();
			loadReplay();
			cout << "\n게임 종료 되었습니다." << endl;
			break;
		}
		else if (Gameover == 2) { //사용자가 이긴 경우
			system("cls");
			PSY::printName();
			printBingoBoard();
			loadReplay();
			cout << "\n게임 종료 되었습니다." << endl;
			break;
		}
		else if (Gameover == 3) { //비긴경우
			system("cls");
			PSY::printName();
			printBingoBoard();
			loadReplay();
			cout << "\n게임 종료 되었습니다." << endl;
			break;
		}
		else if (Gameover == 4) { //도중에 종료한 경우
			cout << "게임 도중에 종료되었습니다" << endl;
			break;
		}
		if (_kbhit()) {
			int keycode = _getch();
			switch (keycode) {
			case 224: //방향키 입력
				keycode = _getch();
				switch (keycode) {
				case 75:
					if (x != 8)
						x -= 3;
					break;
				case 77:
					if (x != 8 + 3 * boardsize - 3)
						x += 3;
					break;
				case 72:
					if (y != 2)
						y -= 1;
					break;
				case 80:
					if (y != 2 + boardsize - 1)
						y += 1;
					break;
				}
				printBoard();
				gotoxy(x, y);
				//cout << "__";
				break;
			case 13: // 엔터키 입력
				checkBoard();
				printBoard();
				gotoxy(x, y);
				saveReplay();
				break;
			case 81: //Q 입력
				this->Gameover = 4;
				system("cls");
				PSY::printName();
				cout << "\n1. 현재까지 저장하고 종료하기" << endl;
				cout << "2. 저장하지 않고 종료하기" << endl;
				int temp2;
				cin >> temp2;
				while (cin.fail() || temp2 < 1 || temp2 > 2) {
					cout << "\n잘못 입력하셨습니다. 다시 입력해주세요(1, 2중에 선택 가능)" << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "\n1. 현재까지 저장하고 종료하기" << endl;
					cout << "2. 저장하지 않고 종료하기" << endl;
					cin >> temp2;
				}
				switch (temp2) {
				case 1:
					saveGame();
					PSY::printName();
					cout << "\n저장 완료" << endl;
					break;
				case 2:
					PSY::printName();
					cout << "\n저장하지 않고 종료합니다." << endl;
					printBingoBoard();
					break;
				}
				system("pause");
				break;
			}
		}
	}

}

void PSYGame::checkBoard()
{

	int checkedRow = (y - 2);
	int checkedCol = (x - 8) / 3;

	if (UserBoard[checkedRow][checkedCol] == 0 || UserBoard[checkedRow][checkedCol] == -1) { //선택된 곳을 또 선택했을 때 
		gotoxy(0, 20);
		cout << "다시" << endl;
		Sleep(1000);
	}
	else {
		for (int i = 0; i < boardsize; i++) { //Userboard가 선택 시
			for (int j = 0; j < boardsize; j++) {
				if (UserBoard[checkedRow][checkedCol] == PCBoard[i][j]) {
					PCBoard[i][j] = 0;
				}
			}
		}
		UserBoard[checkedRow][checkedCol] = 0;
		gameRefree();

		int PCpick = victoryAlgo(); //PC가 알고리즘에 의해 고르는 곳

		for (int i = 0; i < boardsize; i++) {
			for (int j = 0; j < boardsize; j++) {
				if (PCpick == UserBoard[i][j]) {
					UserBoard[i][j] = -1; 
					break;
				}
			}
		}
		gameRefree();
	}
}

int PSYGame::bingoCheckCount(int** board)
{
	int sum = 0;
	for (int i = 0; i < boardsize; i++) { //가로 체크
		int count = 0;
		for (int j = 0; j < boardsize; j++) {
			if (board[i][j] == 0 || board[i][j] == -1) {
				count++;
			}
		}
		if (count == boardsize) {
			sum++;
		}
	}

	for (int i = 0; i < boardsize; i++) { //세로 체크
		int count = 0;
		for (int j = 0; j < boardsize; j++) {
			if (board[j][i] == 0 || board[j][i] == -1) {
				count++;
			}
		}
		if (count == boardsize) {
			sum++;
		}
	}

	int digcount = 0;
	for (int i = 0; i < boardsize; i++) { //대각선 체크
		if (board[i][i] == 0 || board[i][i] == -1) {
			digcount++;
		}
	}
	if (digcount == boardsize) {
		sum++;
	}

	digcount = 0;
	for (int i = 0; i < boardsize; i++) { //아래 대각선 체크
		if (board[i][boardsize - 1 - i] == 0 || board[i][boardsize - 1 - i] == -1) {
			digcount++;
		}
	}
	if (digcount == boardsize) {
		sum++;
	}

	return sum;
}

int PSYGame::victoryAlgo() //컴퓨터 승리를 위한 알고리즘
{
	int* temp = new int[boardsize * 2 + 2];
	int index = 0;

	for (int i = 0; i < boardsize; i++) { // 가로 체크
		int count = 0;
		for (int j = 0; j < boardsize; j++) {
			if (PCBoard[i][j] == 0 || PCBoard[i][j] == -1) {
				count++;
			}
		}
		temp[index++] = count;
	}

	for (int i = 0; i < boardsize; i++) { // 세로 체크
		int count = 0;
		for (int j = 0; j < boardsize; j++) {
			if (PCBoard[j][i] == 0 || PCBoard[j][i] == -1) {
				count++;
			}
		}
		temp[index++] = count;
	}

	int digcount = 0; // 대각선 체크
	for (int i = 0; i < boardsize; i++) {
		if (PCBoard[i][i] == 0 || PCBoard[i][i] == -1) {
			digcount++;
		}
	}
	temp[index++] = digcount;

	digcount = 0; // 아래 대각선 체크
	for (int i = 0; i < boardsize; i++) {
		if (PCBoard[i][boardsize - 1 - i] == 0 || PCBoard[i][boardsize - 1 - i] == -1) {
			digcount++;
		}
	}
	temp[index++] = digcount;

	int maxindex = 0;
	int max = 0;

	for (int i = 0; i < boardsize; i++) {
		if (max <= temp[i] && temp[i] < boardsize) {
			maxindex = i;
			max = temp[i];
		}
	}

	int a = 0;
	if (maxindex / boardsize == 0) { // 가로인 경우
		int n = maxindex % boardsize;
		for (int i = 0; i < boardsize; i++) {
			if (PCBoard[n][i] > 0) {
				a = PCBoard[n][i];
				PCBoard[n][i] = -1;
				return a;
			}
		}
	}
	else if (maxindex / boardsize == 1) { // 세로인 경우
		int n = maxindex % boardsize;
		for (int i = 0; i < boardsize; i++) {
			if (PCBoard[i][n] > 0) {
				a = PCBoard[i][n];
				PCBoard[i][n] = -1;
				return a;
			}
		}
	}
	else { // 대각선인 경우
		if (maxindex % boardsize == 0) {
			for (int i = 0; i < boardsize; i++) {
				if (PCBoard[i][i] > 0) {
					a = PCBoard[i][i];
					PCBoard[i][i] = -1;
					return a;
				}
			}
		}
		else {
			for (int i = 0; i < boardsize; i++) {
				if (PCBoard[i][boardsize - 1 - i] > 0) {
					a = PCBoard[i][boardsize - 1 - i];
					PCBoard[i][boardsize - 1 - i] = -1;
					return a;
				}
			}
		}
	}
	delete[] temp;
}

void PSYGame::setCursorView(bool visible)
{
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void PSYGame::gameRefree() //게임 판정
{
	this->Gameover = 0;
	if (bingoCheckCount(UserBoard) < bingoCheckCount(PCBoard)) {
		this->Gameover = 1;
	}
	else if (bingoCheckCount(UserBoard) > bingoCheckCount(PCBoard)) {
		this->Gameover = 2;
	}
	else if (bingoCheckCount(UserBoard) == bingoCheckCount(PCBoard)) {
		if (bingoCheckCount(UserBoard) == boardsize * 2 + 2) {
			this->Gameover = 3;
		}
		else {
			this->Gameover = 0;
		}
	}
}

void PSYGame::saveGame()
{
	ofstream fout("lastgame.txt"); // 파일열기. 파일쓰기를 위한 스트림 생성
	if (fout.fail()) { //열기 실패할 경우
		cout << "저장 실패" << endl;
	}
	//파일 쓰기
	fout << boardsize << endl;
	for (int i = 0; i < this->boardsize; i++) {
		for (int j = 0; j < this->boardsize; j++) {
			fout << UserBoard[i][j] << ' ';
		}
		fout << "\n";
	}
	for (int i = 0; i < this->boardsize; i++) {
		for (int j = 0; j < this->boardsize; j++) {
			fout << PCBoard[i][j] << ' ';
		}
		fout << "\n";
	}
	fout.close(); //파일 닫기

	//리플레이 저장
	ifstream copyin("replay.txt");
	ofstream copyout("lastreplay.txt");
	copyout << copyin.rdbuf();
	copyout.close();
	copyin.close();
}

void PSYGame::loadData()
{
	//스트림 객체 생성 및 파일 열기
	ifstream fin1("lastgame.txt");
	if (!fin1) { //파일 열기 실패 확인
		cout << "저장된 데이터가 없습니다." << endl;
	}
	fin1 >> this->boardsize; //파일 읽기
	fin1.close(); //파일 읽기를 마치고 파일 닫음
}

void PSYGame::saveReplay()  //리플레이 저장
{
	ofstream rfout("replay.txt", ios::app); //쓰기 모드로 파일 열기
	if (rfout.fail()) {
		cerr << "replay 파일을 찾을 수 없습니다." << endl;
	}
	for (int i = 0; i < this->boardsize; i++) {
		for (int j = 0; j < this->boardsize; j++) {
			rfout << UserBoard[i][j] << ' ';
		}
		rfout << "\n";
	}
	for (int i = 0; i < this->boardsize; i++) {
		for (int j = 0; j < this->boardsize; j++) {
			rfout << PCBoard[i][j] << ' ';
		}
		rfout << "\n";
	}
	rfout.close();
}

void PSYGame::loadReplay() //데이터 불러와서 이어하기
{
	ifstream rfin("replay.txt"); //파일 읽기
	if (rfin.fail()) {
		cerr << "replay 파일을 찾을 수 없습니다." << endl;
	}
	while (!rfin.eof()) {
		for (int i = 0; i < this->boardsize; i++) {
			for (int j = 0; j < this->boardsize; j++) {
				rfin >> UserBoard[i][j];
			}
		}
		for (int i = 0; i < this->boardsize; i++) {
			for (int j = 0; j < this->boardsize; j++) {
				rfin >> PCBoard[i][j];
			}
		}
		printReplayBoard();
	}
	cout << "\nREPLY 끝\n" << endl;
	system("pause");
	rfin.close();
}

void PSYGame::printReplayBoard() //이어하기 기능 제공하여 출력
{
	system("cls");
	PSY::printName();
	cout << "********REPLAY*********" << endl << endl;
	for (int i = 0; i < boardsize; i++) {
		cout << "\t";
		for (int j = 0; j < boardsize; j++) {
			if (UserBoard[i][j] == 0) {
				cout << setw(2) << "○ ";
			}
			else if (UserBoard[i][j] == -1) {
				cout << setw(2) << "● ";
			}
			else {
				cout << setw(2) << UserBoard[i][j] << " ";
			}
		}
		cout << "\t";

		for (int j = 0; j < boardsize; j++) {
			if (PCBoard[i][j] == 0) {
				cout << setw(2) << "○ ";
			}
			else if (PCBoard[i][j] == -1) {
				cout << setw(2) << "● ";
			}
			else {
				cout << setw(2) << PCBoard[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl << endl;

	if (Gameover == 1) {
		cout << "※※※※※※※※LOSE※※※※※※※※" << endl;
	}
	else if (Gameover == 2) {
		cout << "※※※※※※※※※WIN※※※※※※※※" << endl;
	}
	else if (Gameover == 3) {
		cout << "※※※※※※※※※SAME※※※※※※※※" << endl;
	}
	system("pause");
}

void PSYGame::resetReplay() //리플레이 리셋
{
	ofstream resetfout("replay.txt", ios::out); //쓰기 위해 파일을 연다
	if (resetfout.fail()) {
		cerr << "replay 파일을 새로 쓸 수 없습니다." << endl;
	}
	resetfout.close();
}

void PSYGame::printBingoBoard()
{
	printBoard();
	system("pause");
}

void PSYGame::saveLastReplay()
{
	ifstream rcopyin("lastreplay.txt");
	ofstream rcopyout("replay.txt");
	rcopyout << rcopyin.rdbuf();
	rcopyout.close();
	rcopyin.close();
}

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
