#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int arr[100001];
stack <int> st;
vector <char> v;
bool flag = true;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int idx = 1;
	// 배열에 들어있는 모든 수에 대해서 검사
	for (int i = 0; i < n; i++) {
		int val = arr[i];
		// empty하지 않으면 st.top을 보기 때문에 에러 발생 x
		// 오름차순으로 저장되기 때문에 더 작은 값은 이미 stack에서 나갔기 때문에 에러
		if (!st.empty() && val<st.top()) {
			flag = false;
			// 바로 for문 탈출
			break;
		}
		// 같은 값이 있으면 빼는 연산만 처리
		else if (!st.empty() && val == st.top()) {
			st.pop();
			v.push_back('-');
		}
		// 더 큰 값이 있으면 
		else {
			for (int i = idx; i <= val; i++) {
				st.push(idx);
				v.push_back('+');
				// val까지 stack에 들어갔기 때문에 결국 idx는 val+1
				idx = i + 1;
			}
			st.pop();
			v.push_back('-');
		}
	}

	if (flag==true) {
		for (int i = 0; i < v.size(); i++) {
			printf("%c\n", v[i]);
		}
	}
	else {
		printf("NO");
	}
}
