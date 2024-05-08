#ifndef PLAYER_H
#define PLAYER_H
// 創建player類別
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLabel>
#include <QObject>
#include <QScrollArea>
#include <QScrollBar>
#include <QSound>

#include "platform.h"
class Player : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
  // signals:
  //   void outOfBounds();
 public:
  Player();
  void jump();
  void update();
  // bool checkDroping();
  // QRect returncollisionRect();
   long long returnScore();

   void turnLeft();
   void turnRight();
  void keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
      turnLeft();
      turnflag=0;
    } else if (event->key() == Qt::Key_Right) {
      turnRight();
      turnflag=1;
    }
  }
 public slots:
  void checkCollision();

 private:
  qreal velocity;
  qreal Lvelocity;
  qreal Rvelocity;
  qreal gravity;
  qreal jumpDistance;
  qreal leftDistance;
  qreal rightDistance;
  const qreal maxJumpDistance = 320;
  const qreal maxLRDistance = 50;
  QRect collisionRect;
  bool collisionFlag = false;
  long long score = 0;
  bool turnflag=0;
};
#endif