#include <iostream>
#include <chrono>
#include <random>
#include <string>


void title_screen()
{
	// Create title screen
	std::string line01, line02, line03, line04, line05, line06,
	            line07, line08, line09, line10, line11, line12;
	line01 = "              ____   ____   ___   _  _               ";
	line02 = "             |  _ \\ /  _ \\ /  _| | |/ /              ";
	line03 = "             | /| / | || | | |_  |   |               ";
	line04 = "             |_|\\_\\ \\____/ \\___| |_|\\_\\              ";
	line05 = "          ____    _     ____   ____   ____           ";
	line06 = "         |  _ \\  /_\\   |  _ \\ | ___| |  _ \\          ";
	line07 = "         | |__/ / _ \\  | |__/ | __|  | /| /          ";
	line08 = "         |_|   /_/ \\_\\ |_|    |____| |_|\\_\\          ";
	line09 = "  ____   ___   _   ____   ____   ____   ____   ____  ";
	line10 = " / ___\\ /  _| | | / ___\\ / ___\\ /  _ \\ |  _ \\ / ___\\ ";
	line11 = " \\___ \\ | |_  | | \\___ \\ \\___ \\ | || | | /| / \\___ \\ ";
	line12 = " \\____/ \\___| |_| \\____/ \\____/ \\____/ |_|\\_\\ \\____/ ";
	
	// Display title screen
	std::cout << std::endl;
	std::cout << line01 << std::endl;
	std::cout << line02 << std::endl;
	std::cout << line03 << std::endl;
	std::cout << line04 << std::endl;
	std::cout << line05 << std::endl;
	std::cout << line06 << std::endl;
	std::cout << line07 << std::endl;
	std::cout << line08 << std::endl;
	std::cout << line09 << std::endl;
	std::cout << line10 << std::endl;
	std::cout << line11 << std::endl;
	std::cout << line12 << std::endl;
	std::cout << std::endl;
	
	// Return
	return;
}


