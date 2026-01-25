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
            int result = 0;
            int prevValue = -1;
            for (const char c : s) {
                int charValue = 0;
                switch (c){
                    case 'I': charValue = 1;
                    case 'V': charValue = 5;
                    case 'X': charValue = 10;
                    case 'L': charValue = 50;
                    case 'C': charValue = 100;
                    case 'D': charValue = 500;
                    case 'M': charValue = 1000;
                }
                if (charValue < prevValue) {
                    result -= charValue;
                }
                else {
                    result += charValue;
                }
                prevValue = charValue;
            }
            return result;
        }
    };

    struct TestCase {
        std::string str;
        int value;
    };

    void test() {
        Solution solution;

        std::vector<TestCase> testCases = {
            { "III", 3 },
            { "LVIII", 58 },
            { "MCMXCIV", 1994 },
        };

        TestUtils::runTests(testCases, [&](TestCase testCase) {
            int result = solution.romanToInt(testCase.str);
            if (result == testCase.value) {
                return true;
            }
            else {
                return false;
            }
            });
    }

}