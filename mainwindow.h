#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPixmap>
#include <QString>
#include <QPushButton>
#include <QDesktopWidget>
#include <QTimer>
#include <QTime>
#include <QMediaPlayer>
#include <QMovie>
#include "qgame.h"


/*The following code creates a welcome page (welcome) that can lead you to the level page(level) and help page(help)
 * , the level page can leed you to three game pages with different levels of difficulty(easy_game, medium_game, hard_game).
 * In the game pages, cute animals will introduce you to a grid, where english letters and digits will randomly pop up.
 *  What you need to do is simply strike the correct english letter on your keyboard, and you can also return to the level page
 * if you want to choose a different level.
 * If you win(survive in the specified time range), you will be automatically led to a win page that tells you to startover, and if you lose(miss 5 times), you will be led to a lose
 * page that tells you to startover.
 *
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /*A function to create gridlayout grid to hold pictures of animals for the game pages*/
    void drawgrid();

    /*a void function to initialize some private fields*/
    void allocate();

    /*void functions to generate win or lose pages
      @param a pointer to QGame object(a game page)
      @param b pointer to QMediaPlayer(the music in correspoinding game page)*/
    void win(QGame* a, QMediaPlayer* b);
    void lose(QGame* a, QMediaPlayer* b);

public slots:
    //slots to change pages in game
    void toHelpPage();
    void toLevelPage();
    void toEasyPage();
    void toMediumPage();
    void toHardPage();
    void help_to_main();
     void easy_to_level();
     void medium_to_level();
     void hard_to_level();
     void newstart_win();
     void newstart_lose();

    //to show the countdown on the game pages
    void showtime();

    //to allow animal pictures to pop up randomly
    void rand_numb();
    void rand_numb_2();
    void rand_numb_3();

private:
    Ui::MainWindow *ui;
    //objects(pages) that point to QGame class that inherite from QLabel
    //in order to transit through different pages and allow key press event in each page
    QGame* Welcome;
    QGame* Level;
    QGame* Help;
    QGame* easy_game;
    QGame* medium_game;
    QGame* hard_game;

    QLabel* win_stage;
    QLabel* lose_stage;

    QWidget* Game;
    QLabel** boxes;
    QGridLayout* grid;
    int nrow;
    int ncol;
    int box_size;
    int random;
    int random_pos;
    int numbers;
    int popuptime;
    int correct;
    int missing;


    QLabel* time_msg;
    QTimer* counting; //general timer
    QTime* time;
    QMediaPlayer* welcome_music;
    QMediaPlayer* easy_music;
    QMediaPlayer* medium_music;
    QMediaPlayer* hard_music;
    QMediaPlayer* win_music;
    QMediaPlayer* lose_music;
};

#endif // MAINWINDOW_H
