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
	void Insert(CartesianNode*& node, int key,int priority);

	//��������� ������� ������ ������.
	int CalculateHeight(CartesianNode* node);

	//������� ������� ������.
	void DeleteNode(CartesianNode*& node, int data);

	//������� ������� 2�� ��������.
	static CartesianNode* Merge(CartesianNode* a, CartesianNode* b);

	//������� ������ �� �����.
	static void Split(CartesianNode* node, int key, CartesianNode*& a, CartesianNode*& b);

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
	void AddElementNotOptimazed(int key);

	//�������� �������� �� ��������.
	void DeleteElementNotOptimazed(int key);

	
	//���������� �������� � ������.
	void AddElementOptimazed(int key);

	//�������� �������� �� ��������.
	void DeleteElementOptimazed(int key);


	//��������� ����������� ������� ������.
	int FindMin();

	//���������� ������������ ������� ������.
	int FindMax();

};
#endif
