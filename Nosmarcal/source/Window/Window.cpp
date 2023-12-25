//
// Created by m on 10/26/2023.
//

#include <QUiLoader>
#include <QFile>
#include "Window.h"
#include "Calculator.h"

#include <QLineEdit>
#include <QVBoxLayout>

#include <QTextStream>


Window::Window(QWidget *parent) : QWidget(parent)
{
    inputBar = new QPlainTextEdit;
    inputBar->setPlaceholderText("Enter your code here");

    evaluateButton = new QPushButton;
    evaluateButton->setText("Evaluate");

    textOutput = new QPlainTextEdit;

    auto *verticalLayout = new QVBoxLayout;
    auto *horizontalLayout = new QHBoxLayout;

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
    //textOutput->appendPlainText(inputBar->toPlainText());
    Calculator calculator;
    std::string target = inputBar->toPlainText().toStdString() + '\0';
    calculator.calculate(target);
    //textOutput->appendPlainText("qstr");
}

void Window::printSignalHandler(const std::string& content)
{
    QString qstr = QString::fromUtf8(content.c_str());
    textOutput->appendPlainText(qstr);
}