#include "LeetCode34.h"

vector<int> LeetCode34::searchRange(vector<int>& nums, int target)
{	
	vector<int> res = { -1, -1 };

	int len = nums.size();
	int i = 0, j = len - 1;
	int mid = (i + j) / 2;
	while (i < j) {
		if (nums[mid] == target) {
			break;
		}
		else if (nums[mid] > target) {
			j = mid - 1;
		}
		else {
			i = mid + 1;
		}
		mid = (i + j) / 2;
	}
	
	if (i > j || nums[mid] != target) {
		return res;
	}
	int l, r;
	l = r = mid;
	while (l > 0) {
		if (nums[l - 1] == target) {
			l--;
		}
		else {
			break;
		}
	}

	while (r < len - 1) {
		if (nums[r + 1] == target) {
			r++;
		}
		else {
			break;
		}
	}
	res[0] = l;
	res[1] = r;
	return res;
}
