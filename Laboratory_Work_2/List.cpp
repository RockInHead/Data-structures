#include"List.h"
#include <iostream>
using namespace std;
//������ �������� ������
int _size;
//��������� �� ������ ������.
Node* _head;
//��������� �� ����� ������.
Node* _tail;
void List::InitRoot(int data) {
	Node* root = new Node();
	_head = root;
	// ��������� ������ ��� ������ ������

	_head->data = data;
	_head->next = nullptr; // ��������� �� ��������� ����
	_head->prev = nullptr; // ��������� �� ���������� ����
	_size++;
}
List::List():_size(0),_head(nullptr),_tail(nullptr) {

}
//���������� ������ �������� ������.
int List::GetSize() {

	return _size;
}
int* List::GetList() {
	int sizeOfArray = GetSize();
	int* array= new int[sizeOfArray];
	int index = 0;
	if (_head != nullptr) {
		Node* p = _head;
		do {
			/*cout << p->data << endl; */
			array[index] = p->data;
			p = p->next;
			index++;
		} while (p != nullptr); // ������� ��������� ������
		
	}
	return array;
	//Node* p = _head;
	//do {
	//	cout << p->data << endl; // ����� �������� �������� p
	//	p = p->next; // ������� � ���������� ����
	//} while (p != nullptr); // ������� ��������� ������
}
//������� ���������� �������� � ����� �������.
void List::AddNodeAtEnd(int data)
{
	//������� ����� �������, � ��������� data
	Node* newNode = new Node(data);

	//���������, ������� �� "������" �������, ���� ���, �������
	if (_head == nullptr) 
	{
		InitRoot(data);
		return;
	}
	
	Node* temp = _head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;
	_size++;
	/*_tail = newNode;*/
}
void List::AddNodeAtStart(int data) {
	Node* newNode = new Node(data);
	//���������, ������� �� "������" �������, ���� ���, �������
	if (_head == nullptr)
	{
		InitRoot(data);
		return;
	}

	newNode->next = _head;
	_head->prev = newNode;
	_head = newNode;
	_size++;
}
void List::DeleteNodeIndex(int deletedIndex) {

}


