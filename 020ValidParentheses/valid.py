class Solution:
    @staticmethod
    def isValid(s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:
            return True
        if len(s) % 2 != 0:
            return False
        
        matchingbrackets = {'(':')', '[':']', '{':'}'}
        
        stack = []
        
        for bracket in s:
            if bracket in matchingbrackets.keys():
                stack.append(bracket)
            elif not stack:
                return False
            elif matchingbrackets[stack.pop()] != bracket:
                return False
        
        return len(stack) == 0


print(Solution.isValid("(())[]{}[]"))