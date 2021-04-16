#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


//-------------------------------------------------------------------------------------------------------
// @name            : isDelimiter
//
// @description     : Checks whether the provided character (ch) is present in the delimiter list.
//
// @return          : true/false
//-------------------------------------------------------------------------------------------------------
static bool isDelimiter(char ch, const string& delimiters)
{
    return (delimiters.find(ch) != string::npos);
}


//-------------------------------------------------------------------------------------------------------
// @name            : addTokenToList
//
// @description     : if the provided token is not empty, then it adds it to the vector of tokens.
//                    After this add operation, the input token is cleared.
//
// @return          : nothing
//-------------------------------------------------------------------------------------------------------
static void addTokenToList(string& token, vector<string>& tokens)
{
    if (!token.empty())
    {
        tokens.push_back(token);
        token.clear();
    }
}


//-------------------------------------------------------------------------------------------------------
// @name            : Split
//
// @description     : Splits the given string as per the list of delimiters specified
//
// @return          : vector of tokens
//-------------------------------------------------------------------------------------------------------
vector<string> Split(const string& input, const string& delimiters)
{
    vector<string> tokens;

    stringstream ss(input);
    string token;
    for (int i = 0; i < input.size(); i++)
    {
        char ch = input[i];
        if (isDelimiter(ch, delimiters))
        {
            addTokenToList(token, tokens);
        }
        else
        {
            token.push_back(ch);
        }

    }

    // This needs to be done at the end again as the last token would have missed
    // in the for loop above.
    addTokenToList(token, tokens);

    return tokens;
}


//-------------------------------------------------------------------------------------------------------
// @name            : Split
//
// @description     : Splits the given string as per the given delimiter.
//
// @return          : vector of tokens
//-------------------------------------------------------------------------------------------------------
vector<string> Split(const string& input, const char& delimiter)
{
    vector<string> tokens;

    stringstream ss(input);
    string token;
    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}



//-------------------------------------------------------------------------------------------------------
// @name            : DisplayTokens
//
// @description     : Prints the tokens on console
//
// @return          : Nothing
//-------------------------------------------------------------------------------------------------------
void DisplayTokens(vector<string> & tokens)
{
    for (const auto& token : tokens)
    {
        cout << token << endl;
    }
}


//-------------------------------------------------------------------------------------------------------
// M A I N
//-------------------------------------------------------------------------------------------------------
int main()
{
    //string input = "This is   to be  tested";
    //string input = "key=value;key2=value2; key3=value3";
    string input = "key ** ** value;***key2=value2;*key3=value3";
    string delimiters = " =;* ";
    vector<string> tokens = Split(input, delimiters);

    cout << "Input: " << input << endl;
    cout << "Tokens splitted on [" << delimiters << "] " << endl;
    DisplayTokens(tokens);

    return 0;
}