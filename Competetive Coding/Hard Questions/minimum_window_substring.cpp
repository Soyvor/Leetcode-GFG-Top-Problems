#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int left = 0, right = 0;
        // unordered_map<char, int> window;
        // unordered_map<char, int> needs;
        int window[256] = {0};
        int needs[256] = {0};
        for (auto c : t)
        {
            needs[c]++;
        }
        int match = 0, minLength = INT_MAX;
        string res = "";
        int start = -1;
        while (right < s.size())
        {
            char ch1 = s[right];
            if (needs[ch1]) // string present
            {
                window[ch1]++;
                if (window[ch1] <= needs[ch1])
                {
                    match++;
                }
            }
            right++;
            while (match == t.size())
            {
                if (right - left < minLength)
                {
                    start = left;
                    minLength = right - left;
                }
                char ch2 = s[left];
                if (needs[ch2])
                {
                    window[ch2]--;
                    if (window[ch2] < needs[ch2])
                    {
                        match--;
                    }
                }
                left++;
            }
        }
        if (start != -1)
        {
            res = s.substr(start, minLength);
            return res;
        }
        return res;
    }
};