/*

  This file is a part of the Nova Physics Engine
  project and distributed under the MIT license.

  Copyright © Kadir Aksoy
  https://github.com/kadir014/nova-physics

*/

#include "novaphysics/internal.h"
#include "novaphysics/hashmap.h"
#include "novaphysics/constants.h"


/**
 * @file hashmap.c
 * 
 * @details Hash map implementation specifically designed to
 *          store {uint32 -> array} pairs.
 * 
 *          Function documentations are in novaphysics/hashmap.h
 */


uint32_t nv_hash(uint32_t key) {
    // https://stackoverflow.com/a/12996028
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;
    return key;
}


uint32_t nv_pair(uint16_t x, uint16_t y) {
    // https://stackoverflow.com/a/919631
    return (x << 16) | y;
}


void nv_HashMapEntry_free(nv_HashMapEntry *entry) {
    nv_Array_free(entry->value);
}

nv_HashMap *nv_HashMap_new() {
    nv_HashMap *hashmap = NV_NEW(nv_HashMap);
    hashmap->size = 0;
    hashmap->capacity = NV_HASHMAP_CAPACITY;

    hashmap->entries = calloc(hashmap->capacity, sizeof(nv_HashMapEntry));

    return hashmap;
}

void nv_HashMap_free(nv_HashMap *hashmap) {
    for (size_t i = 0; i < hashmap->capacity; i++) {
        if (hashmap->entries[i].key != NULL)
            nv_HashMapEntry_free(&hashmap->entries[i]);
    }

    free(hashmap->entries);
    free(hashmap);
}

nv_Array *nv_HashMap_get(nv_HashMap *hashmap, uint32_t key) {
    // & hash with capacity-1 to ensure it's within entries array
    uint32_t *k = &key;
    uint32_t h = nv_hash(key);
    size_t index = (size_t)(h & (size_t)(hashmap->capacity - 1));

    while (hashmap->entries[index].key != NULL) {
        // Found key
        if (k == hashmap->entries[index].key)
            return hashmap->entries[index].value;

        // Move to next bucket (linear probing)
        index++;
        if (index >= hashmap->capacity) {
            // Wrap around
            index = 0;
        }
    }

    return NULL;
}

static uint32_t *nv_HashMap_set_entry(
    nv_HashMapEntry *entries,
    size_t capacity,
    uint32_t *key,
    nv_Array *value,
    size_t *size_out
) {
    // & hash with capacity-1 to ensure it's within entries array
    uint64_t hash = nv_hash(*key);
    size_t index = (size_t)(hash & (uint64_t)(capacity - 1));

    // Loop till we find an empty entry
    while (entries[index].key != NULL) {
        if (key == entries[index].key) {
            // Found key (it already exists), update value.
            entries[index].value = value;
            return entries[index].key;
        }

        // Move to next bucket (linear probing).
        index++;
        if (index >= capacity) {
            // Wrap around.
            index = 0;
        }
    }

    // Didn't find key, insert it.
    (*size_out)++;

    entries[index].key = key;
    entries[index].value = value;

    return key;
}

uint32_t *nv_HashMap_set(nv_HashMap *hashmap, uint32_t key, nv_Array *value) {
    // TODO: capacity overflow checks

    return nv_HashMap_set_entry(
        hashmap->entries,
        hashmap->capacity,
        &key, value,
        &hashmap->size
    );
}