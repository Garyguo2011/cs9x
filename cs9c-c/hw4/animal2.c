typedef int boolean;
#define FALSE 0
#define TRUE !FALSE

#define MAXSTRLEN 80
#define MAXNUMQS 32

struct treeStruct {
	char *string;
	struct treeStruct *left;
	struct treeStruct *right;
};

struct positionStruct {
	struct treeStruct* node;
};

#include "animal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void unitTest();
TreeType createTreeNode(char *str);
void WriteTreeHelper(FILE* fp, TreeType tree);

int main(int argc, char const *argv[]) {
	unitTest();
	return 0;
}

TreeType createTreeNode (char *str) {
	TreeType tree = (TreeType) malloc(MAXNUMQS*sizeof(TreeType));
	tree->string = (char *) malloc(MAXSTRLEN*sizeof(char));
	strcpy(tree->string, str);
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}

TreeType InitTree (char *file) {
	TreeType top = createTreeNode("Is it furry?");
	top->left = createTreeNode("Is it domesticated?");
	top->right = createTreeNode("Is it smaller than a person?");
	(top->left)->left = createTreeNode("Does it meow?");
	(top->left)->right = createTreeNode("Does it have a tail?");
	(top->right)->left = createTreeNode("a lizard");
	(top->right)->right = createTreeNode("Does it have tusks?");
	((top->left)->left)->left = createTreeNode("a cat");
	((top->left)->left)->right = createTreeNode("a dog");
	((top->left)->right)->left = createTreeNode("a monkey");
	((top->left)->right)->right = createTreeNode("a bear");
	((top->right)->right)->left = createTreeNode("Does it have big ears?");
	((top->right)->right)->right = createTreeNode("an alligator");
	(((top->right)->right)->left)->left = createTreeNode("an elephant");
	(((top->right)->right)->left)->right = createTreeNode("a rhinoceros");
	return top;
}

void PrintTree (TreeType tree) {
	if (tree == NULL) {
		return;
	}
	printf("Node: %s\n", tree->string);
	if (tree->left != NULL) {
		PrintTree(tree->left);
	} 
	if(tree->right != NULL) {
		PrintTree(tree->right);
	}
}

PositionType Top (TreeType tree) {
	PositionType pos = (PositionType) malloc(sizeof(PositionType));
	pos->node = tree;
	return pos;
}

boolean IsLeaf (TreeType tree, PositionType pos) {
	return (((pos->node)->left) == NULL);
}

boolean Answer (char *question) {
	char answer[MAXSTRLEN];
	printf("%s\n", question);
	gets(answer);
	if (answer[0]) {
		return (answer[0] == 'y');
	} else {
		printf("No input detected.\n");
		return Answer(question);
	}
}

char *Question (TreeType tree, PositionType pos) {
	if (IsLeaf(tree, pos)) {
		return Guess(tree, pos);
	} else {
		return (pos->node)->string;
	}
}

char *Guess (TreeType tree, PositionType pos) {
	char *toReturn = (char*) malloc(MAXSTRLEN*sizeof(char));
	strcpy(toReturn, "Is it ");
	strcat(toReturn, (pos->node)->string);
	strcat(toReturn, "?");
	return toReturn;
}

PositionType YesNode (TreeType tree, PositionType pos) {
	PositionType toReturn = (PositionType) malloc(sizeof(PositionType));
	TreeType atPos = pos->node;
	toReturn->node = atPos->left;
	return toReturn;
}

PositionType NoNode (TreeType tree, PositionType pos) {
	PositionType toReturn = (PositionType) malloc(sizeof(PositionType));
	TreeType atPos = pos->node;
	toReturn->node = atPos->right;
	return toReturn;
}

void ReplaceNode (TreeType tree, PositionType pos, char *newA, char *newQ) {
	TreeType newRight = (TreeType) malloc(MAXNUMQS*sizeof(TreeType));
	newRight->string = newA;
	TreeType newLeft = (TreeType) malloc(MAXNUMQS*sizeof(TreeType));
	newLeft->string = pos->node->string;
	pos->node->string = newQ;
	pos->node->left = newLeft;
	pos->node->right = newRight;
}

void GetNewInfo (TreeType tree, PositionType pos, char **newA, char **newQ) {
	printf("I give up. What is it? ");
	char *answer = (char*) malloc(MAXSTRLEN*sizeof(char));
	char *question = (char*) malloc(MAXSTRLEN*sizeof(char));
	gets(answer);
	printf("Please provide a question whose answer is yes for %s and no for %s.\n", (pos->node)->string, answer);
	gets(question);
	*newA = answer;
	*newQ = question;
}

void WriteTree(TreeType tree, char *file) {
	FILE *fp;
	if ((fp = fopen(file, "w")) != NULL) {
		WriteTreeHelper(fp, tree);
		fclose(fp);
	}
}

void WriteTreeHelper(FILE* fp, TreeType tree){
	if (fp == NULL || tree == NULL){
		return;
	}
	fputs(tree->string, fp);
	fputs("\n", fp);
	WriteTreeHelper(fp, tree->left);
	WriteTreeHelper(fp, tree->right);
}

/* A suite of tests. */
void unitTest() {
	TreeType tree = InitTree(0);
	printf("%s\n", tree->string);
	PrintTree(tree);
	PositionType question = (PositionType) malloc(sizeof(PositionType));
	question = Top(tree);
	PositionType answer = (PositionType) malloc(sizeof(PositionType));
	answer->node = (tree->right)->left;
	printf("IsLeaf test 1: %s\n", IsLeaf(tree, question) ? "FAIL" : "PASS");
	printf("IsLeaf test 2: %s\n", IsLeaf(tree, answer) ? "PASS" : "FAIL");
	printf("Top test: %s\n", (((Top(tree))->node)->string ==  tree->string)? "PASS" : "FAIL");
	printf("Question test 1: %s\n", strcmp(Question(tree, question), "Is it furry?") == 0 ? "PASS" : "FAIL");
	printf("Question test 2: %s\n", strcmp(Question(tree, answer), "Is it a lizard?") == 0 ? "PASS" : "FAIL");
	printf("%s\n", Question(tree, answer));
	printf("Is it a lizard?\n");
	TreeType tempTree = InitTree(0);
	PositionType toReplace = (PositionType) malloc(sizeof(PositionType));
	toReplace->node = ((tempTree->left)->left)->left;
	ReplaceNode(tempTree, toReplace, "a kitten", "Is it an adult?");
	PrintTree(tempTree);
	printf("output to file\n");
	WriteTree(tempTree, "tree");
}
