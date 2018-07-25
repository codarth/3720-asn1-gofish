#ifndef CARD_H
#define CARD_H

#include <string>

/**< card.h */
class Card
{
public:
    /** Default constructor */
    Card();
    /** Default constructor */
    Card(std::string face, std::string suit);
    /** Default destructor */
    ~Card();

    /** \brief Access suit
     * \return The current value of suit
     */
    std::string GetSuit()
    {
        return suit;
    }

    /** \brief Set suit
     * \param s std::string
     * \return void
     */
    void SetSuit(std::string s)
    {
        suit = s;
    }

    /** \brief Access face
     * \return The current value of face
     */
    std::string GetFace()
    {
        return face;
    }

    /** \brief Set face
     * \param f std::string
     * \return void
     */
    void SetFace(std::string f)
    {
        face = f;
    }

private:
    std::string face; //!< Member variable "face"
    std::string suit; //!< Member variable "suit"
};

#endif // CARD_H
