#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    char name[64];
    uint64_t phone;
} Contact;

Contact contacts[10] = {
    {"Alice", 1234567890},
    {"Bob", 2345678901},
    {"Charlie", 3456789012},
    {"David", 4567890123},
    {"Eve", 5678901234},
    {"Frank", 6789012345},
    {"Grace", 7890123456},
    {"Heidi", 8901234567},
    {"Ivan", 9012345678},
    {"Judy", 1234567890}
};

void display_contact(Contact contact) {
    printf("%ld, %s\n", contact.phone, contact.name);
}

void display(Contact *contacts, size_t size) {
    for (int i = 0; i < size; i++) 
        display_contact(contacts[i]);
}

int cmp(const void* a, const void* b) {
    return (*(Contact*)a).phone - (*(Contact*)b).phone;
}

int linear_search(Contact *contacts, size_t size, uint64_t needle) {
    for (int i = 0; i < size; i++) {
        if (contacts[i].phone == needle) return i;
    }
    return -1;
}

int main() {
   qsort(contacts, sizeof(contacts)/sizeof(contacts[0]), sizeof(contacts[0]), cmp);
   display(contacts, sizeof(contacts)/sizeof(contacts[0]));
   uint64_t phone = 8901234567;
   printf("Looking for %ld: \n", phone);
   int k = linear_search(contacts, sizeof(contacts)/sizeof(contacts[0]), phone);
   if (k < 0) {
        printf("Contact not found\n");
   } else {
        display_contact(contacts[k]);
   }
}