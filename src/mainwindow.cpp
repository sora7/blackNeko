#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bindHandlers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load()
{
    cout << "blackNeko" << endl;

    QString url = "http://vignette1.wikia.nocookie.net/oreimo/images/c/c9/Kuroneko_s2_profile.jpg";
    url = "http://example.com/";
    url = "http://www.whatismyuseragent.net/";
    QUrl imgUrl(url);

    loader = new Loader(imgUrl);
    connect(loader,
            SIGNAL(downloaded()),
            this,
            SLOT(imgLoaded()));
}

void MainWindow::imgLoaded()
{
//    QPixmap btnImg;
//    btnImg.loadFromData(loader->downloadedData());
//    ui->label->setPixmap(btnImg);
    QString text = QTextCodec::codecForMib(106)->toUnicode(loader->downloadedData());
    cout << text.toStdString() << endl;
}

void MainWindow::bindHandlers()
{
    connect(ui->pushButton_load,
            SIGNAL(clicked(bool)),
            this,
            SLOT(load()));
}
