#include "../include/deck.h"

#include <time.h>

Deck::Deck()
{
    // Face values
    std::string faces[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    // Suits
    std::string suits[] = {"Clubs","Diamonds","Hearts","Spades"};

    // Create the dec of 52 cards
    for(std::string &f : faces)
    {
        for(std::string &s : suits)
        {
            Card* newCard = new Card(f,s);
            deck.push_back(newCard);
        }
    }

    // initialize current player to no one
    currentCard = nullptr;
}

Deck::~Deck()
{
    // Destroy the remaining deck
    for(Card* c : deck)
    {
        delete c;
    }
}

void Deck::Shuffle()
{
    // Create 6 different piles
    std::vector<Card*> d1;
    std::vector<Card*> d2;
    std::vector<Card*> d3;
    std::vector<Card*> d4;
    std::vector<Card*> d5;
    std::vector<Card*> d6;

    // Counter
    int i = 0;
    // Deal cards to the six piles
    for(Card* c : deck)
    {
        if(i == 0)
        {
            d1.push_back(c);
            i++;
        }
        else if(i == 1)
        {
            d2.push_back(c);
            i++;
        }
        else if(i == 2)
        {
            d3.push_back(c);
            i++;
        }
        else if(i == 3)
        {
            d4.push_back(c);
            i++;
        }
        else if(i == 4)
        {
            d5.push_back(c);
            i++;
        }
        else if(i == 5)
        {
            d6.push_back(c);
            i = 0;
        }
    }
    // Clear the deck
    deck.erase(deck.begin(), deck.end());

    // Take a random card from each of the six piles and push them onto the deck
    while(!d1.empty() || !d2.empty() || !d3.empty() || !d4.empty() || !d5.empty() || !d6.empty())
    {
        if(!d1.empty())
        {
            int c = (rand() + time(0)) % d1.size();
            deck.push_back(d1[c]);
            d1.erase(d1.begin() + c);
        }
        if(!d2.empty())
        {
            int c = (rand() + time(0)) % d2.size();
            deck.push_back(d2[c]);
            d2.erase(d2.begin() + c);
        }
        if(!d3.empty())
        {
            int c = (rand() + time(0)) % d3.size();
            deck.push_back(d3[c]);
            d3.erase(d3.begin() + c);
        }
        if(!d4.empty())
        {
            int c = (rand() + time(0)) % d4.size();
            deck.push_back(d4[c]);
            d4.erase(d4.begin() + c);
        }
        if(!d5.empty())
        {
            int c = (rand() + time(0)) % d5.size();
            deck.push_back(d5[c]);
            d5.erase(d5.begin() + c);
        }
        if(!d6.empty())
        {
            int c = (rand() + time(0)) % d6.size();
            deck.push_back(d6[c]);
            d6.erase(d6.begin() + c);
        }
    }
}

Card* Deck::DealCard()
{
    // Dealing takes from the bottom of the deck
    Card* card = deck.back();
    deck.pop_back();
    return card;
}
