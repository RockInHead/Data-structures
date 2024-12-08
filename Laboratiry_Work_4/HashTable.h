#ifndef HASHTABLE_H
#define HASHTABLE_H

//#include"Node.h"
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

public:

	//����������� �� ���������.
	HashTable();

	//�������� ������� � ���-�������.
	void Put(string key, int data);

	//������� ��������� ������� �����.
	int Pop();

	//�������� ���� ����.
	void ClearStack();

};
#endif