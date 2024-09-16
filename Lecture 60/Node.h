#include<bits/stdc++.h>
using namespace std;


class node {
public:
	string key;
	int value;


	node* next;

	node(string k, int v) {
		key = k;
		value = v;
		next = NULL;
	}
};
