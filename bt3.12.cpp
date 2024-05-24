#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

/*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    
int n, k, m;
vector<int> adjacencyList[MAX];
int adjacencyListSize[MAX];

void input() {
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        adjacencyListSize[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        adjacencyList[tmp1].push_back(tmp2);
        adjacencyList[tmp2].push_back(tmp1);
    }
}

int countSimplePaths(int start, int length, vector<bool>& visited) {
    if (length == k) {
        return 1;
    }
    int count = 0;
    visited[start] = true;
    for (int neighbor : adjacencyList[start]) {
        if (!visited[neighbor]) {
            count += countSimplePaths(neighbor, length + 1, visited);
        }
    }
    visited[start] = false;
    return count;
}

int countKLengthSimplePaths() {
    int totalPaths = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        totalPaths += countSimplePaths(i, 0, visited);
    }

    return totalPaths / 2;
}

int main() {
    input();
    int result = countKLengthSimplePaths();
    cout << result << endl;
    return 0;
}
