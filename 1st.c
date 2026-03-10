//1st module 
//AUTHENTICATION
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int user_exists(char *username)
  {
    FILE *fp = fopen("users.txt", "r");
    if (!fp) return 0;
    User u;
    while (fscanf(fp, "%s %s", u.username, u.password) != EOF) {
        if (strcmp(username, u.username) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void register_user() 
{
    char username[50], password[50];

    printf("Enter new username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;
    if (user_exists(username)) {
        printf("Username already exists.\n");
        return;
    }

    printf("Enter new password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;
    FILE *fp = fopen("users.txt", "a");
    if (!fp) {
        printf("Error opening user file.\n");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);
    printf("Registration successful.\n");
}

int login_user(char *liu)
{  char username[50], password[50];

    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    FILE *fp = fopen("users.txt", "r");
    if (!fp) {
        printf("No users registered yet.\n");
        return 0;
    }
 
    User u;
    while (fscanf(fp, "%s %s", u.username, u.password) != EOF)
    {
        if (strcmp(username, u.username) == 0 && strcmp(password, u.password) == 0) {
            fclose(fp);
            strcpy(liu, username);
            return 1;
        }
    }

    fclose(fp);
    printf("Login failed. Incorrect credentials.\n");
    return 0;
}
