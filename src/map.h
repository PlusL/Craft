#ifndef _map_h_
#define _map_h_

#define EMPTY_ENTRY(entry) ((entry)->value == 0)

#define MAP_FOR_EACH(map, ex, ey, ez, ew) \
    for (unsigned int i = 0; i <= map->mask; i++) { \
        MapEntry *entry = map->data + i; \
        if (EMPTY_ENTRY(entry)) { \
            continue; \
        } \
        int ex = entry->e.x + map->dx; \
        int ey = entry->e.y + map->dy; \
        int ez = entry->e.z + map->dz; \
        int ew = entry->e.w;

#define END_MAP_FOR_EACH }

typedef union {                 //地图项
    unsigned int value;         //值
    struct {
        unsigned char x;        //x
        unsigned char y;        //y
        unsigned char z;        //z
        char w;
    } e;
} MapEntry;

typedef struct {                //定义地图
    int dx;                     //长
    int dy;                     //宽
    int dz;                     //高
    unsigned int mask;          //遮挡
    unsigned int size;          //大小
    MapEntry *data;             //数据
} Map;

void map_alloc(Map *map, int dx, int dy, int dz, int mask);
void map_free(Map *map);
void map_copy(Map *dst, Map *src);
void map_grow(Map *map);
int map_set(Map *map, int x, int y, int z, int w);
int map_get(Map *map, int x, int y, int z);

#endif
