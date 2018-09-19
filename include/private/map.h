#ifndef REFLECS_MAP_H
#define REFLECS_MAP_H

#include <reflecs/reflecs.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsMap EcsMap;

typedef struct EcsMapIter {
    uint32_t bucket_index;
    void *node;
} EcsMapIter;

REFLECS_EXPORT
EcsMap* ecs_map_new(
    uint32_t size);

REFLECS_EXPORT
void ecs_map_free(
    EcsMap *map);

REFLECS_EXPORT
uint32_t ecs_map_count(
    EcsMap *map);

REFLECS_EXPORT
uint32_t ecs_map_bucket_count(
    EcsMap *map);

REFLECS_EXPORT
void ecs_map_clear(
    EcsMap *map);

REFLECS_EXPORT
void ecs_map_set(
    EcsMap *map,
    uint64_t key_hash,
    const void *data);

REFLECS_EXPORT
EcsResult ecs_map_remove(
    EcsMap *map,
    uint64_t key_hash);

REFLECS_EXPORT
void* ecs_map_get(
    EcsMap *map,
    uint64_t key_hash);

REFLECS_EXPORT
EcsIter _ecs_map_iter(
    EcsMap *map,
    EcsMapIter *iter_data);

#define ecs_map_iter(me)\
    _ecs_map_iter(me, alloca(sizeof(EcsMapIter)))

#ifdef __cplusplus
}
#endif

#endif