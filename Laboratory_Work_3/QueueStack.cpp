#include"QueueStack.h"
#include <iostream>

using namespace std;
QueueStack::QueueStack():_stack1(), _stack2(), _size(0),_capacity(10) {

	//_stack2= Stack();
 //   _stack1 = Stack();
}


int QueueStack::GetCapacity() {
	return _capacity;
}
int QueueStack::GetSize() {
	return _size;
}

//���������� �������� � ����� �������.
void QueueStack::Enqueue(int Data) {

	_stack1.Push(Data);
	/*int value = _stack1.Pop();*/
	_size++;
}

//�������� ������� �������� � �������.
int QueueStack::Dequeue() {
	if (_size != 0) {
		if (_stack2.GetSize() == 0) {
			while (_stack1.GetSize() != 0) {
				_stack2.Push(_stack1.Pop());
			}
		}
		_size--;
	}
	return _stack2.Pop();

}

//������� ��� �������.
void QueueStack::ClearQueue() {

}

int* QueueStack::GetQueueStack() {
	Stack resStack = Stack();
	/*static Stack reversStack1;
	Stack tempStack1 = _stack1;
	Stack tempStack2 = _stack2;

	
	while (tempStack2.GetSize() != 0) {
		resStack.Push(tempStack2.Pop());
	}*/

	
	
	Stack copiedStack1;
	Stack copiedStack2;
	Stack tempStack1; // ��������� ���� ��� ����������� ���������
	Stack tempStack2; // ��������� ���� ��� ����������� ���������


	while (_stack1.GetSize()!=0) {
		int value = _stack1.Pop();
		tempStack1.Push(value); // �������� �������� �� ��������� ����
		copiedStack1.Push(value);
	}

	while (_stack2.GetSize() != 0) {
		int value = _stack2.Pop();
		tempStack2.Push(value); // �������� �������� �� ��������� ����
	}

	// ��������������� �������� � _stack1 � copiedStack
	while (tempStack1.GetSize()!= 0) {
		int value = tempStack1.Pop();
		_stack1.Push(value); // ��������������� ��������
		//copiedStack1.Push(value); // �������� � �����
	}

	// ��������������� �������� � _stack1 � copiedStack
	while (tempStack2.GetSize() != 0) {
		int value = tempStack2.Pop();
		_stack2.Push(value); // ��������������� ��������
		copiedStack2.Push(value); // �������� � �����
	}

	while (copiedStack2.GetSize() != 0) {
		resStack.Push(copiedStack2.Pop());
	}

	int size = copiedStack1.GetSize();

	for (int i = 0; i < size; i++) {
		resStack.Push(copiedStack1.Pop());
	}

	return resStack.GetStack();

}
