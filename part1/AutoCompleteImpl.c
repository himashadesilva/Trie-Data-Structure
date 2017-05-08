#include "AutoCompleteImpl.h"

struct TrieNode *createTrieNode() {
    //TODO implement logic for creating an Trie node
    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    int i=0;
    for(i=0;i<26;i++){
    	node->children[i]=NULL;
    }
    return node;
}

void insert(struct TrieNode *root, const char *word) {
    //TODO implement logic for inserting a word to the tree
    int size = strlen(word);
    TrieNode *temp=root;

    int i=0,index;
    for(i=0;i<size;i++){
        index = CHAR_TO_INDEX(word[i]);
        if(temp->children[index]==NULL){
            temp->children[index] = createTrieNode();
            temp= temp->children[index];
        }
        else{
          temp= temp->children[index];
        }

    }
    temp->isEndOfWord=true;
}

struct TrieNode *search(struct TrieNode *root, const char *word) {
    //TODO implement search logic for Tries tree.
    //TODO This function should return last node of the node sequence where we found given word
    TrieNode *temp=root;
    int size = strlen(word);
    int i=0,index;

    for(i=0;i<size;i++){
        index = CHAR_TO_INDEX(word[i]);
        temp = temp->children[index];
    }
    //temp->isEndOfWord=true;
    return temp;
}

void traverse(char prefix[], struct TrieNode *root) {
    //TODO implement tree traversal logic here. Use this to traverse underneath tree
    //TODO TIP: use this function to print words once you find the node in search function
    int i=0;
    //TrieNode *temp = root;
    //TrieNode *end = search(root,prefix);
    int len = strlen(prefix);

    if(root->isEndOfWord==true){
        printf("%s\n",prefix);
    }
    while(i<26){
    	int x=0;
        if(root->children[i]!=NULL){
        	char array[len+1];
        	for(x=0;x<len;x++){
        		array[x]=prefix[x];
        	}
        	array[len+1]=i+'a';
            traverse(array,root->children[i]);
        }


    }




}
