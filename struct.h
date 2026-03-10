#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} newcont;

typedef struct {
    char username[50];
    char password[50];
    newcont contacts[100];
    int contactCount;
} User;


int user_exists(char *);
void register_user();
int login_user(char *);

void loadcontacts(char *username);
void savecontacts(char *username);

void addcontact(char *);
void deletecontact(char *);
int updatecontact(char *);
void listcontact();
void searchcontact();
int contactexists(char *name);
int Valid(char *);
int validEmail(char *);
int cindex(char *);

#define MAX_USERS 50

extern User users[MAX_USERS];
extern newcont contacts[100];
extern int contactCount;