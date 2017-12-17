#include "..\TStack\TStack.h"

#include "gtest.h"

TEST(TStack, can_create_TStack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> ts(3));                    //ASSERT_NO_THROW (Œ∆»ƒ¿Õ»≈, ◊“Œ »— Àﬁ◊≈Õ»≈ Õ≈ ¬€À≈«≈“
}                                                       //ASSER


TEST(TStack, can_create_TStack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> ts(-3));
}

TEST(TStack, vzyatie_is_pustogo_TStack)
{
	TStack<int>ts(1);
	ASSERT_ANY_THROW(ts.Pop());
}

TEST(TStack, vzyatie_verhnego_elementa_is_TStack)
{
	TStack<int>ts(2);
	ts.Push(1);
	ts.Push(2);
	ASSERT_EQ(ts.Top(),2);
}

TEST(TStack, ubrat_verhniy_element_is_TStack)
{
	TStack<int>ts(2);
	ts.Push(1);
	ts.Push(2);
	ts.Pop();
	ASSERT_EQ(ts.Top(),1);
}

TEST(TStack, vzyatie_verhnego_elementa_is_pystogo_TStack)
{
	TStack<int>ts(0);
	ASSERT_ANY_THROW(ts.Top());
}

TEST(TStack, ybrat_element_is_pystogo_TStack)
{
	TStack<int>ts(0);
	ASSERT_ANY_THROW(ts.Pop());
}

TEST(TStack, can_create_copied_TStack)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, copied_TStack_is_equal_to_source_one)
{
	TStack <int> m(4);
	m.Push(1);
	TStack <int> m1(m);
	int a = m.Pop();
	int b = m1.Pop();
	EXPECT_EQ(a, b);
}

TEST(TStack, copied_TStack_has_its_own_memory)
{
	TStack<int> m1(4);
	TStack<int> m2(4);

	m1.Push(1);
	m1.Push(2);

	m2.Push(1);
	m2.Push(2);
	EXPECT_FALSE(&m1 == &m2);
}