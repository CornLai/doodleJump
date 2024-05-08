#ifndef GAMEOVERWIDGET_H
#define GAMEOVERWIDGET_H
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>
#include "gamewidget.h"
class GameOverWidget : public QWidget {
  Q_OBJECT
 public:
  GameOverWidget(QStackedWidget *stackedWidget = nullptr,
             QWidget *parent = nullptr);
  void setScore(long long);
  // void keyPressEvent(QKeyEvent *event) ;
  private slots:
    void goToMenu();
    void goToGame();
 private:
  QStackedWidget *stackedWidget;
  QPushButton *menuButton;
  QPushButton *playAgainButton;
  QLabel *scoreBoard;
  QHBoxLayout *hLayout;
  QVBoxLayout *vLayout;
  QHBoxLayout *scoreLayout;
  long long score =0;
  QWidget *parent;

};
#endif