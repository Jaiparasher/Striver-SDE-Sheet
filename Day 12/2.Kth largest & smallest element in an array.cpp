// Brute-Force

void kth_Largest_And_Smallest_By_AscendingOrder(vector<int> &arr, int k)
{

    sort(arr.begin(), arr.end());
    int n = arr.size();

    cout << "kth Largest element " << arr[n - k] << ", "
         << "kth Smallest element " << arr[k - 1];
}
}
;

// Optimal Approach

void kth_Largest_MaxHeap(vector<int> &arr, int k)
{

    priority_queue<int> pq;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }

    int f = k - 1;

    while (f > 0)
    {
        pq.pop();
        f--;
    }

    cout << "Kth Largest element " << pq.top() << "\n";
}

void kth_Smallest_MinHeap(vector<int> &arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }

    int f = k - 1;

    while (f > 0)
    {
        pq.pop();
        f--;
    }

    cout << "Kth Smallest element " << pq.top() << "\n";
}
}
;