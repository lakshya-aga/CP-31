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

    vector<int> arr = { 4, 8, 15, 16, 23, 42};
    unordered_map<int, set<int>> pairs;
    for(int i=0; i<5; i++){
        for(int j=i+1; j<6; j++)
        pairs[arr[i]*arr[j]] = {arr[i], arr[j]};
    }
    int ans_1, ans_2, ans_3, ans_4;
    cout<<"? "<<1<<" 2"<<endl;
    cin>>ans_1;
    cout<<"? "<<2<<" 3"<<endl;
    cin>>ans_2;
    cout<<"? "<<4<<" 5"<<endl;
    cin>>ans_3;
    cout<<"? "<<5<<" 6"<<endl;
    cin>>ans_4;
    vector<int> result;
    // vector<int> result;
    
    set_intersection(pairs[ans_1].begin(), pairs[ans_1].end(),
                              pairs[ans_2].begin(), pairs[ans_1].end(),
                              back_inserter(result));
    arr[1] = result[0];
    arr[0] = ans_1/arr[1];
    arr[2] = ans_2/arr[1]; 
    set_intersection(pairs[ans_3].begin(), pairs[ans_3].end(),
                              pairs[ans_4].begin(), pairs[ans_4].end(),
                              back_inserter(result));
    arr[4] = result[1];
    arr[3] = ans_3/arr[4];
    arr[5] = ans_4/arr[4]; 
    cout<<"! ";
    for(auto i: arr){
        cout<<i<<" ";
    }
    // 32
    // 120
    // 368
    // 966
 
}