#include <iostream>
#include "TV.h"
#include "Vegetable.h"
#include "Customer2.h"

using namespace std;

int main() {

	Customer2 greenjoa("ȫ�浿", 5);
	greenjoa.buy(make_unique<TV>("�Ǳ�TV", 100, 20));
	greenjoa.buy(make_unique<TV>("����TV", 200, 40));
	greenjoa.buy(make_unique<Vegetable>("�ñ�ġ", 50, "����", 5));
	greenjoa.buy(make_unique<TV>("����TV", 100, 15));
	//greenjoa.showlist();
	greenjoa.showTVlist(); //���ϴ� ������ ã�Ƽ� �� �� ����
	cout << endl;
	greenjoa.showVegetablelist();

}