#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <QDebug>
#include <QGraphicsView>
#include <QPointF>
#include <QPushButton>
#include <QStackedWidget>
#include <QTimer>

#include "gamescene.h"
#include "scoreboard.h"
class GameView : public QGraphicsView {
  Q_OBJECT
  signals:
    void gameOver();
 public:
  GameView(QStackedWidget *stackedWidget, GameScene *scene,
           QWidget *parent = nullptr);
  // void paintEvent(QPaintEvent *event) ;
  void setScore(long long);
  bool scrollToPlayer();
  void checkPlayerPosition();

 private:
  ScoreBoard *scoreBoard;
  QPushButton *pauseButton;//TODO暫停按鈕功能未完成
  QTimer *timer;
  long long score = 0;
  GameScene *scene;
  QPointF playerPos;
};
#endif