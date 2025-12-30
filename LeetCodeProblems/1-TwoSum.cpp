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

void test() {
    Solution solution;

    vector<TestCase> testCases = {
        {
            { 0, 3, 5, 7 },
            8
        },
        {
            { 1, 5, 3, 8 },
            6
        },
    };

    for (size_t i = 0; i < testCases.size(); i++) {
        const TestCase& testCase = testCases[i];
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
            std::cout << "[Success] " << solutionResult << " == " << testCase.target << std::endl;
        }
        else {
            std::cout << "[Failed] " << solutionResult << " != " << testCase.target << std::endl;
        }
    }
}

}