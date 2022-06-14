#include "PSYGame.h"


namespace PSY {
	void printName() {
		cout << "202014182 �ڻ���" << endl << endl;
	}
}

PSYGame::PSYGame() :menuNum(1)
{

}

PSYGame::~PSYGame()
{
	//�Ҹ���
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

void PSYGame::play() //������� ����
{
	printMenu();
	switch (this->menuNum) {
	case 1:
		system("cls");
		PSY::printName();
		cout << "\n ex) �������� ũ�� = 5" << endl;
		cout << "�������� ũ�⸦ �Է����ּ���.(3���� 9���� ����) : ";
		int tempSize;
		cin >> tempSize;
		while (cin.fail() || tempSize < 3 || tempSize > 9) {
			cout << "\n�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.(3���� 9���� ���� ����)" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�������� ũ�⸦ �Է����ּ���.(3���� 9���� ����)";
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
	cout << "\n\n���� ����\n\n" << endl;
	cout << endl << endl << endl;
	gotoxy(3, 5);
	cout << "1) �� ����";
	gotoxy(3, 6);
	cout << "2) �̾��ϱ�";
	gotoxy(3, 7);
	cout << "3) ����";
	gotoxy(1, 5);
	cout << "��";
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
				cout << "��";
			}
			else if (keycode == 13) {
				break;
			}
		}
	}
}

