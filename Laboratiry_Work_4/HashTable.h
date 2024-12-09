#ifndef HASHTABLE_H
#define HASHTABLE_H

#include"Node.h"
#include <iostream>

using namespace std;

class HashTable {
private:
	//������ �������� �����.
	int _size;

	//��������� �� ������ �����.
	/*Node* _head;*/

	//��������� �� ��������� ������� �����.
	/*Node* _top;*/
	Node* table[5];

public:

	//����������� �� ���������.
	HashTable() {
		for (int i = 0; i < 5; i++)
		{
			table[i] = nullptr;
		}
	}

	//�������� ������� � ���-�������.
	void Put(string key, int data);

	int Hash(string key);

	int GetNode(string key);

	unsigned int PearsonHash(string key);
};
#endif