#ifndef CARTESIANTREE_H
#define CARTESIANTREE_H

#include <iostream>
#include "CartesianNode.h"
class CartesianTree {
private:
	//��������� �� ������ ������.
	CartesianNode* _root;

	//���������� ��������� � ������.
	int _size;

	//�������������� ������ ������.
	void InitRoot(int data);

	//������� ������� �������� ������.
	void Insert(CartesianNode*& node, int data);

	//��������� ������� ������ ������.
	int CalculateHeight(CartesianNode* node);

	//������� ������� ������.
	void DeleteNode(CartesianNode*& node, int data);

	//������� ������� 2�� ��������.
	CartesianNode* Merge(CartesianNode* a, CartesianNode* b);

	//������� ������ �� �����.
	void Split(CartesianNode* node, int key, CartesianNode*& a, CartesianNode*& b);

public:
	//��������� ���������� ��������� � ������.
	int GetSize();

	//���������� ������ ������.
	int GetHeight();

	//���������� ������� ������ ������.
	CartesianNode* GetRoot();

	//����������� �� ���������.
	CartesianTree();

	//���������� �������� � ������.
	void AddElement(int data);

	//�������� �������� �� ��������.
	void DeleteElement(int data);

	//��������� ����������� ������� ������.
	int FindMin();

	//���������� ������������ ������� ������.
	int FindMax();

};
#endif
