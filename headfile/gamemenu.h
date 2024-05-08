// 遊戲主選單
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>
class GameMenu : public QWidget {
  Q_OBJECT
  
 public:
  GameMenu(QStackedWidget *stackedWidget = nullptr, QWidget *parent = nullptr);
 private:
  QWidget *gameWidget;
};