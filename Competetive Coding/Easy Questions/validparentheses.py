class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        parenthesesList = []
        oppMap = {"(":")", "{":"}", "[":"]"}
        for parentheses in s:
            if parentheses in "({[":
                parenthesesList.append(parentheses)
            else:
                if parenthesesList:
                    openParentheses = parenthesesList.pop()
                    if oppMap[openParentheses] != parentheses: 
                        return False
                else:
                    return False

        if parenthesesList:
            return False
        return True 
                    
            


     
