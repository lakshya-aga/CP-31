#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // vector<int> arr(n*4, 0);
        if(n%2==0){
            for(int i=0; i<n; i+=2){
                cout<<(i+1)<<" ";
                cout<<(i+2)<<" ";
                cout<<(i+2)<<" ";
                cout<<(i+1)<<" ";
                cout<<(i+2)<<" ";
                cout<<(i+1)<<" ";
                cout<<(i+1)<<" ";
                cout<<(i+2)<<" ";
            }
        }
        else{
            cout<<"1 1 2 1 2 3 1 3 2 2 3 3 ";
            for(int i=3; i<n; i+=2){
                cout<<(i+1)<<" ";
                cout<<(i+2)<<" ";
                cout<<(i+2)<<" ";
                cout<<(i+1)<<" ";
                cout<<(i+2)<<" ";
                cout<<(i+1)<<" ";
                cout<<(i+1)<<" ";
                cout<<(i+2)<<" ";
            }
        }
        
    }

    return 0;
}