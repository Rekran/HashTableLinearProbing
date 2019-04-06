#include <math.h>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include"Node.h"

using namespace std;
#define MAX 3187


class HashTable{
	private:
		Node *table[MAX];
	public:
		
		unsigned int hash(char *word);
		void loadDictionary(char *path);
		
		void guarda(char *word);
		
		bool search(char *word);
		void print();

		HashTable();
		~HashTable();
};
