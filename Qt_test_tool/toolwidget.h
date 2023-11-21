#ifndef TOOLWIDGET_H
#define TOOLWIDGET_H

#include <QWidget>
#include <windows.h>
#include <winioctl.h>
#include "WinIo.h"
#include "winio_nt.h"
#include <QMessageBox>
#include <QDebug>

#define EC_ADDR_PORT  0x4E
#define EC_DATA_PORT  0x4F

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

private:
    Ui::ToolWidget *ui;
};
#endif // TOOLWIDGET_H
