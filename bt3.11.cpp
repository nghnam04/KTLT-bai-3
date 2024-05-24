#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;

/*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    
const int MAX = 10000;
int n, r;
int price[MAX][MAX];
int x[MAX];
bool visited[MAX];
vector<int> vt;
int min_price;
int sum_price;
int start, destination, numberOfPoint;

void input() {
    cin >> n >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> price[i][j];
}

bool isValid(int a, int i) {
    return !visited[vt[i]] && price[x[a - 1]][vt[i]] != 0;
}

void updateMinPrice() {
    if (price[x[numberOfPoint - 2]][destination] == 0) return;
    min_price = min(min_price, sum_price + price[x[numberOfPoint - 2]][destination]);
}

void findMinPrice(int a) {
    for (int i = 1; i < numberOfPoint - 1; i++) {
        if (isValid(a, i)) {
            visited[vt[i]] = true;
            sum_price += price[x[a - 1]][vt[i]];

            x[a] = vt[i];
            if (a == numberOfPoint - 2)
                updateMinPrice();
            else
                findMinPrice(a + 1);

            visited[vt[i]] = false;
            sum_price -= price[x[a - 1]][vt[i]];
        }
    }
}

void processRoute(const string& str) {
    vt.clear();
    stringstream ss(str);
    int tmp;
    while (ss >> tmp) {
        vt.push_back(tmp - 1);
    }
    start = vt[0];
    destination = vt.back();
    numberOfPoint = vt.size();
    x[0] = start;
    x[numberOfPoint - 1] = destination;
    fill(visited, visited + n, false);
}

int main() {
    input();
    string str;
    getline(cin, str);

    while (r-- > 0) {
        min_price = numeric_limits<int>::max();
        sum_price = 0;

        getline(cin, str);
        processRoute(str);

        findMinPrice(1);
        if (min_price == numeric_limits<int>::max())
            cout << "0" << endl;
        else
            cout << min_price << endl;
    }
    return 0;
}
