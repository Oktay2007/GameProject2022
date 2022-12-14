//declare what we are using
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std; 


//Declare variables


const char* wordList[10] // Words that will be used in the game
= { "blue", "red", "orange", "sign", "phone", "game", "background", "algorithms", "education", "binoculars"};

int attempts = 0; // current attempts
int maxAttempts = 5; // maximum attempts

int guessed = 0; // how much of the symbols are guessed
int toBeGuess; // how much is left to be guessed


char guessedSymbols[20] ;  // all guessed symbols



// Visualization function of the hangman 
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
""""""""""|_`-'-----|"""|
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



// Generate the random word
string generateRandomWord() {
    srand(time(0)); // using srand to generate random seed using time
    int random = (rand() % 10); // using rand to pick random number till 10 - 1 ( that is the size of the word list )
    return wordList[random]; // return the word
}

// function to get the input of the player
char getInput() {
    char input;
    cin >> input;
    input = tolower(input);
    return input;
}

void addToSymbolList(char input, int symbols) {
    for (int i = 0; i < symbols; i++)
    {
        if (guessedSymbols[i] == '\0') { // check if symbol space is free
            guessedSymbols[i] = input;
            i = 10;
            guessed++;
        }
    }
}

int main()
{


    string word = generateRandomWord(); // using the generateRandomWord function to pick the word for this session
    int symbols = word.length(); // creating intiger symbols that represend the length of the word
    char input; // create input variable
    toBeGuess = symbols; // set the symbols to be guessed to the symbols
    bool type = true; // a temporary bool

    for (size_t i = 0; i < maxAttempts + 2; i++)
    {
        system("cls"); // clear the console at the start every time


        visualization(attempts); // using the function visualization to graphicaly render a hangman
        
        if (guessed == 0) { // if we didn't guess any symbols of the word run bellow
            for (size_t i = 0; i < symbols; i++)
            {
                std::cout << "_ "; // type _ for every symbol
            }
        }
        else if (guessed > 0) { // if we guessed any symbol
            for (size_t i = 0; i < symbols; i++)
            {
                for (size_t j = 0; j < 10; j++)
                {
                    if (word[i] == guessedSymbols[j]) { // if word contains any of the guessed symbols
                        std::cout << guessedSymbols[j]; // instead of _ type the symbol
                        type = false; // we are using type to make sure it doesn't cout the _ again
                    }
                }
                if (type == true) { // type the rest
                    std::cout << "_ ";
                    
                }
                type = true;
                
            }
        }

        input = getInput(); // use the function getInput to get the input from the player


        
        std::cout << endl << endl; // just add 2 more blank lines




       

        if (word.find(input) != string::npos) // of we find a symbol that exists in the word
        {
            for (int k = 0; k < symbols; k++)
            {
                if  (input == guessedSymbols[k]) { // if we guessed typed that symbol
                    attempts++;
                    k = symbols + 1;
                }
                else { // else if we didn't already guessed it
                    addToSymbolList(input, symbols); //add to the symbols list
                    k = symbols + 1;
                }
            }
            

            

        }
        else {
            attempts++;
        }

        
        i = attempts;

        if (guessed >= toBeGuess)
        {
            system("cls"); // clear the console


            visualization(attempts); // using the function visualization to graphicaly render a hangman
            std::cout << word << endl; // write the whole word
            std::cout << "You Won"; // write you won text
            return 0; // just end the program
        }
        
    }


    system("cls"); // clear the console
    visualization(attempts); // using the function visualization to graphicaly render a hangman
    std::cout << "The word was : " << word << endl; // write what was the word
    std::cout << "\nYou lost"; // write you lost text
    return 0; // just end the program


}

