#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::string;

namespace RomanToInteger {
    class Solution {
    public:
        int romanToInt(const string& s) {
            int result = 0;
            int prevValue = std::numeric_limits<int>::max();
            for (const char c : s) {
                int intValue = 0;
                switch (c){
                    case 'I': intValue = 1; break;
                    case 'V': intValue = 5; break;
                    case 'X': intValue = 10; break;
                    case 'L': intValue = 50; break;
                    case 'C': intValue = 100; break;
                    case 'D': intValue = 500; break;
                    case 'M': intValue = 1000; break;
                }
                result += intValue;

                if (intValue > prevValue) {
                    result -= prevValue * 2;
                }
                prevValue = intValue;
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
            { "XIV", 14 }, // 10 + 1 + 5 - 2
            { "LVIII", 58 },
            { "MCMXCIV", 1994 },
        };

        TestUtils::runTests(testCases, [&](TestCase testCase) {
            int result = solution.romanToInt(testCase.str);
            if (result == testCase.value) {
                LOG("[Success] " << result << " == " << testCase.value);
                return true;
            }
            else {
                LOG("[Failed] " << result << " != " << testCase.value);
            }
            });
    }

}