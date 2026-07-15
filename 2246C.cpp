#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // your code here

    return 0;
}

// if no -1:
/*
Just get freq of each and multiple NC2 for each unique number

*/
// if -1 present
/*
after building a get 0 array representing cost of ways to get zero starting from index + 1;
sum it for each unique value

freq[n] * sum_get1[n+1]
*/
