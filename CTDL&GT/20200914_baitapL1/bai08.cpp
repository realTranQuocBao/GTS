// TQB13 - Tran Quoc Bao

//Tính t? h?p ch?p k c?a n ph?n t?.

#include <iostream>
using namespace std;
long long gt(int n) {
    long long s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return s;
}
long long C(int k, int n) {
    return  gt(n) / (gt(k)*gt(n - k));
}
int main(){
    int n, k;
    cout << "Nhap k: ";
    cin >> k;
    cout << "Nhap n: ";
    cin >> n;
    cout << "To hop chap "<<k<<" cua "<<n<<" phan tu bang: " << C(k, n);
    return 0;
}
 
