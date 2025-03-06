
int countchar(char *str, char c) {

}

typedef struct stats {
    int chars; 
    int words;
    int lines;
    int puncts; 
} Stats;

void process_string(const char * str, Stats *stats) {
    char *str = "un \ndeux trois!";

    stats->chars += strlen(str);
    stats->lines += countchar(str, '\n') + 1;
}

int main() {
    Stats stats;

    process_string("un deux trois", &stats)
    process_string("bonjour ca va", &stats)
    assert(stats.words == 6);
    assert(stats.chars == 26);
}