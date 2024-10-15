#pragma once
#include<vector>

using namespace std;

class InsertionSort {
public:
	void insertionSort(vector<int>& vec) {
		size_t vecSize = vec.size();
		int j{}, x{};
		for (int i = 1; i < vecSize; i++) {
			j = i - 1;
			x = vec.at(i);
			while (j > -1 && vec.at(j) > x) {
				vec[j + 1] = vec[j];
				j--;
			}
			vec[j + 1] = x;
		}
	}
};