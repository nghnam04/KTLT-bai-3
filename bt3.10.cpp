#include <bits/stdc++.h>

using namespace std;
/*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920
    */

//Hàm tạo chuỗi khoảng cách hamming
void generateHammingString(string &s, int h, int pos, int currentDistance, vector<string> &result) {
    //Khoảng cách Hamiing hiện tại bằng h thì đẩy vào vector
    if (currentDistance == h) {
        result.push_back(s);
        return;
    }
    for (int i = pos; i < s.size(); i++) {
        if (s[i] == '0') {
            s[i] = '1';
            generateHammingString(s, h, i + 1, currentDistance + 1, result);
            s[i] = '0'; //Quay lui
        }
    }
}

int main() {
    int t;
    cin >> t;
    bool test1 = true;
    while (t != 0) {
        int n, h;
        cin >> n >> h;
        string s(n, '0'); //Tạo chuỗi s độ dài n toàn 0
        vector<string> result;
        generateHammingString(s, h, 0, 0, result);

        if (!test1) {
            cout << endl; //Tạo dòng trống giữa các test case nêu không phải test đầu tiên
        }

        test1 = false;
        for (auto v : result) {
            cout << v << endl;
        }
        t--;
    }
    return 0;
}
