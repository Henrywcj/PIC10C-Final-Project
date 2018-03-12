#include <mainwindow.h>

//generate random int for easy mode
void MainWindow::rand_numb()
{
    //check if the player win(survive the 1:30 minutes) or lose the game(miss 5 times)
    if(easy_game==nullptr) return;
    if(numbers==29)
    {win(easy_game, easy_music);return;}
    if(easy_game->get_mt()>=5)
        {lose(easy_game,easy_music);return;}
    //check if player didn't press any key and remind there is a new letter coming up
    if (numbers>0)
        easy_game->set_ms("Next letter is coming out!");
    if(numbers!=0&&easy_game->get_ct()==correct&&easy_game->get_mt()==missing)
        {easy_game->set_ms("You miss one! No input!"); easy_game->increase_miss();}

    //revert the animal picture back to background picture
    QPixmap bgd(":/grass.jpg");
    boxes[random_pos]->setPixmap(bgd);

    //get a random integer from 1 to 9 and change the background picture into animal picture
    //in corresponding box
    random = rand() % 9 + 1;
    easy_game->set_ri(random);
    random_pos = rand()%9;

        QString test = QString::number(random);

           QPixmap img1(":/Letters/"+test+".png");
           img1 = img1.scaled(boxes[random_pos]->size(),Qt::IgnoreAspectRatio);
           boxes[random_pos]->setPixmap(img1);

        numbers++;
        correct=easy_game->get_ct();
        missing=easy_game->get_mt();
       //repeat this process for every 3 seconds
        counting->singleShot(3000, this, SLOT(rand_numb()));

}

//generate random int for medium mode
void MainWindow::rand_numb_2()
{
    if(medium_game==nullptr) return;

    //check if the player win(survive the 1:30 minutes) or lose the game(miss 5 times)
    if(numbers==29)
    {win(medium_game, medium_music);return;}
    if(medium_game->get_mt()>=5)
        {lose(medium_game,medium_music);return;}
    //check if player didn't press any key and remind there is a new letter coming up
    if (numbers>0)
        medium_game->set_ms("Next letter is coming out!");
    if(numbers!=0&&medium_game->get_ct()==correct&&medium_game->get_mt()==missing)
        {medium_game->set_ms("You miss one! No input!"); medium_game->increase_miss();}


    //revert the animal picture back to background picture
    QPixmap bgd(":/grass.jpg");
    boxes[random_pos]->setPixmap(bgd);

    //get a random integer from 1 to 35 and change the background picture into animal picture
    //in corresponding box
    random = rand() % 35 + 1;
    medium_game->set_ri(random);
    random_pos=rand()%35;
       QString test = QString::number(random);

           QPixmap img1(":/Letters/"+test+".png");
           img1 = img1.scaled(boxes[random_pos]->size(),Qt::IgnoreAspectRatio);
           boxes[random_pos]->setPixmap(img1);

        numbers++;
        correct=medium_game->get_ct();
        missing=medium_game->get_mt();
       //repeat this process for every 2 seconds
        counting->singleShot(popuptime, this, SLOT(rand_numb_2()));

}

//generate random int for hard mode
void MainWindow::rand_numb_3()
{
    if(hard_game==nullptr) return;
    //check if the player win(survive the 1:30 minutes) or lose the game(miss 5 times)
    if(hard_game->get_mt()>=5)
        {lose(hard_game,hard_music);return;}
    else if(numbers==29)
        {win(hard_game, hard_music);return;}
    //check if player didn't press any key and remind there is a new letter coming up
    if(numbers!=0&&hard_game->get_ct()==correct&&hard_game->get_mt()==missing)
        {hard_game->set_ms("You miss one! No input!"); hard_game->increase_miss();}
    else if (numbers>0)
        hard_game->set_ms("Next letter is coming out!");

    //revert the animal picture back to background picture
    QPixmap bgd(":/grass.jpg");
    boxes[random_pos]->setPixmap(bgd);

    //get a random integer from 1 to 40 and change the background picture into animal picture
    //in corresponding box, if random is larger than or equal to 36, the background pic is changed into a bomb
    //appearing at rate 12.5%
    random = rand() % 40 + 1;
    hard_game->set_ri(random);
    random_pos=rand()%35;
       QString test = QString::number(random);

       if(random>=36)
          {
           QPixmap img1(":/Letters/36.png");
           img1 = img1.scaled(boxes[random_pos]->size(),Qt::IgnoreAspectRatio);
           boxes[random_pos]->setPixmap(img1);
           }
       else
       {
           QPixmap img1(":/Letters/"+test+".png");
           img1 = img1.scaled(boxes[random_pos]->size(),Qt::IgnoreAspectRatio);
           boxes[random_pos]->setPixmap(img1);
       }

        numbers++;
        correct=hard_game->get_ct();
        missing=hard_game->get_mt();
       //repeat this process for every 1 seconds
        counting->singleShot(popuptime, this, SLOT(rand_numb_3()));

}
