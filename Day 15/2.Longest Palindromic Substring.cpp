/*
    Dynamic Programming
    Time Complexity = O(N ^ 2)
    Space Complexity = O(N ^ 2)
    
    Where N is the length of the string.
*/

#include <string.h>

string longestPalinSubstring(string str)
{
    int n = str.length();

    if (n < 1) 
    {
        return "";
    }

    /*
        dp[i][j] will be true if str[i..j] is palindrome.
        Else dp[i][j] will be false.
    */
    bool dp[n][n];
    memset(dp, false, sizeof(dp));

    int maxLength = 1;

    // Single letter is always palindromic.
    for (int i = 0; i < n; ++i) 
    {
        dp[i][i] = true;
    }

    int start = 0;

    // Substring of length 2.
    for (int i = 0; i < n - 1; ++i) 
    {
        if (str[i] == str[i+1]) 
        {
            dp[i][i + 1] = true;
            if(maxLength < 2)
            {
                start = i;
                maxLength = 2;
            }
        }
    }

    /*
        Check for lengths greater than 2.
        k is length of substring.
    */
    for (int len = 3; len <= n; len++) 
    {
        // Fix the starting index.
        for (int i = 0; i < n - len + 1; ++i) 
        {
            // Ending index of length len.
            int j = i + len - 1;

            // Condition of str[i, j] to be palindromic.
            if (dp[i + 1][j - 1] && str[i] == str[j]) 
            {
                dp[i][j] = true;

                // Update the starting index and the length.
                if (len > maxLength) 
                {
                    start = i;
                    maxLength = len;
                }
            }

        }
    }

    return str.substr(start, maxLength);
}



/*
    Expanding around the centres
    Time Complexity : O(N ^ 2)
    Space Complexity: O(1)
    
    Where N is the length of the string.
*/

#include <algorithm>

int expandAroundCenter(string str, int left, int right) 
{
    int start = left, end = right;
    int n = str.length();

    // Expand the center.
    while (start >= 0 && end < n && str[start] == str[end]) 
    {
        start--;
        end++;
    }

    return end - start - 1;
}

string longestPalinSubstring(string str)
{
    int n = str.length();

    if (n < 1) 
    {
        return "";
    }

    int start = 0, end = 0;

    for (int i = 0; i < n; i++) 
    {
        // Longest odd length palindrome with center points as i.
        int len1 = expandAroundCenter(str, i, i);

        // Longest even length palindrome with center points as i and i + 1.
        int len2 = expandAroundCenter(str, i, i + 1);

        int len = max(len1, len2);

        // Update the start and end.
        if (len > end - start + 1) 
        {
            start = i - (len - 1) / 2;
            end = i + (len) / 2;
        }

    }

    return str.substr(start, end - start + 1);
}