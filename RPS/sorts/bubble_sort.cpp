#include <vector>
#include <cstdlib>
#include "bubble_sort.h"

std::vector<int> bubble_sort(std::vector<int> nums)
{
	// Initialize tools
	size_t i, j;
	int temp;
	
	// Outer cycle - maximum times inner cycle should have to run to sort nums
	for(i = 0; i < nums.size() -1; i++)
	{
		// Inner cycle - compare nums and sort
		for(j = 0; j < nums.size() -1; j++)
		{
			//compare nums[j] to nums[j+1] and switch if bigger
			if(nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		
		}
	}

	// Return sorted list
	return nums;
}