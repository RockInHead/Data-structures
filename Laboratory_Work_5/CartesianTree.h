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
	
	static CartesianNode* Merge(CartesianNode* a, CartesianNode* b);


	//������� ������� �������� ������.
	void Insert(CartesianNode*& node, int key,int priority);

	void Remove(CartesianNode*& node, int key);

	void FreeTree(CartesianNode*& node);
	//��������� ������� ������ ������.
	int CalculateHeight(CartesianNode* node);

	//������� ������� ������.
	void DeleteNode(CartesianNode*& node, int data);

	//������� ������� 2�� ��������.

	//������� ������ �� �����.
	static void Split(CartesianNode* node, int key, CartesianNode*& a, CartesianNode*& b);

public:
	//������� ��� �������� ������.
	void ClearTree();

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
