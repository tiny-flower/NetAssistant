#ifndef LIDARPOINTOBSEDIT_H
#define LIDARPOINTOBSEDIT_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class lidarPointObsEdit;
}

class lidarPointObsEdit : public QDialog
{
    Q_OBJECT

public:
    explicit lidarPointObsEdit(QWidget *parent = 0);
    ~lidarPointObsEdit();


private:
    bool m_mousePressed;
    QPoint m_lastPos;
    QImage m_image;
    Ui::lidarPointObsEdit *ui;

protected:
    void paintEvent (QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
//    void reject();

signals:
    void send_point_signal(QPoint point);
private slots:
    void on_buttonBox_rejected();
};

#endif // LIDARPOINTOBSEDIT_H
