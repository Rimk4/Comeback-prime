/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (52.99%)
 * Likes:    9052
 * Dislikes: 15754
 * Total Accepted:    2M
 * Total Submissions: 3.8M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "A", numRows = 1
 * Output: "A"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 * 
 * 
 */

#include <cstdint>
#include <cstring>

#include <iostream>
#include <string>

using namespace std;


// @lc code=start
class Solution
{

public:

    string convert (string s, int numRows)
    {
        string zigZagStr;
        const uint16_t columnHeight = numRows;
        const uint16_t diagonalLen = numRows;
        if (columnHeight == s.length () || columnHeight == 1)
            return s;
        const uint16_t oneZigZagElement = columnHeight + diagonalLen - 2;
        const uint16_t rawColumnCount = s.length () / oneZigZagElement;
        const uint16_t columnCount = rawColumnCount + (s.length () % oneZigZagElement ? 1 : 0);
        const uint16_t oneRowLen = columnCount + rawColumnCount * (diagonalLen - 2) + s.length () % oneZigZagElement;
        uint8_t eachLineSymbol[numRows][oneRowLen];
        uint8_t eachLineSymbolCount[numRows];

        for (size_t i = 0; i < numRows; i++)
        {
            memset (&eachLineSymbol[i][0], 0, sizeof (uint8_t) * oneRowLen);
            eachLineSymbolCount[i] = 0;
        }

        uint16_t rowDelta = 0;

        for (size_t i = 1; i <= s.length (); i++)
        {
            const uint16_t rawIndex = i % oneZigZagElement;
            const uint16_t indInOneZigElement = rawIndex ? rawIndex : oneZigZagElement;
            const bool isCol = indInOneZigElement <= columnHeight;

            uint16_t lineNum;

            if (isCol)
                lineNum = indInOneZigElement - 1;
            else
                lineNum = diagonalLen - (indInOneZigElement - columnHeight) - 1;

            eachLineSymbol[lineNum][eachLineSymbolCount[lineNum]++] = s[i - 1];
        }

        for (size_t i = 0; i < numRows; i++)
        {
            for (size_t j = 0; j < oneRowLen; j++)
            {
                if (eachLineSymbol[i][j] == 0)
                    break;

                zigZagStr.push_back (eachLineSymbol[i][j]);
            }       
        }


        return zigZagStr;
    }
};
// @lc code=end

int main (int argc, char const *argv[])
{
    Solution sol;
    cout << sol.convert ("hjouvsuyoypayulyeimuotehzriicfskpggkbbipzzrzucxamludfykgruowzgiooobppleqlwphapjnadqhdcnvwdtxjbmyppphauxnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxztqrsvbspkyhsenbppkqtpddbuotbbqcwivrfxjujjddntgeiqvdgaijvwcyaubwewpjvygehljxepbpiwuqzdzubdubzvafspqpqwuzifwovyddwyvvburczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveymqpxhlrnunyfdzrhbasjeuygafoubutpnimuwfjqsjxvkqdorxxvrwctdsneogvbpkxlpgdirbfcriqifpgynkrrefx", 503) << endl;
    return 0;
}

