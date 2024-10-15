#include<iostream>
#include"BubbleSort.h"
#include"InsertionSort.h"

using namespace std;

void diplay(vector<int> vec) {
	for (int data : vec) {
		cout << data << " ";
	}
	cout << endl;
}

int main() {
	vector<int> vec{ 11,13,7,12,16,9,24,5,3 };
	BubbleSort bSort;
	bSort.bubbleSort(vec);
	diplay(vec);

	vec = { 11,13,7,10,12,16,9,24,5,3 };
	InsertionSort iSort;
	iSort.insertionSort(vec);
	diplay(vec);
	return 0;
}