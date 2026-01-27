#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::vector;
using std::string;

namespace ValidParentheses {
    class Solution {
    private:
        std::unordered_map<char, int> m_ClosingCharsMap = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
    public:
        bool isValid(const string& s) {
            std::string charsStack;
            charsStack.reserve(s.length());

            for (char c : s) {
                auto it = m_ClosingCharsMap.find(c);
                if (it != m_ClosingCharsMap.end()) {
                    if (charsStack.empty() || charsStack.back() != it->second) {
                        return false;
                    }
                    charsStack.pop_back();
                }
                else {
                    charsStack.push_back(c);
                }
            }
            return charsStack.empty();
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