#include "mainwindow.h"
#include "ui_mainwindow.h"

/*construct a welcome window of the game with start, help, exit buttons*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      //welcome
      //welcome labels, buttons, images

      QVBoxLayout *welcome_layout = new QVBoxLayout;
      QLabel *title = new QLabel("LItEraTe FArM");
      title->setAlignment(Qt::AlignCenter);
      QPixmap title_img(":/title1.png");
      title->setPixmap(title_img);

      QPushButton *start = new QPushButton(this);
      start->setText("START");
      start->setFixedSize(150,60);

      QPushButton* help = new QPushButton(this);
      help->setText("HELP");
      help->setFixedSize(150,60);

      QPushButton* exit= new QPushButton(this);
      exit->setText("EXIT");
      exit->setFixedSize(150,60);

      //set window name and background picture
      Welcome=new QGame;
      Welcome->setWindowTitle("Literate Farm");
      QDesktopWidget dw;
      int x=dw.width()*0.8;int y=dw.height()*0.8;Welcome->setFixedSize(x,y);
      QPixmap pixmap(":/vector-set-of-cute-cartoon-animal.png");
      pixmap = pixmap.scaled(Welcome->size(), Qt::IgnoreAspectRatio);
      QPalette palette;
      palette.setBrush(QPalette::Background, pixmap);
      Welcome->setPalette(palette);
      welcome_music=new QMediaPlayer();
      welcome_music->setMedia(QUrl("qrc:/Music/Welcome.mp3"));
      welcome_music->play();


      //welcome layout
      welcome_layout->addWidget(title);
      welcome_layout->addWidget(start,0, Qt::AlignCenter);
      welcome_layout->addWidget(help,0, Qt::AlignCenter);
      welcome_layout->addWidget(exit,0, Qt::AlignCenter);
      Welcome->setLayout(welcome_layout);

      //connections
      //connect start and help to advance to the next page, connect exit to close the main window
      QObject::connect(start,SIGNAL(clicked()),this,SLOT(toLevelPage()));
      QObject::connect(help,SIGNAL(clicked()),this,SLOT(toHelpPage()));
      QObject::connect(exit, SIGNAL(clicked()),QApplication::instance(),SLOT(quit()));

      Welcome->show();
    allocate();

}

/*Initialize some private fields*/
void MainWindow::allocate()
{
    correct=0;
    missing=0;
    numbers=0;
    random=1;
    random_pos=1;
    time=new QTime;
    time_msg=new QLabel;
    counting=new QTimer(this);
    Game=new QWidget;
    grid=new QGridLayout(Game);
}

