#pragma once
#include <string>

#include "trienode.h"

class Trie
{
	private:
	   bool isEmpty(TrieNode* root);  
       void getAllChildInner(TrieNode* root, char buf[], std::uint32_t& ind, std::string& outgoingString);	   
	   
	public:
       	Trie();
	    TrieNode *GetNewNode();	
	    void Insert(TrieNode* root, const std::string& key);
		void InsertMarked(TrieNode* root, const std::string& key);
	    bool Search(struct TrieNode *root, const std::string& key);
		TrieNode* Remove(TrieNode* root, const std::string& key, std::uint32_t depth);
	    void FindMinPrefixes(TrieNode* root, char buf[], std::uint32_t ind, std::string& result);
		void GetAllChild(TrieNode* root, const std::string& prefix, std::string& outgoingString);
};