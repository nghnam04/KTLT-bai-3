#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};
/*
i là chỉ số hiện tại trong chuỗi nhị phân
j là giá trị bit tại vị trí i
old_L là độ dài của chuỗi liên tiếp các bit 1 tính đến vị trí i-1
*/

int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        
        //# Khử đệ quy
        /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/

    //Nếu top.j lớn hơn 0, khôi phục lại giá trị L từ top.old_L
        if (top.j > 0) {
        	L = top.old_L;
		}
	
    //Nếu top.j lớn hơn 1, loại bỏ trạng thái hiện tại vì giá trị j chỉ có thể là 0 hoặc 1
		if (top.j > 1) {
			s.pop();
			continue;
		}
    
    //Nếu top.j bằng 0 hoặc L+1 nhỏ hơn k, cập nhật giá trị tại vị trí i trong chuỗi nhị phân
        if(top.j == 0 || L+1<k){
        	x[top.i] = top.j;
        	top.old_L = L;
			L = top.j ? L+1 : 0;
			s.push(state(top.i+1, 0));
		}
		++top.j;

    }
    return 0;
}