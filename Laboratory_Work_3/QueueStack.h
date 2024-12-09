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

	//������ ����� �������� ����� � ���������� � �������� ��������.
	Stack CopyStack(Stack& inputStack);

public:

	//���������� �� ���������.
	QueueStack();

	//�������� ������� �������.
	int* GetQueueStack();

	//������ ����� ������������ �������.
	int GetCapacity();

	//������ ������� ������ �������.
	int GetSize();

	//���������� �������� � ����� �������.
	void Enqueue(int data);

	//�������� ������� �������� � �������.
	int Dequeue();

	//������� ��� �������.
	void ClearQueue();

};
#endif