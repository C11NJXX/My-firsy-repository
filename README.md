# My-firsy-repository
This is my  first repository on github ~ hello world ~
## 2023.1.4
I'm learning **cpp** at present~  
keep on learning~ :blush:   
I'm going to uplode my project which is **meaningful** on this github repository(e.g. a complete project)  
and the rest of my code(**when studying**) will be uploded to **my gitee repositories**   
Click here-->[**My gitee repository**](https://gitee.com/C-11nJxxs-web/study)  
## 2023.1.5
今天更加理解了**列表初始化**的用法，体会到了列表初始化在对象组合的构造函数初始化中的作用和妙处，还学习了**对象组合**（**composition**)中的一些细节问题
除此之外还学习了**继承**  
在继承中，子类的declaration中可以直接调用和访问父类中的public和protected中的成员函数和成员变量，但是不能直接访问private中的成员，但是如果父辈在自己的protected函数中
使用了自己private里面的成员，那么在子类使用父类protected中的成员时，就可以间接的访问到本不可以访问的父类中private的一部分数据，这是我感觉在coding中很有意思的一个part  
同时在学习过程中我有一个疑惑，现在也解决了，就是子类在main函数中生成一个对象，这个对象是不能直接调用父辈的protected中的成员函数或是访问其中的成员变量，尽管子类继承了父类
继承仅仅发生在子类的declaration中，与生成的对象无关，只能是在子类的declaration中的public中使用函数调用访问父类提供的protected才可以~  
🐇Click here-->[**Today's code on gitee**](https://gitee.com/C-11nJxxs-web/study/tree/master/cpp/2023.1.5)
## 2023.1.6
今天学习了1、函数重载overload，以及与之相关的默认参数default arguments（一般不使用，不便于程序的阅读）  
2、内联函数inline，本质上是以空间换取时间（理解还不够细致，因为没学数据结构，不了解堆stack的一些知识点），与c语言中的宏还是不同的，inline可以检查参数，更加聪明吧hh  
3、const的一些知识点，令我比较不好接受的是:``const int* p;``和``int* const p``之间的一些区别，从右往左理解，**前者**：p是一个指针，所指向的类型是一个const int，但是这里
有一个误区，就是所指的那个int型变量，他自己是可以改变的，只是说不能通过p指针来修改int的值，并不是说int本身是一个const **后者**：p是一个被const修饰的指针，所指向的类型是int，  
说明这个p指针只能指向固定的一个变量，所存储的地址是固定的；还有一个有意思的代码：  
```
int i;
const int ci = 3;
int* ip = &i; //ok，变量i可以被修改，指针p也具有修改的能力
int*ip = &ci;//error，变量ci不能被修改，但是指针p具有修改的能力，不能保证p不会去修改ci的值
const int* cip = &i;//也ok，i可以被修改，指针cip不具备修改的能力，但是不影响二者和谐相处
const int* cip = &ci;//ok，ci不能改，cip没能力改，天凑一对~  
```
3、引用reference 学习后我了解到cpp中的reference本质上就是一个`type *const p = q`，p是一个被初始化成q的type型引用；表面上看起来就是一个别名，但是说有意思点就是固定的“婚姻”，p永远和q绑定，不能再去指向别人，这也是和指针的不同之一。  
reference还可以用于函数中的参数和返回值，作为参数可以美观代码风格，少了很多* 比如：  
```
void swap(int&x,int&y);
swap(a,b);
```
这里面相当于x被初始化成了a的整型引用，y被初始化成了b的整型引用  
在reference作为函数的返回值时，可以将返回值作为左值进行一些赋值操作  
4、向上造型upcast，将子类当作父类看待，自动忽略子类中多出来的东西（在多态性polymorphism（未学:cry:)有用）通过指针和引用都可以创建一个向上造型  
比如创建一个父类类型的指针p，将子类类型的一个对象的地址传给这个指针  
创建一个父类类型的引用p，让这个p初始化为子类对象的**父类**引用  

