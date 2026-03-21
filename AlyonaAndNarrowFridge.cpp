#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main(){
    long long n, h;
    cin>>n;
    cin>>h;
    vector<long long> arr(n);
    for(long long i=0; i<n; i++)
    cin>>arr[i];

    long long high = n;
    long long low = 0;
    long long mid = (high+low)/2; //2
    while(high>=low){
        mid = (high+low)/2; // mid = 2 will pass
        long long height = 0;
        auto arr_copy = arr;
        sort(arr_copy.begin(), arr_copy.begin() + mid);
        for(long long j = mid - 1; j>=0; j-=2){  
            height = height + arr_copy[j];
        }
        // cout<<high<<","<<mid<<","<<low<<":"<<height<<endl;
        if(height <= h){
            low = mid+1;
            mid = (high+low)/2;
        }
        else{
            high = mid-1;
            mid = (high+low)/2;
        }

    }
    cout<<mid<<endl;

}