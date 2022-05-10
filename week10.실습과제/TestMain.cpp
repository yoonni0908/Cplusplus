#include "GeneralTicket.h"
#include "AdvancedTicket.h"
#include "TicketManager2.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "202014182 박상윤" << endl;
	TicketManager2 manager("아이유콘서트", 10);

	manager.buy(make_unique<GeneralTicket>(3200, true));
	manager.buy(new AdvancedTicket(1000, 40));
	manager.buy(new AdvancedTicket(1500, 30));
	manager.buy(new AdvancedTicket(2000, 25));
	manager.buy(new AdvancedTicket(1000, 5));
	manager.buy(new GeneralTicket(2000, true));
	manager.buy(new GeneralTicket(1500, false));

	cout << manager << endl;

	manager.showGeneralTicket(true);
	manager.showGeneralTicket(false);
	manager.showAdvancedTicket();

}