#include <string>
#include <vector>
#include <string>

using namespace std;
// 각 달마다 요일 수 
int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
string day[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};

string solution(int a, int b) {
    string answer = "";
    int date = 0;
    for(int i=0;i<a-1;i++)
        date+=month[i];
    date = date + b - 1;
    answer += day[date%7];
    return answer;
}
