class Solution:
    def maxArea(self, height):
        left = 0
        right = len(height) - 1
        max_area = 0
        while (left < right):
            # max_area = max(max_area, min(height[left], height[right]) * (right - left))
            dist = right - left
            if height[left] < height[right]:
                min_height = height[left]
                left += 1
            else:
                min_height = height[right]
                right -= 1
            temp_area = min_height * dist
            if temp_area > max_area:
                max_area = temp_area
        return max_area