#include "AutoCompleteImpl.h"

struct TrieNode *createTrieNode() {
    //TODO implement logic for creating an Trie node
    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    int i=0;
    for(i=0;i<26;i++){
    	node->children[i]=NULL;
    }
    node->label=NULL;
    node->isEndOfWord = false;
    return node;
}

void insert(struct TrieNode *root, const char *word) {
    //TODO implement logic for inserting a word to the tree
    int size = strlen(word);
    TrieNode *temp=root;

    int i=0,pos;
    for(i=0;i<size-1;i++){
        pos = CHAR_TO_INDEX(word[i]);
        if(temp->children[pos]==NULL){
            temp->children[pos] = createTrieNode();
            temp= temp->children[pos];
            temp->label=(char*)malloc(sizeof(char)+2);
            temp->label[0] = word[i];
            temp->label[2]='\0';
        }
        else{
          temp= temp->children[pos];
        }

    }
    temp->isEndOfWord=true;
}

char *copycat(char *first, char *second) {
    char *result = malloc(strlen(first)+strlen(second)+1);
    strcpy(result, first);
    strcpy(result+strlen(first), second);
    return result;
}

void compress(struct TrieNode *root){

    int i=0,count=0,index;
    bool connections=false;
    struct TrieNode *temp;

    for(i=0;i<26;i++){

        if(root->children!=NULL){
            count++;
            index=i;
        }


    }
    if(count==1&& root->label!=NULL){
        temp=root->children[index];
        root->label=copycat(root->label,temp->label);
    int x=0;
        for(x=0;x<26;x++){
                if(root->children[x]!=NULL){
           root->children[x]=NULL;
           free(root->children[i]);
                }
        }
        for(x=0;x<26;x++){
            if(temp->children[x]!=NULL){
                if(root->children[x]==NULL){
                    root->children[x]=createTrieNode();
                }
                    if(temp->isEndOfWord==true){
                        root->isEndOfWord=true;
                    }
                root->children[x]=temp->children[i];

            }
        }
        if(temp->isEndOfWord==true){
         root->isEndOfWord=true;
        }
        free(temp);
        connections=true;
    }

   int cnt=0;

   for (i = 0; i <26; ++i){
    if(root->children[i]!=NULL){
      cnt++;
     }
  }

  if(cnt==0)
    return;

    int y=0;

    for(y=0;y<26;y++){

    if(root->children[y]!=NULL){
      if(connections==true){
         compress(root);
      }
      else{
      compress(root->children[y]);}
    }
    }
}


struct TrieNode *search(struct TrieNode *root, const char *word) {
    //TODO implement search logic for Tries tree.
    //TODO This function should return last node of the node sequence where we found given word
    struct TrieNode *temp=root;
    int i=0,pos=0;
    int size=strlen(word);

    while(pos<size){
        if(temp->children[i]!=NULL){
            int len=strlen(temp->children[i]->label);
            if(word[pos]==temp->children[i]->label[0]){
                temp=temp->children[i];
                i=0;
                pos+=len;
            }
        }
       i++;
    }
    return temp;
}

void traverse(char prefix[], struct TrieNode *root) {
    //TODO implement tree traversal logic here. Use this to traverse underneath tree
    //TODO TIP: use this function to print words once you find the node in search function
    int i=0;
    //TrieNode *temp = root;
    //TrieNode *end = search(root,prefix);
    //int len = strlen(prefix);

    if(root->isEndOfWord==true){
        printf("%s\n",prefix);
    }
    while(i<26){
    	//int x;
        if(root->children[i]!=NULL){

        	traverse(copycat(prefix,root->children[i]->label),root->children[i]);
        }

    i++;
    }




}
