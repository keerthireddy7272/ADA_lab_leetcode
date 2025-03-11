int firstUniqChar(char *s) {
    int count[26] = {0};
    char queue[strlen(s)];
    int front = 0, rear = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        queue[rear++] = s[i];
    }
    for (int i = 0; i < rear; i++) {
        char ch = queue[i];
        if (count[ch - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}
