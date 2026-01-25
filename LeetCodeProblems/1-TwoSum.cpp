#include <iostream>
#include <vector>
#include <unordered_map>
#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::vector;
using std::unordered_map;

namespace TwoSum {

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pairsMap;
        pairsMap.reserve(nums.size());
        for (size_t i = 0; i < nums.size(); i++) {
            int num = nums[i];
            auto pairIt = pairsMap.find(num);
            if (pairIt != pairsMap.end()) {
                return { static_cast<int>(i), static_cast<int>(pairIt->second) };
            }
            int pairValue = target - num;
            pairsMap[pairValue] = static_cast<int>(i);
        }
        return { -1, -1 };
    }
};

struct TestCase {
    vector<int> numbersArray;
    int target;
};

void test() {
    Solution solution;

    vector<TestCase> testCases = {
        // 1. Standard positive numbers
        { { 2, 11, 7, 15 }, 9 },
        // 2. The solution is at the very end of the array
        { { 3, 2, 4 }, 6 },
        // 3. Array has only two elements (the minimum size)
        { { 3, 3 }, 6 },
        // 4. Using the same value twice, but at different indices
        { { 2, 5, 5, 11 }, 10 },
        // 5. Negative numbers
        { { -1, -2, -3, -4, -5 }, -8 },
        // 6. Including zero
        { { 0, 4, 3, 0 }, 0 },
        // 7. Large numbers (within int limits)
        { { 1000000, 500, 1000000 }, 2000000 }
    };


    TestUtils::runTests(testCases, [&](TestCase& testCase) {
        vector<int> twoSumResult = solution.twoSum(
            testCase.numbersArray,
            testCase.target
        );

        int index1 = twoSumResult[0];
        int index2 = twoSumResult[1];

        if (index1 < 0 || index1 >= testCase.numbersArray.size()) {
            LOG("[Exception] Index 1 of solution (" << index1 << ") is invalid");
        }
        if (index2 < 0 || index2 >= testCase.numbersArray.size()) {
            LOG("[Exception] Index 2 of solution (" << index2 << ") is invalid");
        }
        if (index1 == index2) {
            LOG("[Exception] Index 1 of solution (" << index2 << ") is equals to index 2");
        }

        int solutionResult = testCase.numbersArray[index1] +
            testCase.numbersArray[index2];

        if (solutionResult == testCase.target) {
            LOG("[Success] " << solutionResult << " == " << testCase.target);
            return true;
        }
        else {
            LOG("[Failed] " << solutionResult << " != " << testCase.target);
        }
        return false;
    });

}

}