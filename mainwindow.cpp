#include "./headfile/mainwindow.h"

#include "./headfile/gamemenu.h"
#include "./headfile/gamewidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("Doodle Jump");
  setFixedSize(600, 960);  // 初始化主畫面
  QStackedWidget *stackedWidget =
      new QStackedWidget(this);  // 創建 QStackedWidget
  GameMenu *menu =
      new GameMenu(stackedWidget, this);  // 創建遊戲進行選單和進入遊戲選單

  // 將頁面添加到 QStackedWidget
  stackedWidget->addWidget(menu);  // 將頁面添加到 QStackedWidget// index 0
  setCentralWidget(stackedWidget);
  setMouseTracking(true);
}
// void MainWindow::mouseMoveEvent(QMouseEvent *event) {
//   x = event->x();
//   y = event->y();
//   update();
// }
// void MainWindow::mousePressEvent(QMouseEvent *event) {
//   if (event->button() == Qt::LeftButton) {
//     key = "mouse left button";
//     QSound::play("./dataset/test.wav");
//     update();
//   }
// }

// void MainWindow::paintEvent(QPaintEvent *event) {
//   QPainter painter(this);
//   QFont font;
//   QPen pen;
//   painter.setRenderHints(QPainter::Antialiasing, true);
//   painter.drawImage(10, 10, img);
//   if (time == 8) {
//     animation = new QPropertyAnimation(move_1, "pos");
//     animation->setDuration(500);
//     animation->setStartValue(QPoint(10, 50));
//     animation->setEndValue(QPoint(500, 50));
//     animation->start();
//   }
//   font.setPointSize(20);
//   painter.setFont(font);
//   pen.setColor(Qt::black);
//   painter.setPen(pen);
//   painter.drawText(10, 100, QString("X: %1 Y: %2").arg(x).arg(y));
//   painter.drawText(200, 100, QString("time: %1 ").arg(time));
//   painter.drawText(350, 100, QString("key: %1 ").arg(key));
// }

// void MainWindow::timerEvent(QTimerEvent *event) {
//   if (event->timerId() == timerID && timerID != 0) {
//     time = (time == 0) ? 10 : time - 1;
//     update();
//   }
// }
