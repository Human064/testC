#include <iostream>

using namespace std;

//Ввод с пробелами до 50 символов в строке
string readString() {

    char mes[50];
    cin.getline(mes, 49, '\n');
    
    return mes;
}


int main()
{
    string input, output, dictionary = "";

    input = readString();

    size_t inputLength = input.length();

    for (size_t i = 0; i < inputLength; i++)
    {
        bool oneSym = true;
        size_t j = i + 1;
        char symbol = tolower(input[i]);
        while (oneSym && j < inputLength)
        {
            if (symbol == tolower(input[j]))
                oneSym = false;
            j++;
        }

        if (!oneSym)
            dictionary += tolower(input[i]);

    }

    size_t dictionaryLength = dictionary.length();

    for (size_t i = 0; i < inputLength; i++)
    {
        if (dictionary.find(tolower(input[i])) < dictionaryLength)
            output += ')';
        else
            output += '(';
    }

    cout << output << "\n";

    return 0;
}
