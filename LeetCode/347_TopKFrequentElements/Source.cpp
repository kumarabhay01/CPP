#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

struct freq_order {
    bool operator() (const std::pair<int, int>& l, const std::pair<int, int>& r) {
        if (l.second == r.second) {
            return l.first > r.first;
        }
        return l.second > r.second;
    }
};
using MinHeap = priority_queue<pair<int, int>, vector<pair<int, int>>, freq_order>;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret{};
        unordered_map<int, int> freqs{};
        for (const auto i : nums) {
            freqs[i]++;
        }

        if (freqs.size() <= k) {
            for (const auto& pair_r : freqs) {
                ret.push_back(pair_r.first);
            }
        }
        else {
            MinHeap h{};
            for (const auto& pair_r : freqs) {
                h.push(pair_r);
                if (h.size() > k) {
                    h.pop();
                }
            }

            while (!h.empty()) {
                ret.push_back(h.top().first);
                h.pop();
            }
        }

        return ret;
    }
};