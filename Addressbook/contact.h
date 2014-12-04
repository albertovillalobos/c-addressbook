//
//  contact.h
//  Addressbook
//
//  Created by Isaac on 12/3/14.
//  Copyright (c) 2014 Alberto. All rights reserved.
//


#ifndef __Addressbook__contact__
#define __Addressbook__contact__

#include <stdio.h>

struct contact {
    char lastName[255];
    char firstName[255];
    char email[255];
    char phone[255];
    
    struct contact *nxtPtr;
    struct contact *prvPtr;
};

typedef struct contact Contact;
typedef Contact * ContactPointer;


void addContact(ContactPointer * theContact, int index, char *data);
//void deleteContact(ContactPointer * theContact, int index);
//void printContacts(ContactPointer * theContact, int index);
//void printField(ContactPointer * theContact, int index, char *field);
//int getListSize(ContactPointer * theContact);
//void saveFile(ContactPointer * theContact, char const * filename);
//void loadFile(char * filename);


#endif
