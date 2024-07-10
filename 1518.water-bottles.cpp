#include "commonHeaderMac.h"
/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        // the number of bottles used will always be at least equal to the numBottles param
        int drankBottleNumber = numBottles;
        int leftOverBottles = 0;
        while (numBottles >= numExchange)
        {
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }
        // leftOverBottles += numBottles;
        if (leftOverBottles > numExchange)
            drankBottleNumber += leftOverBottles / numExchange;
        return drankBottleNumber;
    }
};
// @lc code=end

int main()
{
    Solution x = Solution();
    cout << x.numWaterBottles(15, 4);
    cout << endl;
}