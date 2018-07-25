#include <iostream>
#include <iterator>
#include "../include/gofish.h"

GoFish::GoFish()
{
    // Initializers
    view = new GoFishView();
    deck = new Deck();
    numberOfPlayers = 0;
    currentPlayer = nullptr;
    opponent = nullptr;
    guessCard = nullptr;
    keepPlaying = true;
}

GoFish::GoFish(const GoFish& goFish)
{
    // Initializers
    view = new GoFishView();
    deck = new Deck();
    *view = *goFish.view;
    *deck = *goFish.deck;
    numberOfPlayers = 0;
    currentPlayer = nullptr;
    opponent = nullptr;
    guessCard = nullptr;
    keepPlaying = true;

}

GoFish::~GoFish()
{
    // Cleanup
    delete view;
    delete deck;
}

void GoFish::Begin()
{
    // Shuffle the deck
    deck->Shuffle();
    deck->Shuffle();
    deck->Shuffle();

    // How many players
    numberOfPlayers = view->GetNumberOfPlayers();

    // Get players names
    for(int i = 0; i < numberOfPlayers; i++)
    {
        players.push_back(new Player());
        std::string name;
        name = view->SetName(i);
        players[i]->SetName(name);
    }

    // Player to start
    currentPlayer = players[0];
    view->AnnouncePlayersTurn(currentPlayer);

    // Deal and play
    DealInitialHand();
    //Play();
}

void GoFish::Play()
{
    // Game Loop
    keepPlaying = true;
    while(keepPlaying)
    {
        // Print current players hand
        view->PrintHand(currentPlayer);
        // Get opponent to pick from
        SelectOpponent();
        // Guess a card
        SelectCard();
        // See how player did
        CheckGuess();

        char pause;
        std::cout<< "Press any key to continue. ";
        std::cin.ignore();
        std::cin.get(pause);

        system("clear");

        // Switch players
        SetCurrentPlayer();
        view->AnnouncePlayersTurn(currentPlayer);

        // Check for groups and hand size. End game when someone is out
        CheckForGroup();
        keepPlaying = CheckPlayersHandSize();

    }
    // Display results
    view->Results(players);
}

void GoFish::DealInitialHand()
{
    // Deal first hands
    // Could be changed to take in number of players
    // and chacnge the amount of cards delt
    for(Player* p : players)
    {
        for(int i = 0; i < 7; i++)
        {
            p->DrawCard(deck);
        }
    }
}

void GoFish::CheckForGroup()
{
    // Check for groups of 4
    for(Card* c1 : currentPlayer->GetHand())
    {
        unsigned count = 0;
        for(Card* c2: currentPlayer->GetHand())
        {
            if(c1->GetFace() == c2->GetFace())
            {
                count++;
                if(count == 4)
                {
                    // Remove cards form hand and increment counter
                    currentPlayer->RemoveCard(c1);
                    currentPlayer->IncrementGroupCount();
                }
            }
        }
    }
}

void GoFish::SelectOpponent()
{
    // Select an opponent
    std::string opponentName;
    bool invalid = true;
    while(invalid)
    {
        opponentName = view->SelectOpponent();

        // Can't pick yourself
        if(currentPlayer->GetName() == opponentName)
        {
            view->CantPickYourself();
        }
        else
        {
            invalid= false;
        }
    }
    // Check if input was a real players name
    invalid=true;
    for(Player* p : players)
    {
        if(opponentName == p->GetName())
        {
            invalid = false;
        }
        if(!invalid)
        {
            opponent = p;
            return;
        }

    }
    view->NotValidPlayer();
    SelectOpponent();
}

void GoFish::SelectCard()
{
    // What card to guess
    std::string cardFace;
    bool invalid = true;
    while(invalid)
    {
        cardFace = view->GuessACard();

        for(Card* c : currentPlayer->GetHand())
        {
            if(cardFace == c->GetFace())
            {
                guessCard = c;
                invalid = false;
            }
        }
        // Must be a card in your hand
        if(invalid)
        {
            view->InvalidCard();
        }
    }
}

void GoFish::CheckGuess()
{
    // Check the guess, Does opponent have the card
    if(opponent->CheckForCard(guessCard))
    {
        // Yep, remove form opponent and add to current player
        std::vector<Card*> cards = opponent->RemoveCard(guessCard);
        view->GoodGuess(cards.size());
        for(Card* c : cards)
        {
            currentPlayer->AddCard(c);
        }
    }
    else
    {
        // Nope, Draw a new card
        view->GoFish();
        Card* card = currentPlayer->DrawCard(deck);
        view->YouDraw(card);
    }
}

void GoFish::SetCurrentPlayer()
{
    // Set whos turn it is
    if(currentPlayer->GetName() == players[players.size()-1]->GetName())
    {
        // if at end of player array, start over
        currentPlayer = players[0];
        return;
    }
    else
    {
        // set next player
        for(size_t i = 0; i < players.size(); i++)
        {
            if(players[i]->GetName() == currentPlayer->GetName())
            {
                currentPlayer = players[i+1];
                return;
            }
        }
    }
}

bool GoFish::CheckPlayersHandSize()
{
    // Check if any player is out of cards
    for(Player* p : players)
    {
        if(p->GetHand().size() == 0)
        {
            // Someone is out of cards, end game
            return false;
        }
    }
    // Keep playing
    return true;
}

