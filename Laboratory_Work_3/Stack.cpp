#include"Stack.h"
#include <iostream>

using namespace std;

//������ �������� ������
int _size;

//��������� �� ��������� ������� �����.
Node* _top;
//����������� �� ��������� ��� ������
Stack::Stack() :_size(0), _top(nullptr) {}

int Stack::GetSize() {
	return _size;
}

void Stack::InitRoot(int data) {
	_top = new Node(data);
	_size++;
}

//���������� ������� ������
int* Stack::GetStack() {
	int sizeOfStack = _size;
	int* stack = new int[sizeOfStack];
	int index = 0;
	if (_top != nullptr) {
		Node* temp = _top;
		do {
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
	Node* temp = _top;

	temp->next = newNode;
	_top = newNode;
	/*newNode = _top;*/
	/*newNode->next = newNode;
	_top = newNode;*/
	/*_top->next = newNode;
	_top = newNode;*/
	_size++;
}

//������� ��������� ������� �����.
void Stack::Pop() {

}