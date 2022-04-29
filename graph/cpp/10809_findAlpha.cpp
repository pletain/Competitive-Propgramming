#include<iostream>
#include<vector>
using namespace std;
vector<int> alpha(26,-1);

int main(){
    string S;
    cin >> S;
    for(int i = S.size() - 1; i>-1; i--) {
        int N = S[i] - 97;
        alpha[N] = i;
    }
    for (int j=0; j<26; j++) {
        cout << alpha[j] << " ";
    }
}