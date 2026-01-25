#include <iostream>
#include <vector>
#include "TestUtils.h"

#define LOG(x) std::cout << x << std::endl

using std::vector;

namespace ProblemName {

    class Solution {
    public:
        int problemName() {
            return 0;
        }
    };

    struct TestCase {
    };

    void test() {
        Solution solution;

        std::vector<TestCase> testCases = {
        };

        TestUtils::runTests(testCases, [&](TestCase testCase) {
            int result = solution.problemName();
            if (result == 0) {
                return true;
            } else {
                return false;
            }
        });
    }

}