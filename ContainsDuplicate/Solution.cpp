void quick_sort(vector<int>& nums, int head, int tail)
{
    if( head >= tail) return;

    int start = head;
    int middle = (head+tail)/2; int t = nums[middle]; nums[middle] = nums[tail]; nums[tail] = t;
    int end = tail-1;

    while(start <= end)
    {
	if(nums[start] <= nums[tail]) { start++; continue; }
	if(nums[end] >= nums[tail]) { end--; continue; }

	int t = nums[start]; nums[start] = nums[end]; nums[end] = t;

	start++; end--;
    }   

    t = nums[start]; nums[start] = nums[tail]; nums[tail] = t;

    middle = start;
    quick_sort(nums, head, middle-1);
    quick_sort(nums, middle+1, tail);
}

bool decide(vector<int>& nums)
{
    for(int i = 1; i < nums.size(); i++)
    {
	if(nums[i] == nums[i-1]) return true;
    }

    return false;
}

bool containsDuplicate(vector<int>& nums)
{
    quick_sort(nums, 0, nums.size()-1);

    return decide(nums);
}