int welcome()
{
	// Display title screen
	title_screen();
	
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


void graphics(int players_choice, int comps_choice)
{
	// Create graphic for player's choice
	std::string line_1, line_2, line_3, line_4;
	if(players_choice == 0)
	{
		line_1 = "     ___       ";
		line_2 = "    /- _¯-_    ";
		line_3 = "   |_- _-- \\   ";
		line_4 = "   \\_______/   ";
	}
	else if(players_choice == 1)
	{
		line_1 = "      ______   ";
		line_2 = "     /     /   ";
		line_3 = "    /     /    ";
		line_4 = "   /_____/     ";
	}
	else if(players_choice == 2)
	{
		line_1 = "               ";
		line_2 = " ╔═══╗-¯¯¯¯-_  ";
		line_3 = " ╠═══ <======› ";
		line_4 = " ╚═══╝-____-¯  ";
	}
	else if(players_choice == 4)
	{
		line_1 = "               ";
		line_2 = "     WELL      ";
		line_3 = "               ";
		line_4 = "               ";
	}
	else
	{
		line_1 = "               ";
		line_2 = "   ___________ ";
		line_3 = "  / __----____=";
		line_4 = " /_/' ¯¯¯¯     ";
	}
	
	// add 'vs' graphic
	line_1.append("  __     __  _____   ");
	line_2.append("  \\ \\   / / / ____\\  ");
	line_3.append("   \\ \\_/ /  \\____ \\  ");
	line_4.append("    \\___/   \\_____/  ");
	
	// add computer's choice graphic
	if(comps_choice == 0)
	{
		line_1.append("       ___     ");
		line_2.append("    _-¯_ -\\    ");
		line_3.append("   / --_ -_|   ");
		line_4.append("   \\_______/   ");
	}
	else if(comps_choice == 1)
	{
		line_1.append("   ______      ");
		line_2.append("   \\     \\     ");
		line_3.append("    \\     \\    ");
		line_4.append("     \\_____\\   ");
	}
	else if(comps_choice == 2)
	{
		line_1.append("               ");
		line_2.append("  _-¯¯¯¯-╔═══╗ ");
		line_3.append(" ‹======> ═══╣ ");
		line_4.append("  ¯-____-╚═══╝ ");
	}
	else
	{
		line_1.append("               ");
		line_2.append("  WELL         ");
		line_3.append("               ");
		line_4.append("               ");
	} 
	
	// Display graphic
	std::cout << std::endl;
	std::cout << line_1 << std::endl;
	std::cout << line_2 << std::endl;
	std::cout << line_3 << std::endl;
	std::cout << line_4 << std::endl;
	
	// Return
	return;
}


int round(int comp_choice)
{
	// Ask player to choose an option
	std::cout << std::endl;
	std::cout << "Choose either rock, paper, or scissors." << std::endl;
	std::cout << "Options: (1)Rock, (2)Paper, (3)Scissors, (4)Well: ";
	
	// Record player's choice
	std::string ans;
	std::cin >> ans;
	
	// Check if player's choice is valid
	while (ans != "rock"     && ans != "Rock"     && ans != "ROCK"     && ans != "rOCK"
	&&     ans != "paper"    && ans != "Paper"    && ans != "PAPER"    && ans != "pAPER"
	&&     ans != "scissors" && ans != "Scissors" && ans != "SCISSORS" && ans != "sCISSORS"
	&&     ans != "shotgun"  && ans != "Shotgun"  && ans != "SHOTGUN"  && ans != "sHOTGUN"
	&&     ans != "r"        && ans != "R"        && ans != "1"        && ans != "p"
	&&     ans != "P"        && ans != "2"        && ans != "s"        && ans != "S"
	&&     ans != "3"        && ans != "well")
	{
		// Ask player to try again
		std::cout << std::endl;
		std::cout << "Sorry, but that is not a valid response. Please try again." << std::endl;
		std::cout << "Choose either rock, paper, or scissors." << std::endl;
		std::cout << "Options: (1)Rock, (2)Paper, (3)Scissors, (4)Well: ";
		
		// Record player's answer
		std::cin >> ans;
	}
	
	// Check results
	int results;
	int players_choice;
	if(ans == "rock" || ans == "Rock" || ans == "ROCK" || ans == "rOCK"
	|| ans == "r" || ans == "R" || ans == "1")
	{
		players_choice = 0;
		if(comp_choice == 0)      {results = 0;}
		else if(comp_choice == 1) {results = 2;}
		else                      {results = 1;}
	}
	else if(ans == "paper" || ans == "Paper" || ans == "PAPER" || ans == "pAPER"
	|| ans == "p" || ans == "P" || ans == "2")
	{
		players_choice = 1;
		if(comp_choice == 0)      {results = 1;}
		else if(comp_choice == 1) {results = 0;}
		else                      {results = 2;}
	}
	else if(ans == "scissors" || ans == "Scissors" || ans == "SCISSORS" || ans == "sCISSORS"
	|| ans == "s" || ans == "S" || ans == "3")
	{
		players_choice = 2;
		if(comp_choice == 0)      {results = 2;}
		else if(comp_choice == 1) {results = 1;}
		else                      {results = 0;}
	}
	else if(ans == "well")
	{
		players_choice = 4;
		if(comp_choice == 0 || comp_choice == 2)    {results = 1;}
		else if(comp_choice == 3 )                  {results = 0;}
		else                                        {results = 2;}
	}
	else
	{
		players_choice = 3;
		                           results = 1;
	}
	
	// Turn computer's choice into a string
	std::string comp_choice_str;
	if(comp_choice == 0)      {comp_choice_str = "Computer chose rock.";}
	else if(comp_choice == 1) {comp_choice_str = "Computer chose paper.";}
	else if(comp_choice == 3) {comp_choice_str = "Computer chose well.";}
	else                      {comp_choice_str = "Computer chose scissors.";}
	
	// Turn results into a string
	std::string results_str;
	if(results == 0)      {results_str = "It's a tie.";}
	else if(results == 1) {results_str = "You Won!";}
	else                  {results_str = "You lost.";}
	
	// Display graphic
	graphics(players_choice, comp_choice);
	
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
		std::uniform_int_distribution<int> distribution(0, 3);
		
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
			std::cout << "                    ___________" << std::endl;
			std::cout << "                   | Wins  | "  << wins  << " |" << std::endl;
			std::cout << "                   | Loses | "  << loses << " |" << std::endl;
			std::cout << "                   | Ties  | "  << ties  << " |" << std::endl;
			std::cout << "                    ¯¯¯¯¯¯¯¯¯¯¯"  << std::endl;
			
			// See if player wants to play another round
			play = continue_game();
		}
	}
	
	// Display end game graphic
	std::cout << std::endl;
	std::cout << "                 ____  __  _  ____     " << std::endl;
	std::cout << "                | ___||  \\| ||  _ \\    " << std::endl;
	std::cout << "                | __| | \\ \\ || || |    " << std::endl;
	std::cout << "                |____||_|\\__||____/    " << std::endl;
	
	// End session
	std::cout << std::endl;
	std::cout << "Sorry to hear that. Maybe next time." << std::endl;
	std::cout << "Session terminated" << std::endl;
	std::cout << std::endl;
	
	// End program
	return 0;
}