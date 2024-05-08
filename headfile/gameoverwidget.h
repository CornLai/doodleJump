#ifndef GAMEOVERWIDGET_H
#define GAMEOVERWIDGET_H
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>
class GameOverWidget : public QWidget {
  Q_OBJECT
 public:
  GameOverWidget(QStackedWidget *stackedWidget = nullptr,
             QWidget *parent = nullptr);
  // void keyPressEvent(QKeyEvent *event) ;
 private:
  QStackedWidget *stackedWidget;
  

};
#endif