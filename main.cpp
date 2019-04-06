#include "HashTable.h"
#include<vector>
using namespace std;


int main(int argc, char** argv) {
vector<string>erros;
HashTable ht = HashTable();

ht.loadDictionary("dictionary.txt");

string word;
  ifstream myfile("text.txt");
  if (myfile.is_open())
  {
    while ( myfile>>word )
    {
    	if(!ht.search(&word[0]))
			erros.push_back(word);
    }
    myfile.close();
  }
for(int i = 0; i< erros.size();i++)
	cout<<erros[i]<<endl;

	return 0;
}
