#include <iostream>
struct Node
{
    //���� ������.
    std::string Key;

    //�������� ��������.
    int Value;

    //��������� �� ��������� �������, ��� ������������� ��������.
    Node* Next;

    Node(const std::string& k, int v) : Key(k), Value(v), Next(nullptr) {}
};