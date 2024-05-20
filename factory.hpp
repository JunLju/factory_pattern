#include <memory>
#include <string>
enum class Trait
{
    GUARD,
    CASTER,
    DEFENDER,
    SPECIALIST,
    SNIPER
};

class character
{

public:
    virtual ~character() {};
    virtual void initial_stats(int atk, int def, int crit) = 0;
    virtual void initial_traits(std::string trait_desc) = 0;
};

class Blade : character
{
public:
    int m_atk;
    int m_def;
    int m_crit;
    std::string m_trait;

    void initial_stats(int atk, int def, int crit) override
    {
        m_atk = atk;
        m_def = def;
        m_crit = crit;
    }

    void initial_trait(std::string trait_desc)
    {
        m_trait = std::move(trait_desc);
    }
};

template <typename type>
class factory
{
public:
    std::unique_ptr<type> create_object_pointer()
    {
        return std::make_unique<type>();
    }
};
