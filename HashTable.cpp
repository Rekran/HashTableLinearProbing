#include "HashTable.h"


HashTable::HashTable(){
	for(int i = 0; i< MAX ; i++)
		this->table[i] = NULL;
}	

HashTable::~HashTable(){
	for(int i = 0; i< MAX ; i++)
		delete(this->table[i]);	
}

bool HashTable::search(char *word){
	int i = 0;
	int hash = this->hash(word);

	if( this->table[hash + i] == NULL){
		return false;
	}else{
		while(this->table[hash + i] != NULL){

			if(strcmp(this->table[hash + i]->word,word) == 0)
				return true;
			else{
				i++;
				if( hash +i > MAX){
					i = 0;
					hash = 0;
				}
			}
		}
		return false;
	}
}

void HashTable::loadDictionary(char *path){
  string line;
  
  ifstream myfile(path);
  if (myfile.is_open()){

    while ( myfile>>line )
    {
    	int n = line.length();
		char *char_array = new char[n];	
		strcpy(char_array,&line[0]);
    	this->guarda(char_array);
    }
    myfile.close();
  }
	
}


unsigned int HashTable::hash(char *word){
	int size = strlen(word);
	int i;
	unsigned int value = 5381;
	
	for(i = 0;i< size;i++ ){
	
	value += (value << 5)  + word[i];
	
	}
	return value%MAX;
}



void HashTable::guarda(char *word){
	int i = 0;
	int hash = this->hash(word);
	Node *N1 = new Node();
	N1->word = word;

	if( this->table[hash + i] == NULL){
		this->table[hash + i] = N1;
	}else{
		while(this->table[hash + i] != NULL){
			i++;
			if((hash + i) > MAX){
				hash = 0;
				i = 0;
			}
		}
		this->table[hash + i] = N1;
	}
}

void HashTable::print(){
	for(int i = 0;i < MAX ;i++)
		cout<<this->table[i]<<endl;
}
