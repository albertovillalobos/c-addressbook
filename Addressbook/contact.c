//
//  contact.c
//  Addressbook
//
//  Created by Isaac on 12/3/14.
//  Copyright (c) 2014 Alberto. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contact.h"


void addContact(ContactPointer * theContact, int index, char *data) {

    ContactPointer currentContactPointer = *theContact;
    ContactPointer previousContactPointer;
    ContactPointer nextContactPointer;
  
    ContactPointer newContactPointer = malloc(sizeof(Contact));
    char delimiter = ',';
    data = strtok(data, &delimiter);
    for (int x=0; data!=NULL; x++) {
        switch (x) {
            case 0:
                printf("found lastname: %s", data);
                strcpy(newContactPointer->lastName, data);
                break;
                
            case 1:
                printf("found firstname: %s", data);
                strcpy(newContactPointer->firstName, data);
                break;
                
            case 2:
                printf("found email: %s", data);
                strcpy(newContactPointer->email, data);
                break;
                
            case 3:
                printf("found phone: %s", data);                
                strcpy(newContactPointer->phone, data);
            default:
                break;
        }
    }
    printf("Last Name: %s, First Name: %s, Email: %s, Phone: %s", newContactPointer->lastName, newContactPointer->firstName, newContactPointer->email, newContactPointer->phone);
}

