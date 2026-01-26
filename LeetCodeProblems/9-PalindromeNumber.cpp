#include <iostream>
#include <vector>
#include <limits>
#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::vector;

namespace PalindromeNumber {
    // Find out the length of array of decimal digits we need to reserve in array
    constexpr int maxIntDigits = std::numeric_limits<int>::digits10 + 1;

    class Solution {
    public:
        bool isPalindrome(int x) {
            // Negative numbers does not fit because of "-" symbol at the start
            if (x < 0) return false;
            // Single digit numbers are always palindromes, and helps to prevent edge case
            // of "trailing zeros" numbers exclusion for 0, which is actually is the only trailing zero palindrome
            if (x < 10) return true;

            signed int iteration = 0;

            int processedValue = 0;
            int remainingValue = x;

            int decimalNumberLength = -1;

            for (signed int i = 0; i != maxIntDigits; i++) {
                const int quotient = remainingValue / 10;
                const int remainder = remainingValue % 10;

                // Early exit because for numbers with trailing zeros (e.g. 120, 1640) palindromes
                // are impossible and will mess the logic up (what would be the palindrome for 120? "012"?)
                if (iteration == 0 && remainder == 0) return false;

                remainingValue = quotient;

                if (remainingValue == processedValue) return true;

                processedValue = (processedValue * 10) + remainder;

                if (remainingValue == processedValue) return true;

                if (processedValue >= remainingValue) {
                    return false;
                }

                iteration++;
            }

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
            { 0, true },
            { 1, true },
            { 10, false },
            { 1234, false },
            { 121, true },
            { 123321, true },
            { 123454321, true },
            // All negative numbers falsy because of "-" sign
            { -123454321, false },
            { -6767621, false },
        };

        TestUtils::runTests(testCases, [&](const TestCase& testCase) {
            bool result = solution.isPalindrome(
                testCase.number
            );
            if (result == testCase.result) {
                LOG("[Success]: " << result << " == " << testCase.result);
                return true;
            }
            else {
                LOG("[Fail]: " << result << " != " << testCase.result);
                return false;
            }
        });
    }

}