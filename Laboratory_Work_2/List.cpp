#include"List.h"
#include <iostream>
#include <chrono>

using namespace std;
//������ �������� ������
int _size;

//��������� �� ������ ������.
Node* _head;

//��������� �� ����� ������.
Node* _tail;

//�������������� ������ ������.
void List::InitRoot(int data) {
	Node* root = new Node();
	_head = root;
	// ��������� ������ ��� ������ ������
	_head->data = data;
	_head->next = nullptr; // ��������� �� ��������� ����
	_head->prev = nullptr; // ��������� �� ���������� ����
	_size++;
}
//����������� �� ��������� ��� ������
List::List():_size(0),_head(nullptr),_tail(nullptr) {}

//������� ������������, ������� ������.
int List::GetHead() {
	if (_head != nullptr) {
		return _head->data;
	}
	if (_head == nullptr && _size == 0) {
		return 0;
	}
}
//������� ������������, ������� �����.
int List::GetTail() {
	if (_tail != nullptr){
		return _tail->data;
     }
	if (_tail == nullptr && _size < 2) {
		return 0;
	}
	
}
//���������� ������ �������� ������.
int List::GetSize() {

	return _size;
}

//���������� ������� ������
int* List::GetList() {
	int sizeOfArray = GetSize();
	int* array= new int[sizeOfArray];
	int index = 0;
	if (_head != nullptr) {
		Node* temp = _head;
		do {
			array[index] = temp->data;
			temp = temp->next;
			index++;
		} while (temp != nullptr); // ������� ��������� ������
	}
	return array;
	delete[] array;

}
//������� ���������� �������� � ����� �������.
void List::AddNodeAtEnd(int data)
{
	//������� ����� �������, � ��������� data
	Node* newNode = new Node(data);

	//���������, ������� �� "������" �������, ���� ���, �������.
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
}
//������� ���������� �������� � ������ �������.
void List::AddNodeAtStart(int data) {
	auto start =chrono::high_resolution_clock::now(); // ������ ������
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
	if (_size == 2) {
		_tail = _head->next;
	}
	auto end = chrono::high_resolution_clock::now(); // ����� ������
	chrono::duration<double, milli> duration = end - start; // ��������� �������
	cout << "runtime = " << duration.count() << "ms" << endl; // ����� ������ ���������  
	system("pause");
}
//��������� ������� � ������ ����� ������������ ���������
void List::InsertBefore(int data, int indexOfElement) {
	auto start = chrono::high_resolution_clock::now(); // ������ ������
	Node* newNode = new Node(data);
	Node* temp;

	if (indexOfElement <= _size && indexOfElement >= 0) {
		if (_head == nullptr)
		{
			InitRoot(data);
			return;
		}
		if (indexOfElement == 0) {
			AddNodeAtStart(data);
			return;
		}
		if (indexOfElement == _size) {
			AddNodeAtEnd(data);
			return;
		}

		//����������� � ������ ��� � ������ ����� �������.
		if (indexOfElement < _size / 2) {
			temp = _head;
			for (int i = 0; temp != nullptr && i < indexOfElement-1; i++) {
				temp = temp->next;
			}
		}
		else {
			temp = _tail;
			for (int i = _size; temp != nullptr && i > indexOfElement; i--) {
				temp = temp->prev;
			}
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		if (temp->next != nullptr) {
			temp->next->prev = newNode;
		}
		temp->next = newNode;
		_size++;
	}
	auto end = chrono::high_resolution_clock::now(); // ����� ������
	chrono::duration<double, milli> duration = end - start; // ��������� �������
	cout << "runtime = " << duration.count() << "ms" << endl; // ����� ������ ���������  
	system("pause");
}
//�������� ����� �������� ������.
int List::LinearSearch(int seacrhingElement) {
	Node* temp = _head;
	for (int i = 0; i < _size; i++) {
		if (temp->data == seacrhingElement) {
			return i;
		}
		temp = temp->next;
	}
	return -1;
}
//��������� ������� � ������ ����� ������������� ��������
void List::InsertAfter(int data, int indexOfElement)
{
	if (indexOfElement >= 0) {
		InsertBefore(data, indexOfElement + 1);
	}
}

//������������� ������ �� ��������� ������� ������. ������� ������ �������.
void List::DeleteHead() {
	_head = _head->next;
	if (_head != nullptr) {
		_head->prev = nullptr;
	}
	
}
//������������� ����� �� ���������� ������� ������. ������� ����� �������.
void List::DeleteTail() {
	_tail = _tail->prev;
	if (_tail != nullptr) {
		_tail->next = nullptr;
	}
	
}

//������� �������� �������� �� �������.
void List::DeleteNodeIndex(int deletedIndex) 
{
	//���� "������" ����������.
	if (_head != nullptr && deletedIndex<_size && deletedIndex>=0) {
		//���� ���� ������� � ������, ������� �������� � ������� � �������.
		if (_size == 1 && _tail!=nullptr) {
			DeleteHead();
			DeleteTail();
			_size--;
			return;
		}
		//���� ������� ������.
		if (deletedIndex == 0 ) {
			DeleteHead();
			_size--;
			return;
		}
		//������� �����.
		if (deletedIndex == _size - 1 ) {
			DeleteTail();
			_size--;
			return;
		}
		Node* temp;
		//����������� � ������ ��� � ������ ����� �������.
		if (deletedIndex < _size / 2) {
			temp = _head;
			for (int i = 0; temp != nullptr && i < deletedIndex; i++) {
				temp = temp->next;
			}
		}
		else  {
			temp = _tail;
			for (int i = _size-1; temp != nullptr && i > deletedIndex; i--) {
				temp = temp->prev;
			}
		}
		//������� �������.
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
}
//������ ������� ��� �������� �������� ������.
void List::SwapNodes(Node* firstNode,Node* secondNode) 
{
	Node *prev1, * prev2, * next1, * next2;
	prev1 = firstNode->prev;  // ���� �������������� lst1
	prev2 = secondNode->prev;  // ���� �������������� lst2
	next1 = firstNode->next; // ���� ��������� �� lst1
	next2 = secondNode->next; // ���� ��������� �� lst2
	secondNode->next = firstNode;
	secondNode->prev = prev1;
	firstNode->next = next2;
	firstNode->prev = secondNode;

	if (next2 != nullptr) {
		next2->prev = firstNode;
	}
	if (firstNode != _head) {
		prev1->next = secondNode;
	}
	if (prev1 == nullptr) {
		_head= secondNode;
	}
	if (next2 == nullptr) {
		_tail = firstNode;
	}
	
}
//��������� ������ �� �����������.
void List::SortList()
{
	Node* temp = _head;
	for (int i = 0; i < _size; i++) {
		temp = _head;
		for (int j = 0; j < _size; j++) {
			if (temp != nullptr && temp->next!=nullptr) {
				if (temp->data > temp->next->data) {
					SwapNodes(temp, temp->next);
				}
				temp = temp->next;
			}
		}
	}
}


