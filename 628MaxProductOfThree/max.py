from collections import deque

class Solution:
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if len(nums) == 3:
            return nums[0] * nums[1] * nums[2]
        
        positives = deque([-1, -1, -1])
        smallestNonPos = deque([1, 1])
        largestNonPos = deque([-2147483648, -2147483648, -2147483648])
        
        for num in nums:
            if num > 0: 
                if num > positives[2]:
                    positives.popleft()
                    positives.append(num)
                elif num > positives[1]:
                    positives.popleft()
                    positives.insert(1, num)
                elif num > positives[0]:
                    positives[0] = num
            else:
                # nonpos number found
                if num < smallestNonPos[1]:
                    smallestNonPos.popleft()
                    smallestNonPos.append(num)
                elif num < smallestNonPos[0]:
                    smallestNonPos[0] = num
                
                # keep track of largest nonpos if no positives have been found
                if positives[2] == -1:
                    if num > largestNonPos[2]:
                        largestNonPos.popleft()
                        largestNonPos.append(num)
                    elif num > largestNonPos[1]:
                        largestNonPos.popleft()
                        largestNonPos.insert(1, num)
                    elif num > largestNonPos[0]:
                        largestNonPos[0] = num
        
        if positives[2] != -1:
            if positives[0] == -1:
                return positives[2] * smallestNonPos[1] * smallestNonPos[0]
            else:
                return positives[2] * max(positives[1] * positives[0], smallestNonPos[1] * smallestNonPos[0])
        else:
            # no positives found, three largest neg (closest to zero) must be returned
            return largestNonPos[2] * largestNonPos[1] * largestNonPos[0]
                    
                    
                    
                    
print(Solution.maximumProduct(None, [1, 2, 3, 0, 0, -5, -10]))