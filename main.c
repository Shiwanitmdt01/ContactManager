#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

int main() {
    char current_user[50] = "";

    int choice;
    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            register_user();
        } else if (choice == 2) {
            if (login_user(current_user)) {
                printf("Login successful. %s!\n", current_user);
                break;
            }
        } else {
            printf("Invalid choice.\n");
        }
    } while (1);
     loadcontacts(current_user);  
    int n;
    do {
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Update Contact\n");
        printf("4. List Contacts\n");
        printf("5. Search Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice number: ");
        scanf("%d", &n);
        getchar();  
        switch (n) {
            case 1: addcontact(current_user); break;
            case 2: deletecontact(current_user); break;
            case 3: updatecontact(current_user); break;
            case 4: listcontact(); break;
            case 5: searchcontact(); break;
            case 6: printf("-Exiting-\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (n != 6);
    return 0;
}
