#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans = {0,0};
    
    if(v[0][0] == v[1][0])
        ans[0] = v[2][0];
    if(v[0][0] == v[2][0])
        ans[0] = v[1][0];
    if(v[1][0] == v[2][0])
        ans[0] = v[0][0];    
    
    if (v[0][1]==v[1][1])
        ans[1] = v[2][1];
    if(v[0][1] == v[2][1])
        ans[1] = v[1][1];
    if(v[1][1] == v[2][1])
        ans[1] = v[0][1];  

    return ans;
}

// xor 사용하는 방법 
// 같은거면 항상 0 , 0과 다른 문자는 항상 다른 문자 
// 같으면 0 , 다르면 1 
// ans[0] ^= v[i][0]
// ans[1] ^= v[i][1]
