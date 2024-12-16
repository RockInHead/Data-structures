#ifndef CARTESIANNODE_H
#define CARTESIANNODE_H

#include <iostream>
struct CartesianNode
{
    //���� ��������.
    int Key;

    //��������� ��������.
    int Priority;

    //��������� �� ����� ������� ������.
    CartesianNode* Left;

    //��������� �� ������ ������� ������.
    CartesianNode* Right;

    //������������
    CartesianNode() : Key(-1),Priority(-1), Left(nullptr), Right(nullptr) {}
    CartesianNode(int key,int priority) : Key(key), Priority(priority), Left(nullptr), Right(nullptr) {}
};
#endif
