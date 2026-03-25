#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long t;
    cin>>t;

    while(t--)
    {
        long long k,x;

        cin>>k>>x;

        long long low = 1;
        long long high = 2*k-1;
        long long mid = (high+low)/2;
        long long res = 2*k-1;
        bool over = false;

        while(high>=low){
            mid = (high+low)/2;
            auto total = (min(k, mid)*(min(k, mid)+1))/2;
            auto total_2 = (min(k, mid-1)*(min(k, mid-1)+1))/2;
            if(mid>k){
                total+= ((k-1) + (k - 1 - mid + k))/2*(mid - k);
            }
            if(mid-1>k){
                total_2+= ((k-1) + (k - 1 - (mid-1) + k))/2*((mid-1) - k);
            }
            // if(total_2>x && total_1<=x){

            // }
            // cout<<mid<<" "<<total-x<<endl;
            if(total < x){
                low = mid+1;
            }
            else{
                res = mid;
                high = mid - 1;
            }
        }
        cout<<res<<endl;

        
    }
}