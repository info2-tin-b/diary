

// typedef <type> <new type name>;

typedef unsigned long int u64;

typedef unsigned long long int size_t; // size_t...
typedef unsigned char uint8_t;

typedef struct point {
    float x;
    float y;
    float z;
} Point; // point_t (pas bien, réservé par ISO 9899)

Point point; 


Point foo;
u64 bar = 23;


typedef enum {
    A, B, C
} UnionType;

typedef struct person {
    char firstname[64];
    char lastname[64];
    int born_year;
    float age;
} Person;

typedef struct couple {
    Person a;
    Person b;
    UnionType type;
} Couple;