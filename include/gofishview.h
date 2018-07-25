#ifndef GOFISHVIEW_H
#define GOFISHVIEW_H

#include "player.h"

/**< gofishview.h */
class GoFishView
{
public:
    /** Default constructor */
    GoFishView();
    /** Default destructor */
    virtual ~GoFishView();

    /** \brief How many are playing
     * \return number of players
     */
    int GetNumberOfPlayers();

    /** \brief Ask for a name for the player
     * \param i int
     * \return name of player
     */
    std::string SetName(int i);

    /** \brief Announce who's turn it is
     * \param player Player*
     * \return void
     */
    void AnnouncePlayersTurn(Player* player);

    /** \brief Who to choose from
     * \return name of opponent
     */
    std::string SelectOpponent();

    /** \brief Print out current players hand
     * \param player Player*
     * \return void
     */
    void PrintHand(Player* player);

    /** \brief What card to guess
     * \return Card face value
     */
    std::string GuessACard();

    /** \brief You guessed poorly
     * \return void
     */
    void GoFish();

    /** \brief Show what card you drew
     * \param card Card*
     * \return void
     */
    void YouDraw(Card* card);

    /** \brief You chose wisely
     *  Shows how many card received
     * \param n size_t
     * \return void
     */
    void GoodGuess(size_t n);

    /** \brief You can't pick a card from yourself
     * \return void
     */
    void CantPickYourself();

    /** \brief Invalid player entered
     * \return void
     */
    void NotValidPlayer();

    /** \brief Invalid card played
     * \return void
     */
    void InvalidCard();

    /** \brief Show results on end game
     * \param players std::vector<Player*>
     * \return void
     */
    void Results(std::vector<Player*> players);

};

#endif // GOFISHVIEW_H
