/********************************************************************************
** Form generated from reading UI file 'ProjetJeuxEchecs.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJETJEUXECHECS_H
#define UI_PROJETJEUXECHECS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjetJeuxEchecsClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *F7;
    QPushButton *C6;
    QPushButton *H6;
    QPushButton *G2;
    QPushButton *F6;
    QPushButton *G7;
    QPushButton *A3;
    QPushButton *C5;
    QPushButton *H8;
    QPushButton *D3;
    QPushButton *G5;
    QPushButton *A1;
    QPushButton *D7;
    QPushButton *E4;
    QPushButton *D1;
    QPushButton *C4;
    QPushButton *H3;
    QPushButton *E7;
    QPushButton *F5;
    QPushButton *B8;
    QPushButton *H1;
    QPushButton *F2;
    QPushButton *B7;
    QPushButton *D6;
    QPushButton *B4;
    QPushButton *E2;
    QPushButton *H2;
    QPushButton *A4;
    QPushButton *G3;
    QPushButton *E5;
    QPushButton *F8;
    QPushButton *B5;
    QPushButton *C2;
    QPushButton *G8;
    QPushButton *C8;
    QPushButton *D2;
    QPushButton *F1;
    QPushButton *G1;
    QPushButton *A7;
    QPushButton *E8;
    QPushButton *B6;
    QPushButton *C7;
    QPushButton *E1;
    QPushButton *C3;
    QPushButton *H4;
    QPushButton *A8;
    QPushButton *C1;
    QPushButton *G6;
    QPushButton *F4;
    QPushButton *B2;
    QPushButton *A2;
    QPushButton *E3;
    QPushButton *E6;
    QPushButton *H7;
    QPushButton *D8;
    QPushButton *G4;
    QPushButton *D5;
    QPushButton *H5;
    QPushButton *B1;
    QPushButton *B3;
    QPushButton *A5;
    QPushButton *D4;
    QPushButton *A6;
    QPushButton *F3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *piece;
    QComboBox *couleur;
    QLineEdit *position;
    QPushButton *ajouter;
    QPushButton *enlever;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjetJeuxEchecsClass)
    {
        if (ProjetJeuxEchecsClass->objectName().isEmpty())
            ProjetJeuxEchecsClass->setObjectName("ProjetJeuxEchecsClass");
        ProjetJeuxEchecsClass->resize(581, 517);
        centralWidget = new QWidget(ProjetJeuxEchecsClass);
        centralWidget->setObjectName("centralWidget");
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 20, 451, 450));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        F7 = new QPushButton(gridLayoutWidget);
        F7->setObjectName("F7");
        F7->setMinimumSize(QSize(56, 56));
        F7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(F7, 9, 5, 1, 1);

        C6 = new QPushButton(gridLayoutWidget);
        C6->setObjectName("C6");
        C6->setMinimumSize(QSize(56, 56));
        C6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(C6, 10, 2, 1, 1);

        H6 = new QPushButton(gridLayoutWidget);
        H6->setObjectName("H6");
        H6->setMinimumSize(QSize(56, 56));
        H6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(H6, 10, 7, 1, 1);

        G2 = new QPushButton(gridLayoutWidget);
        G2->setObjectName("G2");
        G2->setMinimumSize(QSize(56, 56));
        G2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(G2, 14, 6, 1, 1);

        F6 = new QPushButton(gridLayoutWidget);
        F6->setObjectName("F6");
        F6->setMinimumSize(QSize(56, 56));
        F6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(F6, 10, 5, 1, 1);

        G7 = new QPushButton(gridLayoutWidget);
        G7->setObjectName("G7");
        G7->setMinimumSize(QSize(56, 56));
        G7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(G7, 9, 6, 1, 1);

        A3 = new QPushButton(gridLayoutWidget);
        A3->setObjectName("A3");
        A3->setMinimumSize(QSize(56, 56));
        A3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(A3, 13, 0, 1, 1);

        C5 = new QPushButton(gridLayoutWidget);
        C5->setObjectName("C5");
        C5->setMinimumSize(QSize(56, 56));
        C5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(C5, 11, 2, 1, 1);

        H8 = new QPushButton(gridLayoutWidget);
        H8->setObjectName("H8");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(H8->sizePolicy().hasHeightForWidth());
        H8->setSizePolicy(sizePolicy);
        H8->setMinimumSize(QSize(56, 56));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(117, 149, 85, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush2);
        QBrush brush3(QColor(247, 247, 247, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush4);
        QBrush brush5(QColor(160, 160, 160, 255));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        QBrush brush8(QColor(240, 240, 240, 255));
        brush8.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush8);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush9(QColor(120, 120, 120, 127));
        brush9.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush9);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush2);
#endif
        H8->setPalette(palette);
        H8->setAutoFillBackground(false);
        H8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(H8, 0, 7, 1, 1);

        D3 = new QPushButton(gridLayoutWidget);
        D3->setObjectName("D3");
        D3->setMinimumSize(QSize(56, 56));
        D3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(D3, 13, 3, 1, 1);

        G5 = new QPushButton(gridLayoutWidget);
        G5->setObjectName("G5");
        G5->setMinimumSize(QSize(56, 56));
        G5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(G5, 11, 6, 1, 1);

        A1 = new QPushButton(gridLayoutWidget);
        A1->setObjectName("A1");
        A1->setMinimumSize(QSize(56, 56));
        A1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(A1, 15, 0, 1, 1);

        D7 = new QPushButton(gridLayoutWidget);
        D7->setObjectName("D7");
        D7->setMinimumSize(QSize(56, 56));
        D7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(D7, 9, 3, 1, 1);

        E4 = new QPushButton(gridLayoutWidget);
        E4->setObjectName("E4");
        E4->setMinimumSize(QSize(56, 56));
        E4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(E4, 12, 4, 1, 1);

        D1 = new QPushButton(gridLayoutWidget);
        D1->setObjectName("D1");
        D1->setMinimumSize(QSize(56, 56));
        D1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(D1, 15, 3, 1, 1);

        C4 = new QPushButton(gridLayoutWidget);
        C4->setObjectName("C4");
        C4->setMinimumSize(QSize(56, 56));
        C4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(C4, 12, 2, 1, 1);

        H3 = new QPushButton(gridLayoutWidget);
        H3->setObjectName("H3");
        H3->setMinimumSize(QSize(56, 56));
        H3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(H3, 13, 7, 1, 1);

        E7 = new QPushButton(gridLayoutWidget);
        E7->setObjectName("E7");
        E7->setMinimumSize(QSize(56, 56));
        E7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(E7, 9, 4, 1, 1);

        F5 = new QPushButton(gridLayoutWidget);
        F5->setObjectName("F5");
        F5->setMinimumSize(QSize(56, 56));
        F5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(F5, 11, 5, 1, 1);

        B8 = new QPushButton(gridLayoutWidget);
        B8->setObjectName("B8");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(B8->sizePolicy().hasHeightForWidth());
        B8->setSizePolicy(sizePolicy1);
        B8->setMinimumSize(QSize(56, 56));
        B8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(B8, 0, 1, 1, 1);

        H1 = new QPushButton(gridLayoutWidget);
        H1->setObjectName("H1");
        H1->setMinimumSize(QSize(56, 56));
        H1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(H1, 15, 7, 1, 1);

        F2 = new QPushButton(gridLayoutWidget);
        F2->setObjectName("F2");
        F2->setMinimumSize(QSize(56, 56));
        F2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(F2, 14, 5, 1, 1);

        B7 = new QPushButton(gridLayoutWidget);
        B7->setObjectName("B7");
        B7->setMinimumSize(QSize(56, 56));
        B7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(B7, 9, 1, 1, 1);

        D6 = new QPushButton(gridLayoutWidget);
        D6->setObjectName("D6");
        D6->setMinimumSize(QSize(56, 56));
        D6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(D6, 10, 3, 1, 1);

        B4 = new QPushButton(gridLayoutWidget);
        B4->setObjectName("B4");
        B4->setMinimumSize(QSize(56, 56));
        B4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(B4, 12, 1, 1, 1);

        E2 = new QPushButton(gridLayoutWidget);
        E2->setObjectName("E2");
        E2->setMinimumSize(QSize(56, 56));
        E2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(E2, 14, 4, 1, 1);

        H2 = new QPushButton(gridLayoutWidget);
        H2->setObjectName("H2");
        H2->setMinimumSize(QSize(56, 56));
        H2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(H2, 14, 7, 1, 1);

        A4 = new QPushButton(gridLayoutWidget);
        A4->setObjectName("A4");
        A4->setMinimumSize(QSize(56, 56));
        A4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(A4, 12, 0, 1, 1);

        G3 = new QPushButton(gridLayoutWidget);
        G3->setObjectName("G3");
        G3->setMinimumSize(QSize(56, 56));
        G3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(G3, 13, 6, 1, 1);

        E5 = new QPushButton(gridLayoutWidget);
        E5->setObjectName("E5");
        E5->setMinimumSize(QSize(56, 56));
        E5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(E5, 11, 4, 1, 1);

        F8 = new QPushButton(gridLayoutWidget);
        F8->setObjectName("F8");
        sizePolicy.setHeightForWidth(F8->sizePolicy().hasHeightForWidth());
        F8->setSizePolicy(sizePolicy);
        F8->setMinimumSize(QSize(56, 56));
        F8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(F8, 0, 5, 1, 1);

        B5 = new QPushButton(gridLayoutWidget);
        B5->setObjectName("B5");
        B5->setMinimumSize(QSize(56, 56));
        B5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(B5, 11, 1, 1, 1);

        C2 = new QPushButton(gridLayoutWidget);
        C2->setObjectName("C2");
        C2->setMinimumSize(QSize(56, 56));
        C2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(C2, 14, 2, 1, 1);

        G8 = new QPushButton(gridLayoutWidget);
        G8->setObjectName("G8");
        sizePolicy.setHeightForWidth(G8->sizePolicy().hasHeightForWidth());
        G8->setSizePolicy(sizePolicy);
        G8->setMinimumSize(QSize(56, 56));
        G8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(G8, 0, 6, 1, 1);

        C8 = new QPushButton(gridLayoutWidget);
        C8->setObjectName("C8");
        sizePolicy1.setHeightForWidth(C8->sizePolicy().hasHeightForWidth());
        C8->setSizePolicy(sizePolicy1);
        C8->setMinimumSize(QSize(56, 56));
        C8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(C8, 0, 2, 1, 1);

        D2 = new QPushButton(gridLayoutWidget);
        D2->setObjectName("D2");
        D2->setMinimumSize(QSize(56, 56));
        D2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(D2, 14, 3, 1, 1);

        F1 = new QPushButton(gridLayoutWidget);
        F1->setObjectName("F1");
        F1->setMinimumSize(QSize(56, 56));
        F1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(F1, 15, 5, 1, 1);

        G1 = new QPushButton(gridLayoutWidget);
        G1->setObjectName("G1");
        G1->setMinimumSize(QSize(56, 56));
        G1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(G1, 15, 6, 1, 1);

        A7 = new QPushButton(gridLayoutWidget);
        A7->setObjectName("A7");
        A7->setMinimumSize(QSize(56, 56));
        A7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(A7, 9, 0, 1, 1);

        E8 = new QPushButton(gridLayoutWidget);
        E8->setObjectName("E8");
        sizePolicy1.setHeightForWidth(E8->sizePolicy().hasHeightForWidth());
        E8->setSizePolicy(sizePolicy1);
        E8->setMinimumSize(QSize(56, 56));
        E8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(E8, 0, 4, 1, 1);

        B6 = new QPushButton(gridLayoutWidget);
        B6->setObjectName("B6");
        B6->setMinimumSize(QSize(56, 56));
        B6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(B6, 10, 1, 1, 1);

        C7 = new QPushButton(gridLayoutWidget);
        C7->setObjectName("C7");
        C7->setMinimumSize(QSize(56, 56));
        C7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(C7, 9, 2, 1, 1);

        E1 = new QPushButton(gridLayoutWidget);
        E1->setObjectName("E1");
        E1->setMinimumSize(QSize(56, 56));
        E1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(E1, 15, 4, 1, 1);

        C3 = new QPushButton(gridLayoutWidget);
        C3->setObjectName("C3");
        C3->setMinimumSize(QSize(56, 56));
        C3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(C3, 13, 2, 1, 1);

        H4 = new QPushButton(gridLayoutWidget);
        H4->setObjectName("H4");
        H4->setMinimumSize(QSize(56, 56));
        H4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(H4, 12, 7, 1, 1);

        A8 = new QPushButton(gridLayoutWidget);
        A8->setObjectName("A8");
        A8->setEnabled(true);
        sizePolicy.setHeightForWidth(A8->sizePolicy().hasHeightForWidth());
        A8->setSizePolicy(sizePolicy);
        A8->setMinimumSize(QSize(56, 56));
        A8->setBaseSize(QSize(0, 0));
        A8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));
        A8->setIconSize(QSize(12, 12));
        A8->setCheckable(false);

        gridLayout->addWidget(A8, 0, 0, 1, 1);

        C1 = new QPushButton(gridLayoutWidget);
        C1->setObjectName("C1");
        C1->setMinimumSize(QSize(56, 56));
        C1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(C1, 15, 2, 1, 1);

        G6 = new QPushButton(gridLayoutWidget);
        G6->setObjectName("G6");
        G6->setMinimumSize(QSize(56, 56));
        G6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(G6, 10, 6, 1, 1);

        F4 = new QPushButton(gridLayoutWidget);
        F4->setObjectName("F4");
        F4->setMinimumSize(QSize(56, 56));
        F4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(F4, 12, 5, 1, 1);

        B2 = new QPushButton(gridLayoutWidget);
        B2->setObjectName("B2");
        B2->setMinimumSize(QSize(56, 56));
        B2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(B2, 14, 1, 1, 1);

        A2 = new QPushButton(gridLayoutWidget);
        A2->setObjectName("A2");
        A2->setMinimumSize(QSize(56, 56));
        A2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(A2, 14, 0, 1, 1);

        E3 = new QPushButton(gridLayoutWidget);
        E3->setObjectName("E3");
        E3->setMinimumSize(QSize(56, 56));
        E3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(E3, 13, 4, 1, 1);

        E6 = new QPushButton(gridLayoutWidget);
        E6->setObjectName("E6");
        E6->setMinimumSize(QSize(56, 56));
        E6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(E6, 10, 4, 1, 1);

        H7 = new QPushButton(gridLayoutWidget);
        H7->setObjectName("H7");
        H7->setMinimumSize(QSize(56, 56));
        H7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(H7, 9, 7, 1, 1);

        D8 = new QPushButton(gridLayoutWidget);
        D8->setObjectName("D8");
        sizePolicy1.setHeightForWidth(D8->sizePolicy().hasHeightForWidth());
        D8->setSizePolicy(sizePolicy1);
        D8->setMinimumSize(QSize(56, 56));
        D8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(D8, 0, 3, 1, 1);

        G4 = new QPushButton(gridLayoutWidget);
        G4->setObjectName("G4");
        G4->setMinimumSize(QSize(56, 56));
        G4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(G4, 12, 6, 1, 1);

        D5 = new QPushButton(gridLayoutWidget);
        D5->setObjectName("D5");
        D5->setMinimumSize(QSize(56, 56));
        D5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(D5, 11, 3, 1, 1);

        H5 = new QPushButton(gridLayoutWidget);
        H5->setObjectName("H5");
        H5->setMinimumSize(QSize(56, 56));
        H5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(H5, 11, 7, 1, 1);

        B1 = new QPushButton(gridLayoutWidget);
        B1->setObjectName("B1");
        B1->setMinimumSize(QSize(56, 56));
        B1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(B1, 15, 1, 1, 1);

        B3 = new QPushButton(gridLayoutWidget);
        B3->setObjectName("B3");
        B3->setMinimumSize(QSize(56, 56));
        B3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(B3, 13, 1, 1, 1);

        A5 = new QPushButton(gridLayoutWidget);
        A5->setObjectName("A5");
        A5->setMinimumSize(QSize(56, 56));
        A5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(A5, 11, 0, 1, 1);

        D4 = new QPushButton(gridLayoutWidget);
        D4->setObjectName("D4");
        D4->setMinimumSize(QSize(56, 56));
        D4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(117, 149, 85);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(D4, 12, 3, 1, 1);

        A6 = new QPushButton(gridLayoutWidget);
        A6->setObjectName("A6");
        A6->setMinimumSize(QSize(56, 56));
        A6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(A6, 10, 0, 1, 1);

        F3 = new QPushButton(gridLayoutWidget);
        F3->setObjectName("F3");
        F3->setMinimumSize(QSize(56, 56));
        F3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(237, 237, 209);\n"
"	border: 1px;\n"
"}"));

        gridLayout->addWidget(F3, 13, 5, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(470, 190, 101, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        piece = new QComboBox(verticalLayoutWidget);
        piece->addItem(QString());
        piece->addItem(QString());
        piece->addItem(QString());
        piece->addItem(QString());
        piece->addItem(QString());
        piece->addItem(QString());
        piece->setObjectName("piece");

        verticalLayout->addWidget(piece);

        couleur = new QComboBox(verticalLayoutWidget);
        couleur->addItem(QString());
        couleur->addItem(QString());
        couleur->setObjectName("couleur");

        verticalLayout->addWidget(couleur);

        position = new QLineEdit(verticalLayoutWidget);
        position->setObjectName("position");
        position->setEnabled(false);

        verticalLayout->addWidget(position);

        ajouter = new QPushButton(verticalLayoutWidget);
        ajouter->setObjectName("ajouter");

        verticalLayout->addWidget(ajouter);

        enlever = new QPushButton(verticalLayoutWidget);
        enlever->setObjectName("enlever");

        verticalLayout->addWidget(enlever);

        ProjetJeuxEchecsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjetJeuxEchecsClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 581, 18));
        ProjetJeuxEchecsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjetJeuxEchecsClass);
        mainToolBar->setObjectName("mainToolBar");
        ProjetJeuxEchecsClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjetJeuxEchecsClass);
        statusBar->setObjectName("statusBar");
        ProjetJeuxEchecsClass->setStatusBar(statusBar);

        retranslateUi(ProjetJeuxEchecsClass);

        QMetaObject::connectSlotsByName(ProjetJeuxEchecsClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjetJeuxEchecsClass)
    {
        ProjetJeuxEchecsClass->setWindowTitle(QCoreApplication::translate("ProjetJeuxEchecsClass", "ProjetJeuxEchecs", nullptr));
        F7->setText(QString());
        C6->setText(QString());
        H6->setText(QString());
        G2->setText(QString());
        F6->setText(QString());
        G7->setText(QString());
        A3->setText(QString());
        C5->setText(QString());
        H8->setText(QString());
        D3->setText(QString());
        G5->setText(QString());
        A1->setText(QString());
        D7->setText(QString());
        E4->setText(QString());
        D1->setText(QString());
        C4->setText(QString());
        H3->setText(QString());
        E7->setText(QString());
        F5->setText(QString());
        B8->setText(QString());
        H1->setText(QString());
        F2->setText(QString());
        B7->setText(QString());
        D6->setText(QString());
        B4->setText(QString());
        E2->setText(QString());
        H2->setText(QString());
        A4->setText(QString());
        G3->setText(QString());
        E5->setText(QString());
        F8->setText(QString());
        B5->setText(QString());
        C2->setText(QString());
        G8->setText(QString());
        C8->setText(QString());
        D2->setText(QString());
        F1->setText(QString());
        G1->setText(QString());
        A7->setText(QString());
        E8->setText(QString());
        B6->setText(QString());
        C7->setText(QString());
        E1->setText(QString());
        C3->setText(QString());
        H4->setText(QString());
        A8->setText(QString());
        C1->setText(QString());
        G6->setText(QString());
        F4->setText(QString());
        B2->setText(QString());
        A2->setText(QString());
        E3->setText(QString());
        E6->setText(QString());
        H7->setText(QString());
        D8->setText(QString());
        G4->setText(QString());
        D5->setText(QString());
        H5->setText(QString());
        B1->setText(QString());
        B3->setText(QString());
        A5->setText(QString());
        D4->setText(QString());
        A6->setText(QString());
        F3->setText(QString());
        piece->setItemText(0, QCoreApplication::translate("ProjetJeuxEchecsClass", "Roi", nullptr));
        piece->setItemText(1, QCoreApplication::translate("ProjetJeuxEchecsClass", "Dame", nullptr));
        piece->setItemText(2, QCoreApplication::translate("ProjetJeuxEchecsClass", "Fou", nullptr));
        piece->setItemText(3, QCoreApplication::translate("ProjetJeuxEchecsClass", "Chevalier", nullptr));
        piece->setItemText(4, QCoreApplication::translate("ProjetJeuxEchecsClass", "Tour", nullptr));
        piece->setItemText(5, QCoreApplication::translate("ProjetJeuxEchecsClass", "Pion", nullptr));

        couleur->setItemText(0, QCoreApplication::translate("ProjetJeuxEchecsClass", "Blanc", nullptr));
        couleur->setItemText(1, QCoreApplication::translate("ProjetJeuxEchecsClass", "Noir", nullptr));

        ajouter->setText(QCoreApplication::translate("ProjetJeuxEchecsClass", "ajouter", nullptr));
        enlever->setText(QCoreApplication::translate("ProjetJeuxEchecsClass", "enlever", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjetJeuxEchecsClass: public Ui_ProjetJeuxEchecsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETJEUXECHECS_H
