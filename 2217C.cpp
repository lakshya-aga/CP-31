/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <numeric>

using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--){
    int a,b,n,m;
    cin>>n>>m>>a>>b;
    bool cond1 = gcd(n, a) == 1;
    bool cond2 = gcd(m, b) == 1;
    bool cond3 = gcd(n, m) == 2 || gcd(n, m)==1;
    
    if(cond1 && cond2 && cond3)
    cout<<"YES"<<endl;
    
    else
    cout<<"No"<<endl;
        
    }
}