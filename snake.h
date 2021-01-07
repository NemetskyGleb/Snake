#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QKeyEvent>

class Snake : public QWidget
{
    Q_OBJECT

public:
    Snake(QWidget *parent = 0);
    ~Snake();
protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
private:
    QImage dot;
    QImage head;
    QImage apple;

    static const int B_WIDTH = 300; // длина поля
    static const int B_HEIGHT = 300; // ширина поля
    static const int DOT_SIZE = 10; // размер яблока и частей тела змеи
    static const int ALL_DOTS = 900; // max всех возможных точек
    static const int RAND_POS = 29; // для вычисления случайной пощиции яблока
    static const int DELAY = 140; // скорость игры

    int timerId;
    int dots;
    int apple_x;
    int apple_y;

    int x[ALL_DOTS];
    int y[ALL_DOTS];

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;

    void loadImages();
    void initGame();
    void locateApple();
    void checkApple();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter&);
};

#endif // SNAKE_H
