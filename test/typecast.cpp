#include <iostream>
using namespace std;


void test02(){

    //-----------------------------
    //float指针相关的强制转换
    //不同类型的指针变量，在内存中本质上都是一样的，都是一个整数值的地址值，一般表现为8位十六进制数
    //不同的类型表示地址指向值的解释类型，及该变量在内存中占据字节的数目
    //地址值可以强转为其他类型，但将地址指向值解释为其他类型容易出错，如float解释为int
    //常量直接赋值给指针是不可以的，必须强转为合法地址，另外由于内存地址是整型值，因此浮点型数据不能成为合法地址
    //-----------------------------
    float a = 10.1;
    float *p_ = &a;

    cout << typeid(p_).name() << endl; //float*
    cout << p_ << endl; //地址，8位十六进制数字（32位二进制数字）
    cout << *p_ << endl; //地址指向的数据，同样为32位二进制数字，按照float进行解释，得到10.1

    //cout << (float)p_ << endl; //不允许将地址直接转化为浮点型，但可以间接修改
    /*
     * cout << (char)p_ << endl; //直接将地址转化为字符型
    cout << (int)p_ << endl; //直接将地址转化为十进制整型
    */

    cout << (int*)p_ << endl; //将地址float *类型转换为int*，后面的解释会发生变化，但地址的十六进制数字不会发生变化
    cout << *(int*)p_ << endl; //地址指向的数据，会按照int型进行解释，得到1092721050
    cout << (int&)(*p_) << endl; //同样的将数据解释为int型，得到1092721050, 则是告诉编译器将数据看成int对待

    cout << *(int*)&p_ << endl; //将地址（8位十六进制数字）转换为十进制，先取p_的地址，然后按照int进行解释
    cout << *(float*)&p_ << endl; //将地址（8位十六进制数字）转换为float，先取p_的地址，然后按照float进行解释
    cout << *(float*)p_ << endl; //输出10.1

    cout << (char*)p_ << endl; //将地址float*类型转换为char*类型，其实地址的十六进制数字不会发生变化，但<<会直接输出指向的字符串
    cout << static_cast<const void *>(p_) << endl; //可以这样输出转换为char*后的地址
    cout << *(char*)&p_ << endl; //将地址（8位十六进制数字）转换为char，先取p_的地址，然后按照char进行解释
    cout << *(char*)p_ << endl; //将数值型数据按照字符类型，这里无法将float解释为char型，但是int型默认可以转换为ASCII码,解释为char型
}

int main(int argc, char **argv)
{
    test02();

    return 0;
}
