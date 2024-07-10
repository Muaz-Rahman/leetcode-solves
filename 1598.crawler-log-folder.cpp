#include "commonHeaderMac.h"
/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int steps = 0;
        for (size_t i = 0; i < logs.size(); i++)
        {
            // assuming the root folder to be position 0, it should be impossible to go above the root folder
            // so the steps variable can only be equal to or greater than 0
            if (logs[i] == "../" && steps != 0)
                steps -= 1;
            else if (logs[i] == "../" && steps == 0)
                continue;
            else if (logs[i] == "./")
                continue;
            else
                steps += 1;
        }
        if (steps == 0)
            return 0;
        else
            return steps;
    }
};
// @lc code=end
