#pragma once
#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//�μ��� ������ ���� true, �׷��� ������ false 
bool space(char);
//�μ��� ������ ���� false, �׷��� ������ true 
bool not_space(char);

vector<string> split(const string&);

#endif
