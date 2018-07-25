#include <gtest/gtest.h>
#include "../include/player.h"
#include "../include/deck.h"

struct PlayerTest : public testing::Test
{
    Player* p;
    Deck* d;
    Card* c;

    void SetUp()
    {
        p = new Player();
        d = new Deck();
        c = new Card();
        c->SetFace("Ace");
        c->SetSuit("Clubs");
    }
    void TearDown()
    {
        delete p;
        delete d;
        delete c;
    }
};

TEST_F(PlayerTest, NameTest)
{
    p->SetName("Ed");
    ASSERT_EQ(p->GetName(), "Ed");
}

TEST_F(PlayerTest, DrawCardTest)
{
    c = p->DrawCard(d);
    ASSERT_EQ(p->GetHand().size(), 1);
    p->RemoveCard(c);
    ASSERT_EQ(p->GetHand().size(), 0);
}

TEST_F(PlayerTest, AddCardTest)
{
    p->AddCard(c);
    ASSERT_TRUE(p->CheckForCard(c));
}

TEST_F(PlayerTest, GroupTest)
{
    p->IncrementGroupCount();
    ASSERT_EQ(p->GetGroupCount(), 1);
}
