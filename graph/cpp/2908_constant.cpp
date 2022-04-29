#include<iostream>
using namespace std;
int main() {
    int A, B, ans;
    cin >> A >> B;

    A = (A%10*100) + (A/10%10*10) + (A/100);
    B = (B%10*100) + (B/10%10*10) + (B/100);
    ans = (A > B) ? A : B;
    cout << ans;
}