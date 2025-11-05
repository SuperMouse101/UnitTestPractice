/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, word_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("String");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("aac");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, four_letter_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZ");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, cap_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("aAA");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, spaces_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("S S S");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, newline_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("\n\n\n");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, newline_with_letters_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("SS\n");
	ASSERT_EQ(2, actual);
}