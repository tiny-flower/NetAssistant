#include "lidarpointobsedit.h"
#include "ui_lidarpointobsedit.h"
#include <QPainter>
#include <QtDebug>

//lidarPointObsEdit::lidarPointObsEdit(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::lidarPointObsEdit)
//{
//    ui->setupUi(this);
//}

lidarPointObsEdit::lidarPointObsEdit(QWidget *parent) :
    QDialog(parent),
    m_mousePressed(false),
    m_lastPos(0,0),
    m_image(this->size(), QImage::Format_ARGB32),
    ui(new Ui::lidarPointObsEdit)
{
    m_image.fill(Qt::transparent);
    ui->setupUi(this);
}

lidarPointObsEdit::~lidarPointObsEdit()
{
    delete ui;
}

void lidarPointObsEdit::paintEvent (QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0,0,m_image);
}

void lidarPointObsEdit::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_mousePressed = true;
        m_lastPos = event->pos();
    }
}

void lidarPointObsEdit::mouseMoveEvent(QMouseEvent *event)
{
    if(m_mousePressed){
        QPainter painter(&m_image);
        painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(m_lastPos, event->pos());
        m_lastPos = event->pos();
//        qDebug()<<m_lastPos.rx() << m_lastPos.ry() << m_lastPos.x() << m_lastPos.y();
        emit send_point_signal(m_lastPos);
        update();
    }
//    QJsonObject
}

void lidarPointObsEdit::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_mousePressed = false;
    }
}
