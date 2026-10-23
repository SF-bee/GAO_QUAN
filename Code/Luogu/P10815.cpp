#include <bits/stdc++.h>

int n;
long long sum;

constexpr int BUFFER_SIZE = 1 << 20;
char buffer[BUFFER_SIZE];
int buffer_index;
int buffer_size;

inline int next_char() {
    if (buffer_index >= buffer_size) {
        buffer_size = fread(buffer, 1, BUFFER_SIZE, stdin);
        buffer_index = 0;
        if (buffer_size == 0) return EOF;
    }
    return buffer[buffer_index++];
}

void read(int &x) {
    x = 0;
    int ch = next_char();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = next_char();
    bool neg = ch == '-';
    if (neg) ch = next_char();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = next_char();
    }
    if (neg) x = -x;
}

void write(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    static int sta[40];
    int top = 0;
    do {
        sta[top++] = x % 10;
        x /= 10;
    } while (x);
    while (top) putchar('0' + sta[--top]);
}

int main() {
    read(n);
    int a;
    while (n--)
        read(a), sum += a;
    write(sum);
    return 0;
}
