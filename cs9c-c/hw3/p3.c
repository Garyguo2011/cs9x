typedef int boolean;
#define FALSE 0
#define TRUE !FALSE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTRLEN 80
#define MAXNUMQS 32

typedef char **TreeType;
typedef int PositionType;

/*
 * Function prototypes.
 */
TreeType InitTree ();
void PrintTree (TreeType tree);
PositionType Top (TreeType tree);
boolean IsLeaf (TreeType tree, PositionType pos);
boolean Answer (char *question);
char *Question (TreeType tree, PositionType pos);
char *Guess (TreeType tree, PositionType pos);
PositionType YesNode (TreeType tree, PositionType pos);
PositionType NoNode (TreeType tree, PositionType pos);
void ReplaceNode (TreeType tree, PositionType pos, char *newA, char *newQ);
void GetNewInfo (TreeType tree, PositionType pos, char **newA, char **newQ);
void unitTest();

/*
 *  Play the "animal" game, in which the program attempts to guess an animal
 *  that the user is thinking of by asking yes or no questions. Eventually,
 *  the program either will guess the user's animal or run out of questions
 *  to ask. In the latter case, the program will ask the user to provide a
 *  yes-or-no question that would distinguish between the user's animal and
 *  the program's best guess.
 *  The data structure of questions and guesses is essentially a binary tree,
 *  with each internal node having a "yes" branch and a "no" branch. Leaves
 *  of the tree represent animals to be guessed by the program. If the program
 *  fails to guess the user's animal, it replaces one of the leaves of the tree
 *  by a node containing the new question, whose children are the program's
 *  best guess and the animal provided by the user.
 *  The structure of the program is simple. It initializes the question/guess
 *  data structure, then plays games as long as the user is interested. In each
 *  game, the program starts at the top of the tree (the root) and progresses
 *  toward the bottom (the leaves) depending on the user's responses. Once it
 *  reaches a leaf, it either has won or lost, and handles the situation as
 *  described above.
 */
int main () {
    TreeType tree;
    PositionType pos;
    char *newQuestion, *newAnswer;
    tree = InitTree ();

    // unitTest();
    printf("%s", "Think of an animal. I will try to guess what it is.\n"
         "Please answer my questions with yes or no.\n");

    while (TRUE) {
        pos = Top (tree);
        while (!IsLeaf (tree, pos)) {
            pos = Answer (Question (tree, pos))?
            YesNode (tree, pos): NoNode (tree, pos);
        }
        if (Answer (Guess (tree, pos))) {
            printf ("I got it right!\n");
        } else {
            GetNewInfo (tree, pos, &newAnswer, &newQuestion);
            ReplaceNode (tree, pos, newAnswer, newQuestion);
        }
        if (!Answer ("Want to play again? ")) {
            exit (0);
        }
    }
    return 0;
}

/*
 *  Return an animal tree.
 */
TreeType InitTree () {
    TreeType tree = calloc(MAXNUMQS, MAXSTRLEN);
    if (tree == NULL){
        fprintf(stderr, "Not Enough Momery\n");
        free(tree);
    }
    tree[0] = "Is it furry?";
    tree[1] = "Does it meow?";
    tree[2] = "Does it have tusks?";
    tree[3] = "a cat";
    tree[4] = "a dog";
    tree[5] = "Does it have big ears";
    tree[6] = "an alligator";
    tree[11] = "an elephant";
    tree[12] = "a rhinoceros";
    return tree;
}

/*
 *  Print an animal tree (useful for debugging).
 */
void PrintTree (TreeType tree) {
    int i;
    for (i=0; i < MAXNUMQS; i++) {
        if(tree[i] != NULL){
            printf("%d N%d: %s\n",IsLeaf(tree, i), i, tree[i]);
        }
    }
}

/*
 *  Return the position of the "top" node in the animal tree.
 */
PositionType Top (TreeType tree) {
    return 0;
}

/*
 *  Return true exactly when pos is a "leaf" of the animal tree,
 *  that is, when the string stored at pos is a guess rather than
 *  a question.
 */
boolean IsLeaf (TreeType tree, PositionType pos) {
    /* Your code goes here -- delete this line */
    char buf[MAXSTRLEN];
    strcpy(buf, tree[pos]);
    return buf[strlen(tree[pos]) - 1] != '?';
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
        return tree[pos];
    }
}

/*
 *  Form a guess out of the string stored at position pos in the given
 *  animal tree.  (IsLeaf(tree, pos) must be true.)
 */
char *Guess (TreeType tree, PositionType pos) {
    char* guessStr = (char*) malloc(MAXSTRLEN*sizeof(char));
    strcpy(guessStr, "Is it ");
    strcat(guessStr, tree[pos]);
    strcat(guessStr, "?");
    return guessStr;
}

/*
 *  Return the position of the node that corresponds to a "yes" answer
 *  to the question stored at position pos in the animal tree.
 */
PositionType YesNode (TreeType tree, PositionType pos) {
    return 2 * pos + 1;
}

/*
 *  Return the position of the node that corresponds to a "no" answer
 *  to the question stored at position pos in the animal tree.
 */
PositionType NoNode (TreeType tree, PositionType pos) {
    return 2 * pos + 2;
}

/*
 *  Replace the node at position pos in the given animal tree by a node
 *  containing the given new question whose left child (down the tree in 
 *  the "yes" direction) contains the string stored at position pos, and 
 *  whose right child contains the new answer newA.
 */
void ReplaceNode (TreeType tree, PositionType pos, char *newA, char *newQ) {
    tree[NoNode(tree, pos)] = newA;
    tree[YesNode(tree,pos)] = tree[pos];
    tree[pos] = newQ;
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
    printf("Please provide a question whose answer is yes for %s and no for %s\n", tree[pos], answer);
    gets(question);
    *newA = answer;
    *newQ = question;
}

void unitTest() {
    TreeType tree = InitTree();
    printf("After initlizing tree:\n");
    PrintTree(tree);
    PositionType question = 0;
    PositionType answer = 5;
    printf("IsLeaf test 1: %s\n", IsLeaf(tree, question) ? "error" : "pass");
    printf("IsLeaf test 2: %s\n", IsLeaf(tree, answer) ? "pass" : "error");
    printf("Top test: %s\n", Top(tree) == 0 ? "pass" : "error");
    printf("Question test 1: %s\n", strcmp(Question(tree, question), "Is it furry?") == 0 ? "pass" : "error");
    printf("Question test 2: %s\n", strcmp(Question(tree, answer), "Is it a lizard?") == 0 ? "pass" : "error");
    printf("%s\n", Question(tree, answer));
    ReplaceNode(tree, 7, "a kitten", "Is it an adult?");
    PrintTree(tree);
}
