/*

	Time complexity: O(N*(N*log(N))) 
	Space complexity: O(N)
	
	where N is the total number of elements in the array.

*/

#include <algorithm>

vector<int> findMedian(vector<int> &arr, int n){
	
	// To store the incoming stream elements
	vector<int>store;
	
	// To store the medians
	vector<int> medians;
	
	for(int i = 0; i < n; i++){
		
		// Storing the incoming data from stream in a vector 'store'
		store.push_back(arr[i]);
		
		// Sorting the vector to arrange all the elements in sorted order
		sort(store.begin(),store.end());
		
		int median;
		// Even number of elements are read, (Note - 0 based indexing is used)
		if((i+1)%2==0){
			
			// Average of middle two values
			median = (store[i/2] + store[(i+1)/2])/2;
				
		}
		// odd number of elements are read
		else{
			
			// The middle value of the sorted arrangement of the elements read so far
			median = store[i/2];
			
		}
		
		medians.push_back(median);
		
	}
	
	return medians;
}
