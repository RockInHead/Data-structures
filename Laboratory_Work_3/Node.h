#include <iostream>
class Node {
public:
	//�������� ������. � ����� ������ �����.
	int data;
	//��������� �� ��������� ������� ������.
	class Node* next;

	//����������� ��� ������������� ���� � �������� ���������.
	Node(int data);
	//����������� �� ���������
	Node();

}; 