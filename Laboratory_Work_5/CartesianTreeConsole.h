#ifndef CARTESIANTREECONSOLE_H
#define CARTESIANTREECONSOLE_H
#include <iostream>
#include"Colors.h"
#include"CartesianNode.h"
#include"CartesianTree.h"
#include <vector>
#include <string>
#include <iostream>
#include "Symbols.h"

using namespace std;

//������� ������ � �������.
void Show1(CartesianNode const* node, bool high = true, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);

//������� ������ � �������.
void Show2(CartesianTree* root, int space = 0);

//�������� ������� ������.
void ShowCartesianTree(CartesianTree& tree);

//�������� ���� ��� ������.
void MenuCartesianTree(CartesianTree& tree);

//������� ���������� ���� ��� ������.
void CartesianTreeConsole(CartesianTree& tree);


#endif 