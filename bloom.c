#include "bloom.h"
#include <stdlib.h>
#include <string.h>

void bloom_init(bloom_filter *bf, size_t size, double error_rate) {
    bf->size = size;
    bf->bit_array = calloc(size, sizeof(uint8_t));
}

void bloom_add(bloom_filter *bf, const char *data, size_t len) {
    size_t index = (size_t)(data[0] % bf->size);
    bf->bit_array[index] = 1;
}

int bloom_check(bloom_filter *bf, const char *data, size_t len) {
    size_t index = (size_t)(data[0] % bf->size);
    return bf->bit_array[index];
}

void bloom_free(bloom_filter *bf) {
    free(bf->bit_array);
}