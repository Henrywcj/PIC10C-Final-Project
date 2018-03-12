#ifndef QGAME_H
#define QGAME_H
#include<QApplication>
#include <QLabel>
#include<QKeyEvent>
#include<QWidget>

class QGame: public QLabel
{ 
    public:
        /*Construct a class inherited from QLabel and initialize private fields*/
        QGame();
        /*Key Press Event function to allow players to strick the keyboard in order to interact with the game
        @param event a QKeyEvent pointer to access the key() function in Qt*/
        void keyPressEvent(QKeyEvent *event);

        /*a void function that set the random_integer to be equal to random int selected in mainwindow
           @param random rand_int selected in the mainwindow*/
        void set_ri(int random);

        /*a void function that set the pixmap of top_message according to each msg send
           @param msg message sent to set respective pixmap*/
        void set_ms(QString msg);

        /*an accessor function that returns a pointer to QLabel
          @return top_message*/
        QLabel* get_ms() const {return top_message;}

        /*an accessor function that returns an int
          @return correcttime*/
        int get_ct() const {return correctTime;}

        /*an accessor function that returns an int
          @return missingtime*/
        int get_mt() const {return missingTime;}

        /*a void function used to increment missingtime*/
        void increase_miss() {++missingTime;}

    private:
        int random_integer;
        int missingTime;
        int correctTime;
        QLabel* top_message;


};

#endif // QGAME_H
