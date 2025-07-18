# Reflection playground

This is a repository to play around with C++ reflection that was voted into the standard for C++26:

- [P2996 - Reflection for C++26 (main paper)](https://wg21.link/p2996)
- [P3394 - Annotations for reflection](https://wg21.link/p3394)
- [P3293 - Splicing a base class subobject](https://wg21.link/p3293)
- [P3491 - define_static_{string,object,array}](https://wg21.link/p3491)
- [P1306 - Expansion statements](https://wg21.link/p1306)
- [P3096 - Function parameter reflection in reflection for C++26](https://wg21.link/p3096)
- [P3560 - Error handling in reflection](https://wg21.link/p3560)

## Examples

- [Print all elements in a given namespace](./elements_in_namespace.cpp) (Compiler explorer: [Clang](https://godbolt.org/z/6dbjYecEx))
- [Print all classes in a given namespace](./classes_in_namespace.cpp) (Compiler explorer: [Clang](https://godbolt.org/z/9b8hK3d59))
- [Generate the binding code for emscripten for a class](./emscripten_bindings.cpp) (Compiler explorer: [Clang](https://godbolt.org/z/vdWMqcb89))
- [Generate the binding code for emscripten for a class (naïve approach not working)](./emscripten_bindings.cpp) (Compiler explorer: [Clang](https://godbolt.org/z/dr1Kczb1n))
