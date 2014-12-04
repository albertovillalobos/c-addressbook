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

// Typedef stuff
typedef struct contact Contact;
typedef Contact *nextPtr;
typedef Contact *prvPtr;

nextPtr firstNode;

void insert(char input[255]);
void delete(char value[255]);



#endif /* defined(__Addressbook__contact__) */
