#include <iostream>
#include <vector>
#include <cmath>
int main(){
    using namespace std;

    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;
        int m_copy = m;
        int m_num_digits = 0;
        vector<int> max_dig(20);
        while(m!=0){
            m_num_digits = m_num_digits+1;
            m=m/10;
        } 
        m = m_copy;
        for(int i=1; i<=m_num_digits; i++){
            int curr = m / pow(10, i);
            curr = curr * pow(10, i);
            int potential_ans1 = n*min(2* int(pow(10, i)), curr);
            int potential_ans2 = n*min(5* int(pow(10, i)), curr);
            int potential_ans3 = curr;
        }
    }
}