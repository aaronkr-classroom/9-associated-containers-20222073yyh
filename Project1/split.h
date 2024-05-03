#pragma once
#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//인수가 공백일 때는 true, 그렇지 않으면 false 
bool space(char);
//인수가 공백일 때는 false, 그렇지 않으면 true 
bool not_space(char);

vector<string> split(const string&);

#endif
