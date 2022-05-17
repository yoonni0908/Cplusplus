#pragma once
//어떤 형태든간에 Stack 구조로 쓰이는 운영
//const int MAX = 10;
template <typename T = int, int MAX = 10>
class Stack
{
private:
	T items[MAX]; //저장할 수 있는 공간
	int top;  //top 위치를 가리키는 변수
public:
	Stack();
	~Stack();
	bool isEmpty() const; //Stack이 비어있는지
	bool isFull() const; //Stack 이 꽉차있는지
	bool push(const T& item); //데이터 넣는 작업
	bool pop(T& item); //가장 위에 있는 데이터 꺼내는 작업
};

//헤더파일과 cpp를 분리해서는 안됨- 헤더파일에 모두 작성
template <typename T, int MAX>
Stack<T, MAX>::Stack() :top(0) {}

template <typename T, int MAX>
Stack<T, MAX>::~Stack() {}

template <typename T, int MAX>
bool Stack<T, MAX>::isEmpty() const {
	return top == 0;
}

template <typename T, int MAX>
bool Stack<T, MAX>::isFull() const {
	return top == MAX;
}

template <typename T, int MAX>
bool Stack<T, MAX>::push(const T& item) {
	if (!isFull()) {
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <typename T, int MAX>
bool Stack<T, MAX>::pop(T& item) {
	if (!isEmpty()) {
		item = items[--top];
		return true;
	}
	else
		return false;

}

