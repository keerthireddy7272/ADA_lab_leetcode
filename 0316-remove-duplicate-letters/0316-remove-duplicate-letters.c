char* removeDuplicateLetters(char* s) {
    int last_occurrence[26] = {0};
    bool in_stack[26] = {0};
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        last_occurrence[s[i] - 'a'] = i;
    }
    int stack_index = 0;
    char* stack = (char*)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        int current_char_index = s[i] - 'a';
        if (in_stack[current_char_index]) continue;
        while (stack_index > 0 && s[i] < stack[stack_index - 1] && i < last_occurrence[stack[stack_index - 1] - 'a']) {
            in_stack[stack[stack_index - 1] - 'a'] = 0;
            stack_index--;
        }
        stack[stack_index++] = s[i];
        in_stack[current_char_index] = 1;
    }
    stack[stack_index] = '\0'; 
    return stack;
}

