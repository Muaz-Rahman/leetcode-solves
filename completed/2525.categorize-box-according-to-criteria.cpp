/*
 * @lc app=leetcode id=2525 lang=cpp
 *
 * [2525] Categorize Box According to Criteria
 */
#include "commonHeader.h"
// @lc code=start
class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        // let's store the dimensions in an array to make things easier to write
        long long dim[3] = {length, width, height};
        long long volume = 1;
        // store the description of the box as boolean values
        bool isHeavy = 0, isBulky = 0;
        if (mass >= 100)
            isHeavy = 1;
        for (int i = 0; i < 3; i++)
        {
            volume *= dim[i];
            if (dim[i] >= 10000)
                isBulky = 1;
        }
        if (volume >= pow(10, 9))
            isBulky = 1;
        if (isBulky && isHeavy)
            return "Both";
        else if (isBulky && !isHeavy)
            return "Bulky";
        else if (!isBulky && isHeavy)
        {
            return "Heavy";
        }
        else
            return "Neither";
    }
};
// @lc code=end
