#include <bits/stdc++.h>
using namespace std;

/*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/

const int INF = numeric_limits<int>::max(); //Giá trị lớn nhất kiểu số nguyên

//Hàm nhập vào số địa điểm, số người và ma trận chi phí các địa điểm
void input(int &n, int &r, vector<vector<int>> &price) {
    cin >> n >> r;
    price.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> price[i][j];
}

//Hàm kiểm tra hợp lệ di chuyển giữa hai thành phố
bool check(int a, int i, const vector<int> &vt, const vector<int> &x, const vector<vector<int>> &price, const vector<bool> &visited) {
    return !visited[vt[i]] && price[x[a - 1]][vt[i]] != 0;
}

//Hàm cập nhật giá trị tổi thiểu nếu thấy đường đi hợp lệ
void updateMinPrice(int &min_price, int sum_price, const vector<int> &x, int destination, const vector<vector<int>> &price, int numberOfPoint) {
    if (price[x[numberOfPoint - 2]][destination] != 0) {
        min_price = min(min_price, sum_price + price[x[numberOfPoint - 2]][destination]);
    }
}

//Hàm tìm giá trị tối thiểu sử dụng backtracking
void findMinPrice(int a, vector<int> &x, int &sum_price, int &min_price, const vector<int> &vt, const vector<vector<int>> &price, int numberOfPoint, vector<bool> &visited) {
    for (int i = 1; i < numberOfPoint - 1; i++) {
        if (check(a, i, vt, x, price, visited)) {
            visited[vt[i]] = true;
            sum_price += price[x[a - 1]][vt[i]];
            x[a] = vt[i];
            if (a == numberOfPoint - 2) { //Nếu đã duyệt đến cuối thì update chi phí
                updateMinPrice(min_price, sum_price, x, vt.back(), price, numberOfPoint);
            } else { //Nếu chưa thì quay lui tơi các địa điểm tiếp theo
                findMinPrice(a + 1, x, sum_price, min_price, vt, price, numberOfPoint, visited);
            }
            //Cập nhật lại trạng thái thăm và tổng chi phí
            visited[vt[i]] = false;
            sum_price -= price[x[a - 1]][vt[i]];
        }
    }
}

void processPath(const string &str, vector<int> &vt, int &start, int &destination, int &numberOfPoint) {
    vt.clear(); //Xóa vector lưu trữ danh sách các địa điểm của người trước đó
    stringstream ss(str);
    int tmp;
    while (ss >> tmp) {
        vt.push_back(tmp - 1);
    }
    start = vt[0];
    destination = vt.back();
    numberOfPoint = vt.size();
}

int main() {
    int n, r;
    vector<vector<int>> price;
    input(n, r, price);
    cin.ignore(); 
    string str;
    
    //Duyệt qua danh sách của từng người
    while (r-- > 0) {
        int min_price = INF;
        int sum_price = 0;
        vector<int> vt, x;
        vector<bool> visited(n, false);

        getline(cin, str); //Nhập vào danh sách các địa điểm mỗi người ở dạng chuỗi
        int start, destination, numberOfPoint;
        processPath(str, vt, start, destination, numberOfPoint);
        
        x.resize(numberOfPoint);
        x[0] = start;
        x[numberOfPoint - 1] = destination;

        findMinPrice(1, x, sum_price, min_price, vt, price, numberOfPoint, visited);
        cout << (min_price != INF ? min_price : 0) << endl;
    }
    return 0;
}
