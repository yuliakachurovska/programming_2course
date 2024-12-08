#include <iostream>
#include <fstream>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

set<string> readWordsFromFile(const string& filename) {
    ifstream file(filename);
    set<string> words;
    string word;

    while (file >> word) {
        words.insert(word);
    }

    return words;
}

int main() {
    string file1 = "file1.txt";
    string file2 = "file2.txt";

    set<string> words1 = readWordsFromFile(file1);
    set<string> words2 = readWordsFromFile(file2);

    // Знаходимо спільні слова
    set<string> commonWords;
    set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(),
                      inserter(commonWords, commonWords.begin()));

    cout << "Common words:" << endl;
    for (const string& word : commonWords) {
        cout << word << endl;
    }

    // Знаходимо слова, які не є спільними
    set<string> diffWords;
    set_symmetric_difference(words1.begin(), words1.end(), words2.begin(), words2.end(),
                             inserter(diffWords, diffWords.begin()));

    cout << "\nWords not common:" << endl;
    for (const string& word : diffWords) {
        cout << word << endl;
    }
}
