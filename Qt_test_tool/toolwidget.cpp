#include "toolwidget.h"
#include "ui_toolwidget.h"

ToolWidget::ToolWidget(QWidget *parent): QWidget(parent), ui(new Ui::ToolWidget)
{
    ui->setupUi(this);
    setWindowTitle("Tool v0.05");
    count=0;
    EC_Init();
    electricity_widget=new Control_Electricity();
}

ToolWidget::~ToolWidget(void)
{
    delete ui;
    if(electricity_widget!=NULL)
    {
        delete electricity_widget;
        electricity_widget=NULL;
    }
}

void ToolWidget::EC_Init(void)
{
    if(!InitializeWinIo())
    {
        qDebug()<<"111111111111111";
        ShutdownWinIo();
    }
    else
    {
        connect(ui->ButtonAC,&QPushButton::clicked,this,&ToolWidget::Update_AC_State);
        connect(ui->ButtonShip_Mode,&QPushButton::clicked,this,&ToolWidget::Enter_ShipMode);
        connect(ui->ButtonMirror,&QPushButton::clicked,this,&ToolWidget::Enter_Mirror);
        connect(ui->ButtonControl_Electricity,&QPushButton::clicked,this,&ToolWidget::ControlElectricity);
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

quint8 ToolWidget::IoRead8(quint16 IoIndex)
{
    DWORD value;
    GetPortVal(IoIndex,&value,0x01);
    return (quint8)value;
}

bool ToolWidget::IoWrite8(quint16 IoIndex, quint8 Data)
{
    SetPortVal(IoIndex,Data,0x01);
    return true;
}

quint32 ToolWidget::EcWaitIBE(quint8 CmdPort)
{
    quint32 Index;
    for(Index=0;Index<KBC_TIME_OUT;Index++)
    {
        if((IoRead8(CmdPort)&KBC_IBF)==0x00)
        {
            return ERROR_SUCCESS;
        }
    }
    return ERROR_NOT_READY;
}

quint32 ToolWidget::EcSendCommand(quint8 CmdPort, quint8 Cmd)
{
    quint32 Status;
    Status=EcWaitIBE(CmdPort);
    if(Status)
    {
        //EC Input Buffer isn't empty
        return Status;
    }
    IoWrite8(CmdPort,Cmd);
    return ERROR_SUCCESS;
}

void ToolWidget::Update_AC_State(void)
{
    unsigned char ac_state=EC_Read_Data(0x380);
    qDebug()<<QString::number(ac_state);
    if((ac_state&0x1)==1)
    {
        QMessageBox::information(this,"AC state","AC在位");
    }
    else
    {
        QMessageBox::information(this,"AC state","AC不在位");
    }
}

void ToolWidget::Enter_ShipMode(void)
{
    unsigned char ac_state=EC_Read_Data(0x380);
    if((ac_state&0x1)==0)                                               //AC不在位才可以执行enter shipmode代码
    {
        for(int i=0;i<4;i++)
        {
            if((EcSendCommand(EC_EXTRA_CMD_PORT,0xD4))==ERROR_SUCCESS)  //EC工厂接口0x6C 写命令
            {
                count++;
                Sleep(500);                                             //延时500ms以至于不用那么快写入下一个命令
            }
            if((EcSendCommand(EC_EXTRA_DATA_PORT,0x14))==ERROR_SUCCESS) //EC工厂接口0x68 写数据
            {
                count++;
                if(count==2)
                {
                    count=0;
                    p.start("shutdown /s /t 3");                        //Enter shipMode successful
                    return ;
                }
            }
            count=0;
        }
    }
    else
    {
        QMessageBox::information(this,"AC State","AC 在位无法进ShipMode");
        return ;
    }
    //Enter shipMode fail
    QMessageBox::information(this,"Information","进入ShipMode失败");
}

void ToolWidget::Enter_Mirror(void)
{
    unsigned char ac_state=EC_Read_Data(0x380);
    if((ac_state&0x1)==1)
    {
        for(int i=0;i<4;i++)
        {
            if(EcSendCommand(EC_CMD_PORT,0x50)==ERROR_SUCCESS)
            {
                Sleep(500);
                p.start("shutdown /s /t 3");                           //Enter Mirror successful
                return ;
            }
        }
    }
    else
    {
        QMessageBox::information(this,"AC State","AC不在位,请插入AC");
        return ;
    }
    //Enter Mirror fail
    QMessageBox::information(this,"Information","EC mirror 失败");
}

void ToolWidget::ControlElectricity(void)
{
    electricity_widget->show();
}
