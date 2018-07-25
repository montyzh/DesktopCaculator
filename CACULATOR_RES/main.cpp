#include <QApplication>
#include "caculatorui.h"
#include "caculatordec.h"
//#include <QFile>

int main(int argc, char *argv[])
{


 int ret=0;
    QApplication a(argc, argv);
    CaculatorUi* m_ui=CaculatorUi::new_interface();

  /*  QFile qssFile("css.qss");//资源文件":/css.qss"
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        QString qss = QLatin1String(qssFile.readAll());
        a.setStyleSheet(qss);
        qssFile.close();
    }*/

    if(m_ui!=NULL)
    {
        m_ui->show();
        return a.exec();
        delete m_ui;
    }


    return ret;



}
