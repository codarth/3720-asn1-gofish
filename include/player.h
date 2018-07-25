#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "deck.h"

/**< player.h */
class Player
{
public:
    /** Default constructor */
    Player();
    /** Default destructor */
    virtual ~Player();

    /** \brief Access name
     * \return The current value of name
     */
    std::string GetName()
    {
        return name;
    }

    /** \brief Set name
     * \param val New value to set
     */
    void SetName(std::string val)
    {
        name = val;
    }

    /** \brief Increase number of groups finished
     * \return void
     */
    void IncrementGroupCount()
    {
        groupCount++;
    }

    /** \brief Access groupCount
     * \return Number of groups aquired
     */
    unsigned GetGroupCount()
    {
        return groupCount;
    }

    /** \brief Access hand
     * \return The current value of hand
     */
    std::vector<Card*> GetHand()
    {
        return hand;
    }

    /** \brief Get a card from the deck
     * \param deck Deck*
     * \return void
     */
    Card* DrawCard(Deck* deck);

    /** \brief Look in hand for card
     * \param card Card*
     * \return bool
     */
    bool CheckForCard(Card* card);

    /** \brief Add card to hand
     * \param card Card*
     * \return void
     */
    void AddCard(Card* card);

    /** \brief Remove Card(s) from hand
     * \param card Card*
     * \return vector<Card*>
     */
    std::vector<Card*> RemoveCard(Card* card);

private:
    std::string name; /**< Member variable "name" */
    std::vector<Card*> hand; /**< Member variable "hand" */
    unsigned groupCount;    /**< Member variable "groupCount" */
};

#endif // PLAYER_H
