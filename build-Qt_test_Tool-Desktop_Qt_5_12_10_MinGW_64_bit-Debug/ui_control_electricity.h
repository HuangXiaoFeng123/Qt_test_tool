/********************************************************************************
** Form generated from reading UI file 'control_electricity.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_ELECTRICITY_H
#define UI_CONTROL_ELECTRICITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Control_Electricity
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMin;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEditMax;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ButtonEnter;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonExit;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Control_Electricity)
    {
        if (Control_Electricity->objectName().isEmpty())
            Control_Electricity->setObjectName(QString::fromUtf8("Control_Electricity"));
        Control_Electricity->resize(500, 130);
        gridLayout = new QGridLayout(Control_Electricity);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Control_Electricity);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(70, 0));
        label->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(label);

        lineEditMin = new QLineEdit(Control_Electricity);
        lineEditMin->setObjectName(QString::fromUtf8("lineEditMin"));
        lineEditMin->setMinimumSize(QSize(50, 30));
        lineEditMin->setMaximumSize(QSize(50, 30));

        horizontalLayout->addWidget(lineEditMin);

        label_2 = new QLabel(Control_Electricity);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(20, 0));
        label_2->setMaximumSize(QSize(20, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(16);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        label_4 = new QLabel(Control_Electricity);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(50, 0));
        label_4->setMaximumSize(QSize(50, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(24);
        label_4->setFont(font1);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        horizontalLayout->addWidget(label_4);

        lineEditMax = new QLineEdit(Control_Electricity);
        lineEditMax->setObjectName(QString::fromUtf8("lineEditMax"));
        lineEditMax->setMinimumSize(QSize(50, 30));
        lineEditMax->setMaximumSize(QSize(50, 30));

        horizontalLayout->addWidget(lineEditMax);

        label_3 = new QLabel(Control_Electricity);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(20, 0));
        label_3->setMaximumSize(QSize(20, 16777215));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ButtonEnter = new QPushButton(Control_Electricity);
        ButtonEnter->setObjectName(QString::fromUtf8("ButtonEnter"));
        ButtonEnter->setMinimumSize(QSize(120, 30));
        ButtonEnter->setMaximumSize(QSize(120, 30));

        horizontalLayout_2->addWidget(ButtonEnter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ButtonExit = new QPushButton(Control_Electricity);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        ButtonExit->setMinimumSize(QSize(120, 30));
        ButtonExit->setMaximumSize(QSize(120, 30));

        horizontalLayout_2->addWidget(ButtonExit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Control_Electricity);

        QMetaObject::connectSlotsByName(Control_Electricity);
    } // setupUi

    void retranslateUi(QWidget *Control_Electricity)
    {
        Control_Electricity->setWindowTitle(QApplication::translate("Control_Electricity", "Form", nullptr));
        label->setText(QApplication::translate("Control_Electricity", "\346\216\247\347\224\265\350\214\203\345\233\264\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Control_Electricity", "%", nullptr));
        label_4->setText(QApplication::translate("Control_Electricity", "~", nullptr));
        label_3->setText(QApplication::translate("Control_Electricity", "%", nullptr));
        ButtonEnter->setText(QApplication::translate("Control_Electricity", "\350\277\233\345\205\245\346\216\247\347\224\265", nullptr));
        ButtonExit->setText(QApplication::translate("Control_Electricity", "\351\200\200\345\207\272\346\216\247\347\224\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Control_Electricity: public Ui_Control_Electricity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_ELECTRICITY_H
