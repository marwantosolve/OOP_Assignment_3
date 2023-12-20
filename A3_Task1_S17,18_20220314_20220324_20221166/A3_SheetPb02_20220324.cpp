// File name: A3_SheetPb02_20220324.cpp
// Purpose: A class called "StringSet" which is a document similarity measure.
// Author: Marwan Osama
// ID: 20220324
// Section: S17,18
// Date: 5/12/2023

#include <bits/stdc++.h>
using namespace std;

// Define a class named StringSet
class StringSet
{
private:
    // Private member variable to store a set of strings
    vector<string> set;

    // Private static method to break a string into words
    static vector<string> toWords(string str);

    // Private method to break a string into words and store them in a vector
    void toWords(string str, vector<string> &v);

public:
    // Constructor that takes a string and initializes the set with its tokens
    StringSet(const string &str);

    // Constructor that takes a file name and a boolean flag indicating whether it's a file name
    StringSet(const string &fileName, bool isFile);

    // Public method to add a string to the set
    void add(const string &str);

    // Public method to remove a string from the set
    void remove(string str);

    // Public method to clear the set, removing all elements
    void clear();

    // Public method to print the elements of the set
    void print();

    // Public method to get the size of the set
    size_t size();

    // Public method to check if the set is similar to another StringSet
    bool similar_to(const StringSet &other);

    // Overloaded + operator to perform the union of two StringSets
    StringSet operator+(const StringSet &other);

    // Overloaded * operator to perform the intersection of two StringSets
    StringSet operator*(const StringSet &other);
};

////////////////////////////////////////* The Implementation of the class */////////////////////////////////////////////

// Constructor that initializes the set with words from a given string
StringSet::StringSet(const string &str)
{
    toWords(str, set);
}

// Constructor that reads a file and initializes the set with its content
StringSet::StringSet(const string &fileName, bool isFile)
{
    if (isFile)
    {
        ifstream myFile(fileName); // Using constructor to open the file

        // Check if the file is successfully opened
        if (!myFile.is_open())
        {
            cerr << "Error: Could not open \"" << fileName << "\" !\n";
            cout << "Please, Make sure that \"" << fileName << "\" exists and re-run the program.";
            exit(0);
        }

        // Read each line from the file and add it to the set
        string line;
        while (getline(myFile, line))
        {
            this->add(line);
        }
    }
    // the file will automatically close when myFile goes out of scope
}

// Private method to break a string into words and store them in a vector
void StringSet::toWords(string str, vector<string> &v)
{
    // Convert all characters to lowercase
    for (auto &c : str)
    {
        c = tolower(c);
    }

    // Use regex to extract words from the string
    regex words_regex("([\\w]+)");
    smatch match;

    // Iterate through matches and store them in the vector
    while (regex_search(str, match, words_regex))
    {
        v.push_back(match[0]);
        str = match.suffix();
    }

    // Sort the vector
    sort(v.begin(), v.end());
}

// Static method to break a string into words and return them in a vector
vector<string> StringSet::toWords(string str)
{
    vector<string> res;

    // Convert all characters to lowercase
    for (auto &c : str)
    {
        c = tolower(c);
    }

    // Use regex to extract words from the string
    regex words_regex("([\\w]+)");
    smatch match;

    // Iterate through matches and store them in the vector
    while (regex_search(str, match, words_regex))
    {
        res.push_back(match[0]);
        str = match.suffix();
    }

    // Sort the vector
    sort(res.begin(), res.end());

    return res;
}

// Public method to add a string to the set
void StringSet::add(const string &str)
{
    // Break the string into tokens, add them to the set, and remove duplicates
    vector<string> tmp = toWords(str);
    set.insert(set.end(), tmp.begin(), tmp.end());
    sort(set.begin(), set.end());
    set.erase(unique(set.begin(), set.end()), set.end());
}

// Public method to remove a string from the set
void StringSet::remove(string str)
{
    // Remove the specified string from the set
    set.erase(remove_if(set.begin(), set.end(), [&](const auto &item)
              { return item == str; }),
              set.end());
}

// Public method to clear the set
void StringSet::clear()
{
    // Clear the set
    set.clear();
}

// Public method to print the elements of the set
void StringSet::print()
{
    // Print the elements of the set
    if (set.empty())
    {
        cout << "Set is empty !\n";
        return;
    }

    cout << '{';
    for (int i = 0; i < set.size(); i++)
    {
        if (i == set.size() - 1)
        {
            cout << '\"' << set[i] << '\"';
        }
        else
        {
            cout << '\"' << set[i] << '\"' << ", ";
        }
    }
    cout << "}\n";
}

// Public method to get the size of the set
size_t StringSet::size()
{
    // Return the size of the set
    return set.size();
}

// Public method to check if the set is similar to another StringSet
bool StringSet::similar_to(const StringSet &other)
{
    // Calculate similarity based on the Jaccard similarity coefficient
    size_t sim = 0;
    size_t sz_of_common = ((*this) * other).size();
    size_t sz1 = other.set.size();
    size_t sz2 = set.size();

    sim = (sz_of_common) / (size_t)(sqrt(sz1) * sqrt(sz2));

    // Print whether the sets are similar or not
    cout << (sim ? "They're Similar !\n" : "They are not Similar !\n");

    return sim;
}

// Overloaded + operator to perform the union of two StringSets
StringSet StringSet::operator+(const StringSet &other)
{
    // Create a new StringSet as the result of the union
    StringSet result("");
    set_union(set.begin(), set.end(), other.set.begin(), other.set.end(), back_inserter(result.set));
    return result;
}

// Overloaded * operator to perform the intersection of two StringSets
StringSet StringSet::operator*(const StringSet &other)
{
    // Create a new StringSet as the result of the intersection
    StringSet result("");
    set_intersection(set.begin(), set.end(), other.set.begin(), other.set.end(), back_inserter(result.set));
    return result;
}

/////////////////////////////////////////* The Implementation of int main() *///////////////////////////////////////////

int main()
{
    StringSet set1("Milk, Chocolate bars, and coffee.");
    cout << "print set1 (Inserted manually): \n";
    set1.print();
    cout << "-----------------------------------------------------------------------------\n";
    string fileName = "input.txt"; // you can modify the name of the document file from here
    StringSet set2(fileName, true);
    cout << "print set2 (taken from file \"" << fileName << "\"): \n";
    set2.print();
    cout << "-----------------------------------------------------------------------------\n";
    cout << "adding \"ice cream\" to set1 then print it: \n";
    set1.add("ice cream");
    set1.print();
    cout << "-----------------------------------------------------------------------------\n";
    cout << "adding \"coffee\" to set2 and removing \"are\" then print it: \n";
    set2.add("coffee");
    set2.remove("are");
    set2.print();
    cout << "-----------------------------------------------------------------------------\n";
    StringSet set_union = set1 + set2;
    cout << "print the union of set1 and set2: \n";
    set_union.print();
    cout << "-----------------------------------------------------------------------------\n";
    StringSet set_intersection = set1 * set2;
    cout << "print the intersection between set1 and set2: \n";
    set_intersection.print();
    cout << "-----------------------------------------------------------------------------\n";
    cout << "check if set1 is similar to set2 ot not: \n";
    set1.similar_to(set2);
    cout << "-----------------------------------------------------------------------------\n";
    cout << "clearing both sets and check if they're empty or not: \n";
    set1.clear();
    set2.clear();
    set1.print();
    set2.print();
    cout << "-----------------------------------------------------------------------------";
    return 0;
}