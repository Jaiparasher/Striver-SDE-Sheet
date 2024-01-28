//Brute-Force

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Array to store all the possible sum combinations.
	vector<int>tempArray;
	
	// Loop to traverse the array 'A'.
	for(int i = 0; i < n; i++){
		// Loop to traverse the array 'B'.
		for(int j = 0; j < n; j++){
			int currentSum = a[i] + b[j];
			// Add the sum of current combination .
			tempArray.push_back(currentSum);
		}
	}
	// Sort the array in descending order.
	sort(tempArray.begin(), tempArray.end(), greater<int>()); 
	
	// Return the first 'K' values.
	vector<int> result(tempArray.begin(), tempArray.begin() + k);
	return result;
}


//Optimal Approach

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k) {
    // Sorting the arrays.
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Using a max-heap.
    priority_queue<pair<int, pair<int, int>>>maxHeap;
    maxHeap.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});

    // Using a set.
    set<pair<int, int>>mySet;
    mySet.insert({n - 1, n - 1});

    // Output array to store the K max sum combinations.
    vector<int> result;

    while (k > 0) {
        pair<int, pair<int, int>> top = maxHeap.top();

        // Remove the root of the max heap.
        maxHeap.pop();

        int sum = top.first;
        int x = top.second.first;
        int y = top.second.second;

        // Add the sum to the output array.
        result.push_back(sum);

        // Check if the indices (x-1, y) are present in the set.
        if (mySet.find({x - 1, y}) == mySet.end()) {
            maxHeap.push({a[x - 1] + b[y], {x - 1, y}});
            mySet.insert({x - 1, y});
        }
        // Check if the indices (x, y-1) are present in the set.
        if (mySet.find({x, y - 1}) == mySet.end()) {
            maxHeap.push({a[x] + b[y - 1], {x, y - 1}});
            mySet.insert({x, y - 1});
        }
        k -= 1;
    }
    // Return the output array.
    return result;
}