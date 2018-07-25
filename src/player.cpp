#include "../include/player.h"

Player::Player()
{
    // Initialize the players group count to 0
    groupCount = 0;
}

Player::~Player()
{
    //dtor
}

Card* Player::DrawCard(Deck* deck)
{
    // Draw a card and push it to the back of players hand
    Card* newCard = deck->DealCard();
    hand.push_back(newCard);
    // return just to be able to display the card
    return newCard;
}

bool Player::CheckForCard(Card* card)
{
    // See if given card is in the players hand
    for(Card* c : hand)
    {
        if(c->GetFace() == card->GetFace())
        {
            return true;
        }
    }
    return false;
}

void Player::AddCard(Card* card)
{
    // Add the card to players hand
    hand.push_back(card);
}

std::vector<Card*> Player::RemoveCard(Card* card)
{
    // Get all cards matching the given card
    std::vector<Card*> cards;
    size_t i = 0;
    while (i < hand.size())
    {
        if(hand[i]->GetFace() == card->GetFace())
        {
            Card* c = hand.at(i);
            cards.push_back(c);
        }
        i++;
    }

    // Remove all the given cards from the plaers hand
    // I did it this way to avoid the error then removing the
    // card from the hand and changing the size of the
    // hand.size int the while loop
    std::vector<Card*> tempHand;
    for(Card* c : hand)
    {
        if(card->GetFace() != c->GetFace())
        {
            tempHand.push_back(c);
        }
    }
    hand = tempHand;

    return cards;
}

