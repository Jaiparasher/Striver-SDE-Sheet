#include <bits/stdc++.h>

vector<int> search(string s, string pattern)
{
    int n = s.size();
    int m = pattern.size();
    vector<int> ans;
    vector<int> Z;
    string tot = pattern + '$' + s;
    int tot_size = tot.size();
    int i = 0, j = 1;
    while (j < tot_size)
    {
        int cnt = 0;
        int k = j;
        while (k < tot_size)
        {
            if (tot[i] == tot[k])
            {
                cnt++;
                i++;
                k++;
            }
            else
                break;
        }
        Z.push_back(cnt);
        if (cnt == m)
            ans.push_back(j - m);
        i = 0;
        j++;
    }

    return ans;
}