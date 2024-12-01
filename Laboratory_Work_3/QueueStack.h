#ifndef QUEUESTACK_H
#define QUEUESTACK_H

#include"Stack.h"
#include <iostream>
class QueueStack {
private:

	//���� ����� 1.
	Stack _stack_1 = Stack();

	//���� ����� 2.
	Stack _stack_2 = Stack();

	//����������� ������� �������.
	int _capacity;

	//������ ������� �������.
	int _size;
public:
	//���������� �� ���������.
	QueueStack();

	//�������� ������� �������.
	int* GetQueue();

	////�������� �����.
	//int GetTail();

	////�������� ������.
	//int GetHead();

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