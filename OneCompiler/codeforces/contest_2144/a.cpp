#include <bits/stdc++.h>
using namespace std;

pair<int, int> checkPossible(vector<int> arr) {
    int n = arr.size();
    
    vector<int> prefixSum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }
    
    for(int l = 1; l <= n - 2; l++) {
        for(int r = l + 1; r <= n - 1; r++) {
            int s1 = prefixSum[l] % 3;
            int s2 = (prefixSum[r] - prefixSum[l]) % 3;
            int s3 = (prefixSum[n] - prefixSum[r]) % 3;
            
            bool allSame = (s1 == s2) && (s2 == s3);
            bool allDifferent = (s1 != s2) && (s2 != s3) && (s1 != s3);
            
            if(allSame || allDifferent) {
                return {l, r};
            }
        }
    }
    
    return {0, 0};
}

int main() {
    int testCases;
    cin >> testCases;
    
    while(testCases--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        auto result = checkPossible(arr);
        cout << result.first << " " << result.second << endl;
    }
    
    return 0;
}