def lengthOfLongestSubstring(s):
    seen = {}
    max_length = 0
    start = 0
    for end in range(len(s)):
        if s[end] in seen and seen[s[end]] >= start:
            start = seen[s[end]] + 1
        seen[s[end]] = end
        max_length = max(max_length, end - start + 1)
    return max_length
