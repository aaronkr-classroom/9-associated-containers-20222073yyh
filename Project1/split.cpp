#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//�μ��� ������ ���� true, �׷��� ������ false 
bool space(char c) {

	return isspace(c);
}
//�μ��� ������ ���� false, �׷��� ������ true 
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
		//���� ������ ����
		i = find_if(i, str.end(), not_space);

		//���� �ܾ��� ���� ã��
		//while �ݺ��Ҷ� �׻� ���ο� �ݺ��� j�� ����
		//���� i ��ġ���� ù ��° �پ�� ���� ã��
		iter j = find_if(i, str.end(), space);
		cout << "j pos: " <<
			distance(str.begin(), j) << endl;
		//[i, j)������ ���ڸ� ����
		if (i != str.end()) {
			ret.push_back(string(i, j));
		}

		//i�ݺ��� ��ġ�� j�ݺ����� ��ġ�� ����
		i = j;
		cout << "i �̵� pos: " <<
			distance(str.begin(), i) << endl;
	}
	return ret;
}

