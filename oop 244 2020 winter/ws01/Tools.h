#ifndef SDDS_TOOLS_H 
#define SDDS_TOOLS_H
namespace sdds {
    const int MAX_WORD_LEN = 21;
    const int MAX_NO_OF_WORDS = 500;
    using namespace std;
    struct Word {
        char letters[MAX_WORD_LEN];
        int count;
    };

    void toLowerCaseAndAlphabeticCopy(char des[], const char source[]);
    
    int searchWords(const Word words[], int num, const char word[]);

    void addWord(Word words[], int* index, const char newWord[]);
    
    void title();

    void endList();

    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);

    void print(const Word* w, bool gotoNextLine);

    void report(const Word words[], int noOfWords, int longestWord);

    void swap(Word* p1, Word* p2);

    void sort(Word words[], int cnt);
}
#endif

