#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "split.h"

using namespace std;

// 함수 선언
map<string, vector<int>> xref(istream& in, vector<string> find_words(const string&));
void display_xref(const map<string, vector<int>>& ret);

int main() {
    map<string, vector<int>> ret = xref(cin);

    display_xref(ret);

    return 0;
}

// 함수 정의
map<string, vector<int>> xref(istream& in, vector<string> find_words(const string&)) {
    string line;
    int line_num = 0;
    map<string, vector<int>> ret;

    // 다음 행을 읽음
    while (getline(in, line)) {
        ++line_num;

        // 입력한 행을 단어로 나눔
        vector<string> words = find_words(line);

        // 현재 행에 등장한 모든 단어를 저장
        for (const string& word : words) {
            ret[word].push_back(line_num);
        }
    }
    return ret;
}

void display_xref(const map<string, vector<int>>& ret) {
    for (const auto& entry : ret) {
        cout << entry.first << " is on line(s): ";

        const vector<int>& lines = entry.second;

        if (lines.size() == 1) {
            cout << lines[0];
        }
        else {
            cout << lines[0];
            for (size_t i = 1; i < lines.size(); ++i) {
                cout << ", " << lines[i];
            }
        }
        cout << endl;
    }
}