#include <iostream>
#include <string>
#include "trie.h"

std::string test1[] = {"cat", "call", "rut", "run", "cult"};
std::string test2[] = {"zebra", "dog", "duck", "dove", "dot"};
std::string test3[] = {"the", "a", "answer", "hero", "heroplane"};
std::string test4[] = {"abcd",
                       "acbd",
                       "afgr",
					   "ahij",
					   "aklm",
					   "anop",
					   "aqrs",
					   "atuv",
					   "awxy",
					   "azad",
					   "abfh",
					   "abrs"};

int main(int argc, char* argv[])
{
   TrieNode* rootFirst = new TrieNode;
   TrieNode* rootSecond = new TrieNode;
   TrieNode* rootThird = new TrieNode;
   TrieNode* rootFourth = new TrieNode;
   
   for(uint32_t i = static_cast<uint32_t> (0); i < TrieNode::AlphabetSize; ++i)
   {
	   rootFirst->children[i] = nullptr;
   }
   rootFirst->count = 0;
   rootFirst->mEndOfWord = false;
   
   for(uint32_t i = static_cast<uint32_t> (0); i < TrieNode::AlphabetSize; ++i)
   {
	   rootSecond->children[i] = nullptr;
   }
   rootSecond->count = 0;
   rootSecond->mEndOfWord = false;
   
   for(uint32_t i = static_cast<uint32_t> (0); i < TrieNode::AlphabetSize; ++i)
   {
	   rootThird->children[i] = nullptr;
   }
   rootThird->count = 0;
   rootThird->mEndOfWord = false;
   
   for(uint32_t i = static_cast<uint32_t> (0); i < TrieNode::AlphabetSize; ++i)
   {
	   rootFourth->children[i] = nullptr;
   }
   rootFourth->count = 0;
   rootFourth->mEndOfWord = false;
   
   Trie oTrieFirst;
   Trie oTrieSecond;
   Trie oTrieThird;
   Trie oTrieFourth;
   
   char buf[100] = {};
   int ind = 0;
   std::string res = "";
   
   if(0)
   {
	   for(uint32_t i = {0}; i < 5; ++i)
	   {
		  oTrieFirst.Insert(rootFirst, test1[i]);
	   }
	   
	   for(uint32_t i = {0}; i < 5; ++i)
	   {
		   std::cout << "Is " << test1[i] << " present? " << (oTrieFirst.Search(rootFirst, test1[i]) ? "yes": "no") << std::endl;
	   }
	   
	   std::cout << "Is " << "lem" << " present? " << (oTrieFirst.Search(rootFirst, "lem") ? "yes": "no") << std::endl;
	   
	   oTrieFirst.FindMinPrefixes(rootFirst, buf, ind, res);
	   }
      
   if(0)
   {
	   std::cout << res << std::endl;
	   ind = 0;
	   res = "";
   
	   for(uint32_t i = {0}; i < 5; ++i)
	   {
		  oTrieSecond.Insert(rootSecond, test2[i]);
	   }
	   
	   for(uint32_t i = {0}; i < 5; ++i)
	   {
		   std::cout << "Is " << test2[i] << " present? " << (oTrieSecond.Search(rootSecond, test2[i]) ? "yes": "no") << std::endl;
	   }
	   
	   std::cout << "Is " << "lem" << " present? " << (oTrieSecond.Search(rootSecond, "lem") ? "yes": "no") << std::endl;
	   
	   oTrieSecond.FindMinPrefixes(rootSecond, buf, ind, res);
   }
   
   if(0)
   {
   
	   std::cout << res << std::endl;
	   ind = 0;
	   res = "";
   

	   for(uint32_t i = {0}; i < 5; ++i)
	   {
		  oTrieThird.Insert(rootThird, test3[i]);
	   }
	   
	   for(uint32_t i = {0}; i < 5; ++i)
	   {
		   std::cout << "Is " << test3[i] << " present? " << (oTrieThird.Search(rootThird, test3[i]) ? "yes": "no") << std::endl;
	   }
	   
	   std::cout << "Is " << "lem" << " present? " << (oTrieThird.Search(rootThird, "lem") ? "yes": "no") << std::endl;
	   
	   oTrieThird.Remove(rootThird, "the", 0);
	   
	   for(uint32_t i = {0}; i < 5; ++i)
	   {
		   std::cout << "Is " << test3[i] << " present? " << (oTrieThird.Search(rootThird, test3[i]) ? "yes": "no") << std::endl;
	   }
	   
	   oTrieThird.Insert(rootThird, "the");
	   
	   for(uint32_t i = {0}; i < 5; ++i)
	   {
		   std::cout << "Is " << test3[i] << " present? " << (oTrieThird.Search(rootThird, test3[i]) ? "yes": "no") << std::endl;
	   }
	   
	   oTrieThird.FindMinPrefixes(rootThird, buf, ind, res);
	   
	   std::cout << res << std::endl;
   }
   
   if(1)
   {
	   std::cout << res << std::endl;
	   ind = 0;
	   res = "";
	   
	   for(uint32_t i = {0}; i < sizeof(test4)/sizeof(std::string); ++i)
	   {
		  oTrieFourth.Insert(rootFourth, test4[i]);
	   }
	   
	   for(uint32_t i = {0}; i < sizeof(test4)/sizeof(std::string); ++i)
	   {
		   std::cout << "Is " << test4[i] << " present? " << (oTrieFourth.Search(rootFourth, test4[i]) ? "yes": "no") << std::endl;
	   }
	   
	   /*std::cout << "Is " << "lem" << " present? " << (oTrieFourth.Search(rootFourth, "lem") ? "yes": "no") << std::endl;
	   
	   oTrieFourth.Remove(rootFourth, "ab", 0);
	   
	   for(uint32_t i = {0}; i < sizeof(test4)/sizeof(std::string); ++i)
	   {
		   std::cout << "Is " << test4[i] << " present? " << (oTrieFourth.Search(rootFourth, test4[i]) ? "yes": "no") << std::endl;
	   }
	   
	   oTrieFourth.Insert(rootFourth, "ab");
	   
	   for(uint32_t i = {0}; i < sizeof(test4)/sizeof(std::string); ++i)
	   {
		   std::cout << "Is " << test4[i] << " present? " << (oTrieFourth.Search(rootFourth, test4[i]) ? "yes": "no") << std::endl;
	   }
	      
	   oTrieFourth.FindMinPrefixes(rootFourth, buf, ind, res);
	   
	   std::cout << res << std::endl;*/
	   
	   oTrieFourth.GetAllChild(rootFourth, "a");
   }
   
   delete rootFirst;
   delete rootSecond;
   delete rootThird;
   delete rootFourth;
   
   return 0;	
}