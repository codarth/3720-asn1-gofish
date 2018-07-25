#include <iostream>
#include "../include/gofishview.h"

GoFishView::GoFishView()
{
    //ctor
}

GoFishView::~GoFishView()
{
    //dtor
}

int GoFishView::GetNumberOfPlayers()
{
    int numberOfPlayers;
    std::cout << "How many players are going to play this round? ";
    std::cin >> numberOfPlayers;

    return numberOfPlayers;
}

std::string GoFishView::SetName(int i)
{
    std::string name;
    std::cout << "What is the name of the " << i << " player? ";
    std::cin >> name;

    return name;
}

void GoFishView::AnnouncePlayersTurn(Player* player)
{
    std::cout << "\n" << player->GetName() << ", it is your turn!\n";
    std::cout << "You have " << player->GetGroupCount() << " Groups so far.\n";
}

std::string GoFishView::SelectOpponent()
{
    std::string opponentName;
    std::cout << "Who would you like to guess from? ";
    std::cin >> opponentName;

    return opponentName;
}

void GoFishView::PrintHand(Player* player)
{
    std::cout << "\nHere is your hand : \n";
    for(Card* c : player->GetHand())
    {
        std::cout << c->GetFace() << " of " << c->GetSuit() << "\n";
    }
}

std::string GoFishView::GuessACard()
{
    std::string cardFace;
    std::cout << "What card would you like to ask for? (Just the face value) ";
    std::cin >> cardFace;

    return cardFace;
}

void GoFishView::GoFish()
{
    std::cout << "\nGOFISH!\n\n";
}

void GoFishView::YouDraw(Card* card)
{
    std::cout << "You Draw " << card->GetFace() << " of " << card->GetSuit() << "\n";
}

void GoFishView::GoodGuess(size_t n)
{
    std::cout << "\nGOOD GUESS, You got " << n << " Card(s).\n";
}

void GoFishView::CantPickYourself()
{
    std::cout << "You Can't pick from yourself, its illogical.\n";
}

void GoFishView::NotValidPlayer()
{
    std::cout << "That is not a valid player.\n";
}

void GoFishView::InvalidCard()
{
    std::cout << "You do not have that card.\n";
}

void GoFishView::Results(std::vector<Player*> players)
{
    std::cout << "\n\n\n";
    for(Player* p : players)
    {
        std::cout << p->GetName() << " had " << p->GetGroupCount() << " Groups.\n";
    }
}
