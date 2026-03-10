//5th module
//ERROR HANDLING(DUPLICATE ENTRIES,VALID PH NO.,VALID EMAIL )
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int contactexists(char *name) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

int Valid(char *phone) {
    for (int i = 0; phone[i] != '\0'; i++) {
        if (phone[i] < '0' || phone[i] > '9') return 0;
    }
    return 1;
}

int validEmail(char *email) {
    int at = -1, dot = -1;
    int len = strlen(email);

    if (len < 5) return 0; 
    for (int i = 0; i < len; i++) {
        if (email[i] == ' ') return 0;
        if (email[i] == '@') {
            if (at != -1) return 0;
            at = i;
        } else if (email[i] == '.') {
            if (at != -1 && i > at) {
                dot = i;
            }
        }
    }

    if (at == -1 || dot == -1) return 0; 
    if (dot == at + 1) return 0;
    if (dot == len - 1) return 0; 

    return 1;
}
