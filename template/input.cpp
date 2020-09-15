#include <bits/stdc++.h>
#include<iostream>

using namespace std;
int main()
{
    fstream file;
    string  t, q, filename;
      int word;
    // filename of the file
    filename = "file.txt";

    // opening file
    file.open(filename.c_str());

    // extracting words from the file
    while (file >> word)
    {
        // displaying content
        cout << word ;
        int n=word +1;
        cout<<n<<endl;
    }

    return 0;
}
