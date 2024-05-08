#include "./headfile/gameoverwidget.h"
GameOverWidget::GameOverWidget(QStackedWidget *stackedWidget, QWidget *parent)
    : QWidget(parent), stackedWidget(stackedWidget) {
  qDebug() << "水水水";
  // TODO這裡要有gameover記分板及 返回主畫面 再來一場 按鈕
}
