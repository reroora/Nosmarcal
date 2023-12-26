//
// Created by m on 10/26/2023.
//

#include <QUiLoader>
#include <QFile>
#include "Window.h"
#include "Calculator.h"

#include <QLineEdit>

#include <QTextStream>
#include <iostream>


Window::Window(QWidget *parent) : QWidget(parent)
{
    inputBar = new QPlainTextEdit;
    inputBar->setPlaceholderText("Enter your code here");

    evaluateButton = new QPushButton;
    evaluateButton->setText("Evaluate");

    textOutput = new QTextEdit;
//    textOutput = new QLabel;
    this->verticalLayout = new QVBoxLayout;
    this->horizontalLayout = new QHBoxLayout;

    verticalLayout->addWidget(inputBar);
    verticalLayout->addWidget(evaluateButton);

    horizontalLayout->addLayout(verticalLayout, 1);
    horizontalLayout->addWidget(textOutput);

    this->setLayout(horizontalLayout);


    QWidget::connect(evaluateButton, SIGNAL(clicked(bool)), this, SLOT(evaluateButtonClickedHandler()));
    QWidget::connect(this, SIGNAL(printSignal(std::string)), this, SLOT(printSignalHandler(std::string)));
}

void Window::evaluateButtonClickedHandler()
{
    Calculator calculator;
    std::string target = inputBar->toPlainText().toStdString() + '\0';
    calculator.calculate(target);
}

void Window::printSignalHandler(const std::string& content)
{
    std::cout << "result = " << content << std::endl;
    QString qstr = QString::fromUtf8(content.c_str());
    textOutput->append(qstr);
    textOutput->repaint();
}