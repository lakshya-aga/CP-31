#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map<int, vector<int>> adj_list;
string colors;
unordered_map<int, int> balance;
int get_balance(int node)
{
    int color = colors[node-1]=='W' ? 1 : -1;
    if(balance.find(node) != balance.end())
    return balance[node];
    else
    {
        for(auto i: adj_list[node])
        {
            color += get_balance(i);
        }
        balance[node] = color;
        return color;
    }
}
int main()
{
    int t;
    // cout<<"enter"<<endl;
    cin>>t;

    while(t--)
    {
        int num_nodes;
        cin>>num_nodes;
        unordered_map<int, vector<int>> temp;
        adj_list = temp;
        for (int i=2; i<=num_nodes; i++)
        {
            int temp;
            cin>>temp;   
            adj_list[temp].push_back(i);
        }
        cin>>colors;
        // cout<<colors<<endl;
        int ans = 0;
        get_balance(1);
        for (int i=1; i<=num_nodes; i++)
        ans+= get_balance(i) == 0 ? 1 : 0;
        cout<<ans<<endl;
        unordered_map<int, int> x;
        balance = x;
    }
}