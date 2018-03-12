#include "qgame.h"

//constructor
QGame::QGame()
{
    QLabel();
    top_message=new QLabel;
    top_message->setFixedHeight(45);
    random_integer=1;
    missingTime=0;
    correctTime=0;
}

void QGame::set_ri(int random)
{
    random_integer=random;
}

//set three types of top messages to inform the player's status
void QGame::set_ms(QString msg)
{
    if(msg=="Get Ready!")
    {QPixmap ready_img(":/ready.png");
    top_message->setPixmap(ready_img);}
    else if(msg=="Good!")
    {QPixmap good_img(":/good.png");
        top_message->setPixmap(good_img);}
    else if(msg=="Ah-oh, you missed one!")
    {
        QPixmap missing_img(":/miss.png");
         top_message->setPixmap(missing_img);
    }
    else if(msg=="You miss one! No input!")
    {
        QPixmap noinput(":/no_input.png");
         top_message->setPixmap(noinput);
    }
    else if(msg=="Next letter is coming out!")
    {
        QPixmap next(":/next.png");
         top_message->setPixmap(next);
    }
}

//Key press event for every digit(1-9) and letter(a-z) and increment missingtime if the player hit the wrong key
void QGame::keyPressEvent(QKeyEvent*event)
{
        //If you press the right key corresponding to the picture, you get a good message
        //If you press the wrong one, you get a bad message
        switch (event->key())
        {
        case Qt::Key_1:
              {set_ms("Good!");correctTime++;}
           if (random_integer != 1){
               missingTime++;
               set_ms("Ah-oh, you missed one!");
              }
           break;
        case Qt::Key_2:
                {set_ms("Good!");correctTime++;}
            if (random_integer != 2){
                missingTime++;
                set_ms("Ah-oh, you missed one!");
               }
            break;
        case Qt::Key_3:
                {set_ms("Good!");correctTime++;}
            if (random_integer != 3){
                missingTime++;
                 set_ms("Ah-oh, you missed one!");
               }
            break;
        case Qt::Key_4:
                {set_ms("Good!");correctTime++;}
            if (random_integer != 4){
                missingTime++;
                 set_ms("Ah-oh, you missed one!");
               }
            break;
        case Qt::Key_5:
               {set_ms("Good!");correctTime++;}
            if (random_integer != 5){
                missingTime++;
                set_ms("Ah-oh, you missed one!");
               }
            break;
        case Qt::Key_6:
                {set_ms("Good!");correctTime++;}
            if (random_integer != 6){
                missingTime++;
                set_ms("Ah-oh, you missed one!");
               }
             break;
        case Qt::Key_7:
                {set_ms("Good!");correctTime++;}
             if (random_integer != 7){
                 missingTime++;
                  set_ms("Ah-oh, you missed one!");
                }
              break;
        case Qt::Key_8:
               {set_ms("Good!");correctTime++;}
              if (random_integer != 8){
                  missingTime++;
                   set_ms("Ah-oh, you missed one!");
                 }
              break;
         case Qt::Key_9:
               {set_ms("Good!");correctTime++;}
              if (random_integer != 9){
                  missingTime++;
                   set_ms("Ah-oh, you missed one!");
                 }
                break;
        case Qt::Key_A:
                     {set_ms("Good!");correctTime++;}
                     if (random_integer != 10){
                         missingTime++;
                          set_ms("Ah-oh, you missed one!");
                       }
                       break;
        case Qt::Key_B:
                     {set_ms("Good!");correctTime++;}
                     if (random_integer != 11){
                         missingTime++;
                        set_ms("Ah-oh, you missed one!");
                       }
                      break;
                case Qt::Key_C:
                     {set_ms("Good!");correctTime++;}
                     if (random_integer != 12){
                         missingTime++; set_ms("Ah-oh, you missed one!");
                       }
                      break;
                case Qt::Key_D:
                    {set_ms("Good!");correctTime++;}
                     if (random_integer != 13){
                         missingTime++; set_ms("Ah-oh, you missed one!");
                       }
                      break;
                case Qt::Key_E:
                    {set_ms("Good!");correctTime++;}
                     if (random_integer != 14){
                         missingTime++; set_ms("Ah-oh, you missed one!");
                       }
                      break;
                case Qt::Key_F:
                   {set_ms("Good!");correctTime++;}
                     if (random_integer != 15){
                         missingTime++; set_ms("Ah-oh, you missed one!");
                       }
                      break;
                case Qt::Key_G:
                    {set_ms("Good!");correctTime++;}
                     if (random_integer != 16){
                         missingTime++; set_ms("Ah-oh, you missed one!");}
                      break;
                case Qt::Key_H:
                     {set_ms("Good!");correctTime++;}
                     if (random_integer != 17){
                         missingTime++; set_ms("Ah-oh, you missed one!");}
                      break;
                case Qt::Key_I:
                     {set_ms("Good!");correctTime++;}
                    if (random_integer != 18){
                        missingTime++; set_ms("Ah-oh, you missed one!");
                      }
                    break;
                case Qt::Key_J:
                     {set_ms("Good!");correctTime++;}
                     if (random_integer != 19){
                         missingTime++; set_ms("Ah-oh, you missed one!");
                       }
                      break;
                case Qt::Key_K:
                     {set_ms("Good!");correctTime++;}
                     if (random_integer != 20){
                         missingTime++; set_ms("Ah-oh, you missed one!");
                       }
                      break;
                case Qt::Key_L:
                     {set_ms("Good!");correctTime++;}
                     if (random_integer != 21){
                         missingTime++; set_ms("Ah-oh, you missed one!");
                       }
                      break;
                case Qt::Key_M:
                     {set_ms("Good!");correctTime++;}
                     if (random_integer != 22){
                         missingTime++; set_ms("Ah-oh, you missed one!");
                       }
                      break;
                case Qt::Key_N:
                     {set_ms("Good!");correctTime++;}
                     if (random_integer != 23){
                         missingTime++; set_ms("Ah-oh, you missed one!");
                       }
                      break;
        case Qt::Key_O:
             {set_ms("Good!");correctTime++;}
             if (random_integer != 24){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_P:
             {set_ms("Good!");correctTime++;}
             if (random_integer != 25){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_Q:
            {set_ms("Good!");correctTime++;}
             if (random_integer != 26){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_R:
             {set_ms("Good!");correctTime++;}
             if (random_integer != 27){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_S:
            {set_ms("Good!");correctTime++;}
             if (random_integer != 28){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_T:
            {set_ms("Good!");correctTime++;}
             if (random_integer != 29){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_U:
            {set_ms("Good!");correctTime++;}
             if (random_integer != 30){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_V:
           {set_ms("Good!");correctTime++;}
             if (random_integer != 31){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_W:
             {set_ms("Good!");correctTime++;}
             if (random_integer != 32){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_X:
       {set_ms("Good!");correctTime++;}
             if (random_integer != 33){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_Y:
            {set_ms("Good!");correctTime++;}
             if (random_integer != 34){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_Z:
        {set_ms("Good!");correctTime++;}
             if (random_integer != 35){
                 missingTime++; set_ms("Ah-oh, you missed one!");
               }
              break;
        case Qt::Key_Space:
          {set_ms("Good!");correctTime++;}
             if(!(random_integer >=36))
             {
                 missingTime++;set_ms("Ah-oh, you missed one!");
             }
             break;
        default:
            keyPressEvent(event);
             }
}
