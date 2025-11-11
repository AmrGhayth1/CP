#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MOD 132120577
#define MAXN (1 << 18) // Must be a power of 2 greater than 2*N

typedef long long ll;
typedef struct {
    double real, imag;
} complex_t;

complex_t temp[MAXN];
complex_t fa[MAXN], fb[MAXN];

void fft(complex_t *a, int n, bool invert) {
    for (int i = 0; i < n; ++i) {
        int rev = 0;
        for (int j = 0; j < __builtin_ctz(n); ++j) {
            if (i & (1 << j)) rev |= 1 << (__builtin_ctz(n) - 1 - j);
        }
        if (i < rev) {
            complex_t tmp = a[i];
            a[i] = a[rev];
            a[rev] = tmp;
        }
    }
    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * M_PI / len * (invert ? -1 : 1);
        complex_t wlen;
        wlen.real = cos(angle);
        wlen.imag = sin(angle);
        for (int i = 0; i < n; i += len) {
            complex_t w;
            w.real = 1;
            w.imag = 0;
            for (int j = 0; j < len / 2; ++j) {
                complex_t u = a[i + j];
                complex_t v;
                v.real = a[i + j + len/2].real * w.real - a[i + j + len/2].imag * w.imag;
                v.imag = a[i + j + len/2].real * w.imag + a[i + j + len/2].imag * w.real;
                a[i + j].real = u.real + v.real;
                a[i + j].imag = u.imag + v.imag;
                a[i + j + len/2].real = u.real - v.real;
                a[i + j + len/2].imag = u.imag - v.imag;
                complex_t next_w;
                next_w.real = w.real * wlen.real - w.imag * wlen.imag;
                next_w.imag = w.real * wlen.imag + w.imag * wlen.real;
                w = next_w;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; ++i) {
            a[i].real /= n;
            a[i].imag /= n;
        }
    }
}

void multiply(int *a, int *b, int n, int *res) {
    int size = 1;
    while (size < 2 * n) size <<= 1;
    for (int i = 0; i < size; ++i) {
        fa[i].real = i < n ? a[i] : 0;
        fa[i].imag = 0;
        fb[i].real = i < n ? b[i] : 0;
        fb[i].imag = 0;
    }
    fft(fa, size, false);
    fft(fb, size, false);
    for (int i = 0; i < size; ++i) {
        double real = fa[i].real * fb[i].real - fa[i].imag * fb[i].imag;
        double imag = fa[i].real * fb[i].imag + fa[i].imag * fb[i].real;
        fa[i].real = real;
        fa[i].imag = imag;
    }
    fft(fa, size, true);
    for (int i = 0; i < size; ++i) {
        res[i] = (ll)(fa[i].real + 0.5) % MOD;
    }
}

int c[MAXN * 2] = {0};
int diff[MAXN * 2] = {0};
int prefix[MAXN * 2] = {0};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(c, 0, sizeof(c));
        memset(diff, 0, sizeof(diff));
        memset(prefix, 0, sizeof(prefix));
        
        int N;
        scanf("%d", &N);
        int max_x = 0;
        for (int i = 0; i < N; ++i) {
            int x, f;
            scanf("%d %d", &x, &f);
            c[x] = (c[x] + f) % MOD;
            if (x > max_x) max_x = x;
        }
        
        int size = 1;
        while (size <= 2 * max_x) size <<= 1;
        
        // Prepare the polynomial coefficients
        int *a = (int *)malloc(size * sizeof(int));
        int *b = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; ++i) {
            a[i] = (i <= max_x) ? c[i] : 0;
            b[i] = (i <= max_x) ? c[i] : 0;
        }
        
        // Multiply the polynomials
        int *res = (int *)malloc(size * sizeof(int));
        multiply(a, b, size, res);
        
        // Compute the difference counts
        for (int d = 0; d < size; ++d) {
            if (d == 0) {
                // Subtract the pairs (i, i)
                ll cnt = 0;
                for (int i = 1; i <= max_x; ++i) {
                    cnt = (cnt + (ll)c[i] * (c[i] - 1) / 2) % MOD;
                }
                diff[d] = cnt;
            } else {
                diff[d] = res[d] % MOD;
            }
        }
        
        // Compute prefix sums
        prefix[0] = diff[0];
        for (int d = 1; d < size; ++d) {
            prefix[d] = (prefix[d - 1] + diff[d]) % MOD;
        }
        
        int Q;
        scanf("%d", &Q);
        while (Q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            int ans;
            if (l == 0) {
                ans = prefix[r];
            } else {
                ans = (prefix[r] - prefix[l - 1] + MOD) % MOD;
            }
            printf("%d\n", ans);
        }
        
        free(a);
        free(b);
        free(res);
    }
    return 0;
}