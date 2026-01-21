#include <bits/stdc++.h>
using namespace std;

int main(){

    int testCases;
    cin >> testCases;

    while(testCases--){
        int n;
        cin >> n;

        bool even = false, odd = false;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];


            if(arr[i] % 2 == 0){
                even = true;
            } 
            
            else {
                odd = true;
            }
        }

        if(even && odd){
            sort(arr.begin(), arr.end());
        }
    
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }

        cout << endl;
    }
    return 0;
}