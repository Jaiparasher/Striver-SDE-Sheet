/*
      Time Complexity : O(Nlog(K))
      Space Complexity : O(N),

      where N is the maximum number of integers read at runtime and K is the required order of number in sorted order
*/


#include<queue>

class Kthlargest {
public:

    // Initialise priority queue and 'size'.
    int size;
    priority_queue<int, vector<int>, greater<int>> pq;

    // Initialse the 'Kthlargest' object with 'arr'.
    Kthlargest(int k, vector<int> &arr) {
        size = k;
        for (auto it : arr) {
            pq.push(it);
            if (pq.size() > size) {
                pq.pop();
            }
        }
    }

    int add(int num) {

        // Push the current 'num' in priority queue.
        pq.push(num);

        // Maintain only 'k' elelments in priority queue.
        if (pq.size() > size) {
            pq.pop();
        }

        // Return the top element.
        return pq.top();
    }


};