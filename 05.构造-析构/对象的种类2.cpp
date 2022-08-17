#include"c1test.h"
static C1 tst3(50);//虽然同名，但是能分开，即static作用域仅在一个源文件中，不同源文件不会使用


C1 tst2(40);//不是static 是全局变量 作用在所有源文件中 会出现重命名

C1* Ptst2 = &tst3;