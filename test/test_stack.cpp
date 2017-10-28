#include "TStack.h"

#include "gtest.h"

TEST(TStack, can_create_bitfield_with_positive_length)
{
  ASSERT_NO_THROW(TBitField bf(3));
}