/*Help Page of the game, explains how to play the game*/
void MainWindow::toHelpPage()
{
    Welcome->close();
    //Help_stage
    //set window name and background
    Help = new QGame;
    Help->setWindowTitle("Literate Farm");
    QDesktopWidget dw;
    int x=dw.width()*0.8;int y=dw.height()*0.8;Help->setFixedSize(x,y);
    QPixmap pixmap(":/background.jpg");
    pixmap = pixmap.scaled(Help->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pixmap);
    Help->setPalette(palette);

    //help labels, buttons
    QLabel *levelt = new QLabel("LItEraTe FArM");
    levelt->setAlignment(Qt::AlignCenter);
    QPixmap leveltop(":/level.png");
    levelt->setPixmap(leveltop);

    QLabel *ani1 = new QLabel;
    QMovie *animation = new QMovie(":/cat2.gif");
    animation->start();
    ani1->setAttribute(Qt::WA_NoSystemBackground);
    ani1->setMovie(animation);

    QLabel *ani3 = new QLabel;
    QMovie *animation3 = new QMovie(":/cat3.gif");
    animation3->start();
    ani3->setAttribute(Qt::WA_NoSystemBackground);
    ani3->setMovie(animation3);


    //a text label to explain how to play the game, a button to return to the welcom page
    QLabel *txt = new QLabel;
    QPushButton* retrn = new QPushButton("RETURN");
    retrn ->setFixedSize(200, 90);
    retrn->setStyleSheet("font: bold 25pt \"Times New Roman\";");
    txt->setFixedSize(400, 500);
    txt->setWordWrap(true);
    txt->setText("Welcome, this is a game for kids and people who want to learn basic english"
                 " word. <br>In this game, cute animals will introduce you to a n*n grid, where"
                 " english letters and digits will pop up. <br> What you need to do is simply strike the correct"
                 " english letter on your keyboard. There are three levels in this game: easy, "
                 " medium, and hard. Each level represent different levels of difficulties. <br> "
                 "Easy level will be 3*3; medium will be 5*7; hard will be 5*7<br>"
                 "To win, you need to hit 30 correct keys in each level with missing 5 or less keys<br>"
                 "However, in the hard level, there will be bomb(Trump) coming up and you need to destroy it by hitting Space Key,  prepared for the upcoming challenge and enjoy the game.");
    txt->setAlignment(Qt::AlignTop);
    txt->setStyleSheet("font: bold 15pt;");

    //help page layout
    QVBoxLayout *help_layout = new QVBoxLayout;
    help_layout->addWidget(levelt,0);
       help_layout->addWidget(ani3,0,Qt::AlignCenter);
    help_layout->addWidget(txt, 0, Qt::AlignCenter);
    help_layout->addWidget(ani1,0,Qt::AlignBottom);
    help_layout->addWidget(retrn, 0 ,Qt::AlignCenter);
    Help->setLayout(help_layout);
    Help->show();

    //connect return button with a slot to return to the welcome page
    QObject::connect(retrn, SIGNAL(clicked()), this, SLOT(help_to_main()));
}



/*The Level page of the game, introduces three levels of difficulty*/
void MainWindow::toLevelPage()
{
     Welcome->close();
     //LEVEL PAGE
     //level labels, buttons, images
     QVBoxLayout *level_layout=new QVBoxLayout;
     QPushButton* easy=new QPushButton("EASY");
     easy->setFixedSize(150,60);
     QPushButton* medium=new QPushButton("MEDIUM");
     medium->setFixedSize(150,60);
     QPushButton* hard=new QPushButton("HARD");
     hard->setFixedSize(150,60);

     //connections
     //connect the three buttons to game stages of different level
     QObject::connect(easy,SIGNAL(clicked()),this,SLOT(toEasyPage()));
     QObject::connect(medium,SIGNAL(clicked()),this,SLOT(toMediumPage()));
     QObject::connect(hard,SIGNAL(clicked()),this,SLOT(toHardPage()));

     //set level window name and background picture
     Level=new QGame;
     Level->setWindowTitle("Literate Farm");
     QDesktopWidget dw;
     int x=dw.width()*0.8; int y=dw.height()*0.8; Level->setFixedSize(x,y);
     QPixmap pixmap(":/vector-set-of-cute-cartoon-animal.png");
     pixmap = pixmap.scaled(Level->size(), Qt::IgnoreAspectRatio);
     QPalette palette; palette.setBrush(QPalette::Background, pixmap);
     Level->setPalette(palette);

     //level layout
     level_layout->addWidget(easy,0, Qt::AlignCenter);
     level_layout->addWidget(medium,0, Qt::AlignCenter);
     level_layout->addWidget(hard,0, Qt::AlignCenter);

     Level->setLayout(level_layout);
     Level->show();
}

void MainWindow::drawgrid()
{
    //initialize a qlabel matrix boxes to hold each picture of animals(first set a backgroud picture)
    //initialize a gridlayout grid to hold elements in boxes
    boxes = new QLabel*[nrow*ncol];
    QPixmap *pic = new QPixmap(":/grass.jpg");

    //put each qlabel object in the qlabel matrix boxes into the gridlayout grid
    for(int i=0;i<nrow;i++)
    {
        for(int j=0;j<ncol;j++)
        {
            boxes[i*ncol+j]=new QLabel;
            boxes[i*ncol+j]->setFixedSize(box_size,box_size);
            boxes[i*ncol+j]->setFrameStyle(1);
            boxes[i*ncol+j]->setPixmap(*pic);
            grid->addWidget(boxes[i*ncol+j],i,j);
        }
    }

}

