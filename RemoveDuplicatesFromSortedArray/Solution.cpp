int removeDuplicates(vector<int>& nums)
{
    if(nums.size() <= 1) return nums.size();

    int start = 1;
    for(int i = 1; i < nums.size(); i++)
    {
	if(nums[i] == nums[i-1]) 
	    continue;
	if(start != i)
	    nums[start] = nums[i];
	start++;
    }
    return start;
}
