#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QTimer>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "platform.h"
#include "player.h"
#include "scoreboard.h"
#include "gamescene.h"
#include "gameview.h"
#include "gameoverwidget.h"
class GameWidget : public QWidget {
  Q_OBJECT
 public:
  GameWidget(QStackedWidget *stackedWidget = nullptr,
             QWidget *parent = nullptr);
  // void keyPressEvent(QKeyEvent *event) ;
  void addGameItem(QGraphicsItem *item);
  long long returnScore();
  void handleGameOver();
 private:
  QStackedWidget *stackedWidget;
  GameScene *scene;
  GameView *view;
  // QHBoxLayout *layout;
  Player *player;
  QTimer *timer;
  QPushButton *pauseButton;
  long long score = 0;
  int lastY = 900;         // 上一個平台的 Y 座標
 private slots:
   void updateGame();
   void spawnPlatform();
  

};
#endif