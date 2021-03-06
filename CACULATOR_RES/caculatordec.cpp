#include "caculatordec.h"
#include <QDebug>
#include <QString>
#include <QStack>
CaculatorDec::CaculatorDec()
{
   // m_exp="";
    m_result=0;

}


CaculatorDec::~CaculatorDec(){}

//*********************
//以下是判断字符的函数
//*********************
bool CaculatorDec::isDigitOrDot(QChar c)
{
    return ((c>='0')&&(c<='9')||(c=='.'));
}


bool CaculatorDec::isSymbol(QChar c)
{


    return (isOperator(c)||(c=='(')||(c==')'));

}

bool CaculatorDec::isSign(QChar c)
{

    return (c=='+')||(c=='-');


}

bool CaculatorDec::isNumber(QString s)
{
    bool ret = false;
    s.toDouble(&ret);
    return ret;
}


bool CaculatorDec::isOperator(QString s)
{


    return (s=="+")||(s=="-")||(s=="*")|| (s=="/");
}

bool CaculatorDec::isLeft(QString s)
{
    return (s=="(");


}

bool CaculatorDec::isRight(QString s)
{

    return (s==")");
}

int CaculatorDec::priority(QString s)
{

    int ret = 3;
    if ((s=="+")||(s=="-"))
    {

        ret=1;
    }

    if ((s=="*")|| (s=="/"))
    {

        ret=2;
    }
    return ret;
}
//*********************

//*********************


 QQueue<QString> CaculatorDec::split(const QString& exp)
 {

     QQueue<QString> ret;   //返回的队列
     QString num = "";      //定义变量用于拆分下数字的累计
     QString pre = "";      //用于存放前一个字符，便于后面判断符号是否为正负号
     for(int i=0;i<exp.length();i++)//变量表达式字符串
     {
         if(isDigitOrDot(exp[i]))//是否为数字或是小数点，如果是就累计在num中
         {

             num+=exp[i];
             pre=exp[i];        //保存前一字符
         }
         else if(isSymbol(exp[i]))  //判断是否为符号
         {
             if(!num.isEmpty())  //判断num是否为空，一般不为空
             {
                 ret.enqueue(num);  //是符号就把前面累加的num保存在队列中去
                 num.clear();       //清空以便于保存后面的操作数
             }
             if(isSign(exp[i])&&((pre=="")||(pre=="("||isOperator(pre))))
             //判断符号是否是正负号，如果是正负号那就把此保存在num中，
                 //因为正负号也是数字的一部分
             {
                 num+=exp[i];

             }
             else
             {
                //如果不是正负号，那就是运算符，就存放到队列中
                 ret.enqueue(exp[i]);
             }
             pre=exp[i];//保存一手前一字符
         }

     }

     if(!num.isEmpty())
     {

         ret.enqueue(num);
     }

     return ret;



 }

//******************
//中缀表达式转为后缀表达式的函数
//******************

 QQueue<QString> CaculatorDec::change(const QQueue<QString>& z)
 {
    QQueue<QString> ret ;
    QStack<QString> bk;
    QString sta_pro="";

    for(int i = 0;i<z.length();i++)
    {
        if(isNumber(z[i]))
        {
            ret.enqueue(z[i]);

        }
        else if (z[i].length()==1&&(z[i]=="+"||z[i]=="-"||z[i]=="*"||z[i]=="/"||z[i]=="("||z[i]==")"))//如果字符为符号
        {
            if(z[i]=="+"||z[i]=="-"||z[i]=="*"||z[i]=="/"||z[i]=="(")
            {

                if(!bk.isEmpty())
                {
                    while(1)
                    {
                        sta_pro=bk.pop();

                        if(priority(z[i])<=priority(sta_pro))
                        {
                            if(sta_pro=="(")
                            {
                                bk.push(sta_pro);
                                bk.push(z[i]);
                                break;

                            }
                            ret.enqueue(sta_pro);
                            if(bk.isEmpty())
                            {
                                bk.push(z[i]);
                                break;

                            }
                        }
                        else if(priority(z[i])>priority(sta_pro))
                        {
                           bk.push(sta_pro);
                           bk.push(z[i]);
                           break;

                        }


                    }
                }
               else if(bk.isEmpty())
                {
                    bk.push(z[i]);
                }

            }
            else if(z[i]==")")
            {
                while(!bk.isEmpty())
                {
                    sta_pro = bk.pop();
                    if(sta_pro!="(")
                    {
                        ret.enqueue(sta_pro);

                    }
                    else if(sta_pro=="(")
                    {

                        break;

                    }

                }

            }


        }


    }

   while(!bk.isEmpty())
    {
        sta_pro=bk.pop();
        ret.enqueue(sta_pro);

    }

    return ret;

 }


 //**********************************************************



 float caculate(float a,float b,QString& o)
 {


     float ret ;

     if(o=="+"){ret=a+b;}
     if(o=="-"){ret=a-b;}
     if(o=="*"){ret=a*b;}
     if(o=="/"){ret=a/b;}


     return ret;


 }


float CaculatorDec::h_caculate(const QQueue<QString>& c)
 {
    float ret=0 ;
    float a;
    float b;
    QString o;
    float pre_res = 0;
    QStack<float> result;


    for(int i = 0;i<c.length();i++)
    {
        if(isNumber(c[i]))
        {
            result.push(c[i].toFloat());
        }
        else if(c[i]=="+"||c[i]=="-"||c[i]=="*"||c[i]=="/")
        {

            a=result.pop();
            b=result.pop();
            o=c[i];
           // pre_res = caculate(a,b,o);

            if(o=="+"){pre_res=b+a;}
            if(o=="-"){pre_res=b-a;}
            if(o=="*"){pre_res=b*a;}
            if(o=="/"){pre_res=b/a;}

            result.push(pre_res);

        }


    }

    ret = result.pop();

    return ret;

 }




