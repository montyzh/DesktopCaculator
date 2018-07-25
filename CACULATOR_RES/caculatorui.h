#ifndef _CACULATORUI_H_
#define _CACULATORUI_H_

#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <Qstring>
#include <QKeyEvent>
class CaculatorDec;

class CaculatorUi : public QWidget
{
    Q_OBJECT

private:
    bool construct();
    CaculatorUi();
    QPushButton* m_btn[20];
    QLineEdit* m_Line;

public:
    QString biaodashi;
    float cacu_();
    friend class CaculatorDec;
    static CaculatorUi* new_interface();
    ~CaculatorUi();
    void show();
    void keyPressEvent(QKeyEvent *e);
public slots:
    void on_btn_clicked();

};

#endif
