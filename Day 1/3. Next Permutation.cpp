vector<int> nextGreaterPermutation(vector<int> &A) {

    int idx = -1;

    int n = A.size();

 

    // Step 1: Find the first index 'idx' from the right where A[idx] > A[idx - 1]

    for (int i = n - 1; i > 0; i--) {

      if (A[i] > A[i - 1]){

      idx = i;

      break;

    }

    }

 

    // Step 2: If 'idx' remains -1, reverse the entire vector (no greater permutation possible)

    if (idx == -1) {

        reverse(A.begin(), A.end());

    } 

    else {

        // Step 3: Find the smallest number 'A[prev]' to the right of 'idx' such that 'A[prev] > A[idx - 1]'

        int prev = idx;

        for (int i = idx + 1; i < n; i++) {

            if (A[i] > A[idx - 1] && A[i] <= A[prev]) {

                prev = i;

            }

        }

 

        // Step 4: Swap 'A[idx - 1]' and 'A[prev]'

        swap(A[idx - 1], A[prev]);

 

        // Step 5: Reverse the portion of the vector from index 'idx' onwards

        reverse(A.begin() + idx, A.end());

    }

 

    // Step 6: Return the lexicographically next greater permutation

    return A;

}