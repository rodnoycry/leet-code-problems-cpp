#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

namespace TwoSum {

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return { 0, 1 };
    }
};

struct TestCase {
    vector<int> numbersArray;
    int target;
};

int test() {
    Solution solution;

    vector<TestCase> testCases = {
        {
            { 0, 3, 5, 7 },
            8
        },
    };

    for (int i = 0; i < testCases.size(); i++) {
        TestCase testCase = testCases[i];
        vector<int> twoSumResult = solution.twoSum(
            testCase.numbersArray,
            testCase.target
        );

        int index1 = twoSumResult[0];
        int index2 = twoSumResult[1];
        std::cout << "[Test Case #" << i << "] ";
        if (index1 < 0 || index1 > testCase.numbersArray.size()) {
            std::cout << "[Exception] Index 1 of solution (" << index1 << ") is invalid" << std::endl;
            return -1;
        }
        if (index2 < 0 || index2 > testCase.numbersArray.size()) {
            std::cout << "[Exception] Index 2 of solution (" << index2 << ") is invalid" << std::endl;
            return -1;
        }
        if (index1 == index2) {
            std::cout << "[Exception] Index 1 of solution (" << index2 << ") is equals to index 2" << std::endl;
            return -1;
        }

        int solutionResult = testCase.numbersArray[index1] +
            testCase.numbersArray[index2];

        if (solutionResult == testCase.target) {
            std::cout << "[Success] " << solutionResult << " == " << testCase.target << std::endl;
            return 0;
        }
        else {
            std::cout << "[Failed] " << solutionResult << " != " << testCase.target << std::endl;
            return 0;
        }
    }
}

}