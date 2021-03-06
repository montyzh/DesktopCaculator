#ifndef CACULATORDEC_H
#define CACULATORDEC_H

#include <QWidget>
#include <QString>
#include <QQueue>
class CaculatorUi;

class CaculatorDec
{
public:
    friend class CaculatorUi;
    CaculatorDec();   //构造函数
    ~CaculatorDec();    //析构函数
   // QString m_exp;      //用于保存输入的字符串
    float m_result;   //保存计算的结果

    bool isDigitOrDot(QChar c);  //判断字符是否为数字或是小数点
    bool isSymbol(QChar c);//判断字符是否为符号
    bool isSign(QChar c);//判断字符是否为正负号
    bool isNumber(QString s);//判断字符是否为数字
    bool isOperator(QString s);//判断字符是否为操作符
    bool isLeft(QString s);//判断字符是否为左括号
    bool isRight(QString s);//判断字符是否为右括号
    int priority(QString s);//返回操作符号的权值

    QQueue<QString> split(const QString& exp);//表达式拆分函数；将拆分的结果保存在队列中
    QQueue<QString> change(const QQueue<QString>& z);//中缀表达式转后缀表达式
    float h_caculate(const QQueue<QString>& c);     //将后缀表达式计算出结果
    float caculate(float a,float b,QString& o);

};

#endif // CACULATORDEC_H
