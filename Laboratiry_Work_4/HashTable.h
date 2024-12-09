#ifndef HASHTABLE_H
#define HASHTABLE_H

#include"Node.h"
#include <iostream>

using namespace std;

class HashTable {
private:
	int _capacity;

	//������ �������� �����.
	int _size;

	//��������� �� ������ �����.
	/*Node* _head;*/

	//��������� �� ��������� ������� �����.
	/*Node* _top;*/
	Node* _table;

public:

	//����������� �� ���������.
	HashTable();
	

	//�������� ������� � ���-�������.
	void Put(string key, int data);

	int Hash(string key);

	int GetNode(string key);

	unsigned int PearsonHash(string key);
};
#endif