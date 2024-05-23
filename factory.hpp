#include <memory>
#include <string>
#include <iostream>

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
};

class surtr : character
{
public:
    explicit surtr(std::string trait_desc)
        : m_trait_desc(std::move(trait_desc))
    {
        std::cout << m_trait_desc << "\n";
    }

    int m_atk;
    int m_def;
    int m_crit;
    std::string m_trait_desc;
    Trait m_trait{Trait::GUARD};

    void initial_stats(int atk, int def, int crit) override
    {
        m_atk = atk;
        m_def = def;
        m_crit = crit;
    }
};

class blade : character
{
public:
    explicit blade(std::string trait_desc) : m_trait_desc(std::move(trait_desc))
    {
        std::cout << m_trait_desc << "\n";
    }

    int m_atk;
    int m_def;
    int m_crit;
    std::string m_trait_desc;
    Trait m_trait{Trait::GUARD};

    void initial_stats(int atk, int def, int crit) override
    {
        m_atk = atk;
        m_def = def;
        m_crit = crit;
    }

    void initial_trait(std::string trait_desc)
    {
        m_trait_desc = std::move(trait_desc);
    }
};

class factory
{
public:
    template <typename type>
    std::unique_ptr<type> create_character(std::string trait_desc)
    {
        return std::make_unique<type>(trait_desc);
    }
};
