#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include "particula.h"

#define ANCHO 1000
#define ALTO 500
# define DT 1.7


namespace Ui {
class application;
}

class application : public QMainWindow
{
    Q_OBJECT

public:
    explicit application(QWidget *parent = 0);
    ~application();

private slots:
    void on_START_clicked();
    void actual_scene();

private:
    Ui::application *ui;
    QTimer *timer =nullptr;
    QGraphicsScene *scene = nullptr;
    particula *partic = nullptr;
};

#endif // APPLICATION_H
