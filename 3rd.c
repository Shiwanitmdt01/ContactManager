//3rd module
//SEARCH CONTACT
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
void searchcontact() {
    char keyword[50];
    printf("Enter name or part of name to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < contactCount; i++) {
        if (strstr(contacts[i].name, keyword)) {
            printf("Name : %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n\n", contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching contacts found.\n");
    }
}
