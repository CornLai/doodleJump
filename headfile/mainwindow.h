#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QSound>
#include <QStackedWidget>
#include <QTimer>
#include <QVBoxLayout>
#include <QRect>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>


class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = 0);

 protected:
  // void mouseMoveEvent(QMouseEvent *event);
  // void mousePressEvent(QMouseEvent *event);
  
  // void paintEvent(QPaintEvent *event);
  // void timerEvent(QTimerEvent *event);

 private:
  int x;
  int y;
  int time;
  int timerID;
  QPixmap move_pic;
  QLabel *move_1;
  QImage img;
  QString key;
  QPropertyAnimation *animation;
};






#endif