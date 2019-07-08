#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/min-cost-climbing-stairs/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    int minCostClimbingStairs(vector<int> &cost) {
        switch (cost.size()) {
            case 0 : return 0;
            case 1 : return cost[0];
            case 2 : return min(cost[0], cost[1]);
            default: break;
        }
        // reusing the same vector for path cost
        for (int i = 2; i < cost.size(); ++i) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};

void test1() {
    vector<int> v1{10, 15, 20};

    cout << "15 ? " << Solution().minCostClimbingStairs(v1) << endl;

    vector<int> v2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    cout << "6 ? " << Solution().minCostClimbingStairs(v2) << endl;
}

void test2() {

}

void test3() {

}