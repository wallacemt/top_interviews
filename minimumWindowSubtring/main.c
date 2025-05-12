char *minWindow(char *s, char *t)
{
    int tCount[128] = {0};
    int required = 0;
    for (int i = 0; t[i]; i++)
    {
        tCount[t[i]]++;
        if (tCount[t[i]] == 1)
            required++;
    }

    int left = 0, formed = 0;
    int windowCounts[128] = {0};

    int ans[2] = {-1, 0};
    int minLen = INT_MAX;

    for (int right = 0; s[right]; right++)
    {
        char c = s[right];
        windowCounts[c]++;

        if (tCount[c] > 0 && windowCounts[c] == tCount[c])
            formed++;

        while (left <= right && formed == required)
        {
            c = s[left];

            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                ans[0] = left;
                ans[1] = right;
            }

            windowCounts[c]--;
            if (tCount[c] > 0 && windowCounts[c] < tCount[c])
                formed--;

            left++;
        }
    }

    return ans[0] == -1 ? "" : strndup(s + ans[0], ans[1] - ans[0] + 1);
}
