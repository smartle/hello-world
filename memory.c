#include 
int quanju;//全局变量，全局区/静态区（static）
void fun(int f_jubu); //程序代码区
void main()
{
    int m_jubu;//栈区（stack）
    static int m_jingtai;//静态变量，全局区/静态区（static）
    char *m_zifum,*m_zifuc = "hello";//指针本身位于栈,指向字符串"hello",位于文字常量区
    void (*pfun)(int); //栈区（stack）
    pfun=&fun;
    m_zifum = (char *)malloc(sizeof(char)*10);//指针内容指向分配空间，位于堆区（heap）
    pfun(1);
    printf("&quanju   : %x/n",&quanju);//3.输出quanju: 404070
    printf("&m_jubu   : %x/n",&m_jubu);//4.输出m_jubu: 22ff74
    printf("&m_jingtai: %x/n",&m_jingtai);//5.输出m_jingtai: 404010
    printf("m_zifuc   : %x/n",m_zifuc);//6.输出m_zifuc: 403000
    printf("&m_zifuc  : %x/n",&m_zifuc);//7.输出m_zifuc: 22ff6c
    printf("m_zifum   : %x/n",m_zifum);//8.输出m_zifum: 3d24e0
    printf("&m_zifum  : %x/n",&m_zifum);//9.输出m_zifum: 22ff70
    printf("pfun      : %x/n",pfun);//10.输出pfun: 4013af
    printf("&pfun     : %x/n",&pfun);//11.输出pfun: 22ff68 
}
void fun(int f_jubu)//栈区（stack）,但是与主函数中m_jubu位于不同的栈
{
    static int f_jingtai;
    printf("&f_jingtai: %x/n",&f_jingtai);//1.输出f_jingtai: 404020
    printf("&f_jubu   : %x/n",&f_jubu);//2.输出f_jubu: 22ff40
}