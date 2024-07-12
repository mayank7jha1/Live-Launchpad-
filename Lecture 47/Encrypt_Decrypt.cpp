#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class Encrypter {
public:
    map<char, string>mp;
    vector<string>d;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {

        for (int i = 0; i < keys.size(); i++) {
            mp[keys[i]] = values[i];
        }

        d = dictionary;
    }

    string encrypt(string word1) {
        string ans = "";
        for (int i = 0; i < word1.size(); i++) {

            if (mp.find(word1[i]) == mp.end()) {
                return "";
            }

            // if (mp.count(word1[i]) == 0) {
            //     return "";
            // }

            ans += mp[word1[i]];
        }
        return ans;
    }




    int decrypt(string word2) {

        int count = 0;
        for (int i = 0; i < d.size(); i++) {
            string st = encrypt(d[i]);

            if (st == word2) {
                count++;
            }
        }

        return count;
    }

};


int main() {

}


/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */