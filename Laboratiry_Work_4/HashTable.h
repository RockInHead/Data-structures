#ifndef HASHTABLE_H
#define HASHTABLE_H

#include"Node.h"
#include <iostream>

using namespace std;

class HashTable {
private:
	const int MinCapacity = 5;
	double _growthFactor = 1.5;
	int _capacity;

	//������ �������� �����.
	int _size;

	//��������� �� ������ �����.
	/*Node* _head;*/

	//��������� �� ��������� ������� �����.
	/*Node* _top;*/
	Node** _table;
	/*Node* _table = new Node[5];*/

	bool CompareKeys(Node* nodeFirst,Node* nodeSecond);

	//������� ����� ������� � ����� ������������. ������������� ��������� �� ����� ��������� ������
	void CreateNewHashTable(int capacity);

	//�������� ������ �������, �������� ����� ������
	void ResizeHashTable();

public:

	//����������� �� ���������.
	HashTable();

	Node** GetHashTable();

	int GetSize();

	int GetCapacity();


	//�������� ������� � ���-�������.
	void Put(string key, int data);

	int Hash(string key);

	//���� �������� �� �����. ��������� �������� ��������.
	int SearchingValue(string key);

	//������� ������� �� �����.
	void DeleteElement(string key);

	unsigned int PearsonHash(string key,int capacity);
};
#endif