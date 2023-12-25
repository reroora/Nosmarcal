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

class Window : public QWidget
{
Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);

private:
    QPlainTextEdit* inputBar;
    QPlainTextEdit* textOutput;
    QPushButton* evaluateButton;

signals:
    void printSignal(std::string content);

public slots:
    void evaluateButtonClickedHandler();
    void printSignalHandler(const std::string& content);
};


#endif //NOSMARCAL_WINDOW_H
