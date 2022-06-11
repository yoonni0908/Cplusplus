#include "ArrayDataSmart.h"
#include <iostream>
using namespace std;

ArrayDataSmart::ArrayDataSmart()
	:ArrayDataSmart(3) //����Ʈ ������ - �Ȱ��� 3�� ����
{
}

ArrayDataSmart::ArrayDataSmart(ArrayDataSmart& arr) //���� ������
	:ArrayData(arr), usedB(arr.usedB), backdata(make_unique<double[]>(arr.capacity)) //�θ� arr �״�� �ѱ�, ������ �ʱ�ȭ
{                                                                              //capacity ������ ��ŭ �Ҵ�
	cout << "ArrayData ���������" << endl;
	for (size_t i = 0; i < usedB; i++) { //�������� ����
		backdata[i] = arr.backdata[i];
	}
}

ArrayDataSmart::ArrayDataSmart(ArrayDataSmart&& arr) noexcept //�̵� ������
	:ArrayData(move(arr)), usedB(arr.usedB), backdata(move(arr.backdata)) //�̵������� �̹Ƿ� �θ� arr�� move ��Ŵ
{
	cout << "ArrayDataSmart �̵�������" << endl;
}

ArrayDataSmart::ArrayDataSmart(const int& capacity, const int& used) //���ڰ� �ִ� ������
	:ArrayData(capacity, used), usedB(0), backdata(make_unique<double[]>(capacity)) //capacity, used �� �θ𿡼� �Ѱ���
{                                           //backdata�� capacity ��ŭ �ʱ�ȭ ������
	cout << "ArrayDataSmart ������" << endl;
}

ArrayDataSmart::~ArrayDataSmart()
{
	cout << "ArrayDataSmart �Ҹ���" << endl;
}

void ArrayDataSmart::backup() { //��� ���
	if (backdata != nullptr) { //�����Ҵ� ������ �ִٸ�
		usedB = used;
		for (size_t i = 0; i < usedB; i++) {
			backdata[i] = data[i];  //�θ� �ش��ϴ� ���� data, ����� ���� ��ŭ �״�� ���
		}
	}
}

void ArrayDataSmart::restore() //���󺹱�
{
	if (backdata != nullptr) {
		used = usedB; //����� �ݴ�
		for (size_t i = 0; i < usedB; i++) {
			data[i] = backdata[i];
		}
	}
}

ArrayDataSmart& ArrayDataSmart::operator=(const ArrayDataSmart& rhs)
{
	cout << "ArrayDataSmart ���Կ�����" << endl;
	if (this == &rhs) { //���� �� ���� -> �ּҰ��� ����
		return *this; 
	}
	ArrayData::operator=(rhs); //���� x -> �θ� Ŭ���� operatorȣ��
	usedB = rhs.usedB; //������ �ش��ϴ� �� �ʱ�ȭ
	backdata = make_unique<double[]>(rhs.capacity);
	for (size_t i = 0; i < usedB; i++) {
		backdata[i] = rhs.backdata[i]; //��� ������ ����
	}
	return *this;
}

ArrayDataSmart& ArrayDataSmart::operator=(ArrayDataSmart&& rhs) noexcept
{
	cout << "ArrayDataSmart �̵����Կ�����" << endl;
	if (this == &rhs) {
		return *this;
	}
	ArrayData::operator=(move(rhs));
	usedB = rhs.usedB;
	backdata = move(rhs.backdata); //

	return *this;
}
