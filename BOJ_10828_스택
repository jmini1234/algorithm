#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

using namespace std;


int main() {
	int num;
	cin >> num;

	// 스택은 나가고 들어오는 곳이 top 한곳밖에 없음 
	// 처음 값은 -1 
	int top = -1;

	//메모리 동적 할당 
	int *arr = (int *)malloc(sizeof(int)*num);


	for (int i = 0; i < num; i++) {
		string cmd;
		cin >> cmd;
		//push 일때는 val을 입력 받는다
		if (cmd == "push") {
			int val;
			cin >> val;
			arr[++top] = val;
			
		}
		else if (cmd == "pop")
		{
			int pop_val = arr[top];
			//top이 -1이라는 것은 배열에 아무것도 들어있지 않다는 것 
			if (top==-1) {
				cout << "-1" << "\n";
			}
			else {
				//pop은 값을 빼야하니까 top을 하나줄인다. 
				cout  << pop_val << "\n";
				top--;
			}
		}
		else if (cmd == "size")
		{
			//top에 +1한 값이 사이즈 
			cout  << top+1 << "\n";
		}
		else if (cmd == "empty")
		{
			if (top==-1)
				cout  << "1" << "\n";
			else
				cout<< "0" << "\n";
		}
		else {
			int pop_val = arr[top];
			if (top == -1) {
				cout << "-1" << "\n";
			}
			else {
				cout  << pop_val << "\n";
			}
		}
		

	}
	

}
