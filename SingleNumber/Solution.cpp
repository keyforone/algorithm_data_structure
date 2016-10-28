int singleNumber(vector<int>& nums)
{
    if(nums.size() == 0) return 0;

    for(int i = 1; i < nums.size(); i++)
    {
	nums[0] = nums[0]^nums[i];
    }

    return nums[0];
}
