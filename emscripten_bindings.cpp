#include <iostream>
#include <string>
#include <vector>
#include <meta>
#include <ranges>

constexpr auto MAX_ELEMENTS = 20;
std::string toLowerCamelCase(std::string_view input){
    std::string result;
    bool capitalize = false;
    for(const auto letter : input){
        if(letter == '_'){
            capitalize = true;
        }else{
            if(capitalize){
                result.push_back(std::toupper(letter));
                capitalize = false;
            }else{
                result.push_back(letter);
            }
        }
    }
    return result;
}

struct BasicBlock{};
struct Link{};
struct Point{};

class Canvas
{
public:
    Canvas() = default;
    void add_block(float x, float y, float width, float height);
    std::vector<BasicBlock> get_blocks();
    const BasicBlock &get_block(const std::string &id) const;
    void set_block_position(const std::string &id, float x, float y);
    std::string get_selected_block_id(float x, float y) const;
    void delete_block(const std::string &id);
    std::vector<Link> get_links() const;
    void add_link(const std::string &source, const std::string &target, Point source_point, Point target_point);
    std::string get_selected_link_id(float x, float y) const;
    void delete_link(const std::string &id);
};

consteval std::string_view class_name()
{
    return std::meta::identifier_of(^^Canvas);
}

consteval auto constructors()
{
    std::array<std::optional<std::string_view>, MAX_ELEMENTS> constructors;
    const std::vector<std::string_view> constructors_view = std::meta::members_of(^^Canvas, std::meta::access_context::current())
        | std::views::filter([](std::meta::info member){ return std::meta::is_constructor(member) && std::meta::is_user_declared(member); })
        | std::views::transform([](std::meta::info constructor){ return std::meta::identifier_of(^^Canvas); })
        | std::ranges::to<std::vector>();
    for (int i = 0; auto const &constructor : constructors_view)
    {
        constructors[i++] = constructor;
    }
    return constructors;
}

consteval auto members()
{
    std::array<std::optional<std::string_view>, MAX_ELEMENTS> members;
    const std::vector<std::string_view> members_view = std::meta::members_of(^^Canvas, std::meta::access_context::current())
        | std::views::filter([](std::meta::info member){ return !std::meta::is_special_member_function(member) && !std::meta::is_operator_function(member); })
        | std::views::transform([](std::meta::info member){ return std::meta::identifier_of(member); })
        | std::ranges::to<std::vector>();
    for (int i = 0; auto const &member : members_view)
    {
        members[i++] = member;
    }
    return members;
}

int main()
{
    std::cout << "EMSCRIPTEN_BINDINGS(canvaslib) {\n";
    std::cout << "  emscripten::class_<" << class_name() << ">(\"" << class_name() << "\")";
    for (auto elem : constructors())
    {
        if (elem.has_value())
            std::cout << "\n    .constructor<>()";
    }
    for (auto elem : members())
    {
        if (elem.has_value())
            std::cout << "\n    .function(\"" << toLowerCamelCase(elem.value()) << "\", " << "&" << class_name() << "::" << elem.value() << ")";
    }
    std::cout << ";\n}";
}
