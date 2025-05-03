#include <stdlib.h>
#include <string.h>

char **fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize)
{
    char **result = malloc(sizeof(char *) * wordsSize);
    *returnSize = 0;
    int index = 0;

    while (index < wordsSize)
    {
        int totalChars = strlen(words[index]);
        int last = index + 1;
        while (last < wordsSize)
        {
            if (totalChars + 1 + strlen(words[last]) > maxWidth)
                break;
            totalChars += 1 + strlen(words[last]);
            last++;
        }

        char *line = malloc(sizeof(char) * (maxWidth + 1));
        line[0] = '\0';  
        int numOfWords = last - index;
        int numOfSpaces = maxWidth - totalChars + numOfWords - 1;

        if (last == wordsSize || numOfWords == 1)
        {
            for (int i = 0; i < numOfWords; i++)
            {
                strcat(line, words[index + i]);
                if (i < numOfWords - 1)
                    strcat(line, " ");
            }
            for (int i = strlen(line); i < maxWidth; i++)
                strcat(line, " ");
        }
        else
        {
            int spaces = numOfSpaces / (numOfWords - 1);
            int extraSpaces = numOfSpaces % (numOfWords - 1);

            for (int i = 0; i < numOfWords; i++)
            {
                strcat(line, words[index + i]);
                if (i < numOfWords - 1)
                {
                    for (int j = 0; j < spaces + (i < extraSpaces ? 1 : 0); j++)
                    {
                        strcat(line, " ");
                    }
                }
            }
        }

        result[(*returnSize)++] = line;
        index = last;
    }

    return result;
}

