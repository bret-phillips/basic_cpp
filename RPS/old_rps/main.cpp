#include <iostream>
#include <chrono>
#include <random>
#include <string>



int welcome()
{
	// Welcome player to game
	std::cout << "Hello, would you like to play a game of rock paper scissors?" << std::endl;
	std::cout << "Options: [Y/N]: ";
	
	// Get user input
	std::string ans;
	std::cin >> ans;
	
	// Ensure valid input
	while(ans != "Y" && ans != "y" && ans != "yes" && ans != "Yes" && ans != "YES" && ans != "yES"
	&&    ans != "N" && ans != "n" && ans != "no"  && ans != "No"  && ans != "NO"  && ans != "nO")
	{
		// Ask player to try again
		std::cout << "Sorry, but that is not a valid response. Please try again." << std::endl;
		std::cout << "Hello, would you like to play a game of rock paper scissors?" << std::endl;
		std::cout << "Options: [Y/N]:";
		
		// Record player's answer
		std::cin >> ans;
	}
	
	// Change input to boolean
	int play;
	if(ans == "Y" || ans == "y" || ans == "yes" || ans == "Yes" || ans == "YES" || ans == "yES")
	{
		play = 1;
	}
	else
	{
		play = 0;
	}
	
	// Return answer
	return play;
}



int round(int comp_choice)
{
	// Ask player to choose an option
	std::cout << std::endl;
	std::cout << "Choose either rock, paper, or scissors." << std::endl;
	std::cout << "Options: Rock, Paper, Scissors: ";
	
	// Record player's choice
	std::string ans;
	std::cin >> ans;
	
	// Check if player's choice is valid
	while (ans != "rock"     && ans != "Rock"     && ans != "ROCK"     && ans != "rOCK"
	&&     ans != "paper"    && ans != "Paper"    && ans != "PAPER"    && ans != "pAPER"
	&&     ans != "scissors" && ans != "Scissors" && ans != "SCISSORS" && ans != "sCISSORS"
	&&     ans != "shotgun"  && ans != "Shotgun"  && ans != "SHOTGUN"  && ans != "sHOTGUN")
	{
		// Ask player to try again
		std::cout << std::endl;
		std::cout << "Sorry, but that is not a valid response. Please try again." << std::endl;
		std::cout << "Choose either rock, paper, or scissors." << std::endl;
		std::cout << "Options: Rock, Paper, Scissors: ";
		
		// Record player's answer
		std::cin >> ans;
	}
	
	// Check results
	int results;
	if(ans == "rock" || ans == "Rock" || ans == "ROCK" || ans == "rOCK")
	{
		if(comp_choice == 0)      {results = 0;}
		else if(comp_choice == 1) {results = 2;}
		else                      {results = 1;}
	}
	else if(ans == "paper" || ans == "Paper" || ans == "PAPER" || ans == "pAPER")
	{
		if(comp_choice == 0)      {results = 1;}
		else if(comp_choice == 1) {results = 0;}
		else                      {results = 2;}
	}
	else if(ans == "scissors" || ans == "Scissors" || ans == "SCISSORS" || ans == "sCISSORS")
	{
		if(comp_choice == 0)      {results = 2;}
		else if(comp_choice == 1) {results = 1;}
		else                      {results = 0;}
	}
	else
	{
		                           results = 1;
	}
	
	// Turn computer's choice into a string
	std::string comp_choice_str;
	if(comp_choice == 0)      {comp_choice_str = "Computer chose rock.";}
	else if(comp_choice == 1) {comp_choice_str = "Computer chose paper.";}
	else                      {comp_choice_str = "Computer chose scissors.";}
	
	// Turn results into a string
	std::string results_str;
	if(results == 0)      {results_str = "It's a tie.";}
	else if(results == 1) {results_str = "You Won!";}
	else                 {results_str = "You lost.";}
	
	// Display results
	std::cout << std::endl;
	std::cout << comp_choice_str <<  " " << results_str << std::endl;
	
	// Return results
	return results;
}



int continue_game()
{
	// Ask player if they want to continue playing
	std::cout << std::endl;
	std::cout << "Would you like to play another round?" << std::endl;
	std::cout << "Options: [Y/N]: ";
	
	// Get user input
	std::string ans;
	std::cin >> ans;
	
	// Ensure valid input
	while(ans != "Y" && ans != "y" && ans != "yes" && ans != "Yes" && ans != "YES" && ans != "yES"
	&&    ans != "N" && ans != "n" && ans != "no"  && ans != "No"  && ans != "NO"  && ans != "nO")
	{
		// Ask player to try again
		std::cout << std::endl;
		std::cout << "Sorry, but that is not a valid response. Please try again." << std::endl;
		std::cout << "Would you like to play another round?" << std::endl;
		std::cout << "Options: [Y/N]:";
		
		// Record player's answer
		std::cin >> ans;
	}
	
	// Change input to boolean
	int play;
	if(ans == "Y" || ans == "y" || ans == "yes" || ans == "Yes" || ans == "YES" || ans == "yES")
	{
		play = 1;
	}
	else
	{
		play = 0;
	}
	
	// Return Answer
	return play;
}



int main()
{
	// Welcome player and get input
	int play = welcome();
	
	// Set up game if play == true
	if(play == 1)
	{
		// Set up random engine
		unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		std::uniform_int_distribution<int> distribution(0, 2);
		
		// Set up score
		int wins  = 0;
		int loses = 0;
		int ties  = 0;
		
		// Set up other
		int comp_choice;
		int results;
	
		// Start game loop if play == 1
		while(play == 1)
		{
			// Start round
			comp_choice = distribution(generator);
			results = round(comp_choice);
			
			// Check who won and update score
			if(results == 0)
			{
				ties++;
			}
			else if(results == 1)
			{
				wins++;
			}
			else
			{
				loses++;
			}
			
			// Display score
			std::cout << std::endl;
			std::cout << "Wins: "  << wins << std::endl;
			std::cout << "Loses: " << loses << std::endl;
			std::cout << "Ties: "  << ties << std::endl;
			
			// See if player wants to play another round
			play = continue_game();
		}
	}
	
	// End session
	std::cout << std::endl;
	std::cout << "Sorry to hear that. Maybe next time." << std::endl;
	std::cout << "Session terminated" << std::endl;
	return 0;
}