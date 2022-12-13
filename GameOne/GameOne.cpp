#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;

const char* wordList[4]
= { "blue", "red", "orange", "yellow" };

int attempts = 0;
int maxAttempts = 5;

int guessed = 0;
int toBeGuess;


char* guessedSymbols[20] ;

void visualization(int a) {
    if (a == 0) {
        std::cout << R"(
___________.._______
| .__________))______|
| | / /      
| |/ /       
| | /        
| |/        
| |          
| |         
| |         
| |       
| |       
| |      
| |     
| |        
| |    
| |         
| |          
| |         
""""""""""|_--------|"""|
|"|"""""""\ \       '"|"|
| |        \ \        | |
: :         \ \       : :  
. .          `'       . .      
)" << '\n';
    }
    if (a == 1) {
        std::cout << R"(
___________.._______
| .__________))______|
| | / /      ||
| |/ /       ||
| | /        ||.-''.
| |/         |/  _  \
| |          ||  `/,|
| |          (\\`_.'
| |         
| |        
| |       
| |     
| |        
| |         
| |         
| |         
| |        
| |         
""""""""""|_----------|"|
|"|"""""""\ \       '"|"|
| |        \ \        | |
: :         \ \       : :  
. .          `'       . .      
)" << '\n';
    }
    if (a == 2) {
        std::cout << R"(
___________.._______
| .__________))______|
| | / /      ||
| |/ /       ||
| | /        ||.-''.
| |/         |/  _  \
| |          ||  `/,|
| |          (\\`_.'
| |         .-`--'.
| |         Y . . Y
| |          |   |
| |          | . |  
| |          |   |   
| |         
| |          
| |         
| |         
| |        
""""""""""|_------- |"""|
|"|"""""""\ \       '"|"|
| |        \ \        | |
: :         \ \       : :  
. .          `'       . .

)" << '\n';
    }
    if (a == 3) {
        std::cout << R"(
___________.._______
| .__________))______|
| | / /      ||
| |/ /       ||
| | /        ||.-''.
| |/         |/  _  \
| |          ||  `/,|
| |          (\\`_.'
| |         .-`--'.
| |         Y . . Y\
| |          |   | \\
| |          | . |  \\
| |          |   |   (`
| |         
| |        
| |         
| |          
| |        
""""""""""|_--------|"""|
|"|"""""""\ \       '"|"|
| |        \ \        | |
: :         \ \       : :  
. .          `'       . .
)" << '\n';
    }
    if (a == 4) {
        std::cout << R"(
___________.._______
| .__________))______|
| | / /      ||
| |/ /       ||
| | /        ||.-''.
| |/         |/  _  \
| |          ||  `/,|
| |          (\\`_.'
| |         .-`--'.
| |        /Y . . Y\
| |       // |   | \\
| |      //  | . |  \\
| |     ')   |   |   (`
| |          
| |          
| |          
| |          
| |         
""""""""""|_--------|"""|
|"|"""""""\ \       '"|"|
| |        \ \        | |
: :         \ \       : :  
. .          `'       . .
)" << '\n';
    }
    if (a == 5) {
        std::cout << R"(
 ___________.._______
| .__________))______|
| | / /      ||
| |/ /       ||
| | /        ||.-''.
| |/         |/  _  \
| |          ||  `/,|
| |          (\\`_.'
| |         .-`--'.
| |        /Y . . Y\
| |       // |   | \\
| |      //  | . |  \\
| |     ')   |   |   (`
| |          ||'
| |          || 
| |          ||
| |          || 
| |         / | 
""""""""""|_`-'     |"""|
|"|"""""""\ \       '"|"|
| |        \ \        | |
: :         \ \       : :  
. .          `'       . .
)" << '\n';
    }
    if (a == 6) {
        std::cout << R"(
 ___________.._______
| .__________))______|
| | / /      ||
| |/ /       ||
| | /        ||.-''.
| |/         |/  _  \
| |          ||  `/,|
| |          (\\`_.'
| |         .-`--'.
| |        /Y . . Y\
| |       // |   | \\
| |      //  | . |  \\
| |     ')   |   |   (`
| |          ||'||
| |          || ||
| |          || ||
| |          || ||
| |         / | | \
""""""""""|_`-' `-' |"""|
|"|"""""""\ \       '"|"|
| |        \ \        | |
: :         \ \       : :  
. .          `'       . .
)" << '\n';
    }
}


string generateRandomWord() {
    srand(time(0));
    int random = (rand() % 4);
    return wordList[random];
}


char getInput() {
    char input;
    cin >> input;
    input = tolower(input);
    return input;
}
int main()
{


    string word = generateRandomWord();
    int symbols = word.length();
    char input;
    toBeGuess = symbols;

    for (size_t i = 0; i < maxAttempts + 2; i++)
    {
        system("cls");


        visualization(attempts);
        
        if (guessed == 0) {
            for (size_t i = 0; i < symbols; i++)
            {
                std::cout << "_ ";
            }
        }
        else if (guessed > 0) {
            for (size_t i = 0; i < symbols; i++)
            {

                
                std::cout << "_ ";
            }
        }

        input = getInput();


        
        std::cout << endl << endl;






        if (word.find(input) != string::npos)
        {
            
               
            guessed++;

        }
        else {
            attempts++;
        }

        
        i = attempts;

        if (guessed >= toBeGuess)
        {
            std::cout << "You Won";
            return 0;
        }
        
    }

    visualization(attempts);
    std::cout << "\n You lost";



}

