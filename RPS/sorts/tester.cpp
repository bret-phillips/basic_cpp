#include <iostream>
#include <vector>
#include "bubble_sort.h"

int main()
{
	std::vector<int> nums = {12, 10, 17, 5, 3, 9, 16, 12, 15, 3, 6,11, 1, 2};
	nums = bubble_sort(nums);
	int i;
	for(i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}