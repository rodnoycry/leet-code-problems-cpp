#include <iostream>
#include <vector>
#include <string>
#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::vector;
using std::string;

namespace ValidParentheses {
    class Solution {
    public:
        bool isValid(string s) {
            return false;
        }
    };

    struct TestCase {
        std::string testString;
        bool answer;
    };

    void test() {
        Solution solution;

        std::vector<TestCase> testCases = {
        };

        TestUtils::runTests(testCases, [&](TestCase testCase) {
            bool result = solution.isValid(testCase.testString);
            if (result == testCase.answer) {
                return true;
            }
            else {
                return false;
            }
            });
    }

}