#include "./headfile/gamemenu.h"
#include "./headfile/gamewidget.h"
GameMenu::GameMenu(QStackedWidget *stackedWidget,QWidget *parent) : QWidget(parent) {
   this->setFixedSize(540,960);
  // 創建遊戲選單背景
  QPixmap background("./dataset/images/reference-start-interface.png");  
  QLabel *backgroundLabel = new QLabel(this);
  backgroundLabel->setPixmap(background.scaled(540,960));
  backgroundLabel->setScaledContents(true);
  backgroundLabel->setAlignment(Qt::AlignCenter);
  // 創建一個開始遊戲按鈕
  QPushButton *startButton = new QPushButton(this);
  startButton->move(90,255);
  startButton->setFixedSize(180, 80);
  // 使用樣式表去除按鈕的背景和邊框
  startButton->setStyleSheet(
      "QPushButton {"
      "background-color: transparent;"  // 背景透明
      "border: none;"                   // 去除邊框
      "}");
  // 連接按鈕的點擊信號到槽函數
  connect(startButton, &QPushButton::clicked, [=]
        {
            gameWidget = new GameWidget(stackedWidget, this);
            stackedWidget->addWidget(gameWidget);  // index 1
            stackedWidget->setCurrentIndex(1);  // 切換到第二個頁面（遊戲畫面）
            gameWidget->setFocusPolicy(Qt::StrongFocus);
            qDebug() << "遊戲開始" ;
        });
}

