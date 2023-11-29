#include "control_electricity.h"
#include "ui_control_electricity.h"

Control_Electricity::Control_Electricity(QWidget *parent) :QWidget(parent),ui(new Ui::Control_Electricity)
{
    ui->setupUi(this);
    setWindowTitle("Control Electricity");
    setMinimumSize(500,130);
    setMaximumSize(500,130);
    count=0;
    unsigned short control_Mode=EC_Read_Data(0x13B);  //获取当前控电的状态
    if((control_Mode&0x8)==0x8)                       //进入状态
    {
        ui->ButtonEnter->setEnabled(false);
        ui->ButtonExit->setEnabled(true);
        ui->lineEditMin->setDisabled(true);
        ui->lineEditMax->setDisabled(true);
    }
    else                                              //退出状态
    {
        ui->ButtonEnter->setEnabled(true);
        ui->ButtonExit->setEnabled(false);
        ui->lineEditMin->setDisabled(false);
        ui->lineEditMax->setDisabled(false);
    }
    ui->ButtonEnter->setStyleSheet("background-color:rgb(123,198,238)");
    ui->ButtonExit->setStyleSheet("background-color:rgb(123,198,238)");
}

Control_Electricity::~Control_Electricity(void)
{
    delete ui;
}

void Control_Electricity::paintEvent(QPaintEvent *)
{
    QPainter controlDialog_P(this);
    QPixmap controlDialog_map(":/image/control.jpg");
    controlDialog_P.drawPixmap(0,0,this->width(),this->height(),controlDialog_map);
}

unsigned char Control_Electricity::EC_Read_Data(unsigned short Addr)
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

quint8 Control_Electricity::IoRead8(quint8 IoIndex)
{
    DWORD value;
    GetPortVal(IoIndex,&value,0x01);
    return (quint8)value;
}

bool Control_Electricity::IoWrite8(quint8 IoIndex, quint8 Data)
{
    SetPortVal(IoIndex,Data,0x01);
    return true;
}

quint32 Control_Electricity::EcWaitIBE(quint8 CmdPort)
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

quint32 Control_Electricity::EcSendCommand(quint8 CmdPort, quint8 Cmd)
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

void Control_Electricity::on_ButtonEnter_clicked(void)
{
    unsigned char ac_state=EC_Read_Data(0x380);
    int minRSOC=ui->lineEditMin->text().toInt();
    int maxRSOC=ui->lineEditMax->text().toInt();
    if((ac_state&0x1)==1)
    {
        if((minRSOC!=0)&&(maxRSOC!=0)&&(minRSOC<=maxRSOC))
        {
            for(int i=0;i<4;i++)
            {
                if(EcSendCommand(EC_EXTRA_CMD_PORT,0xD6)==ERROR_SUCCESS)
                {
                    count++;
                    Sleep(100);
                }
                if(EcSendCommand(EC_EXTRA_DATA_PORT,(quint8)maxRSOC)==ERROR_SUCCESS)
                {
                    count++;
                    Sleep(100);
                }
                if(EcSendCommand(EC_EXTRA_DATA_PORT,(quint8)minRSOC)==ERROR_SUCCESS)
                {
                    count++;
                    Sleep(100);
                }
                if(EcSendCommand(EC_EXTRA_CMD_PORT,0xD4)==ERROR_SUCCESS)
                {
                    count++;
                    Sleep(100);
                }
                if(EcSendCommand(EC_EXTRA_DATA_PORT,0x29)==ERROR_SUCCESS)
                {
                    count++;
                    Sleep(100);
                    if(count==5)
                    {
                        count=0;
                        QMessageBox::information(this,"Information","进入控电模式成功");
                        ui->ButtonEnter->setEnabled(false);
                        ui->ButtonExit->setEnabled(true);
                        ui->lineEditMin->setDisabled(true);
                        ui->lineEditMax->setDisabled(true);
                        return ;
                    }
                }
                count=0;
            }
        }
        else
        {
            QMessageBox::information(this,"Information","输入格式有误");
            return ;
        }
    }
    else
    {
        QMessageBox::information(this,"Information","AC不在位无法进入控电模式");
        return ;
    }
    QMessageBox::information(this,"Information","进入控电模式失败");
    ui->ButtonEnter->setEnabled(true);
    ui->ButtonExit->setEnabled(false);
    ui->lineEditMin->setDisabled(false);
    ui->lineEditMax->setDisabled(false);
}

void Control_Electricity::on_ButtonExit_clicked(void)
{
    for(int i=0;i<4;i++)
    {
        if(EcSendCommand(EC_EXTRA_CMD_PORT,0xD4)==ERROR_SUCCESS)
        {
            count++;
            Sleep(100);
        }
        if(EcSendCommand(EC_EXTRA_DATA_PORT,0x2A)==ERROR_SUCCESS)
        {
            count++;
            Sleep(100);
            if(count==2)
            {
                count=0;
                QMessageBox::information(this,"Information","退出控电模式成功");
                ui->ButtonEnter->setEnabled(true);
                ui->ButtonExit->setEnabled(false);
                ui->lineEditMin->setDisabled(false);
                ui->lineEditMax->setDisabled(false);
                return ;
            }
        }
        count=0;
    }
    QMessageBox::information(this,"Information","退出控电模式失败");
    ui->ButtonEnter->setEnabled(false);
    ui->ButtonExit->setEnabled(true);
    ui->lineEditMin->setDisabled(true);
    ui->lineEditMax->setDisabled(true);
}
