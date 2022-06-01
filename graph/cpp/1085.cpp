#include<iostream>
using namespace std;

int main() {
    int arr[4];
    int min = 1001;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    arr[2] = arr[2] - arr[0];
    arr[3] = arr[3] - arr[1];
    for(int i = 0; i <4; i++) {
        if(min > arr[i]) min = arr[i];
    }

    cout << min;

}   