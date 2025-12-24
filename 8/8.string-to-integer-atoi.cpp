/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (20.20%)
 * Likes:    5945
 * Dislikes: 15327
 * Total Accepted:    2.3M
 * Total Submissions: 11.2M
 * Testcase Example:  '"42"'
 *
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit
 * signed integer.
 * 
 * The algorithm for myAtoi(string s) is as follows:
 * 
 * 
 * Whitespace: Ignore any leading whitespace (" ").
 * Signedness: Determine the sign by checking if the next character is '-' or
 * '+', assuming positivity if neither present.
 * Conversion: Read the integer by skipping leading zeros until a non-digit
 * character is encountered or the end of the string is reached. If no digits
 * were read, then the result is 0.
 * Rounding: If the integer is out of the 32-bit signed integer range [-2^31,
 * 2^31 - 1], then round the integer to remain in the range. Specifically,
 * integers less than -2^31 should be rounded to -2^31, and integers greater
 * than 2^31 - 1 should be rounded to 2^31 - 1.
 * 
 * 
 * Return the integer as the final result.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "42"
 * 
 * Output: 42
 * 
 * Explanation:
 * 
 * 
 * The underlined characters are what is read in and the caret is the current
 * reader position.
 * Step 1: "42" (no characters read because there is no leading whitespace)
 * ⁠        ^
 * Step 2: "42" (no characters read because there is neither a '-' nor '+')
 * ⁠        ^
 * Step 3: "42" ("42" is read in)
 * ⁠          ^
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = " -042"
 * 
 * Output: -42
 * 
 * Explanation:
 * 
 * 
 * Step 1: "   -042" (leading whitespace is read and ignored)
 * ⁠           ^
 * Step 2: "   -042" ('-' is read, so the result should be negative)
 * ⁠            ^
 * Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
 * ⁠              ^
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "1337c0d3"
 * 
 * Output: 1337
 * 
 * Explanation:
 * 
 * 
 * Step 1: "1337c0d3" (no characters read because there is no leading
 * whitespace)
 * ⁠        ^
 * Step 2: "1337c0d3" (no characters read because there is neither a '-' nor
 * '+')
 * ⁠        ^
 * Step 3: "1337c0d3" ("1337" is read in; reading stops because the next
 * character is a non-digit)
 * ⁠            ^
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "0-1"
 * 
 * Output: 0
 * 
 * Explanation:
 * 
 * 
 * Step 1: "0-1" (no characters read because there is no leading whitespace)
 * ⁠        ^
 * Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
 * ⁠        ^
 * Step 3: "0-1" ("0" is read in; reading stops because the next character is a
 * non-digit)
 * ⁠         ^
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "words and 987"
 * 
 * Output: 0
 * 
 * Explanation:
 * 
 * Reading stops at the first non-digit character 'w'.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 200
 * s consists of English letters (lower-case and upper-case), digits (0-9), '
 * ', '+', '-', and '.'.
 * 
 * 
 */

#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdint>

using namespace std;


// @lc code=start
class Solution
{

public:

    int64_t myAtoi (string s)
    {
        auto isDigit = [] (char c) -> bool
        {
            return '0' <= c && c <= '9';
        };

        // Ignore any leading whitespace (" ").
        size_t firstNonSpaceInd = 0;
        while (s[firstNonSpaceInd] == ' ' && firstNonSpaceInd < s.length ())
            firstNonSpaceInd++;

        size_t places = 0;
        static constexpr uint8_t maxPlacesInt32 = 10;
        uint8_t digits[maxPlacesInt32];
        memset (&digits[0], 0, maxPlacesInt32 * sizeof (uint8_t));
        
        bool isNegative = false;
        bool nextIsDigit = false;
        size_t i;
        for (i = firstNonSpaceInd; i < s.length () && places < maxPlacesInt32; i++)
        {
            if (s[i] == '0' && places == 0)
                continue;

            if (isDigit (s[i]))
            {
                digits[places] = s[i] - '0';
                places++;
            }
            else if (s[i] == '-' && i - firstNonSpaceInd == 0)
                isNegative = true;
            else if (s[i] == '+' && i - firstNonSpaceInd == 0)
                continue;
            else
                break;
        }
        if (i < s.length ())
            nextIsDigit = isDigit (s[i]);

        if (places == 0)
            return 0;
            
        if ((places == maxPlacesInt32) && nextIsDigit)
            return (isNegative ? INT32_MIN : INT32_MAX);

        int64_t integer = 0;
        int64_t tenPower = 1;
        for (int8_t i = places - 1; i >= 0; i--)
        {
            if (isNegative)
                integer -= digits[i] * tenPower;
            else
                integer += digits[i] * tenPower;
            tenPower *= 10;
        }

        if (integer > INT32_MAX)
            return INT32_MAX;
        
        if (integer < INT32_MIN)
            return INT32_MIN;

        return integer;
    }
};
// @lc code=end

int main (int argc, char const *argv[])
{
    Solution sol;

    cout << "Example 1:" << sol.myAtoi ("42") << endl;
    cout << "Example 2:" << sol.myAtoi (" -042") << endl;
    cout << "Example 3:" << sol.myAtoi ("1337c0d3") << endl;
    cout << "Example 4:" << sol.myAtoi ("0-1") << endl;
    cout << "Example 5:" << sol.myAtoi ("words and 987") << endl;
    cout << "Example 6:" << sol.myAtoi ("-91283472332") << endl;
    cout << "Example 7:" << sol.myAtoi ("+1") << endl;
    cout << "Example 8:" << sol.myAtoi ("  0000000000012345678") << endl;
    cout << "Example 9:" << sol.myAtoi ("2147483646") << endl;
    cout << "Example 0:" << sol.myAtoi ("2147483648") << endl;

    return 0;
}
