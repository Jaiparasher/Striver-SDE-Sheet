#define d 256
vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	vector<int> ans;
	int q=5381;
	int n=text.length();
	int m=pattern.length();
	int i, j;
	int p=0;
	int t=0;
	int h=1;

	for(i=0;i<m-1;i++){
		h=(h*d)%q;
	}

	for(i=0;i<m;i++){
		t=(d*t+text[i])%q;
		p=(d*p+pattern[i])%q;
	}

	for(i=0;i<=n-m;i++){
		if(p==t){
			int j;
			for(j=0;j<m;j++){
				if(text[i+j]!=pattern[j]) break;
			}
			if(j==m) ans.push_back(i+1);
		}
		if(i<n-m){
			t=(d*(t-text[i]*h)+text[i+m])%q;

			if(t<0){
				t=t+q;
			}
		}
	}
	return ans;
}

//Coding ninjas Solution

#define MOD 1000000007

long long modPower(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long p = modPower(a, b / 2);

    if (b % 2 == 1)
        return p * p % MOD * a % MOD;
    return p * p % MOD;
}

vector<int> stringMatch(string text, string pattern)
{
    int n = text.size(), m = pattern.size();

    // List storing the indices of occurrences
    vector<int> ans;

    long long maxPow = modPower(26, m - 1);

    long long hashPattern = 0, hashText = 0;
    for (int i = 0; i < m; i++)
    {
        hashPattern = hashPattern * 26 + pattern[i] - 'a';
        hashPattern %= MOD;
    }
    for (int i = 0; i < m - 1; i++)
    {
        hashText = hashText * 26 + text[i] - 'a';
        hashText %= MOD;
    }

    for (int i = 0; i <= n - m; i++)
    {
        // Adding the last character in hash
        hashText = hashText * 26 + text[i + m - 1] - 'a';
        hashText %= MOD;

        if (hashText == hashPattern)
        {
            // Checking if the substring is equal to 'pattern'
            bool match = true;

            for (int j = 0; j < m; j++)
            {
                // If a character mismatch occurs
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                ans.push_back(i + 1);
            }
        }

        // Removing the first character in hash
        hashText = hashText - maxPow * (text[i] - 'a');
        hashText %= MOD;
        hashText = (hashText + MOD) % MOD;
    }

    return ans;
}
