#include <iostream>
#include <vector>
#include <string>
#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::string;

namespace RomanToInteger {

    class Solution {
    public:
        int romanToInt(string s) {

        }
    };

    struct TestCase {
    };

    void test() {
        Solution solution;

        std::vector<TestCase> testCases = {
        };

        TestUtils::runTests(testCases, [&](TestCase testCase) {
            int result = solution.romanToInt();
            if (result == 0) {
                return true;
            }
            else {
                return false;
            }
            });
    }

}