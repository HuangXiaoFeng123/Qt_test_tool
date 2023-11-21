#include "toolwidget.h"
#include "ui_toolwidget.h"

ToolWidget::ToolWidget(QWidget *parent): QWidget(parent), ui(new Ui::ToolWidget)
{
    ui->setupUi(this);
    setWindowTitle("Tool v0.01");
    EC_Init();
}

ToolWidget::~ToolWidget(void)
{
    delete ui;
}

void ToolWidget::EC_Init(void)
{
    if(!InitializeWinIo())
    {
        qDebug()<<"111111111111111111111";
        ShutdownWinIo();
    }
    else
    {
        connect(ui->ButtonAC,&QPushButton::clicked,this,&ToolWidget::Update_AC_State);
    }
}

unsigned char ToolWidget::EC_Read_Data(unsigned short Addr)
{
    DWORD data=0x00;
    SetPortVal(EC_ADDR_PORT,0x2E,1);
    SetPortVal(EC_DATA_PORT,0x11,1);
    SetPortVal(EC_ADDR_PORT,0x2F,1);
    SetPortVal(EC_DATA_PORT,Addr>>8,1);

    SetPortVal(EC_ADDR_PORT,0x2E,1);
    SetPortVal(EC_DATA_PORT,0x10,1);
    SetPortVal(EC_ADDR_PORT,0x2F,1);
    SetPortVal(EC_DATA_PORT,Addr&0xFF,1);

    SetPortVal(EC_ADDR_PORT,0x2E,1);
    SetPortVal(EC_DATA_PORT,0x12,1);
    SetPortVal(EC_ADDR_PORT,0x2F,1);
    GetPortVal(EC_DATA_PORT,&data,1);
    return data;
}

void ToolWidget::Update_AC_State(void)
{
    unsigned char tmp_state=EC_Read_Data(0x380);
    qDebug()<<QString::number(tmp_state);
    if((tmp_state&0x1)==1)
    {
        QMessageBox::information(this,"AC state","AC在位");
    }
    else
    {
        QMessageBox::information(this,"AC state","AC不在位");
    }
}

