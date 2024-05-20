#include "factory.hpp"

int main()
{
    std::unique_ptr<factory<Blade>> character_factory = std::make_unique<factory<Blade>>();
    auto character_1 = character_factory->create_object_pointer();

    return 0;
}