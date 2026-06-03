#include "catch_amalgamated.hpp"
#include "List.h"

TEST_CASE("Check Empty", "[List]")
{
    List list;

    SECTION("empty after creation")
    {
        CHECK(list.Empty());
    }

    SECTION("non empty after PushFront")
    {
        list.PushFront(1);
        CHECK(!list.Empty());
    }
}

TEST_CASE("Check Size", "[List]")
{
    List list;

    SECTION("size is 0 after creation")
    {
        CHECK(list.Size() == 0);
    }

    SECTION("size is 1 after PushFront")
    {
        list.PushFront(1);
        CHECK(list.Size() == 1);
    }
}

TEST_CASE("Check Clear", "[List]")
{
    List list;
    list.PushFront(1);

    list.Clear();

    CHECK(list.Empty());
}
