#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_LEN 16  // 15文字 + '\0'

int max(int a, int b) {
    return a > b ? a : b;
}

// s1の末尾とs2の先頭が重なる最大の長さを求める
int overlap_length(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int max_overlap = 0;

    // 最長でmin(len1, len2)まで重なりうる
    for (int k = 1; k <= len1 && k <= len2; ++k) {
        if (strncmp(s1 + len1 - k, s2, k) == 0) {
            max_overlap = k;
        }
    }
    return max_overlap;
}

int main() {
    int N;
    char words[MAX_N][MAX_LEN];
    int max_length = 0;

    // 入力
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", words[i]);
    }

    // 全ペアを調べる（i ≠ j）
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;

            int overlap = overlap_length(words[i], words[j]);
            int merged_length = strlen(words[i]) + strlen(words[j]) - overlap;

            max_length = max(max_length, merged_length);
        }
    }

    printf("%d\n", max_length);
    return 0;
}
