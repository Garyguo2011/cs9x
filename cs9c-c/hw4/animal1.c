typedef int boolean;
#define FALSE 0
#define TRUE !FALSE

#define MAXSTRLEN 80
#define MAXNUMQS 32

#include "animal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct treeStruct {
    char *nodes[MAXNUMQS];
} treeStruct;

struct positionStruct {
    int nodeIndex;
} positionStruct;

void unitTest();

// int main(int argc, char const *argv[])
// {
//     unitTest();
//     return 0;
// }

/*s
 *  Return an animal tree.
 */
TreeType InitTree (char *file) {
    TreeType tree = calloc(MAXNUMQS, MAXSTRLEN);
    FILE *fp;
    if ((fp = fopen(file, "r")) == NULL) {
        tree->nodes[0] = "Is it furry?";
        tree->nodes[1] = "Does it meow?";
        tree->nodes[2] = "Does it have tusks?";
        tree->nodes[3] = "a cat";
        tree->nodes[4] = "a dog";
        tree->nodes[5] = "Does it have big ears";
        tree->nodes[6] = "an alligator";
        tree->nodes[11] = "an elephant";
        tree->nodes[12] = "a rhinoceros";    
    } else {
        int i;
        for (i=0; i < MAXNUMQS; i++) {
            char *readLine = (char*) malloc(MAXSTRLEN);
            fgets(readLine, MAXSTRLEN+1, fp);
            readLine[strlen(readLine)-1] = 0;
            tree->nodes[i] = readLine;
        }
        fclose(fp);
    }
    return tree;
}

/*
 *  Print an animal tree (useful for debugging).
 */
void PrintTree (TreeType tree) {
    int i;
    for (i=0; i < MAXNUMQS; i++) {
        if(tree->nodes[i] != NULL){
            printf("N%d: %s\n", i, tree->nodes[i]);
        }
    }
}

/*
 *  Return the position of the "top" node in the animal tree.
 */
PositionType Top (TreeType tree) {
    PositionType pos = (PositionType) malloc(sizeof(PositionType));
    pos->nodeIndex = 0;
    return pos;
}

/*
 *  Return true exactly when pos is a "leaf" of the animal tree,
 *  that is, when the string stored at pos is a guess rather than
 *  a question.
 */
boolean IsLeaf (TreeType tree, PositionType pos) {
    /* Your code goes here -- delete this line */
    char buf[MAXSTRLEN];
    strcpy(buf, tree->nodes[pos->nodeIndex]);
    return buf[strlen(tree->nodes[pos->nodeIndex]) - 1] != '?';
}

/*
 *  Return true if the answer supplied by the user to the given question
 *  starts with 'y', false otherwise.
 */
boolean Answer (char *question) {
    char buf[MAXSTRLEN];
    printf("%s\n", question);
    gets(buf);
    if (buf[0]) {
        return buf[0] == 'y';
    } else {
        printf("Please provide an answer\n");
        return Answer(question);
    }
}

/*
 *  Form a question out of the string stored at position pos in the given
 *  animal tree.
 */
char *Question (TreeType tree, PositionType pos) {
    /* Your code goes here -- delete this line */
    if (IsLeaf(tree, pos)) {
        return Guess(tree, pos);
    } else {
        return tree->nodes[pos->nodeIndex];
    }
}

/*
 *  Form a guess out of the string stored at position pos in the given
 *  animal tree.  (IsLeaf(tree, pos) must be true.)
 */
char *Guess (TreeType tree, PositionType pos) {
    char* guessStr = (char*) malloc(MAXSTRLEN*sizeof(char));
    strcpy(guessStr, "Is it ");
    strcat(guessStr, tree->nodes[pos->nodeIndex]);
    strcat(guessStr, "?");
    return guessStr;
}

/*
 *  Return the position of the node that corresponds to a "yes" answer
 *  to the question stored at position pos in the animal tree.
 */
PositionType YesNode (TreeType tree, PositionType pos) {
    PositionType returnPos = (PositionType) malloc(sizeof(PositionType));
    returnPos->nodeIndex = (2 * (pos->nodeIndex)) + 1;
    return returnPos;
}

/*
 *  Return the position of the node that corresponds to a "no" answer
 *  to the question stored at position pos in the animal tree.
 */
PositionType NoNode (TreeType tree, PositionType pos) {
    PositionType returnPos = (PositionType) malloc(sizeof(PositionType));
    returnPos->nodeIndex = (2 * (pos->nodeIndex)) + 2;
    return returnPos;
}

/*
 *  Replace the node at position pos in the given animal tree by a node
 *  containing the given new question whose left child (down the tree in 
 *  the "yes" direction) contains the string stored at position pos, and 
 *  whose right child contains the new answer newA.
 */
void ReplaceNode (TreeType tree, PositionType pos, char *newA, char *newQ) {
    tree->nodes[NoNode(tree, pos)->nodeIndex] = newA;
    tree->nodes[YesNode(tree,pos)->nodeIndex] = tree->nodes[pos->nodeIndex];
    tree->nodes[pos->nodeIndex] = newQ;
}

/*
 *  Admit that you guessed wrong, ask the player what animal he/she was 
 *  thinking of, and return this in *newA.  Also ask for a question that 
 *  would be answered "yes" for what you guessed and "no" for what the 
 *  player was thinking of, and return this in *newQ.  (The node with
 *  your guess is at position pos in the tree.)
 */
void GetNewInfo (TreeType tree, PositionType pos, char **newA, char **newQ) {
    printf("I give up. What is it?");
    char* answer = (char*) malloc(MAXSTRLEN*sizeof(char));
    char* question = (char*) malloc(MAXSTRLEN*sizeof(char));
    gets(answer);
    printf("Please provide a question whose answer is yes for %s and no for %s\n", tree->nodes[pos->nodeIndex], answer);
    gets(question);
    *newA = answer;
    *newQ = question;
}

void WriteTree(TreeType tree, char *file) {
    FILE *fp;
    if ((fp = fopen(file, "w")) != NULL) {
        int i;
        for (i=0; i < MAXNUMQS; i++) {
            if (tree->nodes[i] != NULL) {
                fputs(tree->nodes[i], fp);
            }
            fputs("\n", fp);
        }
        fclose(fp);
    }
}

void unitTest() {
    TreeType tree = InitTree("inputTree");
    PrintTree(tree);
    PositionType question = (PositionType) malloc(sizeof(PositionType));
    question->nodeIndex = 0;
    PositionType answer = (PositionType) malloc(sizeof(PositionType));
    answer->nodeIndex = 5;
    printf("IsLeaf test 1: %s\n", IsLeaf(tree, question) ? "error" : "pass");
    printf("IsLeaf test 2: %s\n", IsLeaf(tree, answer) ? "pass" : "error");
    printf("Top test: %s\n", (Top(tree))->nodeIndex == 0 ? "pass" : "error");
    printf("Question test 1: %s\n", strcmp(Question(tree, question), "Is it furry?") == 0 ? "pass" : "error");
    printf("Question test 2: %s\n", strcmp(Question(tree, answer), "Is it a lizard?") == 0 ? "pass" : "error");
    printf("%s\n", Question(tree, answer));
    printf("Is it a lizard?\n");
    PositionType toReplace = (PositionType) malloc(sizeof(PositionType));
    toReplace->nodeIndex = 7;
    TreeType tempTree = InitTree(0);
    ReplaceNode(tempTree, toReplace, "a kitten", "Is it an adult?");
    PrintTree(tempTree);
    WriteTree(tree, "outputTree");
}
