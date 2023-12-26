#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &interval){
	// Write your code here.
	sort(interval.begin(),interval.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<interval.size();i++){
            if(ans.empty()){
                ans.push_back(interval[i]);
            }
            else{
                vector<int> &v=ans.back();
                int a=v[1];
                if(interval[i][0]<=a){
                    v[1]=max(v[1],interval[i][1]);
                }
                else{
                    ans.push_back(interval[i]);
                }
            }
        }
        return ans;
}