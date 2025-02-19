﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QDataStream>
#include <QTextStream>
#include  "TcpServer.h"
#include  "lidarpointobsedit.h"
#include <QPoint>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setUdpGuiExt();
    void setTcpSvrGuiExt();
    void setTcpClientGuiExt();

    QList<int> tcpClientSocketDescriptorList;
    int TcpClientLinkCnt;
//    lidarPointObsEdit *errLidarPointWindow;

signals:
    void sendDataToClient(char *msg, int length, int socketDescriptor, int socketDescriptorEx);

private slots:
    void on_actionEnglish_triggered();

    void on_pBtnNetCnnt_clicked(bool checked);
    void on_cBoxNetType_currentIndexChanged(int index);

    void on_pBtnSendData_clicked();
    void on_pBtnClearRcvDisp_clicked();
    void on_lEditUdpPort_textChanged(QString text);
    void on_lEditUdpIP_textChanged(QString text);
    void on_pBtnResetCnt_clicked();
    char ConvertHexChar(char ch);
    char ConvertHexStr(QString hexSubStr);

    //=======UDP========
    void udpDataReceived();

    //=====TCP Client=====
    void tcpClientDataReceived();

    //=====TCP Server=====
    bool slotTryCreateTcpServer();
    void slotDeleteTcpServer();
    void tcpServerDataReceived(char* msg, int length, int socketDescriptorEx);

    void addClientLink(QString clientAddrPort, int socketDescriptor);
    void removeClientLink(QString clientAddrPort, int socketDescriptor);
    void toSendData();
    void toSendFile();
    void insertDateTimeInRcvDisp();

    void msDelay(unsigned int msec);

    void on_pBtnSaveRcvData_clicked();
    void on_cBoxLoopSnd_toggled(bool checked);
    void on_lEdit_Interval_ms_editingFinished();

    void on_pBtnClearSndDisp_clicked();

    void on_pBtnLoadSndData_clicked();

    void on_StartRcvFile_clicked(bool checked);

    void on_cBoxStartSndFile_clicked(bool checked);

    void on_cBox_SndHexDisp_clicked(bool checked);


    void on_actionChinese_triggered();

    void on_action_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QString m_ip;
    //-----UDP-----
    QUdpSocket *udpSocket;
    QHostAddress lhAddr;
    int lhPort;
    QHostAddress rmtAddr;
    int rmtPort;

    //-----TCP Client-----
    QHostAddress *rmtServerIP;
    QTcpSocket *tcpClientSocket;
    TcpServer *mtcpServer;

    //Global state
    unsigned int rcvDataCnt;
    unsigned int sndDataCnt;
    //bool NetState;
    QTimer *timer;
    bool loopSending;

    QString CurIPPort;

    QString CurPath;
    QFile *curFile;

    QTranslator translator;

public slots:
    void rece_point_slots(QPoint point);
};

#endif // MAINWINDOW_H
