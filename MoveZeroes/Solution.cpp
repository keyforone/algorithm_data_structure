void moveZeroes(int* nums, int numsSize)
{
    int tail = 0;

    for(int i = 0; i < numsSize; i++)
    {
	if(nums[i] != 0)
	{
	    nums[tail] = nums[i];
	    tail++;
	}
    }

    for(int i = tail; i < numsSize; i++)
    {
	nums[i] = 0;
    }
}
