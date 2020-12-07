#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    led_timer = new QTimer(this);
    led_timer -> connect(led_timer, SIGNAL(timeout()), this, SLOT(update_leds()));
    led_timer -> start(1);

    off_pix = new QPixmap("off_led.png");
    //off_pix->load(");
    on_pix = new QPixmap("on_led.png");

    ui ->label->setPixmap(*off_pix);
    ui -> label_2 ->setPixmap(*off_pix);
    ui -> label_3 ->setPixmap(*off_pix);
    ui -> label_4 ->setPixmap(*off_pix);
    ui -> label_5 ->setPixmap(*off_pix);
    ui -> label_6 ->setPixmap(*off_pix);
    ui -> label_7 ->setPixmap(*off_pix);
    ui -> label_8 ->setPixmap(*off_pix);


    off_switch = new QIcon();
    on_switch = new QIcon();
    off_switch->addPixmap(QPixmap("off_switch.jpeg"),QIcon::Normal,QIcon::On);
    on_switch->addPixmap(QPixmap("on_switch.jpg"),QIcon::Normal,QIcon::On);
    ui->checkBox->setIcon(*off_switch);
    ui->checkBox->setIconSize(QSize(50,50));
    ui->checkBox_2->setIcon(*off_switch);
    ui->checkBox_2->setIconSize(QSize(50,50));
    ui->checkBox_3->setIcon(*off_switch);
    ui->checkBox_3->setIconSize(QSize(50,50));
    ui->checkBox_4->setIcon(*off_switch);
    ui->checkBox_4->setIconSize(QSize(50,50));

    connect(ui->pushButton, SIGNAL(released()), this, SLOT(button1_released()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(button2_released()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(button3_released()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(button4_released()));


}


void MainWindow::update_leds()
{
    string line;
    char tval1, tval2, tval3, tval4, tval5, tval6, tval7, tval8;
    leds_file.open("/dev/leds");
    if (leds_file.is_open())
      {
        while ( getline (leds_file,line) )
        {
          //cout << line << '\n';
        }
        tval1 = line[2] - 48;
        tval2 = line[3] - 48;
        tval3 = line[4] - 48;
        tval4 = line[5] - 48;
        tval5 = line[6] - 48;
        tval6 = line[7] - 48;
        tval7 = line[8] - 48;
        tval8 = line[9] - 48;

        if (tval1 == 1)
            ui ->label->setPixmap(*on_pix);
        else
            ui ->label->setPixmap(*off_pix);
        if (tval2 == 1)
            ui ->label_2->setPixmap(*on_pix);
        else
            ui ->label_2->setPixmap(*off_pix);
        if (tval3 == 1)
            ui ->label_3->setPixmap(*on_pix);
        else
            ui ->label_3->setPixmap(*off_pix);
        if (tval4 == 1)
            ui ->label_4->setPixmap(*on_pix);
        else
            ui ->label_4->setPixmap(*off_pix);
        if (tval5 == 1)
            ui ->label_5->setPixmap(*on_pix);
        else
            ui ->label_5->setPixmap(*off_pix);
        if (tval6 == 1)
            ui ->label_6->setPixmap(*on_pix);
        else
            ui ->label_6->setPixmap(*off_pix);
        if (tval7 == 1)
            ui ->label_7->setPixmap(*on_pix);
        else
            ui ->label_7->setPixmap(*off_pix);
        if (tval8 == 1)
            ui ->label_8->setPixmap(*on_pix);
        else
            ui ->label_8->setPixmap(*off_pix);


        leds_file.close();
      }
    else
    {
        led_timer -> stop();
        cout << "Unable to open leds file, make sure there is a leds file in /dev directory";
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_checkBox_toggled(bool checked)
{
   string line;
   switch_file.open("/dev/switches", ios::out | ios::in);
   if (switch_file.is_open())
   {
       getline (switch_file,line);
       line[2] = checked + 48;
       //std::cout <<line<<std::endl;
       switch_file.seekp(0);
       switch_file << line;
       switch_file.close();
       if (checked)
           ui->checkBox->setIcon(*on_switch);
       else
           ui->checkBox->setIcon(*off_switch);
   }
   else
       cout << "Unable to open switch file, make sure there is a switch file in /dev directory";
}


void MainWindow::on_checkBox_2_clicked(bool checked)
{
    string line;
    switch_file.open("/dev/switches", ios::out | ios::in);
    if (switch_file.is_open())
    {
        getline (switch_file,line);
        line[3] = checked + 48;
        //std::cout <<line<<std::endl;
        switch_file.seekp(0);
        switch_file << line;
        switch_file.close();
        if (checked)
            ui->checkBox_2->setIcon(*on_switch);
        else
            ui->checkBox_2->setIcon(*off_switch);
    }
    else
        cout << "Unable to open switch file, make sure there is a switch file in /dev directory";
}

void MainWindow::on_checkBox_3_clicked(bool checked)
{
    string line;
    switch_file.open("/dev/switches", ios::out | ios::in);
    if (switch_file.is_open())
    {
        getline (switch_file,line);
        line[4] = checked + 48;
        //std::cout <<line<<std::endl;
        switch_file.seekp(0);
        switch_file << line;
        switch_file.close();
        if (checked)
            ui->checkBox_3->setIcon(*on_switch);
        else
            ui->checkBox_3->setIcon(*off_switch);
    }
    else
        cout << "Unable to open switch file, make sure there is a switch file in /dev directory";
}

void MainWindow::on_checkBox_4_clicked(bool checked)
{
    string line;
    switch_file.open("/dev/switches", ios::out | ios::in);
    if (switch_file.is_open())
    {
        getline (switch_file,line);
        line[5] = checked + 48;
        //std::cout <<line<<std::endl;
        switch_file.seekp(0);
        switch_file << line;
        switch_file.close();
        if (checked)
            ui->checkBox_4->setIcon(*on_switch);
        else
            ui->checkBox_4->setIcon(*off_switch);

    }
    else
        cout << "Unable to open switch file, make sure there is a switch file in /dev directory";
}


void MainWindow::on_pushButton_pressed()
{

        string line;
        button_file.open("/dev/buttons", ios::out | ios::in);
        if (button_file.is_open())
        {
            getline (button_file,line);
            line[2] = 49;
            //std::cout <<line<<std::endl;
            button_file.seekp(0);
            button_file << line;
            button_file.close();

        }
        else
            cout << "Unable to open switch file, make sure there is a switch file in /dev directory";

}

void MainWindow::button1_released()
{
    string line;
    button_file.open("/dev/buttons", ios::out | ios::in);
    if (button_file.is_open())
    {
        getline (button_file,line);
        line[2] = 48;
        //std::cout <<line<<std::endl;
        button_file.seekp(0);
        button_file << line;
        button_file.close();

    }
    else
        cout << "Unable to open switch file, make sure there is a switch file in /dev directory";
}
void MainWindow::button2_released()
{
    string line;
    button_file.open("/dev/buttons", ios::out | ios::in);
    if (button_file.is_open())
    {
        getline (button_file,line);
        line[3] = 48;
        //std::cout <<line<<std::endl;
        button_file.seekp(0);
        button_file << line;
        button_file.close();

    }
    else
        cout << "Unable to open switch file, make sure there is a switch file in /dev directory";
}
void MainWindow::button3_released()
{
    string line;
    button_file.open("/dev/buttons", ios::out | ios::in);
    if (button_file.is_open())
    {
        getline (button_file,line);
        line[4] = 48;
        //std::cout <<line<<std::endl;
        button_file.seekp(0);
        button_file << line;
        button_file.close();

    }
    else
        cout << "Unable to open switch file, make sure there is a switch file in /dev directory";
}
void MainWindow::button4_released()
{
    string line;
    button_file.open("/dev/buttons", ios::out | ios::in);
    if (button_file.is_open())
    {
        getline (button_file,line);
        line[5] = 48;
        //std::cout <<line<<std::endl;
        button_file.seekp(0);
        button_file << line;
        button_file.close();

    }
    else
        cout << "Unable to open switch file, make sure there is a switch file in /dev directory";

}



void MainWindow::on_pushButton_2_pressed()
{
    string line;
    button_file.open("/dev/buttons", ios::out | ios::in);
    if (button_file.is_open())
    {
        getline (button_file,line);
        line[3] = 49;
        //std::cout <<line<<std::endl;
        button_file.seekp(0);
        button_file << line;
        button_file.close();

    }
    else
        cout << "Unable to open switch file, make sure there is a switch file in /dev directory";
}

void MainWindow::on_pushButton_3_pressed()
{
    string line;
    button_file.open("/dev/buttons", ios::out | ios::in);
    if (button_file.is_open())
    {
        getline (button_file,line);
        line[4] = 49;
       // std::cout <<line<<std::endl;
        button_file.seekp(0);
        button_file << line;
        button_file.close();

    }
    else
        cout << "Unable to open switch file, make sure there is a switch file in /dev directory";
}

void MainWindow::on_pushButton_4_pressed()
{
    string line;
    button_file.open("/dev/buttons", ios::out | ios::in);
    if (button_file.is_open())
    {
        getline (button_file,line);
        line[5] = 49;
        //std::cout <<line<<std::endl;
        button_file.seekp(0);
        button_file << line;
        button_file.close();

    }
    else
        cout << "Unable to open switch file, make sure there is a switch file in /dev directory";
}
