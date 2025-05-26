
static int i = 0;

static int *p = &i;

#define LED (*p)

int main() {
    LED = 0;
    LED = 1;
    LED = 0;
    LED = 1;
}