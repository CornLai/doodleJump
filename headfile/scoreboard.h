#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QWidget>
class ScoreBoard : public QWidget {
  Q_OBJECT
 public:
  ScoreBoard(QWidget *parent = nullptr);
  void culScore(long long score);
 private slots:

  void culHP();
  void onCollision();

 private:
  QHBoxLayout *layout;
  QLabel *scoreLabel;
  QLabel *healthLabel;
  int HP = 3;
  QPixmap fullHeart;
  QPixmap emptyHeart;
};
#endif