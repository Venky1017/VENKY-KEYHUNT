#ifndef BLOOM_H
#define BLOOM_H
#include <stdint.h>

typedef struct {
    uint8_t *bit_array;
    size_t size;
} bloom_filter;

void bloom_init(bloom_filter *bf, size_t size, double error_rate);
void bloom_add(bloom_filter *bf, const char *data, size_t len);
int bloom_check(bloom_filter *bf, const char *data, size_t len);
void bloom_free(bloom_filter *bf);

#endif
