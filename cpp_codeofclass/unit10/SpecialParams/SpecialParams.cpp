#include<iostream>
#include<array>
#include<string>
#include"stack.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(void) {
	string s{ "aloha,world!" };
	stack<char> stack1;//������Բ����������Ҳ����ֻ��char�������С
	for (auto x : s) {
		stack1.push(x);
	}
	cout << s << endl;
	for (; !stack1.empty();) {
		cout << stack1.pop();
	}
	cout << endl;
	return 0;
}