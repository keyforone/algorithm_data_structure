vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
    quick_sort(nums1, 0, nums1.size()-1);
    quick_sort(nums2, 0, nums2.size()-1);

    return decide(nums1, nums2);
}

void quick_sort(vector<int>& num, int head, int tail)
{
    if(head >= tail) return;

    int start = head;
    int middle = tail;
    int end = tail-1;

    while(start <= end)
    {
	if(num[start] <= num[middle]) { start++; continue; }
	if(num[end] >= num[middle]) { end--; continue; }

	int t = num[start]; num[start] = num[end]; num[end] = t;

	start++; end--;
    }

    int t = num[start]; num[start] = num[middle]; num[middle] = t;

    quick_sort(num, head, start-1);
    quick_sort(num, start+1, tail);
}

vector<int> decide(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> result;

    int i,j;
    for(i = 0, j = 0; i < nums1.size() && j < nums2.size();)
    {
	if(nums1[i] < nums2[j]) { i++; continue; }
	if(nums1[i] > nums2[j]) { j++; continue; }
	
	result.push_back(nums1[i]);i++;j++;
    }

    return result;
}
