#include <iostream>
#include <vector>
#include <unordered_map>

#define LOG(x) std::cout << x << std::endl

using std::vector;
using std::unordered_map;

namespace TwoSum {

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pairsMap;
        for (size_t i = 0; i < nums.size(); i++) {
            int num = nums[i];
            auto pairIt = pairsMap.find(num);
            if (pairIt != pairsMap.end()) {
                int pairIndex = pairIt->second;
                return { (int)i, pairIndex };
            }
            int pairValue = target - num;
            pairsMap[pairValue] = i;
        }
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

    int successPassCount = 0;
    int totalTests = testCases.size();

    for (size_t i = 0; i < testCases.size(); i++) {
        TestCase& testCase = testCases[i];
        vector<int> twoSumResult = solution.twoSum(
            testCase.numbersArray,
            testCase.target
        );

        int index1 = twoSumResult[0];
        int index2 = twoSumResult[1];

        std::cout << "[Test Case #" << i << "] ";
        if (index1 < 0 || index1 >= testCase.numbersArray.size()) {
            std::cout << "[Exception] Index 1 of solution (" << index1 << ") is invalid" << std::endl;
        }
        if (index2 < 0 || index2 >= testCase.numbersArray.size()) {
            std::cout << "[Exception] Index 2 of solution (" << index2 << ") is invalid" << std::endl;
        }
        if (index1 == index2) {
            std::cout << "[Exception] Index 1 of solution (" << index2 << ") is equals to index 2" << std::endl;
        }

        int solutionResult = testCase.numbersArray[index1] +
            testCase.numbersArray[index2];

        if (solutionResult == testCase.target) {
            successPassCount++;
            std::cout << "[Success] " << solutionResult << " == " << testCase.target << std::endl;
        }
        else {
            std::cout << "[Failed] " << solutionResult << " != " << testCase.target << std::endl;
        }
    }

    if (successPassCount < totalTests) {
        std::cout << "FAILED: " << successPassCount << " / " << totalTests << " PASSED" << std::endl;
    }
    else {
        std::cout << "SUCCESS: " << successPassCount << " / " << totalTests << " PASSED" << std::endl;
    }
}

}