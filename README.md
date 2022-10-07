# CDP
使用 C++ Template (CRTP) 实现常用的设计模式

---

# Set up
该项目使用 cmake 构建

```cpp
#include <CDP/Singleton/Singleton.h>
#include <CDP/Visitor/Visitor.h>
#include <CDP/Visitor/General_Visitor.h>
```

---

# TEST

```shell
mkdir build && cd build

cmake ..

cmake --build .

./Test/Test.exe

```

---

# Principle
*设计模式基于六大原则*
* 开闭原则 : 对扩展开放，对修改关闭
* 单一职责原则
* 里氏替换原则
* 依赖倒置原则
* 迪米特法则
* 接口隔离原则
