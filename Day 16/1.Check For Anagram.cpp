// Brute-Force

bool areAnagram(string &str1, string &str2){
    // Get lengths of both strings.
    int n1 = str1.length();
    int n2 = str2.length();

    // If length of both strings is not same, then they cannot be anagram.
    if (n1 != n2){
       return false;
    }

    // Sort both the strings.
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare sorted strings.
    for (int i = 0; i < n1; i++){
        if (str1[i] != str2[i]){
            return false;
        }
    }
    return true;
}

//Optimal Approach

#define NO_OF_CHARS 256

bool areAnagram(string &str1, string &str2){
    // Create a count array and initialize all values as 0.
    int hash[NO_OF_CHARS] = { 0 };
    int i;

    int n1 = str1.length();
    int n2 = str2.length();
    // If length of both strings is not same, then they cannot be anagram.
    if (n1 != n2){
       return false;
    }

    /*
       For each character in input strings, 
       increment count in the corresponding count array.
    */
    for (i = 0; i < n1; i++){
        hash[str1[i]]++;
        hash[str2[i]]--;
    }

    // Check if all values in hash array are 0.
    for (i = 0; i < NO_OF_CHARS; i++){
        if (hash[i]){
            return false;
        }
    }
    return true;
}