bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    if(k <= 0) return false;

    if(k > (nums.size()-1))
	k = nums.size()-1;

    unordered_set<int> numsets;
    for(int i = 0; i <= k; i++)
    {
	if(numsets.find(nums[i]) == numsets.end()) numsets.insert(nums[i]);
	else return true;
    }

    for(int i = k+1; i < nums.size(); i++)
    {
	numsets.erase(nums[i-k-1]);
	if(numsets.find(nums[i]) == numsets.end()) numsets.insert(nums[i]);
	else return true;
    }
    return false;
}
