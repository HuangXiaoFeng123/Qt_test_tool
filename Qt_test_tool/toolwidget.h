#ifndef TOOLWIDGET_H
#define TOOLWIDGET_H

#include <QWidget>
#include <windows.h>
#include <winioctl.h>
#include "WinIo.h"
#include "winio_nt.h"
#include <QMessageBox>
#include <QProcess>
#include <QDebug>

#define EC_ADDR_PORT  0x4E
#define EC_DATA_PORT  0x4F

#define KBC_TIME_OUT  80000
#define KBC_IBF  0x02

#define EC_EXTRA_CMD_PORT 0x6C
#define EC_EXTRA_DATA_PORT 0x68
#define EC_CMD_PORT  0x66

QT_BEGIN_NAMESPACE
namespace Ui
{
class ToolWidget;
}
QT_END_NAMESPACE

class ToolWidget : public QWidget
{
    Q_OBJECT

public:
    ToolWidget(QWidget *parent = nullptr);
    ~ToolWidget(void);
    void EC_Init(void);
    void Update_AC_State(void);
    unsigned char EC_Read_Data(unsigned short Addr);
    quint8 IoRead8(quint16 IoIndex);
    bool IoWrite8(quint16 IoIndex,quint8 Data);
    quint32 EcWaitIBE(quint8 CmdPort);
    quint32 EcSendCommand(quint8 CmdPort,quint8 Cmd);
    void Enter_ShipMode(void);
    void Enter_Mirror(void);

private:
    Ui::ToolWidget *ui;
    int count;
    QProcess p;
};
#endif // TOOLWIDGET_H
