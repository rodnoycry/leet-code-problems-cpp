#include <iostream>
#include <vector>
#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::vector;

namespace RomanToInteger {

    class Solution {
    public:
        int problemName() {
            return 0;
        }
    };

    struct TestCase {
    };

    void test() {
        Solution solution;

        vector<TestCase> testCases = {
        };

        int successPassCount = 0;
        int totalTests = testCases.size();

        for (size_t i = 0; i < testCases.size(); i++) {
            TestCase& testCase = testCases[i];
            int result = solution.problemName(
            );

            std::cout << "[Test Case #" << i << "] ";

            if (result) {
                successPassCount++;
                std::cout << "[Success] " << std::endl;
            }
            else {
                std::cout << "[Failed] " << std::endl;
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