class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        numDiff = 0
        differences = []
        for i in range(len(s2)):
            if s1[i] != s2[i]:
                differences.append(i)
                numDiff += 1
        if numDiff > 2 or numDiff == 1:
            return False
        if numDiff == 0:
            return True
        return s1[differences[0]] == s2[differences[1]] and s1[differences[1]] == s2[differences[0]]