#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# Lưu tọa độ các bước di chuyển của quân mã
int mark[100][100]; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua

//# Mảng hx, hy mô tả 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    if(xx >= 1 && xx <= n && yy >= 1 && yy <= n && mark[xx][yy] == 0){
        //Nếu ô tiếp theo là hợp lệ và chưa được đi qua thì lấy vị trí này
            X[k] = xx;
            Y[k] = yy;
            mark[xx][yy] = 1; //Đánh dấu ô này đã đi qua
            if(k == n * n) print_sol(); // Nếu đã đi qua hết các ô trên bảng thì in ra dãy di chuyển
            else TRY(k + 1);
            mark[xx][yy] = 0; // Quay lui
        }
    }
}

int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}