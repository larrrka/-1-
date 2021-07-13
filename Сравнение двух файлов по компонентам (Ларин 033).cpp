#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
using namespace std;
 
int main(int argc, char *argv[]) {
    string firstPath;
    string secondPath;
    string outputPath;
    if (argc == 4) {
        firstPath = argv[1];
        secondPath = argv[2];
        outputPath = argv[3];
    } else {
        cout << "Enter first file path" << endl;
        cin >> firstPath;
        cout << "Enter second file path" << endl;
        cin >> secondPath;
        cout << "Enter output file path" << endl;
        cin >> outputPath;
    }
    ifstream firstFile(firstPath, ios::in);
    string first{istreambuf_iterator<char>(firstFile), istreambuf_iterator<char>()};
    
    ifstream secondFile(secondPath, ios::in);
    string second{istreambuf_iterator<char>(secondFile), istreambuf_iterator<char>()};
    
    ofstream output;
    output.open(outputPath, ios::out | ios::app);
    
    for (int i = 0; i < min(first.length(), second.length()); i++)
        if (first[i] != second[i])
            output << i << ": " << first[i] << " != " << second[i] << endl;
    
    int diff = first.length() - second.length();
    if (diff == 0)
        return 0;
    else if (diff < 0)
        diff = -diff;
    
    output << "length diff is " << diff << endl;
    return 0;
}