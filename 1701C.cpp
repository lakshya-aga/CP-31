#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

#include <iomanip>

int main(){

    long long t;
    cin>>t;
    while(t--){
        
        long long n, m;
        cin>>n>>m;
        vector<long long> a(m);
        for(long long i=0; i<m; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());

        long long high = m*2;
        long long low = 0;
        long long mid = (high+low)/2;

        long long ans = high;
        while(high>=low){
            long long tasks_left = m;
            mid = (high+low)/2;
            vector<long long> num_hours(n+1, mid);
            for(long long i=1; i<=n; i++){
                long long count_opt = lower_bound(a.begin(), a.end(), i+1) - lower_bound(a.begin(), a.end(), i);
                num_hours[i] = num_hours[i] - min(count_opt, mid);
                tasks_left = tasks_left - min(count_opt, mid);
                // cout<<"Candidate_hours:"<<num_hours[i]<<"tasks:"<<tasks_left<<endl;
            }
            long long total_tasks_that_can_be_done = 0;
            for(long long i=1; i<=n; i++){
                total_tasks_that_can_be_done+=num_hours[i]/2;
            }
            // cout<<"total_tasks_that_can_be_done:"<<total_tasks_that_can_be_done<<endl;
            if(total_tasks_that_can_be_done>=tasks_left){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        cout<<ans<<endl;

    
    }
}