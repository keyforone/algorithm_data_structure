int majorityElement(vector<int>& nums)
{
    int maj = nums[0];
    int counter = 1;

    for(int i = 1; i < nums.size(); i++)
    {
	if(nums[i] == maj)
	{
	    counter++;
	}
	else
	{
	    if(counter == 0)
	    {
		counter = 1;
		maj = nums[i];
	    }
	    else if(counter > 0)
	    {
		counter--;
	    }
	    else 
	    {
		counter--;
		maj = nums[i];
	    }
	}
    }

    return maj;
}
