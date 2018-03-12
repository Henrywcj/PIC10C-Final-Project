#include <mainwindow.h>



void MainWindow::help_to_main()
{
    Help->close();
    delete Help;
    Help=nullptr;
    Welcome->show();
}

void MainWindow::easy_to_level()
{
    easy_game->close();
    easy_music->stop();
    delete counting;
    delete time;
    delete time_msg;
    delete grid;
    delete boxes;
    delete easy_game;
    easy_game=nullptr;
    delete easy_music;
    allocate();

    Level->show();
    welcome_music->play();
}

void MainWindow::medium_to_level()
{
    medium_game->close();
    medium_music->stop();
    delete counting;
    delete time;
    delete time_msg;
    delete grid;
    delete boxes;
    delete medium_game;
    medium_game=nullptr;
    delete medium_music;
    allocate();

    Level->show();
    welcome_music->play();
}

void MainWindow::hard_to_level()
{
    hard_game->close();
    hard_music->stop();
    delete counting;
    delete time;
    delete time_msg;
    delete grid;
    delete boxes;
    delete hard_game;
    hard_game=nullptr;
    delete hard_music;
    allocate();

    Level->show();
    welcome_music->play();
}

//start new game for win and lose conditions
void MainWindow::newstart_win()
{
    win_stage->close();
    win_music->stop();
    delete win_stage;
    win_stage=nullptr;
    delete win_music;
    allocate();

    Welcome->show();
    welcome_music->play();
}

void MainWindow::newstart_lose()
{
    lose_stage->close();
    lose_music->stop();
    delete lose_stage;
    lose_stage=nullptr;
    delete lose_music;
    allocate();

    Welcome->show();
    welcome_music->play();
}