void MainWindow::showtime()
{
    //for every 1 second, show time through the time_msg label
      *time=time->addSecs(-1);
      time_msg->setText(time->toString());
}


/*The Easy Mode Game Stage, a 3x3 grid with digits appearing every 3 seconds and a countdown of 1:30 minutes */
void MainWindow::toEasyPage()
{
    Level->close();
    welcome_music->stop();
    //Start the 1:30 minute countdown
    QObject::connect(counting,SIGNAL(timeout()),this,SLOT(showtime()));
    counting->singleShot(1000,this,SLOT(rand_numb()));
    counting->start(1000);
    time->setHMS(0,1,30);
    time_msg->setStyleSheet("font:bold 30pt");

    //EASY Page
    //set window name and background pic
    easy_game=new QGame;
    easy_game->setWindowTitle("Literate Farm");
    QDesktopWidget dw;int x=dw.width()*0.8; int y=dw.height()*0.8;
    easy_game->setFixedSize(x,y);
    QPixmap pixmap(":/farm.png");
    pixmap = pixmap.scaled(easy_game->size(), Qt::IgnoreAspectRatio);
    QPalette palette;palette.setBrush(QPalette::Background, pixmap);
    easy_game->setPalette(palette);
    easy_music=new QMediaPlayer();
    easy_music->setMedia(QUrl("qrc:/Music/Easy.mp3"));
    easy_music->play();
    QPushButton* retrn = new QPushButton("RETURN");
    retrn ->setFixedSize(100, 50);
    retrn->setStyleSheet("font: bold 15pt \"Times New Roman\";");
    QObject::connect(retrn, SIGNAL(clicked()), this, SLOT(easy_to_level()));
    QString msg="Get Ready!";
    easy_game->set_ms(msg);

    //create the game grid
    Game=new QWidget;
    nrow=3; ncol=3; box_size=150;
    drawgrid();
    Game->setLayout(grid);

    //Easy stage layout
    QHBoxLayout* temp=new QHBoxLayout;
    temp->addWidget(retrn,0,Qt::AlignCenter);
    temp->addWidget(time_msg,0,Qt::AlignCenter);
    QVBoxLayout* easy_layout=new QVBoxLayout;
    easy_layout->addWidget(easy_game->get_ms(),0,Qt::AlignCenter);
    easy_layout->addWidget(Game,0,Qt::AlignCenter);
    easy_layout->addLayout(temp);

    easy_game->setLayout(easy_layout);
    easy_game->show();
}

/*The Medium Mode Game Stage, a 5x7 grid with a
 * countdown of 1:00 minute*/
