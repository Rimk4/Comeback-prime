/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>


class Solution
{

public:

    u_int16_t lengthOfLongestSubstring (std::string s)
    {
        u_int16_t l = 0;

        u_int16_t lastCheckedPos[CHAR_MAX];
        memset (lastCheckedPos, 0, sizeof (lastCheckedPos));
        u_int16_t ind = 1;
        u_int16_t start = 0;
        for (auto c = s.begin (); c < s.end (); c++, ind++)
        {
            if (lastCheckedPos[*c] > start)
                start = lastCheckedPos[*c];

            l = std::max ((int) l, ind - start);
            lastCheckedPos[*c] = ind;
        }

        return l;
    }
};

int main ()
{
    Solution sol;
    std::string input;
    std::cin >> input;
    u_int8_t result = sol.lengthOfLongestSubstring (input);
    std::cout<< std::to_string (result) << std::endl;

    return 0;
}
// @lc code=end

