#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <set>
using namespace std;

#include <iomanip>

int main(){

    int n, m;
    cin>>n>>m;
    vector<int> counts(n, 0);
    vector<int> parents(n, n);
    for(int i=0; i<n; i++){
        parents[i] = i;
    }
    for(int i=0; i<m; i++){
        vector<int> arr;
        int x;
        cin>>x;
        for(int j=0; j<x; j++){
            int temp;
            cin>>temp;
            arr.push_back(--temp);
        }
        sort(arr.begin(), arr.end());
        auto parent = parents[arr[0]];
        while(parent!=parents[parent]){
            parent = parents[parent];
        }
        for(auto i: arr){
            parents[i] = parent;
        }
    }
    
    for(int i=0; i<n; i++){
        auto parent = parents[i];
        while(parent!=parents[parent]){
            parent = parents[parent];
        }
        parents[i] = parent;
    }
    for(int i=0; i<n; i++){
        counts[parents[i]]++;
    }
    for(int i=0; i<n; i++){
        cout<<counts[parents[i]]<<" ";
    }
    cout<<endl;

}