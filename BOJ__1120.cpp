#include <iostream>
#include <string>


using namespace std;

int main() {
	string a;
	string b;

	cin >> a >> b;

	int len_a = a.length();
	int len_b = b.length();

	int gap = len_b - len_a; //a와 b의 size 차이 
	int res = 50;
	int tmp = 0;

//a의 문자열에 붙이는 알파벳은 b의 알파벳과 같다고 가정하고 차이 계산 

	for (int i = 0; i <= gap; i++) {
		for (int j = 0; j < len_a; j++) {
				if (a[j] != b[i+j]) {
					tmp++;
			}
		}
		if (tmp < res)
			res = tmp;
		tmp = 0;
	}
	printf("%d", res);

	//adaabc 
	//aababbc
}
