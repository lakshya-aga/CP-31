#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(auto &i: arr) cin>>i;
    vector<int> idx_zeroes;
    idx_zeroes.push_back(-1);
    for(int i=0; i<n; i++)
    if(arr[i]==0) idx_zeroes.push_back(i);
    idx_zeroes.push_back(n);
    
    int ans_left = 0;
    int ans_right = 0;
    int max2s=-1;
    for(int j=1; j<idx_zeroes.size(); j++){
        
        vector<int> left2(n, 0);
        vector<int> right2(n, 0);
        int left = idx_zeroes[j-1]+1; int right = idx_zeroes[j]-1;
        
        int count_left2 = 0;
        int count_right2 = 0;
        int count_negs = 0;
        for(int i=left; i<=right; i++){
            if(abs(arr[i])==2) count_left2++;
            left2[i] = (count_left2);
            if(arr[i]<0) count_negs++;
        }

        if(count_negs%2==0){
            if(max2s<count_left2){
                ans_left = left;
                ans_right = right;
                max2s = count_left2;
            }
            continue;
        }
        // cout<<"Negs were odd"<<endl;
        for(int i=right; i>=left; i--){
            if(abs(arr[i])==2) count_right2++;
            right2[i] = count_right2;
        }

        int cost = n;
        for(int i=left; i<=right; i++){
            if(arr[i]<0){
                // cout<<"i detected:"<<i<<endl;
                cost = min(left2[i],  cost);
                // cout<<count_left2<<endl;
                // cout<<cost<<endl;
                if(max2s<count_left2-cost){
                    ans_left = i+1;
                    ans_right = right;
                    max2s = count_left2-cost;
                }
                break;
            }
        }

        cost = n;
        for(int i=right; i>=left; i--){
            if(arr[i]<0){
                // cout<<"i detected:"<<i<<endl;
                cost = min(right2[i], cost);
                // cout<<count_left2<<endl;
                // cout<<cost<<endl;
                if(max2s<count_left2-cost){
                    // cout<<left<<" "<<i<<endl;
                    ans_left = left;
                    ans_right = i-1;
                    max2s = count_left2-cost;
                }
                break;
            }
        }

    }
    cout<<ans_left<<" "<<n-ans_right-1<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}