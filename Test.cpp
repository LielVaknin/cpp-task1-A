#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;
#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // Straw Hat
    CHECK(nospaces(snowman(21111111)) == nospaces("___\n.....\n(.,.)\n<( : )>\n( : )")); // Mexican Hat
    CHECK(nospaces(snowman(31111111)) == nospaces("_\n/_\\\n(.,.)\n<( : )>\n( : )")); // Fez
    CHECK(nospaces(snowman(41111111)) == nospaces("___\n(_*_)\n(.,.)\n<( : )>\n( : )")); // Russian Hat

    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // Normal nose
    CHECK(nospaces(snowman(12111111)) == nospaces("_===_\n(...)\n<( : )>\n( : )")); // Dot nose
    CHECK(nospaces(snowman(13111111)) == nospaces("_===_\n(._.)\n<( : )>\n( : )")); // Line nose
    CHECK(nospaces(snowman(14111111)) == nospaces("_===_\n(. .)\n<( : )>\n( : )")); // None

    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // Left eye - Dot
    CHECK(nospaces(snowman(11211111)) == nospaces("_===_\n(o,.)\n<( : )>\n( : )")); // Left eye - Bigger Dot
    CHECK(nospaces(snowman(11311111)) == nospaces("_===_\n(O,.)\n<( : )>\n( : )")); // Left eye - Biggest Dot
    CHECK(nospaces(snowman(11411111)) == nospaces("_===_\n(-,.)\n<( : )>\n( : )")); // Left eye - Closed

    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // Right eye - Dot
    CHECK(nospaces(snowman(11121111)) == nospaces("_===_\n(.,o)\n<( : )>\n( : )")); // Right eye - Bigger Dot
    CHECK(nospaces(snowman(11131111)) == nospaces("_===_\n(.,O)\n<( : )>\n( : )")); // Right eye - Biggest Dot
    CHECK(nospaces(snowman(11141111)) == nospaces("_===_\n(.,-)\n<( : )>\n( : )")); // Right eye - Closed

    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // Normal left Arm
    CHECK(nospaces(snowman(11112111)) == nospaces("_===_\n(.,.)\n\\( : )>\n( : )")); // Upwards left Arm
    CHECK(nospaces(snowman(11113111)) == nospaces("_===_\n(.,.)\n/( : )\n( : )")); // Downwards left Arm
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n ( : )>\n( : )")); // None

    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // Normal Right Arm
    CHECK(nospaces(snowman(11111211)) == nospaces("_===_\n(.,.)\n<( : )/\n( : )")); // Upwards Right Arm
    CHECK(nospaces(snowman(11111311)) == nospaces("_===_\n(.,.)\n<( : )\\\n( : )")); // Downwards Right Arm
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : ) \n( : )")); // None

    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // Torso - Buttons
    CHECK(nospaces(snowman(11111121)) == nospaces("_===_\n(.,.)\n<(] [)>\n( : )")); // Torso - Vest
    CHECK(nospaces(snowman(11111131)) == nospaces("_===_\n(.,.)\n<(> <)>\n( : )")); // Torso - Inward Arms
    CHECK(nospaces(snowman(11111141)) == nospaces("_===_\n(.,.)\n<(   )>\n( : )")); // None

    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // Base - Buttons
    CHECK(nospaces(snowman(11111112)) == nospaces("_===_\n(.,.)\n<( : )>\n(" ")")); // Base - Feet
    CHECK(nospaces(snowman(11111113)) == nospaces("_===_\n(.,.)\n<( : )>\n(___)")); // Base - Flat
    CHECK(nospaces(snowman(11111114)) == nospaces("_===_\n(.,.)\n<( : )>\n(   )")); // None
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(2)); // Input with less than 8 digits - 1 digit
    CHECK_THROWS(snowman(22)); // Input with less than 8 digits - 2 digits
    CHECK_THROWS(snowman(222)); // Input with less than 8 digits - 3 digits
    CHECK_THROWS(snowman(2222)); // Input with less than 8 digits - 4 digits
    CHECK_THROWS(snowman(22222)); // Input with less than 8 digits - 5 digits
    CHECK_THROWS(snowman(222222)); // Input with less than 8 digits - 6 digits
    CHECK_THROWS(snowman(2222222)); // Input with less than 8 digits - 7 digits
    CHECK_THROWS(snowman(222222222)); // input with more than 8 digits - 9 digits
    CHECK_THROWS(snowman(-98675678)); // Negative number with illegal digits
    CHECK_THROWS(snowman(-12121414)); // Negative number with legal digits
    CHECK_THROWS(snowman(-333)); // Negative number with less than 8 digits
    CHECK_THROWS(snowman(51111111)); // Input with illegal first digit
    CHECK_THROWS(snowman(16111111)); // Input with illegal second digit
    CHECK_THROWS(snowman(11711111)); // Input with illegal third digit
    CHECK_THROWS(snowman(11181111)); // Input with illegal fourth digit
    CHECK_THROWS(snowman(11119111)); // Input with illegal fifth digit
    CHECK_THROWS(snowman(11111811)); // Input with illegal Sixth digit
    CHECK_THROWS(snowman(11111171)); // Input with illegal Seventh digit
    CHECK_THROWS(snowman(11111116)); // Input with illegal Eighth digit
}
