#include "catch_amalgamated.hpp"
#include "List.h"

TEST_CASE("PushBack", "[List]")
{
    List list;

    list.PushBack(101);

    REQUIRE(!list.Empty());
    int val = list.PopBack();
    REQUIRE(val == 101);
}

TEST_CASE("PushFront", "[List]")
{
    List list;

    list.PushFront(101);

    REQUIRE(!list.Empty());
    int val = list.PopFront();
    REQUIRE(val == 101);
}

TEST_CASE("PopFront", "[List]")
{
    List list;

    SECTION("empty list")
    {
        REQUIRE_THROWS_AS(
            list.PopFront(),
            std::runtime_error
        );
    }

    SECTION("nonempty list")
    {
        list.PushFront(101);

        int val = list.PopFront();

        CHECK(list.Empty());
        CHECK(val == 101);
    }
}

TEST_CASE("PopBack", "[List]")
{
    List list;

    SECTION("empty list")
    {
        REQUIRE_THROWS_AS(
            list.PopBack(),
            std::runtime_error
        );
    }

    SECTION("nonempty list")
    {
        list.PushBack(101);

        int val = list.PopBack();

        CHECK(list.Empty());
        CHECK(val == 101);
    }
}
