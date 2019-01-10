#include<iostream>

typedef char* ptrstring;
int main() {
	const ptrstring cstr = 0;
	*cstr = 'a';
	char a{ '4' };
	//q = &a;
	return 0;
}