void PSYGame::setBoard()
{
	//������ ����
	if (this->boardSize > 0) {
		this->UserBoard = new int* [boardsize];
		this->PCBoard = new int* [boardsize];
		for (int i = 0; i < boardsize; i++) {
			this->UserBoard[i] = new int[boardsize];
			this->PCBoard[i] = new int[boardsize];
		}
		srand((unsigned int)time(NULL)); //�������� ���� ��ġ�Ͽ� ������ ����
		int* temp = new int[boardSize];
		for (int i = 0; i < boardSize; i++) {
			int RandVal = (rand() % boardSize) + 1; 
			temp[i] = RandVal;
			for (int j = 0; j < i; j++) {
				if (temp[j] == temp[i]) { //�ߺ��� �������� ������ ����
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

void PSYGame::loadBoard() //���� ���� �ҷ��ͼ� board �ʱ�ȭ
{
	ifstream fin("lastgame.txt");
	if (!fin) {
		cout << "����� �����Ͱ� �����ϴ�." << endl;
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

void PSYGame::printBoard() //������ ���
{
	system("cls");
	PSY::printName();
	for (int i = 0; i < boardsize; i++) {
		cout << "\t";
		for (int j = 0; j < boardsize; j++) {
			if (UserBoard[i][j] == 0) {
				cout << setw(2) << "�� ";
			}
			else if (UserBoard[i][j] == -1) {
				cout << setw(2) << "�� ";
			}
			else {
				cout << setw(2) << UserBoard[i][j] << " ";
			}
		}
		cout << "\t";

		for (int j = 0; j < boardsize; j++) {
			if (PCBoard[i][j] == 0) {
				cout << setw(2) << "�� ";
			}
			else if (PCBoard[i][j] == -1) {
				cout << setw(2) << "�� ";
			}
			else {
				cout << setw(2) << PCBoard[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl << endl;

	if (Gameover == 1) {
		cout << "��ǻ�Ͱ� �̰���ϴ�" << endl;
		system("pause");
	}
	else if (Gameover == 2) {
		cout << "����ڰ� �̰���ϴ�." << endl;
		system("pause");
	}
	else if (Gameover == 3) {
		cout << "������ӿ��� �����ϴ�" << endl;
	}
	else if (Gameover == 4) { //Q�Է��ؼ� ������ ���
		cout << "++++��Ȳ++++" << endl;
	}
	else {
		cout << "==============����=============" << endl;
		cout << "���� : Enter" << endl;
		cout << "�����¿� �̵� : ����Ű����� " << endl;
		cout << "__" << endl;
		cout << "���� : Q" << endl;
	}
}

void PSYGame::shuffle(int mNum)
{
	if (mNum == 1) {  //�� ����
		resetReplay();
	}
	else if (mNum == 2) { //�̾��ϱ�
		saveLastReplay();
	}
	gotoxy(x, y);
	setCursorView(true);
	//cout << "__";
	while (true) {
		if (Gameover == 1) { //PC�� �̱���
			system("cls");
			PSY::printName();
			printBingoBoard();
			loadReplay();
			cout << "\n���� ���� �Ǿ����ϴ�." << endl;
			break;
		}
		else if (Gameover == 2) { //����ڰ� �̱� ���
			system("cls");
			PSY::printName();
			printBingoBoard();
			loadReplay();
			cout << "\n���� ���� �Ǿ����ϴ�." << endl;
			break;
		}
		else if (Gameover == 3) { //�����
			system("cls");
			PSY::printName();
			printBingoBoard();
			loadReplay();
			cout << "\n���� ���� �Ǿ����ϴ�." << endl;
			break;
		}
		else if (Gameover == 4) { //���߿� ������ ���
			cout << "���� ���߿� ����Ǿ����ϴ�" << endl;
			break;
		}
		if (_kbhit()) {
			int keycode = _getch();
			switch (keycode) {
			case 224: //����Ű �Է�
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
			case 13: // ����Ű �Է�
				checkBoard();
				printBoard();
				gotoxy(x, y);
				saveReplay();
				break;
			case 81: //Q �Է�
				this->Gameover = 4;
				system("cls");
				PSY::printName();
				cout << "\n1. ������� �����ϰ� �����ϱ�" << endl;
				cout << "2. �������� �ʰ� �����ϱ�" << endl;
				int temp2;
				cin >> temp2;
				while (cin.fail() || temp2 < 1 || temp2 > 2) {
					cout << "\n�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���(1, 2�߿� ���� ����)" << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "\n1. ������� �����ϰ� �����ϱ�" << endl;
					cout << "2. �������� �ʰ� �����ϱ�" << endl;
					cin >> temp2;
				}
				switch (temp2) {
				case 1:
					saveGame();
					PSY::printName();
					cout << "\n���� �Ϸ�" << endl;
					break;
				case 2:
					PSY::printName();
					cout << "\n�������� �ʰ� �����մϴ�." << endl;
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

	if (UserBoard[checkedRow][checkedCol] == 0 || UserBoard[checkedRow][checkedCol] == -1) { //���õ� ���� �� �������� �� 
		gotoxy(0, 20);
		cout << "�ٽ�" << endl;
		Sleep(1000);
	}
	else {
		for (int i = 0; i < boardsize; i++) { //Userboard�� ���� ��
			for (int j = 0; j < boardsize; j++) {
				if (UserBoard[checkedRow][checkedCol] == PCBoard[i][j]) {
					PCBoard[i][j] = 0;
				}
			}
		}
		UserBoard[checkedRow][checkedCol] = 0;
		gameRefree();

		int PCpick = victoryAlgo(); //PC�� �˰��� ���� ���� ��

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
	for (int i = 0; i < boardsize; i++) { //���� üũ
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

	for (int i = 0; i < boardsize; i++) { //���� üũ
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
	for (int i = 0; i < boardsize; i++) { //�밢�� üũ
		if (board[i][i] == 0 || board[i][i] == -1) {
			digcount++;
		}
	}
	if (digcount == boardsize) {
		sum++;
	}

	digcount = 0;
	for (int i = 0; i < boardsize; i++) { //�Ʒ� �밢�� üũ
		if (board[i][boardsize - 1 - i] == 0 || board[i][boardsize - 1 - i] == -1) {
			digcount++;
		}
	}
	if (digcount == boardsize) {
		sum++;
	}

	return sum;
}

int PSYGame::victoryAlgo() //��ǻ�� �¸��� ���� �˰���
{
	int* temp = new int[boardsize * 2 + 2];
	int index = 0;

	for (int i = 0; i < boardsize; i++) { // ���� üũ
		int count = 0;
		for (int j = 0; j < boardsize; j++) {
			if (PCBoard[i][j] == 0 || PCBoard[i][j] == -1) {
				count++;
			}
		}
		temp[index++] = count;
	}

	for (int i = 0; i < boardsize; i++) { // ���� üũ
		int count = 0;
		for (int j = 0; j < boardsize; j++) {
			if (PCBoard[j][i] == 0 || PCBoard[j][i] == -1) {
				count++;
			}
		}
		temp[index++] = count;
	}

	int digcount = 0; // �밢�� üũ
	for (int i = 0; i < boardsize; i++) {
		if (PCBoard[i][i] == 0 || PCBoard[i][i] == -1) {
			digcount++;
		}
	}
	temp[index++] = digcount;

	digcount = 0; // �Ʒ� �밢�� üũ
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
	if (maxindex / boardsize == 0) { // ������ ���
		int n = maxindex % boardsize;
		for (int i = 0; i < boardsize; i++) {
			if (PCBoard[n][i] > 0) {
				a = PCBoard[n][i];
				PCBoard[n][i] = -1;
				return a;
			}
		}
	}
	else if (maxindex / boardsize == 1) { // ������ ���
		int n = maxindex % boardsize;
		for (int i = 0; i < boardsize; i++) {
			if (PCBoard[i][n] > 0) {
				a = PCBoard[i][n];
				PCBoard[i][n] = -1;
				return a;
			}
		}
	}
	else { // �밢���� ���
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

void PSYGame::gameRefree() //���� ����
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
	ofstream fout("lastgame.txt"); // ���Ͽ���. ���Ͼ��⸦ ���� ��Ʈ�� ����
	if (fout.fail()) { //���� ������ ���
		cout << "���� ����" << endl;
	}
	//���� ����
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
	fout.close(); //���� �ݱ�

	//���÷��� ����
	ifstream copyin("replay.txt");
	ofstream copyout("lastreplay.txt");
	copyout << copyin.rdbuf();
	copyout.close();
	copyin.close();
}

void PSYGame::loadData()
{
	//��Ʈ�� ��ü ���� �� ���� ����
	ifstream fin1("lastgame.txt");
	if (!fin1) { //���� ���� ���� Ȯ��
		cout << "����� �����Ͱ� �����ϴ�." << endl;
	}
	fin1 >> this->boardsize; //���� �б�
	fin1.close(); //���� �б⸦ ��ġ�� ���� ����
}

void PSYGame::saveReplay()  //���÷��� ����
{
	ofstream rfout("replay.txt", ios::app); //���� ���� ���� ����
	if (rfout.fail()) {
		cerr << "replay ������ ã�� �� �����ϴ�." << endl;
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

void PSYGame::loadReplay() //������ �ҷ��ͼ� �̾��ϱ�
{
	ifstream rfin("replay.txt"); //���� �б�
	if (rfin.fail()) {
		cerr << "replay ������ ã�� �� �����ϴ�." << endl;
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
	cout << "\nREPLY ��\n" << endl;
	system("pause");
	rfin.close();
}

void PSYGame::printReplayBoard() //�̾��ϱ� ��� �����Ͽ� ���
{
	system("cls");
	PSY::printName();
	cout << "********REPLAY*********" << endl << endl;
	for (int i = 0; i < boardsize; i++) {
		cout << "\t";
		for (int j = 0; j < boardsize; j++) {
			if (UserBoard[i][j] == 0) {
				cout << setw(2) << "�� ";
			}
			else if (UserBoard[i][j] == -1) {
				cout << setw(2) << "�� ";
			}
			else {
				cout << setw(2) << UserBoard[i][j] << " ";
			}
		}
		cout << "\t";

		for (int j = 0; j < boardsize; j++) {
			if (PCBoard[i][j] == 0) {
				cout << setw(2) << "�� ";
			}
			else if (PCBoard[i][j] == -1) {
				cout << setw(2) << "�� ";
			}
			else {
				cout << setw(2) << PCBoard[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl << endl;

	if (Gameover == 1) {
		cout << "�ءءءءءءء�LOSE�ءءءءءءء�" << endl;
	}
	else if (Gameover == 2) {
		cout << "�ءءءءءءءء�WIN�ءءءءءءء�" << endl;
	}
	else if (Gameover == 3) {
		cout << "�ءءءءءءءء�SAME�ءءءءءءء�" << endl;
	}
	system("pause");
}

void PSYGame::resetReplay() //���÷��� ����
{
	ofstream resetfout("replay.txt", ios::out); //���� ���� ������ ����
	if (resetfout.fail()) {
		cerr << "replay ������ ���� �� �� �����ϴ�." << endl;
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
