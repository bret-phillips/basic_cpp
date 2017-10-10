#include <iostream>
#include <chrono>
#include <random>

int main()
{
  unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution(0, 2);

  int playing = 1;
  int wins = 0;
  int loses = 0;
  int ties = 0;
  while(playing == 1)
  {
    std::cout << "Would you like to play a game of rock paper sciccors? Y/N:";
    char ans;
    std::cin >> ans;
    if(ans == 'Y' || ans == 'y')
    {
      int flag = 1;
      int comp = distribution(generator);
      while(flag != 0)
      {
        std::cout << "Choose (R)ock, (P)aper, or (S)ciccors:";
        std::cin >> ans;
        if(ans == 'R' || ans == 'r')
        {
          flag = 0;
          if(comp == 0)
          {
            std::cout << "Computer chose Rock. It's a draw." << std::endl;
            ties += 1;
          }
          else if(comp == 1)
          {
            std::cout << "Computer chose Paper. You lose this round." << std::endl;
            loses += 1;
          }
          else
          {
            std::cout << "Computer chose Sciccors. You won!" << std::endl;
            wins += 1;
          }
          std::cout << "Wins: " << wins << std::endl << "Loses: " << loses << std::endl << "Drwas: " << ties << std::endl;
        }
        else if(ans == 'P' || ans == 'p')
        {
          flag = 0;
          if(comp == 0)
          {
            std::cout << "Computer chose Rock. You Won!" << std::endl;
            wins += 1;
          }
          else if(comp == 1)
          {
            std::cout << "Computer chose Paper. It's a draw." << std::endl;
            ties += 1;
          }
          else
          {
            std::cout << "Computer chose Scissors. You lose." << std::endl;
            loses += 1;
          }
          std::cout << "Wins: " << wins << std::endl << "Loses: " << loses << std::endl << "Drwas: " << ties << std::endl;
        }
        else if(ans == 'S' || ans == 's')
        {
          flag = 0;
          if(comp == 0)
          {
            std::cout << "Computer chose Rock. You lose." << std::endl;
            loses += 1;
          }
          else if(comp == 1)
          {
            std::cout << "Computer chose Paper. You won!" << std::endl;
            wins += 1;
          }
          else
          {
            std::cout << "Computer chose Scissors. It's a draw." << std::endl;
            ties += 1;
          }
          std::cout << "Wins: " << wins << std::endl << "Loses: " << loses << std::endl << "Drwas: " << ties << std::endl;
        }
        else
        {
          flag = 1;
        }
      }
    }
    else if(ans == 'N' || ans == 'n')
    {
      std::cout << "Sorry to hear that. Session terminated." << std::endl;
      playing = 0;
    }
  }
  return 0;
}