void MainWindow::toMediumPage()
{
    Level->close();
    welcome_music->stop();
    //Start the 1:00 minute countdown
    QObject::connect(counting,SIGNAL(timeout()),this,SLOT(showtime()));
    popuptime=2000;
    counting->singleShot(1000,this,SLOT(rand_numb_2()));
    counting->start(1000);
    time->setHMS(0,1,0);
    time_msg->setStyleSheet("font:bold 30pt");

    //Medium Page
    //Set background pic and window name
    medium_game=new QGame;
    medium_game->setWindowTitle("Literate Farm");
    QDesktopWidget dw;int x=dw.width()*0.8; int y=dw.height()*0.8;
    medium_game->setFixedSize(x,y);
    QPixmap pixmap(":/farm.png");
    pixmap = pixmap.scaled(medium_game->size(), Qt::IgnoreAspectRatio);
    QPalette palette;palette.setBrush(QPalette::Background, pixmap);
    medium_game->setPalette(palette);
    medium_music=new QMediaPlayer();
    medium_music->setMedia(QUrl("qrc:/Music/Medium.mp3"));
    medium_music->play();
    QPushButton* retrn = new QPushButton("RETURN");
    retrn ->setFixedSize(100, 50);
    retrn->setStyleSheet("font: bold 15pt \"Times New Roman\";");
    QObject::connect(retrn, SIGNAL(clicked()), this, SLOT(medium_to_level()));
    QString msg="Get Ready!";
    medium_game->set_ms(msg);

    //Create the game grid
    Game=new QWidget;
    nrow=5; ncol=7; box_size=90;
    drawgrid();
    Game->setLayout(grid);

    //Medium Layout
    QHBoxLayout* temp=new QHBoxLayout;
    temp->addWidget(retrn,0,Qt::AlignCenter);
    temp->addWidget(time_msg,0,Qt::AlignCenter);
    QVBoxLayout* medium_layout=new QVBoxLayout;
    medium_layout->addWidget(medium_game->get_ms(),0,Qt::AlignCenter);
    medium_layout->addWidget(Game,0,Qt::AlignCenter);
    medium_layout->addLayout(temp);

    medium_game->setLayout(medium_layout);
    medium_game->show();
}


/*The Hard Mode Game Stage, a 5x7 grid with a
 * countdown of 30 seconds*/
void MainWindow::toHardPage()
{
    Level->close();
    welcome_music->stop();
    //Start the 1:30 minute countdown
    popuptime=1000;
    QObject::connect(counting,SIGNAL(timeout()),this,SLOT(showtime()));
    counting->singleShot(1000,this,SLOT(rand_numb_3()));

    counting->start(1000);
    time->setHMS(0,0,30);
    time_msg->setStyleSheet("font:bold 30pt");

    //Hard Page
    //set window name and background pic
    hard_game=new QGame;
    hard_game->setWindowTitle("Literate Farm");
    QDesktopWidget dw;int x=dw.width()*0.8; int y=dw.height()*0.8;
    hard_game->setFixedSize(x,y);
    QPixmap pixmap(":/farm.png");
    pixmap = pixmap.scaled(hard_game->size(), Qt::IgnoreAspectRatio);
    QPalette palette;palette.setBrush(QPalette::Background, pixmap);
    hard_game->setPalette(palette);
    hard_music=new QMediaPlayer();
    hard_music->setMedia(QUrl("qrc:/Music/Hard.mp3"));
    hard_music->play();
    QPushButton* retrn = new QPushButton("RETURN");
    retrn ->setFixedSize(100, 50);
    retrn->setStyleSheet("font: bold 15pt \"Times New Roman\";");
    QObject::connect(retrn, SIGNAL(clicked()), this, SLOT(hard_to_level()));
    QString msg="Get Ready!";
    hard_game->set_ms(msg);

    //create the game grid
    Game=new QWidget;
    nrow=5; ncol=7; box_size=90;
    drawgrid();
    Game->setLayout(grid);

    //hard game layout
    QHBoxLayout* temp=new QHBoxLayout;
    temp->addWidget(retrn,0,Qt::AlignCenter);
    temp->addWidget(time_msg,0,Qt::AlignCenter);
    QVBoxLayout* hard_layout=new QVBoxLayout;
    hard_layout->addWidget(hard_game->get_ms(),0,Qt::AlignCenter);
    hard_layout->addWidget(Game,0,Qt::AlignCenter);
    hard_layout->addLayout(temp);

    hard_game->setLayout(hard_layout);
    hard_game->show();
}


