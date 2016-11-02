int removeElement(vector<int>& nums, int val)
{
    int current = 0;
    for(int i = 0; i < nums.size(); i++)
    {
	if(nums[i] == val) continue;

	nums[current++] = nums[i];
    }

    return current;
}
