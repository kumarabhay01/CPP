#include <iostream>
#include <vector>
#include <climits>

int minJumpsToReachEnd(const std::vector<int>& ARR) {
    int N = ARR.size();
    std::vector<int> min_jumps(N, INT_MAX);
    min_jumps[0] = 0;

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (j + ARR[j] >= i) {
                min_jumps[i] = std::min(min_jumps[i], min_jumps[j] + 1);
            }
        }
    }

    return min_jumps[N - 1];
}

int main() {
    std::vector<int> ARR = { 2, 3, 1, 1, 4 };
    int result = minJumpsToReachEnd(ARR);
    std::cout << "Minimum jumps to reach end: " << result << std::endl;
    return 0;
}
