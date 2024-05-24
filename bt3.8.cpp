#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main() {
    int n, M;
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    stack<state> s;
    //# sum of selected weights
    int sum = 0;
    s.push(state(1, -1));
    while (!s.empty()){
        state &top = s.top();
        if (top.i > n){
            if (sum == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue;
        }

        //# Khử đệ quy
        /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    
    //Nếu top.j không phải là giá trị khởi tạo cần phải khôi phục giá trị của sum
        if (top.j != -1) {
            sum -= x[top.i] * m[top.i];
        }
    
    //Cập nhật trạng thái hiện tại và đẩy trạng thái tiếp theo vào stack
        if (top.j <= 1) {
            x[top.i] = top.j;
            sum += x[top.i] * m[top.i];
            s.push(state(top.i + 1, -1));
            top.j++;
        } else {
            s.pop();
        }
    }
    cout << -1;
    return 0;
}