#include <iostream>
struct Node {
public:
	//�������� ������. � ����� ������ �����.
	int Data;
	//��������� �� ��������� ������� ������.
	struct Node* Next;
	//��������� �� ���������� ������� ������.
	struct Node* Prev;
	//����������� ��� ������������� ���� � �������� ���������.
	Node(int Data);

	Node();

};