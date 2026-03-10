//2nd module 
//ADD,DELETE,UPDATE CONTACTS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void addcontact(char *username) {
    newcont c;
    char ch;
    int found;
    printf("Enter name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0';
    found = contactexists(c.name);
    if (found == 1) {
        printf("Contact already exists. Do you want to update it? (Y/N): ");
        scanf(" %c", &ch);
        getchar();
        if (ch == 'y' || ch == 'Y') {
            updatecontact(username);
        } else {
            printf("Contact not added.\n");
        }
        return;
    }

    printf("Enter phone no.: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';
    if (!Valid(c.phone)) {
        printf("Invalid phone number. Try again.\n");
        return;
    }

    printf("Enter email ID: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';
    if (!validEmail(c.email)){
        printf("Invalid email . Try again.\n");
        return;
        }
    contacts[contactCount++] = c;
    
    savecontacts(username);
    printf("Contact added successfully!\n");
}

void deletecontact(char *username) {
    char name[50];
    printf("Enter name to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int index = cindex(name);
    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (int i = index; i < contactCount - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contactCount--;
    
    savecontacts(username);
    printf("Contact deleted successfully.\n");
}

int cindex(char *name) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) return i;
    }
    return -1;
}

int updatecontact(char *username)
{
    char name[50];
    printf("Enter name to update: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int sh=0;
    int index = cindex(name);
    if (index == -1) {
        printf("Contact not found.\n");
        return 0;
    }

    while (1) {
        printf("Enter new phone (digits only): ");
        fgets(contacts[index].phone, sizeof(contacts[index].phone), stdin);
        contacts[index].phone[strcspn(contacts[index].phone, "\n")] = '\0';
        if (Valid(contacts[index].phone)) break;
        else printf("Invalid phone number. Try again: ");
    }

    printf("Enter new email: ");
    fgets(contacts[index].email, sizeof(contacts[index].email), stdin);
    contacts[index].email[strcspn(contacts[index].email, "\n")] = '\0';

    savecontacts(username);
    printf("Contact updated successfully.\n");
    
return 0;
}

void listcontact() {
    if (contactCount == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Name : %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n\n", contacts[i].email);
    }
}
void loadcontacts(char *username) {
    char filename[100];
    strcpy(filename, username);       
    strcat(filename, "_contacts.txt"); 

    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    contactCount = 0;
    while (fgets(contacts[contactCount].name, sizeof(contacts[contactCount].name), fp)) 
    
    {
        contacts[contactCount].name[strcspn(contacts[contactCount].name, "\n")] = '\0';

        if (fgets(contacts[contactCount].phone, sizeof(contacts[contactCount].phone), fp)) {
            contacts[contactCount].phone[strcspn(contacts[contactCount].phone, "\n")] = '\0';
        }

        if (fgets(contacts[contactCount].email, sizeof(contacts[contactCount].email), fp)) {
            contacts[contactCount].email[strcspn(contacts[contactCount].email, "\n")] = '\0';
        }
        contactCount++;
    }
    fclose(fp);
}
