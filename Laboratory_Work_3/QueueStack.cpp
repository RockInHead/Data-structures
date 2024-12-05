#include"QueueStack.h"
#include <iostream>

using namespace std;

//����������� �� ���������.
QueueStack::QueueStack():_stack1(), _stack2(), _size(0),_capacity(10) {}

//������ ����� ������������ �������.
int QueueStack::GetCapacity() {
	return _capacity;
}

//������ ������� ������ �������.
int QueueStack::GetSize() {
	return _size;
}

//���������� �������� � ����� �������.
void QueueStack::Enqueue(int Data) {
	_stack1.Push(Data);
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
	while (_size != 0) {
		Dequeue();
	}
}

//�������� ������� �������.
int* QueueStack::GetQueueStack() {
	Stack resStack;
	Stack copiedStack1;
	Stack copiedStack2;
	Stack reverseStack1;

	copiedStack1 = CopyStack(_stack1);
	while (copiedStack1.GetSize() != 0) {
		reverseStack1.Push(copiedStack1.Pop());
	}

	copiedStack2 = CopyStack(_stack2);
	while (copiedStack2.GetSize() != 0) {
		resStack.Push(copiedStack2.Pop());
	}

	while (reverseStack1.GetSize() != 0) {
		resStack.Push(reverseStack1.Pop());
	}

	return resStack.GetStack();

}

//������ ����� �������� ����� � ���������� � �������� ��������.
Stack QueueStack::CopyStack(Stack& inputStack) {
	Stack tempStack;
	Stack copiedStack;

	while (inputStack.GetSize() != 0) {
		int value = inputStack.Pop();
		tempStack.Push(value); // �������� �������� �� ��������� ����
	}

	while (tempStack.GetSize() != 0) {
		int value = tempStack.Pop();
		inputStack.Push(value); // ��������������� ��������
		copiedStack.Push(value); // �������� � �����
	}
	return copiedStack;
}

