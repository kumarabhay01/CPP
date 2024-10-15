#pragma once
#include<vector>

using namespace std;

class BubbleSort{
public:
	void bubbleSort(vector<int>& vec) {
		size_t vecSize = vec.size();
		for (int i = 0; i < vecSize; i++) {
			bool SwapHappned = false;
			for (int j = 0; j < vecSize - 1 - i; j++) {
				if (vec[j] > vec[j + 1]) {
					std::swap(vec[j], vec[j + 1]);
					SwapHappned = true;
				}	
			}
			if (!SwapHappned)
				break;
		}
	}
};