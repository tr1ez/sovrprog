#include "calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent), after_operand(true) {
    display = new QLineEdit("0");
    display->setReadOnly(true);

    main_layout = new QGridLayout;
    QPushButton* buttons[16];
    for (int i = 0; i <10; i++) {
        buttons[i] = create_button(QString::number(i), SLOT(digit_clicked()));
    }
    buttons[10] = create_button("+", SLOT(addition_operator_clicked()));
    buttons[11] = create_button("-", SLOT(subtraction_operator_clicked()));
    buttons[12] = create_button("*", SLOT(multiplication_operator_clicked()));
    buttons[13] = create_button("/", SLOT(division_operator_clicked()));
    buttons[14] = create_button("=", SLOT(equal_clicked()));
    buttons[15] = create_button("C", SLOT(clear()));

    main_layout->addWidget(display, 0, 0, 1, 4);
    main_layout->addWidget(buttons[0], 4, 1);
    for (int i = 1; i < 10; i++) {
        int row = ((9 - i) / 3) + 1;
        int column = ((i - 1) % 3);
        main_layout->addWidget(buttons[i], row, column);
    }

    main_layout->addWidget(buttons[10], 1, 3);
    main_layout->addWidget(buttons[11], 2, 3);
    main_layout->addWidget(buttons[12], 3, 3);
    main_layout->addWidget(buttons[13], 4, 3);
    main_layout->addWidget(buttons[14], 4, 2);
    main_layout->addWidget(buttons[15], 4, 0);
    setLayout(main_layout);
    setWindowTitle("Calculator");
}

QPushButton *Calculator::create_button(const QString &text, const char *member) {
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Calculator::digit_clicked() {
    QPushButton *clicked_button = qobject_cast<QPushButton *>(sender());
    int digit_value = clicked_button->text().toInt();
    if (display->text() == "0" && digit_value == 0.0)
        return;
    if (after_operand) {
        display->clear();
        after_operand = false;
    }
    display->setText(display->text() + QString::number(digit_value));
}

void Calculator::addition_operator_clicked() {
    QPushButton *clicked_button = qobject_cast<QPushButton *>(sender());
    after_operand = true;
    memory = display->text();
    current_operator = '+';
}

void Calculator::multiplication_operator_clicked() {
    QPushButton *clicked_button = qobject_cast<QPushButton *>(sender());
    after_operand = true;
    memory = display->text();
    current_operator = '*';
}

void Calculator::subtraction_operator_clicked() {
    QPushButton *clicked_button = qobject_cast<QPushButton *>(sender());
    after_operand = true;
    memory = display->text();
    current_operator = '-';
}

void Calculator::division_operator_clicked() {
    QPushButton *clicked_button = qobject_cast<QPushButton *>(sender());
    after_operand = true;
    current_operator = '/';
}

void Calculator::equal_clicked() {
    QPushButton *clicked_button = qobject_cast<QPushButton *>(sender());
    bool tru = true;
    switch (current_operator) {
            case '+':
                display->setText(QString::number(memory.toInt() + display->text().toInt()));
                break;
            case '*':
                display->setText(QString::number(memory.toInt() * display->text().toInt()));
                break;
            case '/':
                display->setText(QString::number(memory.toInt() / display->text().toInt()));
                break;
            case '-':
                display->setText(QString::number(memory.toInt() - display->text().toInt()));
                break;
            default:
                display->setText("error");
        }
    memory = "";
    after_operand = true;
}

void Calculator::clear() {
    display->setText("0");
    memory = "";
    after_operand = true;
}
