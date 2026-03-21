#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x,m;
        cin>>n;
        cin>>x;
        cin>>m;
        int left_max = x;
        int right_max = x;
        while(m--)
        {   
            int l, r;
            cin>>l;
            cin>>r;

            if((left_max <= r && left_max >= l) || (right_max <= r && right_max >= l))
            {
                left_max = min(left_max, l);
                right_max = max(r, right_max);
            }
        }
        cout<<(right_max - left_max + 1)<<endl;
    }
}