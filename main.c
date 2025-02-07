/*
 * BSGSD-like Private Key Search Tool
 * Author: VENKATA NAIDU NELLI
 * Description: This C project finds a 67-bit private key using a RIPEMD-160 hash
 *              within a given range, using a bloom filter and BSGSD optimization.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "bloom.h"  // Bloom filter header file
#include "bsgsd.h"  // BSGSD mode header file

#define START_RANGE 0x40000000000000000
#define END_RANGE   0x7ffffffffffffffff
#define TARGET_HASH "739437bb3dd6d1983e66629c5f08c70e52769371"

void search_private_key(uint64_t start, uint64_t end, int k_factor) {
    bloom_filter bf;
    bloom_init(&bf, 1000000, 0.01);  // Initialize bloom filter with size and error rate
    
    bsgsd_search(start, end, k_factor, &bf, TARGET_HASH);
    
    bloom_free(&bf);
}

int main(int argc, char *argv[]) {
    int k_factor = 232;
    if (argc > 1) k_factor = atoi(argv[1]);
    
    printf("Starting search with k-factor: %d\n", k_factor);
    search_private_key(START_RANGE, END_RANGE, k_factor);
    return 0;
}
