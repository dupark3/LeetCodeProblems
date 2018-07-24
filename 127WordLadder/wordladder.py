class Solution:
    def oneAway(self, firstWord, secondWord):
        firstDiffEncountered = False
        for i in range(len(firstWord)):
            if firstWord[i] != secondWord[i]:
                if firstDiffEncountered == True:
                    return False
                firstDiffEncountered = True

        return True

    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        if beginWord == endWord:
            return 1
        if endWord not in wordList:
            return 0

        answer = 1
        queue = [beginWord, None]

        while (len(queue) > 0):
            #print(queue)
            if queue[0] == None:
                queue = queue[1:]
                queue.append(None)
                answer +=1
                if queue[0] == None:
                    break
            for i in range(len(wordList)):
                if wordList[i] == beginWord:
                    wordList[i] = None
                elif wordList[i] != None and Solution.oneAway(self, queue[0], wordList[i]):
                    if wordList[i] == endWord:
                        return answer + 1
                    queue.append(wordList[i])
                    wordList[i] = None
                    #print(wordList)
            queue = queue[1:]

        return 0

sol = Solution
print(Solution.ladderLength(Solution, "hit", "cog", ["hot","dot","dog","lot","log","cog"]))
