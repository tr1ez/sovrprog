#pragma once
#include <QObject>
#include <QLineEdit>
#include <QWidget>
#include <QGridLayout>
#include <Qlabel>
#include <QPushButton>
#include <QMessageBox>

class LogWindow : public QWidget
{
public:
    LogWindow(QWidget *parent = nullptr);
private slots:
    void login_attempt();
private:
    Q_OBJECT
    QGridLayout* main_layout;
    QPushButton* log_try_button;
    QLabel* login_label;
    QLabel* password_label;
    QLineEdit* login;
    QLineEdit* password;
signals:
    void login_attempt_succeded();
};
