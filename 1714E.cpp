#include <iostream>
#include <vector>
using namespace std;

long long applyOp(long long x){
    return x+x%10;
}

void fastio() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int i=0;
        bool ans = false;
        for(i=0; i<n-1; i++){
            long long n1 = arr[i];
            long long n2 = arr[i+1];
            n1 = applyOp(n1);
            n2 = applyOp(n2);
            if(n1>n2){
                swap(n1, n2);
            }
            // cout<<"n1:"<<n1<<endl;
            // cout<<"n2:"<<n2<<endl;
            bool ans = n1==n2;
            if(n1%10!=0)
            n1 = n1 + (n2 - n1)/20 * 20;

            // cout<<"n1:"<<n1<<endl;
            // cout<<"n2:"<<n2<<endl;

            for(int i=0; i<=5; i++){
                if(n1==n2){
                    ans = true;
                    break;
                }
                n1=applyOp(n1);
                // cout<<n1<<"->";
            }
            // cout<<n2<<endl;
            if(!ans){
                // i=n;
                cout<<"No"<<endl;
                break;
            }
            arr[i] = n2;
            arr[i+1] = n2;
        }
        if(n==1 || arr[n-1]==arr[n-2] && i==n-1){
            cout<<"Yes"<<endl;
        }

    }
}