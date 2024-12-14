#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "Node.h"
class BinaryTree {
private:
	//��������� �� ������ ������.
	Node* _root;

	//���������� ��������� � ������.
	int _size;

	//�������������� ������ ������.
	void InitRoot(int data);

	void Insert(Node* node, int data);
public:

	//���������� ������� �������� ������.
	Node* GetBinaryTree();

	//����������� �� ���������.
	BinaryTree();
	
	//���������� �������� � ������.
	void AddElement(int data);

	//�������� �������� �� ��������.
	void DeleteElement();
};
#endif
