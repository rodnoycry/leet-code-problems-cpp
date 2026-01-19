#include <iostream>
#include <vector>

#define LOG(x) std::cout << x << std::endl

using std::vector;

namespace PalindromeNumber {

    class Solution {
    public:
        bool isPalindrome(int x) {
            return false;
        }
    };

    struct TestCase {
        int number;
        bool result;
    };

    void test() {
        Solution solution;

        vector<TestCase> testCases = {
            { 1, true },
            { 1234, false },
            { 121, true },
            { 123454321, true },
        };

        int successPassCount = 0;
        int totalTests = testCases.size();

        for (size_t i = 0; i < testCases.size(); i++) {
            TestCase& testCase = testCases[i];
            int result = solution.isPalindrome(
                testCase.number
            );

            std::cout << "[Test Case #" << i << "] ";

            if (result == testCase.result) {
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