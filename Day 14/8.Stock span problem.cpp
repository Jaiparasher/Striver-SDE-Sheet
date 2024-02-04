#include <bits/stdc++.h>

vector<int> prevGreater(vector<int> &prices) {
  stack<int> s;
  int n = prices.size();
  vector<int> ans(n, 1);

  for (int i = 0; i < n; i++) {
    int curr = prices[i];
    while (!s.empty() && prices[s.top()] < curr) {
      s.pop();
    }
    if (!s.empty())
      ans[i] = s.top();
    else
      ans[i] = -1;

    s.push(i);
  }
  
  return ans;
}

vector<int> findStockSpans(vector<int> &prices) {
  vector<int> prevG = prevGreater(prices);
  int n = prices.size();
  vector<int> ans(n, 1);

  for (int i = 1; i < n; i++) {
    ans[i] = i - prevG[i];
  }

  return ans;
}