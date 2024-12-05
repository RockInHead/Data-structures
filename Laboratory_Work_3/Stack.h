#ifndef STACK_H
#define STACK_H

#include"Node.h"
#include <iostream>

class Stack {
private:
	//������ �������� �����.
	int _size;

	//��������� �� ������ �����.
	Node* _head;

	//��������� �� ��������� ������� �����.
	Node* _top;

	//������� �������� ������� �����.
	void InitRoot(int Data);
public:
	// ���������� ��������� ������� �����.
	int GetTop();

	// ���������� ������� ������ �����.
	int GetSize() const;

	//���������� ������� ����.
	int* GetStack();

	//����������� �� ���������.
	Stack();

	//�������� ������� � ����� �����.
	void Push(int Data);

	//������� ��������� ������� �����.
	int Pop();

	//�������� ���� ����.
	void ClearStack();

	////������ ����� �������� ����� � ���������� � �������� ��������.
	//static Stack CopyStack(Stack inputStack);

};
#endif
