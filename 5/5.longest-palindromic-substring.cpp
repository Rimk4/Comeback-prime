/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (36.87%)
 * Likes:    31952
 * Dislikes: 1969
 * Total Accepted:    4.4M
 * Total Submissions: 11.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 * 
 * 
 */

#include <string>
#include <iostream>
#include <cstring>

using namespace std;


class Solution
{

public:

    string longestPalindrome (string s)
    {
        bool isPrevSubstringPalindrom[s.length ()][s.length ()];

        for (size_t i = 0; i < s.length (); i++)
        {
            memset (&isPrevSubstringPalindrom[i][0], 0, s.length () * sizeof (bool));
            isPrevSubstringPalindrom[i][i] = true;
        }

        int maxLen = 1;
        int start = 0;
        int end = 0;

        for (size_t i = 0; i < s.length () - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                isPrevSubstringPalindrom[i][i + 1] = true;
                maxLen = 2;
                start = i;
            }
        }

        for (size_t len = 3; len <= s.length (); len++)
        {
            for (size_t indStart = 0; indStart <= s.length () - len; indStart++)
            {
                size_t indEnding = indStart + len - 1;
                if (s[indStart] == s[indEnding] && isPrevSubstringPalindrom[indStart + 1][indEnding - 1])
                {
                    isPrevSubstringPalindrom[indStart][indEnding] = true;
   
                    if (maxLen < len)
                    {
                        maxLen = len;
                        start = indStart;
                    }
                }
            }
        }

        return s.substr (start, maxLen);
    }
};

int main (int argc, char const *argv[])
{
    Solution sol;
    string str ("123234qwertytrewqasddsa");
    string str1 ("aacabdkacaa");
    cout << sol.longestPalindrome (str1) << endl;
    return 0;
}
