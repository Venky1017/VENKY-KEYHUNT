#include "bsgsd.h"
#include <stdio.h>
#include <string.h>

void compute_ripemd160(uint64_t key, char *output) {
    snprintf(output, 41, "%016llx", key);  // Placeholder for actual RIPEMD-160
}

void bsgsd_search(uint64_t start, uint64_t end, int k_factor) {
    for (uint64_t key = start; key <= end; key += k_factor) {
        char hash[41];
        compute_ripemd160(key, hash);
        printf("Checking key: 0x%llx\n", key);
    }
}
