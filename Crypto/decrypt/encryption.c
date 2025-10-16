#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

static inline unsigned char rol(unsigned char val, unsigned int n) {
    return (val << (n & 7)) | (val >> (8 - (n & 7)));
}


int main(void) {
    FILE *in = fopen("highly_important.txt", "rb");
    if (!in) return 1;
    fseek(in, 0, SEEK_END);
    size_t size = ftell(in);
    rewind(in);
    unsigned char *buf = malloc(size);
    if (!buf) { fclose(in); return 1; }
    fread(buf, 1, size, in);
    fclose(in);

    uint32_t seed = (uint32_t)time(NULL);
    srand(seed);

    for (size_t i = 0; i < size; i++)
        buf[i] = rol(buf[i], rand() & 7);

    FILE *out = fopen("highly_important.enc", "wb");
    if (!out) { free(buf); return 1; }
    fwrite(&seed, sizeof(seed), 1, out);
    fwrite(buf, 1, size, out);
    fclose(out);

    free(buf);
    return 0;
}
