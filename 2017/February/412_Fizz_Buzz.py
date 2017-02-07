class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans = []
        for i in range(1, n+1):
            if i % 3 == 0 or i % 5 == 0:
                if i % 15 == 0:
                    ans.append("FizzBuzz")
                elif i % 5 == 0:
                    ans.append("Buzz")
                else:
                    ans.append("Fizz")
            else:
                ans.append("%d" % i)
        return ans
