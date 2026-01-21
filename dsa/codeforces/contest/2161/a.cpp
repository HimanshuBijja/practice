#include <bits/stdc++.h>
using namespace std;


int main(){

    int testCases;
    cin >> testCases;

    while(testCases--){
        int r, x, d, n;
        cin >> r >> x >> d >> n;
        string s;
        cin >> s;



        int count = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1'){
                count += s.length() - i;
                break;
            }
            if(r < x){
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}