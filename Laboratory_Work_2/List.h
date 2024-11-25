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

	void DeleteHead();
	void DeleteTail();

public:
	List();
	int GetHead();
	int GetTail();
	int GetSize();
	int* GetList();
	void AddNodeAtEnd(int data);
	void AddNodeAtStart(int data);
	void DeleteNodeIndex(int data);
	void InsertBefore(int data, int indexOfElement);
	void InsertAfter(int data, int indexOfElement);

};
