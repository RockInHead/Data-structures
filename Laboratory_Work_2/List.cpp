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

}
List::List():_size(0),_head(nullptr),_tail(nullptr) {

}
void List::GetList() {
	Node* p = _head;
	do {
		cout << p->data << endl; // ����� �������� �������� p
		p = p->next; // ������� � ���������� ����
	} while (p != nullptr); // ������� ��������� ������
}
void List::AddNodeAtEnd(int data)
{
	Node* newNode = new Node(data);

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

	
}




