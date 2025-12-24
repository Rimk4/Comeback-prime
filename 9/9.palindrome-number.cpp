/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (59.96%)
 * Likes:    15257
 * Dislikes: 2895
 * Total Accepted:    7.4M
 * Total Submissions: 12.4M
 * Testcase Example:  '121'
 *
 * Given an integer x, return true if x is a palindrome, and false
 * otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without converting the integer to a string?
 */


#include <string>
#include <cmath>
#include <cstdint>
#include <iostream>

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

    bool isPalindrome (int x)
    {
        if (x < 0)
            return false;

        return x == reverse (x);
    }
};
// @lc code=end

int main (int argc, char const *argv[])
{
    Solution sol;
    cout << sol.isPalindrome (121) << endl;
    cout << sol.isPalindrome (-121) << endl;
    cout << sol.isPalindrome (12) << endl;
    return 0;
}
