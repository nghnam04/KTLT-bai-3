#include <iostream>
#include <vector>

using namespace std;

const int MAX = 20;
int N, H;
int x[MAX];
int S[MAX]; 


/*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    
int hammingDistance(int str1[], int str2[]){
    int count = 0;
    int len = N;
    for(int i=0; i<len; i++){
        if(str1[i] != str2[i]) count++;
    }
    return count;
}

void printsolution(){
    if(hammingDistance(x,S) == H){
        for(int i=0; i<N; i++)
            cout << x[i];
        cout << endl;
    }
}

void TRY(int a){
    if(a == N){
        printsolution();
        return;
    }
    x[a] = 0;
    TRY(a+1);
    x[a] = 1;
    TRY(a+1);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> N >> H;
        for(int i=0; i<N; i++){
            S[i] = 0;
            x[i] = 0;
        }
        TRY(0);
    }
}
