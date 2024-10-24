#pragma once

#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QKeyEvent>

class QLineEdit;

class Calculator : public QWidget {
    public:
        Calculator(QWidget *parent = nullptr);
    private slots:
        void digit_clicked();
        void addition_operator_clicked();
        void multiplication_operator_clicked();
        void subtraction_operator_clicked();
        void division_operator_clicked();
        void equal_clicked();
        void clear();
    private:
        Q_OBJECT
        QLineEdit* display;
        QGridLayout* main_layout;
        QString memory;
        char current_operator;
        bool after_operand;
        QPushButton *create_button(const QString &text, const char *member);
};
