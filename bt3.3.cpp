#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr; //# tổng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX]; //# lưu giữ các thành phố đã đi

//# Đọc dữ liệu vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
    /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/

    if(!mark[i]){
        x[k] = i;
        curr += c[x[k-1]][x[k]]; // Cập nhật chi phí tới thời điểm hiện tại
        mark[i] = 1; // Đánh dấu thành phố i đã đi
        if(k == n) { // Nếu đã đi qua hết các thành phố
        //Nếu tổng chi phí tốt hơn chi phí tốt nhất hiện tại thì cập nhật chi phí tốt nhất
            if (curr + c[x[n]][x[1]] < best) 
                best = curr + c[x[n]][x[1]];
        } 
        // Nếu tổng chi phí còn nhỏ hơn giá trị tốt nhất hiện tại thì đi tới thành phố tiếp theo
        else if(curr + (n - k + 1) * cmin < best) { 
            TRY(k + 1);
        }
        // Nếu không thì quay lui và trả lại chi phí trước đó
        curr -= c[x[k-1]][x[k]]; 
        mark[i] = 0; 
    }
    }
    
}

int main() {
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}