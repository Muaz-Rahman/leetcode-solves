/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
#include "commonHeader.h"

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        // first order of business, store the roman numerals with their corresponding integer values
        unordered_map<char, int> values;
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;
        int size = s.size();
        int integerResult = 0;
        for (int i = 0; i < size; i++)
        {
            // as we need to ensure that i+1 doesn't go to an out of bound value, but also the subtraction only occurs if the NEXT character is greater
            // that is, the last character can ONLY be added
            if (i < size - 1 && values[s[i]] < values[s[i + 1]])
            {
                integerResult -= values[s[i]];
            }
            else
                integerResult += values[s[i]];
        }
        return integerResult;
    }
};
// @lc code=end
