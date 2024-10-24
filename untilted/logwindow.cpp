#include "logwindow.h"

LogWindow::LogWindow(QWidget *parent) {

    main_layout = new QGridLayout;
    log_try_button = new QPushButton("let me calc");
    login_label = new QLabel;
    password_label = new QLabel;
    login = new QLineEdit;
    password = new QLineEdit;

    login_label->setText("enter login");
    password_label->setText("enter password");

    main_layout->addWidget(login_label, 0, 0);
    main_layout->addWidget(login, 1, 0);
    main_layout->addWidget(password_label, 2, 0);
    main_layout->addWidget(password, 3, 0);
    main_layout->addWidget(log_try_button, 4, 0);
    setLayout(main_layout);
    setWindowTitle("Login");
    connect(log_try_button, &QPushButton::clicked, this, &LogWindow::login_attempt);
}

void LogWindow::login_attempt(){
    if(login->text() == "raz" && password->text() == "dva") {
            emit login_attempt_succeded();
        close();
    }else {
        QMessageBox::warning(this, "incorrect login or password", "try login:raz, password:dva");
    }
}
