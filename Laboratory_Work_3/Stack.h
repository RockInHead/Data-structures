#include"Node.h"
#include <iostream>

class Stack {
private:
	//������ �������� ������
	int _size;

	//��������� �� ��������� ������� �����.
	Node* _top;

	//������� �������� ������� �����.
	void InitRoot(int data);
public:
	// ���������� ������� ������ �����.
	int GetSize();

	//���������� ������� ����.
	int* GetStack();

	//����������� �� ���������.
	Stack();

	//�������� ������� � ����� �����.
	void Push(int data);

	//������� ��������� ������� �����.
	void Pop();

	//�������� ���� ����.
	void ClearStack();


};

