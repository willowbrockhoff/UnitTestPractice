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

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}

TEST(PasswordTest, two_leding_letters)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aab"));
}
TEST(PasswordTest, no_repeats)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("acab"));
}
TEST(PasswordTest, leading_number)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("11234"));
}
TEST(PasswordTest, case_sensitive)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("AaAaAa"));
}
TEST(PasswordTest, empty)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters(""));
}
TEST(PasswordTest, symbols)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("$$$#"));
}



//mixed_case_tests

TEST(PasswordTest, mixed_case)
{
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("Abc"));
}

TEST(PasswordTest, all_lowercase)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("abc"));
}

TEST(PasswordTest, all_uppercase)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("ABC"));
}

TEST(PasswordTest, empty)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case(""));
}

TEST(PasswordTest, symbols_and_numbers)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("12$#"));
}