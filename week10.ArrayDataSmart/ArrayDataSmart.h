#pragma once
#include "ArrayData.h"
class ArrayDataSmart :
    public ArrayData
{
private:
    unique_ptr<double[]> backdata; //������� �������
    int usedB;//��� ��������Ͱ� �ִ��� ���� ����
public:
    ArrayDataSmart(); //����Ʈ ������
    ArrayDataSmart(ArrayDataSmart& arr); // ���� ������
    ArrayDataSmart(ArrayDataSmart&& arr) noexcept; // �̵� ������
    ArrayDataSmart(const int& capacity, const int& used = 0); // ���ڰ� �ִ� ������
    ~ArrayDataSmart(); //�Ҹ���
    void backup();  //����޴� ����� ���� �Լ�
    void restore();  //����޾Ҵ��� ���� ���·� ������ �Լ�
    ArrayDataSmart& operator=(const ArrayDataSmart& rhs);  //���Կ����� �����ε� 
    ArrayDataSmart& operator=(ArrayDataSmart&& rhs) noexcept; //�̵����Կ�����
};

