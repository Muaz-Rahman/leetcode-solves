/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
#include "commonHeader.h"
// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string inputString = "Hello, @World! 123";
        regex pattern("[^a-zA-Z0-9]");
        string result = regex_replace(s, pattern, "");
    }
};
// @lc code=end
