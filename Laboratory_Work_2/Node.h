#include <iostream>
class Node {
public:
	//�������� ������. � ����� ������ �����.
	int data;
	//��������� �� ��������� ������� ������.
	struct Node* next;
	//��������� �� ���������� ������� ������.
	struct Node* prev;
	//����������� ��� ������������� ���� � �������� ���������.
	Node(int data);

	Node();

};