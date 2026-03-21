#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    // while(t--)
    // {
        int n;
        cin>>n;

        // 6/2 = 3 -> odd -> 3+1
        // 4/2 = 2 -> eve -> 2+1
        if (n%2!=0){
            int vert = (n-1)/2+1;
            int horz = (n+1)/2+1;
            cout<<vert*horz*2<<endl;
        }
        else
        {
            int vert = (n)/2+1;
            int horz = (n)/2+1;
            cout<<vert*horz<<endl;

        }

    // }
}