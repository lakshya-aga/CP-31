#include <iostream>

#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    double avg = 0.0;
    long long total;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        // avg = avg + arr[i]*1.0*min(i+1, min(k, n-i))/(n-k+1);
        total += arr[i]*1.0*min(i+1, min(k, n-i));
    }
    cout<<total/(n-k+1)<<endl;
}