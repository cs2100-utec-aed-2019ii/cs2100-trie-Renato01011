#include <iostream>
#include "Trie.h"

int main() {

    Trie<char> t;
    t.insert("Renato");
    t.insert("Renzo");
    t.insert("Gabriel");
    t.insert("Lorenzo");
    t.insert("Lorenza");
    t.find_word("Renato");
    t.find_word("Renzo");
    t.find_word("Gabriel");
    std::cout << t.find_prefix("Re") << std::endl;
    t.print();
    t.delete_word("Lorenzo");
    t.delete_word("Gabriel");
    std::cout << "After Delete" << std::endl;
    std::cout << "//////////////////////////////////////////////" << std::endl;
    t.print();

    /*
    for (int i = 0; i < 1000; i++) {
        std::cout << "\r" << i;
        fflush(stdout);
        usleep(10000);
    }
    */

    return 0;
}
