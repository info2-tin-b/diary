#include <stdio.h>
#include <ctype.h>

typedef struct stats {
    size_t vowels;
    size_t consonants;
} Stats;

void process_string(char * s, Stats *data) {
    const size_t size = strlen(s);
    for (int i = 0; i < size; i++) {
        if (strchr("aeiouy", s[i])) {
            data->vowels++;
            continue;
        }
        if (isalpha(s[i])) {
            data->consonants++;
        } 
    }
}

int main() {
    Stats stats = {0};
    process_string("chocolat", &stats);
    process_string("banane", &stats);

    printf("Consonnes : %ld, Voyelles : %ld\n", 
        stats.consonants, stats.vowels);
}