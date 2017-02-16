class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        ans = []
        n = len(words)
        i = 0
        width = maxWidth
        while i < n:
            wlen = len(words[i])
            j = i + 1
            while j < n and wlen + 1 + len(words[j]) <= width:
                wlen = wlen + 1 + len(words[j])
                j = j + 1

            line = words[i]
            if j == n:
                # if this is the last line
                for k in range(i + 1, n):
                    line = line + ' ' + words[k]
                line = line + ' '*(width - wlen)
            else:
                remain = width - wlen
                spaceNum = j - i - 1

                if spaceNum == 0:
                    # only one word
                    line = line + ' '*(width - wlen)
                else:
                    for k in range(i + 1, j):
                        line = line + ' '
                        for p in range(remain / spaceNum):
                            line = line + ' '
                        if k - i <= remain % spaceNum:
                            line = line + ' '
                        line = line + words[k]
            ans.append(line)
            i = j
        return ans