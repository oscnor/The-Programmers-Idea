#include "game.h"
#include <iostream>

int main()
{
    char yesOrNo;
    while(true)
    {
        /*std::cout<< "Would you like to play a game of chess? y/n: ";
        std::cin>>yesOrNo;
        if(yesOrNo == 'N' || yesOrNo == 'n')
            break;
        else if(yesOrNo == 'Y' || yesOrNo == 'y')*/
        {
            Game game;
            game.run();


            /*REMOVE*/
            break;
        }
    }

    return 0;
}


