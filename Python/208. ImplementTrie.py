# we are creating Trie Data Structure and implementing various methods of the Data Structure
class TrieNode:        
    def __init__(self, val):
        self.val = val
        self.isEnd = False
        self.children = [None for i in range(26)]
class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode('*')


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self.root
        for c in word:
            x = ord(c) - ord('a')
            if node.children[x] is None:
                node.children[x] = TrieNode(c)
            node = node.children[x]
        node.isEnd = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self.root
        for c in word:
            x = ord(c) - ord('a')
            if node.children[x] is not None:
                node = node.children[x]
            else:
                return False
        return node.isEnd


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node = self.root
        for c in prefix:
            x = ord(c) - ord('a')
            if node.children[x] is not None:
                node = node.children[x]
            else:
                return False
        return True
