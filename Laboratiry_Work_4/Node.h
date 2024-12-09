#ifndef NODE_H
#define NODE_H

#include <iostream>
struct Node
{
    //���� ������.
    std::string Key;

    //�������� ��������.
    int Value;

    //��������� �� ��������� �������, ��� ������������� ��������.
    Node* Next;

    Node() :Key(""), Value(0), Next(nullptr) {}
    Node(const std::string& k, int v) : Key(k), Value(v), Next(nullptr) {}
};
#endif