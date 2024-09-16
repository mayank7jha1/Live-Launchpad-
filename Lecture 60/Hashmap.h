#include<bits/stdc++.h>
#include"Node.h"
using namespace std;

class Hashmap {

	node** Hashtable;
	int ts;//Total Size of the Hashtable.
	int cs;//Current Size of the Hashtable.

	void Rehashing() {

		node** OldHashTable = Hashtable;

		Hashtable = new node*[2 * ts];
		ts = 2 * ts;
		cs = 0;

		for (int i = 0; i < ts; i++) {
			Hashtable[i] = NULL;
		}

		//Copy All the Data of the OldHashTable to the New HashTable.

		for (int i = 0; i < ts / 2; i++) {
			node*head = OldHashTable[i];
			while (head != NULL) {
				insert(head->key, head->value);
				head = head->next;
			}

		}
		delete[]OldHashTable;
	}

	int HashFunction(string key) {
		int multiplier = 1;
		int index = 0;
		for (int i = 0; i < key.size(); i++) {
			index += (key[i] % ts * multiplier % ts);
			multiplier *= 29;
			multiplier %= ts;
		}
		return index % ts; //This index should be within the Hashtable Index.
	}

public:

	//Constructor
	Hashmap(int size = 7) {
		Hashtable = new node*[size];
		cs = 0;
		ts = size;

		for (int i = 0; i < ts; i++) {
			Hashtable[i] = NULL;
		}
	}



	void insert(string key, int value) {
		int HashIndex = HashFunction(key);


		node* n = new node(key, value);
		cs++;

		//Insert at Head At Linked List.
		n->next = Hashtable[HashIndex];
		Hashtable[HashIndex] = n;

		if (((cs / ts) * 1.0) >= 0.7) {
			Rehashing();
		}
	}

	void Search(string k) {

		int HashIndex = HashFunction(k);
		node*head = Hashtable[HashIndex];

		while (head != NULL) {
			if (head->key == k) {
				cout << head->key << " " << head->value << endl;
				return;
			}
			head = head->next;
		}

		cout << "-1" << endl;
		return;
	}


	void Print() {

		for (int i = 0; i < ts; i++) {
			cout << i << "--->";
			node*head = Hashtable[i];

			while (head != NULL) {
				cout << head->key << " " << head->value << "--->";
				head = head->next;
			}
			cout << endl;
		}


	}


};




//Design Round: Atlassian