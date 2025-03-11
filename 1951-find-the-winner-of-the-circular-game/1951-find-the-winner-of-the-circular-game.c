int findTheWinner(int n, int k) {
    int queue[n];
    for (int i = 0; i < n; i++) {
        queue[i] = i + 1;
    }

    int current = 0;
    while (n > 1) {
        current = (current + k - 1) % n;
        for (int i = current; i < n - 1; i++) {
            queue[i] = queue[i + 1];
        }
        n--;
    }
    return queue[0];
}


