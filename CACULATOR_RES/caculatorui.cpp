

#include "caculatorui.h"
#include <QString>
#include "caculatordec.h"


 CaculatorUi::CaculatorUi():QWidget(NULL)
 {



 }




 CaculatorUi* CaculatorUi::new_interface()
{
    CaculatorUi* ret = new CaculatorUi();
    if(ret==NULL||!ret->construct())
    {
        delete ret;
        ret=NULL;

    }

    return ret;

}


bool CaculatorUi::construct()
{
    bool ret = true;
    const char *btn_text[20]={
    "7","8","9","+","(",
    "4","5","6","-",")",
    "1","2","3","*","<-",
    "0",".","=","/","C",
    };

    m_Line=new QLineEdit(this);
    if(m_Line==NULL)
    {

      ret=false;
    }
    else
    {
        m_Line->move(10,10);
        m_Line->resize(240,50);
        m_Line->setReadOnly(true);
        m_Line->setFont(QFont("Timers" , 28 ,  QFont::Bold));
        m_Line->setAlignment(Qt::AlignRight);
    }


    for(int i=0;(i<4)&&ret;i++)
    {
        for(int j=0;(j<5)&&ret;j++)
        {
            m_btn[i*5+j]=new QPushButton(this);
            if(m_btn[i*5+j]==NULL)
            {
              ret=false;

            }
            else
            {
                m_btn[i*5+j]->resize(40,40);
                m_btn[i*5+j]->move(10+(10+40)*j,70+(10+40)*i);
                m_btn[i*5+j]->setText(btn_text[i*5+j]);
                m_btn[i*5+j]->setStyleSheet("color:blue;font-size:25px;");

                connect(m_btn[i*5+j],SIGNAL(clicked()),this,SLOT(on_btn_clicked()));

            }


        }
    }

    return ret;


}


CaculatorUi::~CaculatorUi()
{

}


void CaculatorUi::show()
{
   resize(260,280);
   setFixedSize(width(),height());

   setWindowTitle(QStringLiteral("计算器"));
   QWidget::show();


}


void CaculatorUi::on_btn_clicked()
{

   QPushButton *bt = (QPushButton*)sender();
    QString clicktext = bt->text();
    if(clicktext == "<-")
    {
        QString text1 = m_Line->text();
        if(text1.length()>0)
        {
            text1.remove(text1.length()-1,1);
            m_Line->setText(text1);

        }


    }


    else if (clicktext == "C")
    {
    m_Line->setText("");


    }
    else if (clicktext == "=")
    {
       QString dis2;
       float dis1;
       biaodashi = m_Line->text();
       dis1 = this->cacu_();
       dis2 = QString::number(dis1);
       m_Line->setText(dis2);

    }
    else
    {
         m_Line->setText(m_Line->text()+clicktext);
    }

}


float CaculatorUi::cacu_()
{
    float ret ;
    CaculatorDec c1;
    QQueue<QString> a;
    a=c1.split(biaodashi);
    a=c1.change(a);
    ret = c1.h_caculate(a);
    return ret;
}




//************
//重构按键处理函数
//************
void CaculatorUi::keyPressEvent(QKeyEvent *e)
{
       QString press_text="";
       press_text=e->text();
       if(e->key() == Qt::Key_Backspace)
       {
           QString text1 = m_Line->text();
           if(text1.length()>0)
           {
               text1.remove(text1.length()-1,1);
               m_Line->setText(text1);

           }


       }


       else if (press_text == "C"||press_text == "c"||e->key() == Qt::Key_Delete)
       {
       m_Line->setText("");


       }
       else if (press_text == "="||e->key()==Qt::Key_Enter||e->key()==Qt::Key_Return)
       {
          QString dis2;
          float dis1;
          biaodashi = m_Line->text();
          dis1 = this->cacu_();
          dis2 = QString::number(dis1);
          m_Line->setText(dis2);

       }
       else
       {
           if(press_text>="0"&&press_text<="9"||press_text=="+"||press_text=="-"||press_text=="*"||press_text=="/"
                   ||press_text=="."||press_text=="("||press_text==")")
           {
            m_Line->setText(m_Line->text()+press_text);
           }
       }





}

