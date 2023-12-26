//
// Created by m on 10/26/2023.
//

#ifndef NOSMARCAL_WINDOW_H
#define NOSMARCAL_WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class Window : public QWidget
{
Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private:
    QPlainTextEdit* inputBar;
    //QPlainTextEdit* textOutput;
    QTextEdit* textOutput;
//    QLabel* textOutput;
    QPushButton* evaluateButton;

    QVBoxLayout* verticalLayout;
    QHBoxLayout* horizontalLayout;

signals:
    void printSignal(std::string content);

public slots:
    void evaluateButtonClickedHandler();
    void printSignalHandler(const std::string& content);
};


#endif //NOSMARCAL_WINDOW_H
