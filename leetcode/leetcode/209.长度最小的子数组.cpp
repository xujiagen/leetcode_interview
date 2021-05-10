#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
class Solution {
public:
	int minSubArrayLen(int target, std::vector<int> & nums) {
		if (nums.size() < 1) return 0;
		int left = 0, right = 0;
		miniLength = INT_MAX;
		if (nums[0] >= target) return 1;	
		int tmpSum = nums[0];
		while (right < nums.size()) {
			if (tmpSum >= target) {
				printList(nums, left, right);
				miniLength = std::min(miniLength, right - left + 1);
				tmpSum -= nums[left];
				left++;
			} else {
				tmpSum += nums[right];
				right++;
			}
		}
		if (miniLength == INT_MAX) return 0;
		else return miniLength;
	}
	void printList(const std::vector<int>  &_VecList, int _Left, int _Right) {
		if (_Left < 0 || _Right < _Left || _Left >  _Right || _Right >= _VecList.size() - 1) return;
		for (int i = _Left; i <= _Right; i++) {
			std::cout << _VecList[i] << " ";
		}
		std::cout << std::endl;
	}
	
	int miniLength;

	
};

int main(int argc, char** argv) {
	std::vector<int> vecList = {2,3,1,2,4,3};
	std::cout << Solution().minSubArrayLen(7, vecList) << std::endl;
	return 0;
}

