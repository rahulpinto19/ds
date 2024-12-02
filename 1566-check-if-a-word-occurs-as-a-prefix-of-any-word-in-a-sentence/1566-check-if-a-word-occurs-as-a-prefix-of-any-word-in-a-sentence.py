class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(" ")
        # Iterate through the words and their one-based index
        for index, word in enumerate(words, start=1):
            # Check if the current word starts with searchWord
            if word.startswith(searchWord):
                return index
        # If no word is found, return -1
        return -1
        
        