#pragma once
#include "Node.h"

template <typename type>
class Trie {
	Node<type>* root;

public:
	Trie() {
	    root = new Node<type>();
	}
	~Trie() {
        delete root;
    }

	void insert(const std::string& word) {
		Node<type>* temp = root;
		for (auto it : word) {
			bool found = false;
			for (auto& [letter, node] : temp->children) {
			    if (letter == it) {
			        temp = node;
			        found = true;
			        break;
			    }
			}

			if (!found) {
                Node<type> *newNode = new Node<char>();
                temp->children.insert(std::pair<char, Node<char> *>{it, newNode});
                temp = newNode;
            }
		}
		temp->is_word = true;
	}

	void find_word(const std::string& word) {
		Node<type>* temp = root;
		for (auto it : word) {
            for (auto itr = temp->children.begin(); itr != temp->children.end(); itr++) {
                if (itr->first == it) { temp = itr->second; break; }
            }
		}
		if (temp->is_word) { std::cout << word << " Word Found" << std::endl; }
	}

	bool find_prefix(const std::string& word) {
	    Node<type>* temp = root;
	    for (auto it : word) {
	        for (auto itr = temp->children.begin(); itr != temp->children.end(); itr++) {
	            if (itr->first == it) { temp = itr->second; break; }
	            return false;
	        }
	    }
	    return true;
	}

	void delete_word(const std::string& word, Node<type>* temp, int& index) {

        for (auto itr = temp->children.begin(); itr != temp->children.end(); itr++) {
            if (itr->first == word[index]) {
                index++;
                if (index == word.length()) {
                    if (!(itr->second->children.empty())) {
                        temp->is_word = false;
                    }
                    else {
                        temp->children.erase(itr);
                        return;
                    }
                }
                delete_word(word, itr->second, index);
                if (itr->second->children.empty()) {
                    temp->children.erase(itr);
                    return;
                }
                else {
                  temp->is_word = false;
                }
            }
        }

	}

	void delete_word(const std::string& word) {
        Node<type>* temp = root;
        int index = 0;
        for (auto itr = temp->children.begin(); itr != temp->children.end(); itr++) {
            if (itr->first == word[index]) {
                index++;
                delete_word(word, itr->second, index);
                if (itr->second->children.empty()) {
                    temp->children.erase(itr);
                    return;
                }
                else {
                    temp->is_word = false;
                }
            }
        }
	}

	void print(Node<type>* temp, int& i) {
	    for (auto& [letter, node] : temp->children) {
            std::cout << letter << ' ';
            i++;
            print(node, i);
            if (node->is_word) {
                std::cout << std::endl;
                for (int j = 0; j < i-1; j++) {
                    std::cout << "  ";
                }
            }
        }
        i--;
    }

	void print() {
		Node<type>* temp = root;
		int i = 0;
        for (auto& [letter, node] : temp->children) {
            std::cout << letter << ' ';
            i++;
            print(node, i);
            std::cout << std::endl;
            i = 0;
        }
	}
};

