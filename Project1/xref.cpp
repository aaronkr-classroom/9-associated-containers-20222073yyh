#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "split.h"

using namespace std;

//입력에서 각 단어가 등장한 모든 행을 찾음
//연습문제 xref.cpp에서
//연습문제 7-7 7-8
//그리고 한 줄에 단억 ㅏ두번 이상 나타나면 줄 번호를 여러번 출력하지 않고 한번만 출력하세요
map<string, vector<int>	>xref(
	istream& in,
	vector<string> find_words(const string&) = split)
{
	string line;
	int line_num = 0;
	map<string, vector<int>	>ret;

	//다음 행을 읽음:
	while (getline(in, line)) {


		++line_num;

		//입력한 행을 단어로 나눔.
		vector<string> words = find_words(line);

		//현재 행에 등장한 모든 단어를 저장
		for (vector<string>::const_iterator it = words.begin();
			it != words.end(); ++it) {
			ret[*it].push_back(line_num);
		}

	}
	return ret;
}

int main() {
	map<string, vector<int>	> ret = xref(cin);


	for (map < string, vector<int> > ::const_iterator it = ret.begin();
		it != ret.end(); ++it) {


		cout << it->first << " is on line(s)";

		vector<int>::const_iterator line_it = it->second.begin();

		cout << *line_it;
		++line_it;

		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}
		cout << endl;
	}
	return 0;
}

