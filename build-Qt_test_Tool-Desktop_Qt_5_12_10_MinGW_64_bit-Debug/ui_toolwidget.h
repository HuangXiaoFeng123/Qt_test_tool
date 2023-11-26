/********************************************************************************
** Form generated from reading UI file 'toolwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLWIDGET_H
#define UI_TOOLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolWidget
{
public:
    QPushButton *ButtonAC;
    QPushButton *ButtonShip_Mode;
    QPushButton *ButtonMirror;
    QPushButton *ButtonEnter_Electricity;

    void setupUi(QWidget *ToolWidget)
    {
        if (ToolWidget->objectName().isEmpty())
            ToolWidget->setObjectName(QString::fromUtf8("ToolWidget"));
        ToolWidget->resize(295, 454);
        ButtonAC = new QPushButton(ToolWidget);
        ButtonAC->setObjectName(QString::fromUtf8("ButtonAC"));
        ButtonAC->setGeometry(QRect(80, 10, 121, 51));
        ButtonShip_Mode = new QPushButton(ToolWidget);
        ButtonShip_Mode->setObjectName(QString::fromUtf8("ButtonShip_Mode"));
        ButtonShip_Mode->setGeometry(QRect(80, 90, 121, 51));
        ButtonMirror = new QPushButton(ToolWidget);
        ButtonMirror->setObjectName(QString::fromUtf8("ButtonMirror"));
        ButtonMirror->setGeometry(QRect(80, 170, 121, 51));
        ButtonEnter_Electricity = new QPushButton(ToolWidget);
        ButtonEnter_Electricity->setObjectName(QString::fromUtf8("ButtonEnter_Electricity"));
        ButtonEnter_Electricity->setGeometry(QRect(80, 250, 121, 51));

        retranslateUi(ToolWidget);

        QMetaObject::connectSlotsByName(ToolWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolWidget)
    {
        ToolWidget->setWindowTitle(QApplication::translate("ToolWidget", "ToolWidget", nullptr));
        ButtonAC->setText(QApplication::translate("ToolWidget", "AC_Check", nullptr));
        ButtonShip_Mode->setText(QApplication::translate("ToolWidget", "Ship_Mode", nullptr));
        ButtonMirror->setText(QApplication::translate("ToolWidget", "Mirror", nullptr));
        ButtonEnter_Electricity->setText(QApplication::translate("ToolWidget", "Enter_Electricity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolWidget: public Ui_ToolWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLWIDGET_H
