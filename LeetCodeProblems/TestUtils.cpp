#include <vector>
#include <iostream>
#include <concepts>
#include <functional>

template <typename T, typename F>
concept TestProcessor = requires(F func, T testCase) {
    {func(testCase)} -> std::convertible_to<bool>;
};

template <typename T>
void runTests(const std::vector<T>& testCases, TestProcessor<T> auto processTest) {
    int successPassCount = 0;
    int totalTests = testCases.size();

    for (size_t i = 0; i < testCases.size(); i++) {
        std::cout << "[Test Case #" << i << "] ";

        if (processTest(testCases[i])) {
            successPassCount++;
            std::cout << "[Success] " << std::endl;
        }
        else {
            std::cout << "[Failed] " << std::endl;
        }
    }

    if (successPassCount < totalTests) {
        std::cout << "FAILED: " << successPassCount << " / " << totalTests << " PASSED" << std::endl;
    }
    else {
        std::cout << "SUCCESS: " << successPassCount << " / " << totalTests << " PASSED" << std::endl;
    }
}