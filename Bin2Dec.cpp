#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//bin2Dec converts the binary number to decimal
int bin2Dec(string binInput)
{
    //toReturn holds the value to be returned during the algorithm
    int toReturn;

    //the for loop uses the length of the input to convert the number
    for (int i = binInput.length()-1; i > -1; --i)
    {
        if(binInput.at(i) == '1')
        {
            toReturn += pow(2,binInput.length()-i-1);
        }
    }
    return toReturn;
}

//checkInput simply ensures that only 1's and 0's were entered
//returns true if there are no illegal values
bool checkInput(string toCheck)
{
    for (int i = 0; i < toCheck.length(); ++i)
    {
        if(toCheck.at(i) != '0' && toCheck.at(i) != '1')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //uses a string to hold the input value
    //a string is used for easy indexing using the .at() function
    string input;
    while (input != "q")
    {
        cout << "Enter a binary number to convert to decimal. q to quit\n";
        cin >> input;
        if(checkInput(input))
        {
            cout << bin2Dec(input) << endl;
        } else if (input.length() > 8)
        {
            cout << "Can only enter up to 8 digits for a binary number\n";
        }
        else {
            cout << "Only 0's and 1's are valid inputs (Other than q to quit)\n";
        }
    }
    return 0;
}