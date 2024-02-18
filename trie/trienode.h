#pragma once

#include <cstdint>

struct TrieNode
{	
	static constexpr const uint32_t AlphabetSize = static_cast<uint32_t>(26);
	struct TrieNode* children[AlphabetSize];
	
	bool mEndOfWord;
	uint32_t count;
};