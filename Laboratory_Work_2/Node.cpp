#include"Node.h"
Node::Node() {
    this->data = -1;
    this->next = nullptr;
    this->prev = nullptr;
}
//����������� ��� ������������� ���� � �������� ���������.
Node::Node(int data) 
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}