#include"Node.h"
#include <iostream>
class List {
private:
	//������ �������� ������
	int _size;
	//��������� �� ������ ������.
	Node* _head;
	//��������� �� ����� ������.
	Node* _tail;

	void InitRoot(int data);
public:
	List();
	void GetList();
	void AddNodeAtEnd(int data);
};
