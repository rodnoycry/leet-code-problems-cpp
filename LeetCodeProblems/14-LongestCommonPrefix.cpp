#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::vector;
using std::string;

namespace LongestCommonPrefix {
    class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string& lastString = strs[0];
            for (size_t i = 1; i < strs.size(); i++) {
                string& currentString = strs[i];
                size_t leastStrLength = std::min(lastString.length(), currentString.length());

                for (size_t i = 0; i < leastStrLength; ++i) {
                    // A bit of bitwise masking to get only repeating strings and \0 at 
                    // all other places
                    lastString[i] = lastString[i] & -(lastString[i] == currentString[i]);
                }
            }
            // We need to resize the thing because we will have something like "pre\0\0s\0" and
            // we clear everything till first null terminator character by treating it as regular string
            // and we get pointer to the data by .data() and strlen to get length till first null
            // terminator character
            lastString.resize(strlen(lastString.data()));
            return lastString;
        }
    };

    struct TestCase {
        std::vector<std::string> strings;
        std::string answer;
    };

    // Making \0 visible in logs
    static std::string visualizeString(const std::string& s) {
        std::string res = "";
        for (char c : s) {
            if (c == '\0') res += "\\0";
            else res += c;
        }
        return res;
    }

    void test() {
        Solution solution;

        std::vector<TestCase> testCases = {
            // 1. The "Standard" case
            { {"flower", "flow", "flight"}, "fl" },

            // 2. No common prefix at all (should result in an empty string)
            { {"dog", "racecar", "car"}, "" },

            // 3. Only one string in the vector (The prefix is the string itself)
            { {"single"}, "single" },

            // 4. The first string is very long, others are short
            // (Crucial for your "in-place" logic!)
            { {"abracadabra", "ab", "abc"}, "ab" },

            // 5. The strings are identical
            { {"test", "test", "test"}, "test" },

            // 6. One of the strings is empty
            { {"", "b", "c"}, "" },
            { {"a", "", "c"}, "" },

            // 7. The common prefix is the entire first string
            { {"low", "lower", "lowest"}, "low" },

            // 8. Strings with only one character (matching)
            { {"a", "a", "a"}, "a" },

            // 9. Strings with only one character (not matching)
            { {"a", "b", "c"}, "" }
        };

        TestUtils::runTests(testCases, [&](TestCase& testCase) {
            std::string result = solution.longestCommonPrefix(testCase.strings);

            // Format the strings to see null terminator characters
            std::string visualResult = visualizeString(result);
            std::string visualAnswer = visualizeString(testCase.answer);

            if (result == testCase.answer) {
                LOG("[SUCCESS] \"" << visualResult << "\" == \"" << visualAnswer << "\"");
                return true;
            }
            else {
                LOG("[FAIL] \"" << visualResult << "\" != \"" << visualAnswer << "\"");
                return false;
            }
        });
    }

}