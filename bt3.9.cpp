#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
int n, k1, k2; //Số ngày làm việc, số ngày liên tiếp tối thiểu, tối đa
int x[MAX]; //Mảng lưu lịch làm việc
int goodSchedule = 0; //Số lịch làm việc tốt
int so1 = 0, so0 = 0; //Số ngày làm việc, nghỉ tính đến hiện tại

/*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    
//Hàm nhập dữ liệu
void input(){
    cin >> n >> k1 >> k2;
}

//Hàm kiểm tra điều kiện bài toán
bool check(int  a, int  i){
    if(a==1) return true; //Ngày đầu tiên đi làm
    if (i == 1) {
        // Kiểm tra số ngày làm việc liên tiếp không vượt quá k2
        if (so1 >= k2) return false;
        else{
            if(n-a+1 < k1 && x[a-1] == 0) return false;
        }
    } else { //Ngày nghỉ
        //Nếu ngày trước đó là ngày nghỉ trả về false
        if (x[a-1] == 0) return false;
        //Số ngày làm việc trước đó ở ngoài khoảng [k1, k2] trả về false
        if (so1 < k1) return false;
    }
    return true;
}

//Hàm in lịch làm việc
void printSchedule(){
    for(int i=1; i<=n; i++)
        cout << x[i];
    cout << endl;
    goodSchedule++;
}

void TRY(int  a){
    for(int i = 0; i <= 1; i++){
        if(check(a,i)){
            int previousState = so1;
            x[a] = i; 
            if(i == 0){
                so1 = 0;
            }
            else if( x[a-1] == 1 && i == 1) ++so1;
            else so1 = 1;

            if(a==n) printSchedule();
            else TRY(a+1);

            so1 = previousState;
        }
    }
}


int main(){
    input();
    TRY(1);
    return 0;
}
