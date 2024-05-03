#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//인수가 공백일 때는 true, 그렇지 않으면 false 
bool space(char c) {

	return isspace(c);
}
//인수가 공백일 때는 false, 그렇지 않으면 true 
bool not_space(char c) {

	return !isspace(c);
}

vector<string> split(const string& str) {
	typedef string::const_iterator iter;

	iter i = str.begin();
	vector<string> ret;

	//for(iter i = str.begin(); i != str.end(); i++)
	while (i != str.end()) {
		cout << "String begin pos: " <<
			distance(str.begin(), i) << endl;
		//선행 공백을 무시
		i = find_if(i, str.end(), not_space);

		//다음 단어의 끝을 찾음
		//while 반복할때 항상 새로운 반복자 j를 생서
		//지금 i 위치부터 첫 번째 뛰어쓰기 문자 찾기
		iter j = find_if(i, str.end(), space);
		cout << "j pos: " <<
			distance(str.begin(), j) << endl;
		//[i, j)범위의 문자르 조사
		if (i != str.end()) {
			ret.push_back(string(i, j));
		}

		//i반복자 위치가 j반복자의 위치를 저장
		i = j;
		cout << "i 이동 pos: " <<
			distance(str.begin(), i) << endl;
	}
	return ret;
}

