#include <bits/stdc++.h>
using namespace std;

int main(){

    int testCases;
    cin >> testCases;

    while(testCases--){
        int n;
        cin >> n;

        if(n % 2 != 0){
            cout << 0 << endl;
            continue;
        }

        cout << n/4 +1 << endl;
    }
    return 0;
}

