def findAnagrams(s, p):
    from collections import Counter
    p_counter = Counter(p)
    s_counter = Counter(s[:len(p) - 1])
    result = []
    for i in range(len(p) - 1, len(s)):
        s_counter[s[i]] += 1
        if s_counter == p_counter:
            result.append(i - len(p) + 1)
        s_counter[s[i - len(p) + 1]] -= 1
        if s_counter[s[i - len(p) + 1]] == 0:
            del s_counter[s[i - len(p) + 1]]
    return result
