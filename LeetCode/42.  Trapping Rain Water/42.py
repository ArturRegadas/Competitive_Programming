from typing import List
class Solution:
    def trap(self, height: List[int]) -> int:
        size= len(height)
        left = [0 for i in range(size + 1)]
        right = [0 for i in range(size + 2)]

        #pega o maior tamanho ate a posicao atual, ponteiro left
        for i in range(1, size+1):
            left[i] = max(left[i-1], height[i-1])

        #pega o maior tamanho ate a posicao atual vindo de traz pra frente, ponteiro right
        for i in range(size, 0, -1):
            right[i] = max(right[i+1], height[i-1])


        result = 0
        
        lines = [None for i in range(size)]
        for i in range(1, size+1):
            currentLine = max(min(left[i], right[i])-height[i-1],0)
            result += currentLine
            lines[i-1] = currentLine
        
        print(height)
        print(left)
        print(right)
        print(lines)
        
        return result

l = Solution()
l.trap([1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])