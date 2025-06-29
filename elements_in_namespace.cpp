#include <array>
#include <iostream>
#include <meta>
#include <optional>

constexpr auto MAX_ELEMENTS = 100;
namespace foo
{
    class Class1
    {
    public:
        Class1() = default;
        auto method1(int, int) -> float;
        auto method2() -> void;
    };
    class Class2
    {
    public:
        Class2() = default;
        auto method1(int, int) -> float;
        auto method2() -> void;
    };
    class Class3
    {
    public:
        Class3() = default;
        auto method1(int, int) -> float;
        auto method2() -> void;
    };
    void function1();
}

consteval auto element_names_in_foo()
{
    constexpr auto namespace_info = ^^foo;
    std::array<std::optional<std::string_view>, MAX_ELEMENTS> classes;
    for (int i = 0; auto element : std::meta::members_of(namespace_info, std::meta::access_context::current()))
    {
        classes[i++] = std::meta::identifier_of(element);
    }
    return classes;
}

int main()
{
    for (auto elem : element_names_in_foo())
    {
        if (elem.has_value())
        {
            std::cout << elem.value() << "\n";
        }
    }
}
