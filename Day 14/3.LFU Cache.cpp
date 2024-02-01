/*
    Time Complexity: O(Q)
    Space Complexity: O(N)

    Where 'N' denotes size of cache and 'Q' denotes the number of operations.
*/
class LFUCache {
public:
    int capacity;
    int minFreq;
    
    // Stores key-value pairs and frequencies.
    unordered_map<int, pair<int, int>> keyVal;  

    // Groups keys with the same frequency.
    unordered_map<int, list<int>> freqList;    

    // Tracks the position of keys in freqList.
    unordered_map<int, list<int>::iterator> pos;  

    // Function to update the frequency of a key.
    void updateFreq(int key) {

        // Current frequency of the key.
        int curr_freq = keyVal[key].second;  

        // Remove the key from its current frequency list.
        freqList[curr_freq].erase(pos[key]);

        // Increment the frequency of the key.
        keyVal[key].second++;

        // Add the key to the new frequency list.
        freqList[curr_freq + 1].push_back(key);

        // Update the iterator position of the key in the new frequency list.
        pos[key] = --freqList[curr_freq + 1].end();

        // If the minimum frequency list is empty, update minFreq.
        if (freqList[minFreq].empty())
            minFreq++;
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        // If key is not found in keyVal, return -1.
        if (keyVal.find(key) == keyVal.end()) {
            return -1;
        }

        // Update the frequency of the key.
        updateFreq(key);

        // Return the value.
        return keyVal[key].first;
    }

    void put(int key, int value) {
        // If capacity is 0, do nothing.
        if (capacity == 0) {
            return;
        }

        // If key is found, update its value and frequency.
        if (keyVal.find(key) != keyVal.end()) {
            keyVal[key].first = value;
            updateFreq(key);
            return;
        }

        // Deletion case when the cache is full.
        if (keyVal.size() == capacity) {
            int delKey = freqList[minFreq].front();  // Least frequently used key.

            // Erase the key from keyVal, pos, and its frequency list.
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }

        // Creation case.

        // Store the key-value pair and set frequency to 1.
        keyVal[key] = {value, 1};

        // Add the key to the frequency list with frequency 1.
        freqList[1].push_back(key);

        // Update the iterator position of the key in the frequency list.
        pos[key] = --freqList[1].end();

        // Update the minimum frequency.
        minFreq = 1;
    }
};
