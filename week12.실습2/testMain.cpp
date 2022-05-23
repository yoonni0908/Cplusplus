#include <iostream>
#include "TV.h"
#include "Vegetable.h"
#include "Customer2.h"

using namespace std;

int main() {

	Customer2 greenjoa("홍길동", 5);
	greenjoa.buy(make_unique<TV>("건국TV", 100, 20));
	greenjoa.buy(make_unique<TV>("대학TV", 200, 40));
	greenjoa.buy(make_unique<Vegetable>("시금치", 50, "남해", 5));
	greenjoa.buy(make_unique<TV>("세종TV", 100, 15));
	//greenjoa.showlist();
	greenjoa.showTVlist(); //원하는 정보만 찾아서 볼 수 있음
	cout << endl;
	greenjoa.showVegetablelist();

}