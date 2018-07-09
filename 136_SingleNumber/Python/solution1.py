class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = 0
        for i in range(len(nums)):
            ret = ret ^ nums[i]

        return ret


if __name__ == '__main__':
    solu = Solution()
    vec = [2, 3, 2, -1, 3]
    print('Single number is: {}'.format(solu.singleNumber(vec)))
