#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//x,y 가 쌍이니까 구조체 정의
struct Dot {
	int x;
	int y;
};

// 비교함수, & 는 참조변수 => call by reference, 객체를 만들지 않으므로 얕은 복사, 즉 메모리 사용이 줄어든다. 
// const 하면 읽기 전용, 값을 수정하지 않음 
// 여기선 단순히 정렬만하는 것이니까 const 사용 
bool cmp(const Dot &d1, const Dot &d2) {
	if (d1.x != d2.x)
		return d1.x < d2.x;
	else if (d1.x == d2.x)
		return d1.y < d2.y;
}

int main() {
	int n;
	cin >> n;
  
	vector<Dot>dot(n);


	for (int i = 0; i < n; i++) {
		cin >> dot[i].x >> dot[i].y; 
	}

	sort(dot.begin(), dot.end(), cmp);


	for (int i = 0; i < n; i++) {
		cout << dot[i].x << ' ' << dot[i].y << "\n";
	}
	
}
