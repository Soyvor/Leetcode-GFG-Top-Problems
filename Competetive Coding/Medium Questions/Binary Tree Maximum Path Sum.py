class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
def maxPathSum(root):
    def helper(node):
        nonlocal max_sum
        if not node:
            return 0
        left_sum = max(helper(node.left), 0)
        right_sum = max(helper(node.right), 0)
        max_sum = max(max_sum, node.val + left_sum + right_sum)
        return node.val + max(left_sum, right_sum)
    
    max_sum = float('-inf')
    helper(root)
    return max_sum
