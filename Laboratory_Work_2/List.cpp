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
int List::GetTail() {
	if (_tail != nullptr){
		return _tail->data;
}
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

	if ( _size > 1)
	{
		_tail = newNode;
	}
	

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
	_tail = _head->next;
	_size++;
}
//������� �������� �������� �� �������.
void List::DeleteNodeIndex(int deletedIndex) 
{
	//���� "������" ����������.
	if (_head != nullptr) {
		//���� ������� ������.
		if (deletedIndex == 0) {
			_head = _head->next;
			if (_head != nullptr) {
				_head->prev = nullptr;
			}
			_size--;
			return;
		}
		if (deletedIndex == _size - 1) {
			_tail = _tail->prev;
			_tail->next = nullptr;
			_size--;
			return;
		}
		Node* temp;
		if (deletedIndex < _size / 2) {
			temp = _head;
			for (int i = 0; temp != nullptr && i < deletedIndex; i++) {
				temp = temp->next;
			}
			if (temp != nullptr) {
				if (temp->next != nullptr) {
					temp->next->prev = temp->prev;
				}
				else if (temp->next == nullptr) {
					_tail = temp->prev;
				}
				if (temp->prev != nullptr) {
					temp->prev->next = temp->next;
				}
				delete temp;
				_size--;
			}
		}
		else if(deletedIndex >= _size / 2) {
			temp = _tail;
			for (int i = _size-1; temp != nullptr && i > deletedIndex; i--) {
				temp = temp->prev;
			}
			if (temp != nullptr) {
				if (temp->next != nullptr) {
					temp->next->prev = temp->prev;
				}
				else if (temp->next == nullptr) {
					_tail = temp->prev;
				}
				if (temp->prev != nullptr) {
					temp->prev->next = temp->next;
				}
				delete temp;
				_size--;
			}
		}

		/*if (temp != nullptr) {
			if (temp->next != nullptr) {
				temp->next->prev = temp->prev;
			}
			else if (temp->next == nullptr) {
				_tail = temp->prev;
			}
			if (temp->prev != nullptr) {
				temp->prev->next = temp->next;
			}
			delete temp;
			_size--;
		}*/
	}
}


