#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>

#define LOG(x) std::cout << x << std::endl

using std::vector;

namespace PalindromeNumber {
    // Find out the length of array of decimal digits we need to reserve in array
    constexpr int maxIntDigits = std::numeric_limits<int>::digits10 + 1;

    class Solution {
    public:
        bool isPalindrome(int x) {
            // Negative numbers does not fit because of "-" symbol in the start
            if (x < 0) return false;

            int digits[maxIntDigits];
            int digitsLength = 0;

            int remainingValue = x;

            do {
                std::div_t result = std::div(remainingValue, 10);
                // Appending extracted digit to an array of digits
                digits[digitsLength] = result.rem;
                digitsLength++;
                // Assigning "remaining" value to processing variable
                remainingValue = result.quot;
            } while (remainingValue != 0); // Remaining value 0 means we split whole nubmer into decimal digits

            for (unsigned int i = 0; i < digitsLength / 2; i++) {
                if (digits[i] != digits[digitsLength - 1 - i]) {
                    return false;
                };
            };
            return true;
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
            // All negative numbers falsy because of "-" sign
            { -123454321, false },
            { -6767621, false },
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