#include "gtest/gtest.h"
#include "../include/card.h"

struct CardTest : public testing::Test
{
    Card* c;
    void SetUp()
    {
        c = new Card;
    }
    void TearDown()
    {
        delete c;
    }
};

TEST_F(CardTest, FaceTest)
{
    c->SetFace("Ace");
    ASSERT_EQ(c->GetFace(), "Ace");
}

TEST_F(CardTest, SuitTest)
{
    c->SetSuit("Clubs");
    ASSERT_EQ(c->GetSuit(), "Clubs");
}

