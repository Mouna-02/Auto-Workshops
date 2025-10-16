#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static inline unsigned char ror8(unsigned char v, unsigned int n){
    n &= 7;
    return (unsigned char)((v >> n) | (v << (8 - n)));
}

int main(void){
    FILE *f = fopen("highly_important.enc","rb");
    if(!f) return 1;
    if(fseek(f,0,SEEK_END) != 0) { fclose(f); return 1; }
    long total = ftell(f);
    if(total < 0) { fclose(f); return 1; }
    size_t payload = (size_t)(total - 4);
    rewind(f);

    uint32_t seed;
    if(fread(&seed, sizeof(seed), 1, f) != 1) { fclose(f); return 1; }

    unsigned char *buf = malloc(payload ? payload : 1);
    if(!buf) { fclose(f); return 1; }
    if(fread(buf, 1, payload, f) != payload) { free(buf); fclose(f); return 1; }
    fclose(f);
    

    srand((unsigned)seed);
    for(size_t i = 0; i < payload; ++i)
        buf[i] = ror8(buf[i], rand() & 7);

    FILE *out = fopen("highly_important.dec","wb");
    if(!out) { free(buf); return 1; }
    fwrite(buf, 1, payload, out);
    fclose(out);
    free(buf);
    return 0;
}
