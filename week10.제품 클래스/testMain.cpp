#include <iostream>
#include "TV.h"
#include "Vegetable.h"
//#include "Customer.h"
#include "Customer2.h"

using namespace std;

int main() {
	
	/*Product item1("�Ǳ�TV", 100);
	item1.show();

	TV item2("�Ǳ�TV", 100, 20);
	item2.show();

	Vegetable item3("�ñ�ġ", 10, "����", 5);
	item3.show();*/

	/*Customer greenjoa("ȫ�浿", 5);
	greenjoa.buy(new TV("�Ǳ�TV", 100, 20));
	greenjoa.buy(new TV("����TV", 200, 40));
	greenjoa.buy(new Vegetable("�ñ�ġ", 50, "����", 5));
	greenjoa.buy(new TV("����TV", 100, 15));
	greenjoa.showlist();*/

	Customer2 greenjoa("ȫ�浿", 5);
	greenjoa.buy(make_unique<TV>("�Ǳ�TV", 100, 20));
	greenjoa.buy(make_unique<TV>("����TV", 200, 40));
	greenjoa.buy(make_unique<Vegetable>("�ñ�ġ", 50, "����", 5));
	greenjoa.buy(make_unique<TV>("����TV", 100, 15));
	greenjoa.showlist();

}