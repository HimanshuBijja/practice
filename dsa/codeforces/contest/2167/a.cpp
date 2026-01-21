#include <bits/stdc++.h>
using namespace std;

int main(){

    int testCases;
    cin >> testCases;

    while(testCases--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if( a == b && b == c && c == d ){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}