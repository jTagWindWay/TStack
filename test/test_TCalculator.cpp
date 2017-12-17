#include "..\TStack\TCalculator.h"
#include "..\TStack\TCalculator.cpp"

#include "gtest.h"
#include <iostream>
 
TEST(TCalculator, can_create_TCalculator)
{
	TCalculator TCR;
	ASSERT_NO_THROW(TCR);
}

TEST(TCalculator, can_setInfix_with_non_equal_count_brakets_TCalculator)
{
	TCalculator TCR;
	ASSERT_ANY_THROW(TCR.setInfix(")((2+(2-3+1))"));
}

TEST(TCalculator, can_setInfix_with_equal_count_brakets_TCalculator)
{
	TCalculator TCR;
	ASSERT_NO_THROW(TCR.setInfix("((2+(2-3+1)))"));
}

TEST(TCalculator, can_setInfix_void_TCalculator)
{
	TCalculator TCR;
	ASSERT_NO_THROW(TCR.setInfix(""));
}

TEST(TCalculator, right_postfix_setInfix_TCalculator)
{
	TCalculator TCR;
	TCR.setInfix("3+2");
	TCR.toPostfix();
	string tmp;
	tmp = ("03 2+");
	ASSERT_EQ(TCR.GetPostfix(), tmp);
}

TEST(TCalculator, can_toPostfix_empty_string_TCalculator)
{
	TCalculator TCR;
	TCR.setInfix("");
	ASSERT_NO_THROW( TCR.toPostfix());
}

TEST(TCalculator, can_toPostfix_string_with_equal_brackets_TCalculator)
{
	TCalculator TCR;
	TCR.setInfix("(1+2+(3-4)+5)");
	ASSERT_NO_THROW(TCR.toPostfix());
}

TEST(TCalculator, right_Calculation_TCalculator)
{
	TCalculator TCR;
	TCR.setInfix("3+2");
	TCR.toPostfix();
	ASSERT_EQ(TCR.Calculation(), 5);
}

TEST(TCalculator, right_otrizateliniy_Calculation_TCalculator)
{
	TCalculator TCR;
	TCR.setInfix("-3+2");
	TCR.toPostfix();
	ASSERT_EQ(TCR.Calculation(), -1);
}

TEST(TCalculator, minus_right_Calculation_TCalculator)
{
	TCalculator TCR;
	TCR.setInfix("-(-(2-(3+2)))");
	TCR.toPostfix();
	ASSERT_EQ(TCR.Calculation(), -3);
}