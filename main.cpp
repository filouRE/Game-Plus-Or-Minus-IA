#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
using namespace std;
using namespace chrono;

int bot;

// Bot function
int computerVsComputer()
{
        srand(time(NULL));
        // Variables
        int botNumber = rand() % 101 + 1;
        int userInput = 0;
        int randomNb = rand() % 100 + 1;
        printf("╔════════════════════════════════════════════╗\n");
        printf("║ L'ordinateur choisit le nombre %i          ║\n", randomNb); // to know the number
        printf("╚════════════════════════════════════════════╝\n");
        if (bot == true)
        {
          auto start = std::chrono::steady_clock::now();
          while (botNumber != randomNb)
          {
            printf("\n>> ");
            printf("%i\n", botNumber);
            botNumber = botNumber + rand() % 14 + 1;  
            botNumber = botNumber - rand() % 19 + 1;                      
          if (botNumber >= 100)
          {
            botNumber = botNumber / 9;
          }
          if (botNumber < 1)
          {
            botNumber = botNumber + 20;
          }
          if (botNumber == randomNb)
          {
            auto elapsed = duration_cast<std::chrono::milliseconds>(steady_clock::now() - start);
            printf("\n>> %i\n", randomNb);
            printf("\nRéponse trouvée en %li milisecondes, la réponse est : %i \n", elapsed.count(), randomNb);
            sleep(6);
            cout << "\033[2J\033[0;0H";
            break;
      }
	  }	
  }
  return 0;
}     

// Player function
int ordinateurVsPlayer()
{ 
        srand(time(NULL));
        // Variables
        int i = 0;
        int v = 0;
        int botNumber = rand() % 101 + 1;
        int userInput = 0;
        int randomNb = rand() % 100 + 1;
        printf("╔════════════════════════════════════════════╗\n");
        printf("║ Trouve mon nombre! Il est entre 1 et 100!  ║\n");
        printf("╚════════════════════════════════════════════╝\n");
        printf("L'ordinateur choisit le nombre %i\n", randomNb); // to know the number
        // Game part
        while (userInput != randomNb)
        {
        i++;
        v++;
        if (v < 2)
          printf("\nEntrer un nombre :\n\n>> ");
        scanf("\n%i", &userInput);
        if (userInput < randomNb)
          printf("\nLa réponse est plus grande!\n\n>> ");
        else if (userInput > randomNb) 
          printf("\nLa réponse est plus petite!\n\n>> ");
        else if (i == 1 && userInput == randomNb)
        {
          printf("\nBravo! Tu as trouvé la bonne réponse, tu as trouvé la réponse du premier coup\n");
          sleep(5);
          cout << "\033[2J\033[0;0H";
          break;
        }
        else if (userInput == randomNb)
        {
          printf("\nBravo! Tu as trouvé la bonne réponse! Cela t'a pris %i essais pour y arriver\n", i);
          sleep(5);
          cout << "\033[2J\033[0;0H";
          break;
    }
  }
 return 0;
}

//  Entry (function loader)
int main()
{
    // Variables
    int k = 0;
    int ordiOrPlay;
    int yesOrNo;
    while (true)
    {
          printf("\n╔══════════════════════════════════════════════════╗\n");
          printf("║Voulez vous jouer ou laisser l'ordinateur jouer ? ║\n║1) Jouer                                          ║\n║2) Ordinateur                                     ║\n║3) Quitter                                        ║\n");
          printf("╚══════════════════════════════════════════════════╝\n\n>> ");
          scanf("%i", &ordiOrPlay);
          if (ordiOrPlay == 1)
          {
            bot = false;
            cout << "\033[2J\033[0;0H";
            ordinateurVsPlayer();

          }
          else if (ordiOrPlay == 2)
          {
              bot = true;
              cout << "\033[2J\033[0;0H";
              computerVsComputer();
          }
          else if (ordiOrPlay == 3)
          {
              cout << "\033[2J\033[0;0H";
              printf("|>---<|\n");
              printf("| o_o |\n");
              printf(" |_^_|\n\n");
              printf(" 𝗕𝘆𝗲!!\n\n");
              exit(0);
          }
          else 
            printf("Erreur: Option non valide!");
    }
    return 0;
}