class Solution {
public:
    int minMoves(vector<int>& nums, int k) 
{
	long result=INT_MAX;
	vector<int> total; //to store indices of all 1s
	for(int i=0;i<nums.size();i++)
		if(nums[i]==1) total.push_back(i);
			
	int n=total.size();
	vector<long> s={0}; //to store the prefix sum of the indices of 1s
	for(int i=0;i<n;i++)
		s.push_back(s.back()+total[i]);

	for(int i=k/2;i<n-(k-1)/2;i++)
	{
		long current = 1LL * (k / 2) * total[i] - (s[i] - s[i - k / 2]) - 1LL * (k / 2) * (k / 2 + 1) / 2; //calculate the distances to combine all left k/2 1s with the median value
		current += s[i + 1 + (k - 1) / 2] - s[i + 1] - 1LL * ((k - 1) / 2) * total[i] - 1LL * ((k - 1) / 2) * ((k - 1) / 2 + 1) / 2; //to calculate the distances to combine all right (k-1)/2 1s with the median value
		result=min(result,current);
	}
	return result;
}
};