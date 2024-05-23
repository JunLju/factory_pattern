#include "factory.hpp"

int main()
{
    factory character_factory{};
    auto character_1 = character_factory.create_character<blade>("Attack all blocked enemies");
    auto character_2 = character_factory.create_character<surtr>("Attack deals art damage");

    return 0;
}