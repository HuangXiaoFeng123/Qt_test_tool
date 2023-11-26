#ifndef CONTROL_ELECTRICITY_H
#define CONTROL_ELECTRICITY_H

#include <QWidget>
#include <windows.h>
#include <winioctl.h>
#include "WinIo.h"
#include "winio_nt.h"
#include <QMessageBox>
#include <QDebug>

#define EC_ADDR_PORT  0x4E
#define EC_DATA_PORT  0x4F

#define KBC_TIME_OUT  80000
#define KBC_IBF  0x02

#define EC_EXTRA_CMD_PORT 0x6C
#define EC_EXTRA_DATA_PORT 0x68

namespace Ui
{
class Control_Electricity;
}

class Control_Electricity : public QWidget
{
    Q_OBJECT

public:
    explicit Control_Electricity(QWidget *parent = nullptr);
    ~Control_Electricity(void);
    unsigned char EC_Read_Data(unsigned short Addr);
    quint8 IoRead8(quint16 IoIndex);
    bool IoWrite8(quint16 IoIndex,quint8 Data);
    quint32 EcWaitIBE(quint8 CmdPort);
    quint32 EcSendCommand(quint8 CmdPort,quint8 Cmd);

private slots:
    void on_ButtonSure_clicked(void);

private:
    Ui::Control_Electricity *ui;
    int count;
};

#endif // CONTROL_ELECTRICITY_H
