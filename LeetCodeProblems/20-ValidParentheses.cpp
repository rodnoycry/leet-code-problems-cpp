#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::vector;
using std::string;

namespace ValidParentheses {
    std::unordered_map<char, int> openingCharsMap = {
        {'(', 1},
        {'[', 10},
        {'{', 100},
    };

    std::unordered_map<char, int> closingCharsMap = {
        {')', -1},
        {']', -10},
        {'}', -100},
    };

    class Solution {
    public:
        bool isValid(const string& s) {
            int sum = 0;
            int lastCharValue = 0;
            for (const char c : s) {
                int value;
                auto it = openingCharsMap.find(c);
                if (it != openingCharsMap.end()) {
                    value = it->second;
                }
                else {
                    value = closingCharsMap[c];
                }
                if (value < 0) {
                    int temp = lastCharValue + value;
                    if ((lastCharValue + value) != 0) return false;
                }
                lastCharValue = value;
                sum += value;
            }
            return sum == 0;
        }
    };

    struct TestCase {
        const std::string testString;
        bool answer;
    };

    void test() {
        Solution solution;

        std::vector<TestCase> testCases = {
            { "()", true },
            { "[({})]", true },
            { "[](){}", true },
            { "[]({}){}", true },
            { "[]({}}){}", false },
            { "[(}]", false },
            { "(((((((((((]", false },
        };

        TestUtils::runTests(testCases, [&](TestCase testCase) {
            bool result = solution.isValid(testCase.testString);
            if (result == testCase.answer) {
                LOG("[Success] " << testCase.testString << " validated as " << result);
                return true;
            }
            else {
                LOG("[Failed] " << testCase.testString << " validated as " << result);
                return false;
            }
            });
    }

}