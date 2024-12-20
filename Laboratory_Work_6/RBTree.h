#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include "RBNode.h"
class RBTree {
private:
	//��������� �� ������ ������.
	RBNode* _root;
	
	//���������� ��������� � ������.
	int _size;

	void InsertValue(RBNode*& root, const int value);

	RBNode* InsertNode(RBNode*& root, RBNode*& node);

	void FixInsertRBTree( RBNode*& node);

	Color GetColor(RBNode* node);

	void SetColor(RBNode*& node, const Color color);

	void RotateLeft(RBNode*& root, RBNode*& node);

	void RotateRight(RBNode*& root, RBNode*& node);
	////�������������� ������ ������.
	//void InitRoot(int data);

	////������� ������� �������� ������.
	//void Insert(Node*& node, int data);

	////��������� ������� ������ ������.
	//int CalculateHeight(Node* node);

	////������� ������� ������.
	//void DeleteNode(Node*& node, int data);

public:
	//��������� ���������� ��������� � ������.
	int GetSize();

	//���������� ������ ������.
	int GetHeight();

	//���������� ������� ������ ������.
	RBNode* GetRoot();

	//����������� �� ���������.
	RBTree();

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
