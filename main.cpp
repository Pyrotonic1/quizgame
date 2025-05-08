#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>

// Windows and unix-based operating systems use different commands for clearing the screen. So, this assigns the correct commands to "CLEAR" depending on the OS.
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

int animalQuestions()
{
    int finalScore{};
    std::string answer{};
    std::system(CLEAR);

    std::cout << "Animal time! The questions in this topic will be true or false statements. Just type in 'true' or 'false' when answering. Let's begin!\n\n"; // double newline for formatting reasons

    std::cout << "Statement one: One dog year is equal to 7 human years.\n";
    std::cin >> answer;
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower); // transforms the answer to be lower case, just in case someone decide to user capital letters when answering
    if (answer == "false")
    {
        std::cout << "You are correct! Dogs don't age the same way humans do (obviously), so it isn't as simple as multiplying their age by 7. You gained 1 point!\n\n";
        finalScore++;
        answer = "";
    }
    else 
    {
        std::cout << "Wrong! That is actually a myth. Google 'dog years graph' to see how dogs actually age compared to humans.\n\n";
        answer = "";
    }

    std::cout << "Statement two: Octopi have three hearts.\n";
    std::cin >> answer;
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    if (answer == "true")
    {
        std::cout << "You are correct! You gained 1 point! Octopi need 2 of their hearts to pump blood through their gills, and the last one for the rest of their body.\n\n";
        finalScore++;
        answer = "";
    }
    else
    {
        std::cout << "Wrong! Octopi actually DO have 3 hearts. They need two of the hearts for blood to circulate to the gills, and the third one is for the rest of the body.\n\n";
        answer = "";
    }

    std::cout << "Statement three: Cats LOVE milk.\n";
    std::cin >> answer;
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    if (answer == "true")
    {
        std::cout << "Correct! Cats do like the taste of milk, but most adult cats become lactose intolerant, so the aftermath of drinking that milk is all too\nfamiliar to the aftermath of my trip to taco bell. You gained 1 Point!\n\n";
        finalScore++;
        answer = "";
    }
    else
    {
        std::cout << "Wrong! How did you not know that? While cats like milk, most adult cats are lactose intolerant. That doesn't mean they don't like milk though!";
        answer = "";
    }

    return finalScore;
}

void startGame()
{
    int finalScore {0};
    std::cout << "First, pick a topic. The questions on the quiz will adapt to your choice.\n\n";
    std::cout << "    1. Animals\n    2. Technology\n    3. History\n    4. Math\n\n"; // Lists the 3 options formatted in this specifc way to be more readable for the user

    int topicSelectOption{};
    std::cin >> topicSelectOption;

    switch (topicSelectOption)
    {
    case 1:
        finalScore = animalQuestions();
        break;
    
    default:
        break;
    }
    std::cout << "You are done with the quiz! your final score is: " << finalScore << "\n";
    return;
}

int main()
{
    std::cout << "Welcome to the quiz game! Please choose an option below:\n\n";
    std::cout << "    1. Start\n    2. Options\n    3. Quit\n\n"; 

    int mainMenuOption{};
    std::cin >> mainMenuOption;

    switch (mainMenuOption)
    {
    case 1:
        std::cout << "Alright! Let's begin!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::system(CLEAR);
        startGame();
    
    case 2:
        std::cout << "Options not implemeted yet, pick something else!\n";
        break;

    case 3:
        break;

    default:
        std::cout << "I'm unsure what you mean by that. Try running the program again.\n";
        break;
    }
    std::cout << "The game has now shut down. Press any button to close the program.\n";
    std::cin.ignore();
    std::cin.get();
    std::cout << "Thanks for playing!\n";
    return 0;
}
