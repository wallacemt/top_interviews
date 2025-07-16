int ladderLength(char* beginWord, char* endWord, char** wordList,
                 int wordListSize) {
    int len = strlen(beginWord);
    bool* visited = (bool*)calloc(wordListSize, sizeof(bool));
    char** queue = (char**)malloc(sizeof(char*) * (wordListSize + 1));

    int front = 0, rear = 0;
    queue[rear++] = beginWord;
    int level = 1;

    while (front < rear) {
        int currentLevelSize = rear - front;
        for (int i = 0; i < currentLevelSize; i++) {
            char* currentWord = queue[front++];
            for (int j = 0; j < wordListSize; j++) {
                if (visited[j])
                    continue;

                int diff = 0;
                for (int k = 0; k < len; k++) {
                    if (currentWord[k] != wordList[j][k])
                        diff++;
                    if (diff > 1)
                        break;
                }

                if (diff == 1) {
                    if (strcmp(wordList[j], endWord) == 0) {
                        free(visited);
                        free(queue);
                        return level + 1;
                    }
                    visited[j] = true;
                    queue[rear++] = wordList[j];
                }
            }
        }
        level++;
    }

    free(visited);
    free(queue);
    return 0;
}
