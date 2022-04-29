#include<iostream>
using namespace std;
int main() {
    int sum = 0;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    sum = (a*a) + (b*b) + (c*c) + (d*d) + (e*e);
    cout << sum % 10;
}