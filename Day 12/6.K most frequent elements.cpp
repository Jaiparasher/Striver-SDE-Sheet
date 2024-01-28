//Using Heap

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    if (k == n)
    {
        return arr;
    }

    unordered_map<int, int> mp;

    // Build map where the key is element
    // and value is how often this element appears in 'ARR'.
    for (int ele : arr)
    {
        mp[ele]++;
    }

    // Elements in heap will be sorted in descending order
    // according to the frequency of the element.
    priority_queue<pair<int, int>> heap;

    // Build heap of maximum size 'K'.
    for (auto x : mp)
    {
        heap.push({x.second, x.first});
    }

    vector<int> ans(k);

    // Build output array.
    for (int i = 0; i < k; i++)
    {
        ans[i] = heap.top().second;
        heap.pop();
    }

    return ans;
}

//Using Bucket Sort

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int, int> mp;

    // Build map where the key is element
    // and value is how often this element appears in 'ARR'.
    for (int ele : arr)
    {
        mp[ele]++;
    }

    vector<int> bucket[n + 1];

    for (auto x : mp)
    {
        int freq = x.second;

        // Add in correct bucket.
        bucket[freq].push_back(x.first);
    }

    vector<int> ans(k);
    int cur = 0;

    // Add 'K' elements to answer array starting from the rightmost bucket.
    for (int i = n; i > 0 && k > 0; i--)
    {
        if (bucket[i].size() == 0)
        {
            continue;
        }

        for (int num : bucket[i])
        {

            ans[cur++] = num;
            k--;
            if (k == 0)
            {
                break;
            }
        }
    }

    return ans;
}