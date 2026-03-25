#include <iostream>

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int countZeros(int x){
    int ans = 0;
    while(x!= 0 && x%10==0){
        ans++;
        x/=10;
    }
    return ans;
}

int countDigits(int x){
    int ans = 0;
    while(x!= 0){
        ans++;
        x/=10;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        vector<int> arr(n);
        vector<int> digits(n);
        vector<int> zeros(n);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            digits[i] = countDigits(arr[i]);
            zeros[i] = countZeros(arr[i]);
            
        }
        for(int i=0; i<n; i++){
            cout<<"ROW"<<endl;
            cout<<arr[i]<<" ";
            cout<<digits[i]<<" ";
            cout<<zeros[i]<<" "<<endl;
        }
        int total = 0;
        total = accumulate(digits.begin(), digits.end(), total);
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());

        for(int i=0; i<n; i+=2){
            total-=zeros[i];
        }

        if(total - m - 1>=0)
        cout<<"SASHA"<<endl;
        else
        cout<<"ANNA"<<endl;
    }
}

