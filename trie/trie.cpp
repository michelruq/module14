#include <cstdint>
#include <iostream>

#include "Trie.h"

Trie::Trie()
{
	
}

TrieNode* Trie::GetNewNode()
{
   struct TrieNode * newNode = new TrieNode;
   
   newNode->mEndOfWord = false;
   newNode->count = 0;
   
   for(uint32_t i = static_cast<uint32_t> (0); i < TrieNode::AlphabetSize; ++i)
   {
	   newNode->children[i] = nullptr;
   }
   
   return newNode;
}

void Trie::Insert(TrieNode* root, const std::string& key) 
{
    struct TrieNode *pCrawl = root;
   
    for (uint32_t i = static_cast<uint32_t>(0); i < key.length(); ++i)
	{
		uint32_t index = key[i] - 'a';
		if (!pCrawl->children[index])
		{
			pCrawl->children[index] = GetNewNode();
		}

        pCrawl->children[index]->count++;
		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->mEndOfWord = true;
}	

bool Trie::Search(struct TrieNode *root, const std::string& key)
{
	struct TrieNode *node = root;
   
    for (uint32_t i = static_cast<uint32_t>(0); i < key.length(); ++i)
	{
		uint32_t index = key[i] - 'a';
		if (!node->children[index])
		{
			return false;
		}

		node = node->children[index];
	}

	return ((node != nullptr) && (node->mEndOfWord));
}

bool Trie::isEmpty(TrieNode* root)
{
   for(uint32_t i = static_cast<uint32_t> (0); i < TrieNode::AlphabetSize; ++i)
   {
       if (root->children[i])
	   {
           return false;
	   }
   }
   return true;
}

TrieNode* Trie::Remove(TrieNode* root, const std::string& key, std::uint32_t depth)
{
	if(!root)
	{
		return nullptr;
	}
	
	if (depth == key.size()) 
	{
		if (root->mEndOfWord)
		{
           root->mEndOfWord = false;
		}
		
		if (isEmpty(root)) 
		{
           delete (root);
           root = nullptr;
       }
	   
	   return root;
	}
	
	std::uint32_t index = key[depth] - 'a';
    root->children[index] = Remove(root->children[index], key, depth + 1);
	
	if (isEmpty(root) && root->mEndOfWord == false) 
	{
       delete (root);
       root = nullptr;
    }
	
	return root;
}

void Trie::FindMinPrefixes(TrieNode* root, char buf[], std::uint32_t ind, std::string& result)
{
	if(!root)
	{
		return;
	}
	
	if (root->count == 1)
    {
        result += buf;
        result += ' ';
        std::cout << result << '\n';
        return;
    }
	
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < TrieNode::AlphabetSize; ++i)
    {
        if(root->children[i] != nullptr)
        {
            buf[ind] = i + 'a';
            buf[ind+1] = '\0' ;     //!!! out of bounds
            FindMinPrefixes(root->children[i], buf, ind+1, result);
        }
    }
}

void Trie::GetAllChild(TrieNode* root, const std::string& prefix, std::string& outgoingString)
{
	if(!root)
	{
		return;
	}
	
	bool result = true;
	
	for (uint32_t i = static_cast<uint32_t>(0); i < prefix.length(); ++i)
	{
		uint32_t index = prefix[i] - 'a';
		if (!root->children[index])
		{
			result = false;
			break;
		}

		root = root->children[index];
	}
	
    char buf[100] = {};
	std::uint32_t ind = 0;
	if(result)
	{
		getAllChildInner(root, buf, ind, outgoingString);
	}

}

void Trie::getAllChildInner(TrieNode* root, char buf[], std::uint32_t& ind, std::string& outgoingString)
{
	if(!root)
	{
		return;
	}
	
	if(root->mEndOfWord)
	{
		outgoingString += buf;
		outgoingString += '\n';
	}
	
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < TrieNode::AlphabetSize; ++i)
    {
        if(root->children[i] != nullptr)
        {
            buf[ind] += i + 'a';
			++ind;
            getAllChildInner(root->children[i], buf, ind, outgoingString);
			--ind;
			buf[ind] = '\0';
        }
    }
}
