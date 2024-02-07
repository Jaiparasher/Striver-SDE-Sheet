/* 
	Time complexity: O(N). 
	Space complexity: O(1). 

	Where 'N' is the length of string 's'
*/

int createAtoi(string s) {
    int i = 0, n = s.size();

    // Skipping space characters at the beginning
    while (s[i] == ' ') {
        i++;
    }

    int positive = 0, negative = 0; 

    // Detecting and counting positive and negative signs
    if (s[i] == '+') {
        positive++; // Number of positive signs at the start of the string
        i++;
    }

    if (s[i] == '-') {
        negative++; // Number of negative signs at the start of the string
        i++;
    }

    double ans = 0; 

    // Parsing the numeric portion of the string
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        ans = ans * 10 + (s[i] - '0'); // (s[i] - '0') converts character to integer
        i++;
    }

    // Handling negative sign
    if (negative > 0) {
        ans = -ans;
    }
    
    // Handling cases where both +ve and -ve signs exist
    if (positive > 0 && negative > 0) {
        return 0;
    }

    // Handling integer overflows and underflows
    if (ans > INT_MAX) {
        ans = INT_MAX;
    }

    if (ans < INT_MIN) {
        ans = INT_MIN;
    }

    return (int)ans;
}