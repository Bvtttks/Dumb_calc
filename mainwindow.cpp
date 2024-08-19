#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->num0, SIGNAL(clicked(), this, SLOT(Digit_numbers())));
    //connect(ui->num0, signal());
    connect(ui->num0, &QPushButton::clicked, this, &MainWindow::Digit_numbers);
    connect(ui->num1, &QPushButton::clicked, this, &MainWindow::Digit_numbers);
    connect(ui->num2, &QPushButton::clicked, this, &MainWindow::Digit_numbers);
    connect(ui->num3, &QPushButton::clicked, this, &MainWindow::Digit_numbers);
    connect(ui->num4, &QPushButton::clicked, this, &MainWindow::Digit_numbers);
    connect(ui->num5, &QPushButton::clicked, this, &MainWindow::Digit_numbers);
    connect(ui->num6, &QPushButton::clicked, this, &MainWindow::Digit_numbers);
    connect(ui->num7, &QPushButton::clicked, this, &MainWindow::Digit_numbers);
    connect(ui->num8, &QPushButton::clicked, this, &MainWindow::Digit_numbers);
    connect(ui->num9, &QPushButton::clicked, this, &MainWindow::Digit_numbers);

    connect(ui->AC, &QPushButton::clicked, this, &MainWindow::AC_clicked);
    connect(ui->divide, &QPushButton::clicked, this, &MainWindow::Choose_action);
    connect(ui->multiply, &QPushButton::clicked, this, &MainWindow::Choose_action);
    connect(ui->minus, &QPushButton::clicked, this, &MainWindow::Choose_action);
    connect(ui->sum, &QPushButton::clicked, this, &MainWindow::Choose_action);

    connect(ui->dot, &QPushButton::clicked, this, &MainWindow::Dot_clicked);
    connect(ui->equal, &QPushButton::clicked, this, &MainWindow::Calc_Result);
    connect(ui->sign, &QPushButton::clicked, this, &MainWindow::Calc_Result);
    connect(ui->persent, &QPushButton::clicked, this, &MainWindow::Calc_Result);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::Digit_numbers() {
    QPushButton* button = (QPushButton*)sender();
    if(result_str == "0")
        result_str = button->text();
    else
        result_str += button->text();
    ui->result_panel->setText(result_str);
    is_num_setted = true;
}

void MainWindow::AC_clicked() {
    ui->result_panel->setText("0");
    result_str = "0";
    is_num_setted = false;
    operations.clear();
}

void MainWindow::Dot_clicked() {
    if(result_str.contains('.'))
        return;
    QPushButton* button = (QPushButton*)sender();
    result_str += button->text();
    ui->result_panel->setText(result_str);
    is_num_setted = true;
}

void MainWindow::Choose_action() {
    QPushButton* button = (QPushButton*)sender();
    std::pair<double, QChar> prr(result_str.toDouble(), button->text()[0]);
    operations.push_back(prr);
    result_str = "0";
    is_num_setted = false;
}

void MainWindow::Calc_Result() {
    std::pair<double, QChar> prr(result_str.toDouble(), 'f');
    operations.push_back(prr);
    while(operations[0].second != 'f') {
        for(auto it = operations.begin(); it < operations.end(); ++it) {
            if(it->second == '+' && (it + 1)->second != 'x' && (it + 1)->second != '/') {
                (it + 1)->first += it->first;
                operations.erase(it);
                --it;
            } else if(it->second == '-' && (it + 1)->second != 'x' && (it + 1)->second != '/') {
                (it + 1)->first = it->first - (it + 1)->first;
                operations.erase(it);
                --it;
            } else if(it->second == 'x') {
                (it + 1)->first *= it->first;
                operations.erase(it);
                --it;
            } else if(it->second == '/') {
                (it + 1)->first = it->first / (it + 1)->first;
                operations.erase(it);
                --it;
            }
        }
    }
    QPushButton* button = (QPushButton*)sender();
    if(button->text() == '=')
        result_str = QString::number(operations.back().first);
    else if(button->text() == "+/-")
        result_str = QString::number(-1.0 * operations.back().first);
    else
        result_str = QString::number(0.01 * operations.back().first);
    operations.clear();
    ui->result_panel->setText(result_str);
    is_num_setted = false;
}

/*                   я купил пиво, живу красиво
               __  /
              / _)
     _.----._/ /
    /         /
 __/ (  | (  |
/__.-'|_|--|_|
*/































