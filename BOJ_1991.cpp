#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int n;
int childLeft[30];
int childRight[30];

void preorder(int idx) {
	printf("%c",idx + 'A');
	if (childLeft[idx]!='.'-'A')
		preorder(childLeft[idx]);
	if (childRight[idx] != '.' - 'A')
		preorder(childRight[idx]);
}

void inorder(int idx) {
	if (childLeft[idx] != '.' - 'A')
		inorder(childLeft[idx]);
	printf("%c", idx + 'A');
	if (childRight[idx] != '.' - 'A')
		inorder(childRight[idx]);
}

void postorder(int idx) {
	if (childLeft[idx] != '.' - 'A')
		postorder(childLeft[idx]);
	if (childRight[idx] != '.' - 'A')
		postorder(childRight[idx]);
	printf("%c", idx + 'A');
}

int main() {
	cin >> n;

	while (n--) {
		char a, b, c;
		cin >> a >> b >> c;
		childLeft[a - 'A'] = b - 'A';
		childRight[a - 'A'] = c - 'A';
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
}
