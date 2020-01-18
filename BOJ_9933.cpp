#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int a;
	cin >> a;

	set <string> str_set;
	for (int i = 0; i < a; i++) {
		string str;
		cin >> str;
		//string이 set에 없을 때 
		if (str_set.find(str) == str_set.end()) {
			str_set.insert(str);
			reverse(str.begin(), str.end());
			//string 바꿔본다. 
			if (str_set.find(str) != str_set.end()) {
				//reverse 했는데 있으면 -> 즉 앞뒤 바꿔도 똑같은 string일때는 end 가 아닐 것이다. 
				cout << str.length() << " " << str[str.length() / 2];
			}
		}
		else {
			cout << str.length() << " " << str[str.length() / 2];
		}
	}

}