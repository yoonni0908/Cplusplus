#include "PSYGame.h"
#include <crtdbg.h>
using namespace std;

//�޸� ���� üũ
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int main() {
	//�޸� ���� üũ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PSYGame yoonni;
	yoonni.play(); //���� �÷���


	return 0;
}