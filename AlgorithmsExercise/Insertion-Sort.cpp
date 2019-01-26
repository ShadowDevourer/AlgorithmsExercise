#include<iostream>

int main() {
	int a[5]{ 5,2,4,1,3 };
	//Insertion-Sort
	for (int j = 1; j < 5; j++) {
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i = i - 1;
			a[i + 1] = key;
		}
	}
	int *ptr = a;
	int count = 0;
	
	while (count<(sizeof(a)/sizeof(int))) {
		std::cout << *ptr << " ";
		ptr++;
		count++;
	}
	std::cout << std::endl;
	std::getchar();
	return 0;
}