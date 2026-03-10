//4th module
//FILE HANDLING(SAVE,READ)
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void savecontacts(char *username) {
FILE *fp;
    char filename[100];

strcpy(filename, username);        
strcat(filename, "_contacts.txt");  

    fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file to save contacts.\n");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        fprintf(fp, "%s\n%s\n%s\n", contacts[i].name,contacts[i].phone,contacts[i].email);
    }

    fclose(fp);
    printf("Contacts saved successfully!\n");
}
