#include <iostream>
#include <vector>
#include <cmath>
int main(){
    using namespace std;

    long long t;
    cin>>t;
    ios_base::sync_with_stdio(false);
    while(t--){
        long long n, m;
        cin>>n>>m;
        long long count_2 = 0;
        long long count_5 = 0;
        while(n!=0 && n%2==0){
            n=n/2;
            count_2++;
        }
        while(n!=0 && n%5==0){
            n=n/5;
            count_5++;
        }
        long long ans = 1;
        while(count_2>count_5 && ans*5<=m){
            ans*=5;
            count_5++;
        }
        while(count_2<count_5 && ans*2<=m){
            ans*=2;
        }

        while(count_2<count_5 && ans*10<=m){
            ans*=10;
        }
        long long max_ans = n;
        if((ans*n)%10!=0){
            max_ans = n*m;
        }
        else{
            max_ans = ans*n;
        }

        cout<< max_ans;
    }
}