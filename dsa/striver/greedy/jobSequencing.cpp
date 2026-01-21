#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

int comp(Job a, Job b){
    return a.profit > b.profit;
}

int main(){

    int n;
    cin >> n;
    vector <Job> jobs(n);

    int maxDeadline = 0;
    for(int i=0; i<n; i++){
        cin  >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    sort(jobs.begin(), jobs.end(), comp);

    vector <int> idSlot(maxDeadline + 1, -1);
    int totalProfit = 0 , countJobs = 0;

    for(int i=0; i<n; i++){
        for(int j=jobs[i].deadline; j>=0; j--){
            if(idSlot[j] == -1){
                idSlot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                countJobs++;
                break;
            }
        }
    }

    cout << "jobIds" << endl;
    for(int i=0; i< idSlot.size(); i++){
        if(idSlot[i] != -1){
            cout << idSlot[i] << " ";
        }
    }
    cout << endl;
    cout << "Total Profit: " << totalProfit << endl;
    cout << "Number of Jobs: " << countJobs << endl;
    
    return 0;
}