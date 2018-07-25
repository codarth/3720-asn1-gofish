#ifndef DECK_H
#define DECK_H

#include <string>
#include <vector>
#include "card.h"

/**< deck.h */
class Deck
{
public:
    /** Default constructor */
    Deck();
    /** Default destructor */
    virtual ~Deck();

    /** \brief Shuffle deck
     * \return Error code
     */
    void Shuffle();

    /** \brief Deal a card
     * \return Error code
     *//**< card.h */

    Card* DealCard();

    /** \brief Access deck
     * \return The current deck
     */
    std::vector<Card*> GetDeck()
    {
        return deck;
    }

    /** \brief Access currentCard
     * \return The current value of currentCard
     */
    Card* GetCurrentCard()
    {
        return currentCard;
    }

    /** \brief Set currentCard
     * \param val New value to set
     */
    void SetCurrentCard(Card* val)
    {
        currentCard = val;
    }

private:
    std::vector<Card*> deck; //!< Member variable "deck"
    Card* currentCard; //!< Member variable "currentCard"
};

#endif // DECK_H
