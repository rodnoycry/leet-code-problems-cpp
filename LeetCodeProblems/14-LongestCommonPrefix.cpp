#include <iostream>
#include <vector>
#include <string>
#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::vector;
using std::string;

namespace LongestCommonPrefix {

    class Solution {
    public:
        string longestCommonPrefix(const vector<string>& strs) {
            string commonPrefix = "";
            return commonPrefix;
        }
    };

    struct TestCase {
        const std::vector<std::string>& strings;
        const std::string& answer;
    };

    void test() {
        Solution solution;

        std::vector<TestCase> testCases = {
        };

        TestUtils::runTests(testCases, [&](TestCase testCase) {
            std::string result = solution.longestCommonPrefix(
                testCase.strings
            );
            if (result == testCase.answer) {
                return true;
            }
            else {
                return false;
            }
            });
    }

}