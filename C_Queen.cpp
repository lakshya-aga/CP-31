#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> is_not_respected(n+1, 1);
    vector<int> disrespects_parent(n+1, 0);
    int root;
    for(int i = 1; i<=n; i++){
        int parent, disrespect;
        cin>>parent>>disrespect;
        disrespects_parent[i] = disrespect;
        if(parent!=-1)
        is_not_respected[parent] = is_not_respected[parent] && disrespect;
        else
        root = i;
    }
    int count= 0;
    for(int i = 1; i<=n; i++){
        if(is_not_respected[i] && disrespects_parent[i] && i!=root)
        {
            cout<<i<<' ';
            count++;
        }

    }
    if(count==0){
        cout<<-1<<endl;
    }
    cout<<endl;
}
