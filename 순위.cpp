#include <string>
#include <vector>

using namespace std;
int arr[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=0;i<results.size();i++){
        arr[results[i][0]][results[i][1]] = 1;
    }
    // 플로이드 와샬 알고리즘을 사용
    for(int t=1;t<=n;t++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][t]==1 && arr[t][j]==1)
                    arr[i][j] = 1;
            }
        }
    }
    for(int t=1;t<=n;t++){
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=(arr[t][i] + arr[i][t]);
        }
        if(cnt==n-1)
            answer++;
    }
    
    return answer;
}
