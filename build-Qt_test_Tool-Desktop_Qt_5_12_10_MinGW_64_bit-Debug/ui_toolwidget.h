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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *ButtonAC;
    QSpacerItem *verticalSpacer;
    QPushButton *ButtonShip_Mode;
    QSpacerItem *verticalSpacer_2;
    QPushButton *ButtonMirror;
    QSpacerItem *verticalSpacer_3;
    QPushButton *ButtonControl_Electricity;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ToolWidget)
    {
        if (ToolWidget->objectName().isEmpty())
            ToolWidget->setObjectName(QString::fromUtf8("ToolWidget"));
        ToolWidget->resize(300, 330);
        gridLayout = new QGridLayout(ToolWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ButtonAC = new QPushButton(ToolWidget);
        ButtonAC->setObjectName(QString::fromUtf8("ButtonAC"));
        ButtonAC->setMinimumSize(QSize(125, 50));
        ButtonAC->setMaximumSize(QSize(125, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        ButtonAC->setFont(font);

        verticalLayout->addWidget(ButtonAC);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        ButtonShip_Mode = new QPushButton(ToolWidget);
        ButtonShip_Mode->setObjectName(QString::fromUtf8("ButtonShip_Mode"));
        ButtonShip_Mode->setMinimumSize(QSize(125, 50));
        ButtonShip_Mode->setMaximumSize(QSize(125, 50));
        ButtonShip_Mode->setFont(font);

        verticalLayout->addWidget(ButtonShip_Mode);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        ButtonMirror = new QPushButton(ToolWidget);
        ButtonMirror->setObjectName(QString::fromUtf8("ButtonMirror"));
        ButtonMirror->setMinimumSize(QSize(125, 50));
        ButtonMirror->setMaximumSize(QSize(125, 50));
        ButtonMirror->setFont(font);

        verticalLayout->addWidget(ButtonMirror);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        ButtonControl_Electricity = new QPushButton(ToolWidget);
        ButtonControl_Electricity->setObjectName(QString::fromUtf8("ButtonControl_Electricity"));
        ButtonControl_Electricity->setMinimumSize(QSize(125, 50));
        ButtonControl_Electricity->setMaximumSize(QSize(125, 50));
        ButtonControl_Electricity->setFont(font);

        verticalLayout->addWidget(ButtonControl_Electricity);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(ToolWidget);

        QMetaObject::connectSlotsByName(ToolWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolWidget)
    {
        ToolWidget->setWindowTitle(QApplication::translate("ToolWidget", "ToolWidget", nullptr));
        ButtonAC->setText(QApplication::translate("ToolWidget", "AC_Check", nullptr));
        ButtonShip_Mode->setText(QApplication::translate("ToolWidget", "Ship_Mode", nullptr));
        ButtonMirror->setText(QApplication::translate("ToolWidget", "Mirror", nullptr));
        ButtonControl_Electricity->setText(QApplication::translate("ToolWidget", "Control_Electricity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolWidget: public Ui_ToolWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLWIDGET_H
