#ifndef RBNODE_H
#define RBNODE_H

//��������������� ������������ ��� ������ ��������.
enum class Color
{
	Red,
	Black,
	DoubleBlack
};

struct RBNode
{
	//�������� ��������.
	int Data;

	//���� ��������.
	Color Color ;
	
	//��������� �� ����� �������.
	RBNode* Left;

	//��������� �� ������ �������.
	RBNode* Right;
	
	//��������� �� �������� ��������.
	RBNode* Parent;

	//�������������.
	RBNode() : Data(-1),Color(Color::Red), Left(nullptr), Right(nullptr), Parent(nullptr) {}
	RBNode(int data) : Data(data),Color(Color::Red), Left(nullptr), Right(nullptr), Parent(nullptr) {}
};
#endif