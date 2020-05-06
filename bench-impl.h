#include <stdio.h>
#include <picotls/fusion.h>

int main(int argc, char **argv)
{
    static const uint8_t key[16] = {}, iv[12] = {}, aad[13] = {}, text[16384] = {};
    ptls_fusion_aesgcm_context_t ctx;
    uint8_t encrypted[sizeof(text) + 16];
    size_t textlen = 16384;

#ifdef USE_SSCANF
	printf("with sscanf\n");
    if (sscanf(argv[1], "%zu", &textlen) != 1) {
        fprintf(stderr, "failed to obtain text length from argument\n");
        return 1;
    }
#else
	printf("without sscanf\n");
#endif

    ptls_fusion_aesgcm_init(&ctx, key);

    for (int i = 0; i < 1000000; ++i)
        ptls_fusion_aesgcm_encrypt(&ctx, iv, aad, sizeof(aad), encrypted, text, textlen);


    for (int i = 0; i < 16; ++i)
        printf("%02x", encrypted[sizeof(text) + i]);
    printf("\n");

    return 0;
}
