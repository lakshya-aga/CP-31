#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;

int main()
{
    int count;
    // cout<<"Input"<<endl;
    cin>>count;
    while(count--)
    {
        int num;
        cin>>num;
        unordered_map<int, int> lookup;
        vector<vector<int>> arr2d;
        while(num--) // for every c
        {
            int digits;
            cin>>digits; // for number of 1s in c
    
            vector<int> curr_vec; 
            while(digits--){
                int curr;
                cin>>curr;
                lookup[curr]++;
                curr_vec.push_back(curr);
            }
            // cout<<"==========";
            // for(auto i: curr_vec)
            //     cout<<i<<" ";
            // cout<<"\n";
            // cout<<"==========";

            arr2d.push_back(curr_vec);
        }
        bool ans = false;
        for(auto vec: arr2d)
        {
            bool has_all_redundant = true;
            for(auto num: vec)
                has_all_redundant = has_all_redundant && lookup[num]!=1;
            if (has_all_redundant)
            {
                ans = true;
                break;
            }
            
        }
        cout<< (ans ? "Yes": "No") <<endl;
    }

}