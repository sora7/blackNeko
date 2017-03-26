#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QTextCodec>

#include "loader.h"

using namespace std;

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void load();
    void imgLoaded();

private:
    Ui::MainWindow *ui;
    void bindHandlers();

    Loader* loader;
};

#endif // MAINWINDOW_H
