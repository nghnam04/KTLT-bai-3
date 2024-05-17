int lucas(int n) {
    
    /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    
    if(n == 0) return 2;
    if(n == 1) return 1;
    return lucas(n - 1) + lucas( n - 2);
}