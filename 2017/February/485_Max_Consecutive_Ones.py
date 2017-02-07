class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxCons = 0
        maxHere = 0
        for i in range(len(nums)):
            maxHere = maxHere + 1 if nums[i] == 1 else 0
            maxCons = max(maxCons, maxHere)
        return maxCons
