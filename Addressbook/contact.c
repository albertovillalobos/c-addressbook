//
//  contact.c
//  Addressbook
//
//  Created by Isaac on 12/3/14.
//  Copyright (c) 2014 Alberto. All rights reserved.
//

#include "contact.h"

void insert(char value[255]) {
    
}


//void insert(char value) {
//    pNode pNewNode; //New node pointer
//    pNode pPreviousNode; //Previous node pointer
//    pNode pCurNode; //current node pointer
//    y
//    pNewNode = malloc(sizeof(Node)); //allocate memory needed for new item in list
//    
//    if (pNewNode) //if allocation succeeded
//    {
//        pNewNode->data = value;
//        pNewNode->pNext = NULL; //does not point to anything yet
//        
//        //starting at startNode, find where to insert the node in the list
//        pPreviousNode = NULL;
//        pCurNode = pGenNode;
//        while (pCurNode && (value > pCurNode->data)) //find where to insert
//        {
//            pPreviousNode = pCurNode;
//            pCurNode = pCurNode->pNext;
//        }
//        if (pPreviousNode == NULL) //Insert at the beginning of list
//        {
//            pNewNode->pNext = pGenNode;
//            pGenNode = pNewNode;
//        } else {
//            pPreviousNode->pNext = pNewNode;
//            pNewNode->pNext = pCurNode;
//        }
//    } else
//        printf("%c not inserted. Not enough memory\n");
//    
//}
////Delete a node in the list that has data value value
//char delete(char value) {
//    pNode pTempNode; //temporary node pointer
//    pNode pPreviousNode; //Previous node pointer
//    pNode pCurNode; //current node pointer
//    
//    //Delete first item
//    if (pGenNode && (value == pGenNode->data)) {
//        pTempNode = pGenNode;
//        pGenNode = pGenNode->pNext;
//        free(pTempNode);
//        return value;
//    } else //set previous node equal to first node and current node to 2nd node
//    {
//        pPreviousNode = pGenNode;
//        pCurNode = pGenNode->pNext;
//        
//        //Loop through list to find correct location
//        while (pCurNode && pCurNode->data != value) {
//            pPreviousNode = pCurNode;
//            pCurNode = pCurNode->pNext;
//        }
//        if (pCurNode) {
//            pTempNode = pCurNode;
//            pPreviousNode->pNext = pCurNode->pNext;
//            free(pTempNode);
//            return value;
//        }
//        
//    }
//    return '\0';
//}

