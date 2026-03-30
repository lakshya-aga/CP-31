#include <iostream>

int main(){
    int t;
    using namespace std;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> p(n);
        for(int i=0; i<n; i++){
            cin>>p[i];
            p[i] = p[i]-1; // 0 indexing
        }
        vector<int> dp_sit(n);
        vector<int> dp_nosit(n);
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                dp_sit[i] = 1;
                dp_nosit[i] = 0;
                continue;
            }
            if(p[i]>=i){
                dp_sit[i] = 1+max(dp_sit[i+1], dp_nosit[i+1]);
            }
            else{
                dp_sit[i] = 1 + max(dp_sit[i+1], dp_nosit[i+1]) - max(dp_nosit[p[i]], dp_sit[p[i]]);
            }
            dp_nosit[i] = max(dp_sit[i+1], dp_nosit[i+1]);
        }
        cout<<max(dp_sit[0], dp_nosit[0])<<"\n";
    }
}