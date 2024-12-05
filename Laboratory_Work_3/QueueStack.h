#ifndef QUEUESTACK_H
#define QUEUESTACK_H

#include"Stack.h"
#include <iostream>
class QueueStack {
private:

	//���� ����� 1.
	Stack _stack1;

	//���� ����� 2.
	Stack _stack2;

	//����������� ������� �������.
	int _capacity;

	//������ ������� �������.
	int _size;

public:


	//���������� �� ���������.
	QueueStack();

	//�������� ������� �������.
	int* GetQueueStack();

	////�������� �����.
	//int GetTail();

	////�������� ������.
	//int GetHead();

	//������ ����� ������������ �������.
	int GetCapacity();

	//������ ������� ������ �������.
	int GetSize();

	//���������� �������� � ����� �������.
	void Enqueue(int Data);

	//�������� ������� �������� � �������.
	int Dequeue();

	//������� ��� �������.
	void ClearQueue();

	Stack CopyStack(Stack& inputStack);
};
#endif