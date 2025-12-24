/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (31.15%)
 * Likes:    15028
 * Dislikes: 13933
 * Total Accepted:    4.6M
 * Total Submissions: 14.8M
 * Testcase Example:  '123'
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers (signed
 * or unsigned).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 120
 * Output: 21
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 */

#include <cstdint>
#include <cstring>

#include <iostream>
#include <math.h>

using namespace std;


// @lc code=start
class Solution
{

public:

    int64_t reverse (int64_t x)
    {
        if (x == 0)
            return 0;

        int64_t reversed = 0;

        const bool isNegative = x < 0;
        x *= (isNegative ? (-1) : 1);

        size_t len = round (log10 (x) + 0.5);
        for (size_t i = 0; i < len; i++)
        {
            const auto next = ((x / (int) pow (10, i)) % 10) * pow (10, len - i - 1);
            reversed += next;
        }

        reversed *= (isNegative ? (-1) : 1);

        if (reversed < INT32_MIN || reversed > INT32_MAX)
            return 0;

        return reversed;
    }
};
// @lc code=end

int main (int argc, char const *argv[])
{
    Solution sol;
    cout << sol.reverse (1534236469) << endl;
    cout << sol.reverse (-120) << endl;
    return 0;
}

