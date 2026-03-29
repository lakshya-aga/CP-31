#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void fastio() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main(){
    fastio();
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;

        vector<int> next_right(n+2, n+1);
        for(int i=0; i<m; i++){
            int x, y;
            cin>>x;
            cin>>y;
            if(x>y){
                next_right[y] = min(x, next_right[y]);
            }
            else
                next_right[x] = min(y, next_right[x]);


        }
        long long ans = 0;
        int just_right = n+1;
        for(int i=n; i>=1; i--){
            // cout<<just_right<<":"<<i<<endl;
            just_right = min(next_right[i], just_right);
            ans += just_right - i ;
            // cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
}