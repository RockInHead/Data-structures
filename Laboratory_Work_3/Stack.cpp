#include"Stack.h"
#include <iostream>

using namespace std;

//������ �������� ������
int _size;

//��������� �� ��������� ������� �����.
Node* _top;
//����������� �� ��������� ��� ������
Stack::Stack() :_size(0), _top(nullptr) {}

int Stack::GetTop() {
	if (_top != nullptr) {
		return _top->data;
	}
	return 0;
}

int Stack::GetSize() {
	return _size;
}

void Stack::InitRoot(int data) {
	_head = new Node(data);
	_top = _head;
	_size++;
}

//���������� ������� ������
int* Stack::GetStack() {
	int sizeOfStack = _size;
	int* stack = new int[sizeOfStack];
	int index = 0;
	if (_head != nullptr) {
		Node* temp = _head;
		do{
			stack[index] = temp->data;
			temp = temp->next;
			index++;
		} while (temp != nullptr); // ������� ��������� ������
	}
	return stack;
	delete[] stack;

}
//�������� ������� � ����� �����.
void Stack::Push(int data) {
	if (_size == 0) {
		InitRoot(data);
		return;
	}
	Node* newNode = new Node(data);

	Node* temp = _head;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = newNode;
	_top = newNode;
	_size++;
}

//������� ��������� ������� �����.
void Stack::Pop() 
{
	if (_size != 0) {
		if (_size == 1) {
			_head = nullptr;
			_top = nullptr;
			_size--;
			return;
		}
		Node* temp = _head;
		while (temp->next->next) {
			temp = temp->next;
		}
		temp->next = nullptr;
		_top = temp;
		_size--;
		
	}
}