#ifndef NODE_H
#define NODE_H

#include <iostream>
struct Node {
public:
	//�������� ������. � ����� ������ �����.
	int Data;

	//��������� �� ��������� ������� ������.
	Node* Next;

	//����������� ��� ������������� ���� � �������� ���������.
	Node(int data);

	//����������� �� ���������
	Node();

}; 
#endif