/*The win page that throws a win message and the startover button*/
void MainWindow::win(QGame* a, QMediaPlayer* b)
{
    //delete all the dynamically allocated objects in game page
    a->close();
    delete counting;
    delete time;
    delete time_msg;
    delete grid;
    delete boxes;
    delete a;
    a = nullptr;
    b->stop();
    delete b;
    //delete other pages
    delete Level;
    allocate();

    //Win Stage
    //Set window name and background pic
    win_stage=new QLabel;
    win_stage->setWindowTitle("Literate Farm");
    QDesktopWidget dw;int x=dw.width()*0.8; int y=dw.height()*0.8;
    win_stage->setFixedSize(x,y);
    QPixmap pixmap(":/winlose/background.png");
    pixmap = pixmap.scaled(win_stage->size(), Qt::IgnoreAspectRatio);
    QPalette palette;palette.setBrush(QPalette::Background, pixmap);
    win_stage->setPalette(palette);
    win_music=new QMediaPlayer;
    win_music->setMedia(QUrl("qrc:/Music/win.mp3"));
    win_music->play();

    //Win stage labels and button
    QLabel* output=new QLabel;
    QPixmap win1(":/winlose/win.png");
    output->setPixmap(win1);
    QLabel* output2=new QLabel;
    QPixmap win2(":/winlose/win2.png");
    output2->setPixmap(win2);
    QPushButton* start_over=new QPushButton("START OVER!");

    QLabel *ani1 = new QLabel;
    QMovie *animation = new QMovie(":/winlose/win_cat.gif");
    animation->start();
    ani1->setAttribute(Qt::WA_NoSystemBackground);
    ani1->setMovie(animation);
    ani1->setAlignment(Qt::AlignCenter);


    //Win stage Layout
    QObject::connect(start_over, SIGNAL(clicked()),this, SLOT(newstart_win()));
    QVBoxLayout* layout=new QVBoxLayout;
    layout->addWidget(output, Qt::AlignCenter);
    layout->addWidget(output2, Qt::AlignCenter);
    layout->addWidget(ani1);
    layout->addWidget(start_over, Qt::AlignCenter);
    win_stage->setLayout(layout);
    win_stage->show();

}

/*The lose page that throws a lose message and the startover button*/
void MainWindow::lose(QGame* a,QMediaPlayer* b)
{
    //delete all the dynamically allocated objects in game pages
    a->close();
    delete counting;
    delete time;
    delete time_msg;
    delete grid;
    delete boxes;
    delete a;
    a = nullptr;
    b->stop();
    delete b;
    //delete other pages
    delete Level;
    allocate();

    //Lose Stage
    //set window name and background pic
    lose_stage=new QLabel;
    lose_stage->setWindowTitle("Literate Farm");
    QDesktopWidget dw;int x=dw.width()*0.8; int y=dw.height()*0.8;
    lose_stage->setFixedSize(x,y);
    QPixmap pixmap(":/winlose/lose_background.png");
    pixmap = pixmap.scaled(lose_stage->size(), Qt::IgnoreAspectRatio);
    QPalette palette;palette.setBrush(QPalette::Background, pixmap);
    lose_stage->setPalette(palette);
    lose_music=new QMediaPlayer;
    lose_music->setMedia(QUrl("qrc:/Music/lose.mp3"));
    lose_music->play();

    //lose stage label and button
    QLabel* output=new QLabel;
    QPixmap lose1(":/winlose/lose.png");
    output->setPixmap(lose1);

    QLabel *ani = new QLabel;
    QMovie *anima = new QMovie(":/winlose/lose_cat.gif");
    anima->start();
    ani->setAttribute(Qt::WA_NoSystemBackground);
    ani->setMovie(anima);
    ani->setAlignment(Qt::AlignCenter);

    QPushButton* start_over=new QPushButton("START OVER!");

    //lose stage layout
    QObject::connect(start_over, SIGNAL(clicked()),this, SLOT(newstart_lose()));
    QVBoxLayout* layout=new QVBoxLayout;
    layout->addWidget(output, Qt::AlignCenter);
    layout->addWidget(ani);
    layout->addWidget(start_over, Qt::AlignCenter);
    lose_stage->setLayout(layout);
    lose_stage->show();
}



MainWindow::~MainWindow()
{
    delete ui;
}
