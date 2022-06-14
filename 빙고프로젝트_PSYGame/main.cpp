#include "PSYGame.h"
#include <crtdbg.h>
using namespace std;

//메모리 누수 체크
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int main() {
	//메모리 누수 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PSYGame yoonni;
	yoonni.play(); //게임 플레이


	return 0;
}