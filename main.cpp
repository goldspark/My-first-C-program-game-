//this is where is the gameplay!


#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include "loadsave.h"
#include "Creatures.h"


void check_rating(Player *p, Creatures *c); //rating check so it knows who to send against player
void computer_decision(Player *p, Creatures *c, char *i); //computer thinking
int player_special = 3; // gain 2 hp every three rounds
int computer_special = 3; // loose 5 hp every three rounds

int random_number(int x); //random stuff to happen
int set_level = 0;
int gold = 100; //in game currency
bool in_market = false; //checks to see if player in shopping
bool loop = true;
int computer_selected = 0;
bool computer_special_active = false;
bool player_special_active = false;
bool computer_defense_active = false;
bool player_defense_active = false;
bool alive = false;
int player_damage;
int computer_damage;
int check = 0;

//leveling
int new_playerhp = 0;
int new_playerdmg = 0;
int new_playerrating = 0;

int new_computerhp = 0;
int new_computerdmg = 0;
int new_computerrating = 0;
 double temp1 = 0;
 double temp2 = 0;

int main()
{

    srand(time(nullptr)); //set random number seed


    char *input = new char[10]; //console input

    char *name = new char[10];

    std::cout << "Welcome to Conzol Arena!" << std::endl;
    std::cout << "What is your name? : ";
    std::cin.getline(input, 9);
    strncpy(name, input, 9);
    std::ifstream load("save.txt");



   if((check = load_game1(input, load)) == -1)
   {


        delete [] name;
        delete [] input;
            return - 1;
   }

   Player player(100, 10, 0); // starting player
   new_playerhp = player.get_health();
   new_playerdmg = player.get_damage();
   new_playerrating = player.get_rating();
   Creatures creature(100, 10, 10); // starting creature
   new_computerhp = creature.get_health();
   new_computerdmg = creature.get_damage();
   new_computerrating = creature.get_rating();


    //END OF LOAD FUNCTION
    std::ofstream save;
    //saving game
    if(no_save)
    {
        check = save_game1(name, save);
        if(check == -1)
        {


        delete [] name;
        delete [] input;
            return - 1;
        }

    }




    std::cout << " Welcome to the game " << name << std::endl;


    //main game loop
    check = 0;
    bool main_menu = true;
    while(loop)
    {
        while(main_menu) // main menu options
        {


        std::cout << "1: Battle " << std::endl;
        std::cout << "2: Your stats " << std::endl;
        std::cout << "market: Market" << std::endl;
        std::cout << "4: Exit " << std::endl;
        std::cin.getline(input, 9);
        while((strcmp(input,"1")  !=  0) && (strcmp(input,"2")  !=  0) && (strcmp(input,"market")  !=  0)) // make sure player selects correct option
        {

         std::cin.getline(input, 9);

        }
         //Player selected second option
         while((strcmp(input,"2")  ==  0))
         {
             system("cls");
             std::cout << "Type anything except 2 to go back to main menu." << std::endl;
             player.get_stats(temp1);
             std::cin.getline(input, 9);

         }


         //Player selected fourth option
         if((strcmp(input,"4")  ==  0))
         {
             break;

         }
         //Player selected third option
         if((strcmp(input,"market")  ==  0))
         {
             in_market = true;

             while(in_market)
             {


              player.get_stats(temp1);
              std::cout <<"Available items(3 for exit):\n1:Sword of Fury(+10 dmg) = 50 gold\n2:Gun of lolita(+15 dmg) = 75 gold";
              std::cin.getline(input, 9);
              if(strcmp(input,"3") == 0) // exit
              {
                  in_market = false;
              }
              if(strcmp(input,"1") == 0) // selected first item
              {
                  if(gold >= 50)
                  {
                  gold = gold - 50;

                  std::cout << "Successfully purchased Sword of Fury(+10 dmg)!" << std::endl;
                  std::cout << "Your gold: " << gold << std::endl;
                  player.set_status_d(0,10,0); // upgrade damage
                  }

              }

              if(strcmp(input,"2") == 0) // selected second item
              {
                  if(gold >= 50)
                  {
                  gold = gold - 75;
                  system("cls");
                  std::cout << "Successfully purchased Gun of lolita(+15 dmg)!" << std::endl;
                  std::cout << "Your gold: " << gold << std::endl;
                  player.set_status_d(0,15,0); // upgrade damage
                  }

              }


             }

         }

         //Player selected first option
         if((strcmp(input,"1")  ==  0))
         {
             system("cls");
             main_menu = false;

         }


        } // end of main menu options


       //first option game starts... this is the main thing in the code
      while(true)
      {
          temp1 = new_playerhp; //for percentage calculations
          temp2 = new_computerhp; //

       if((strcmp(input,"4")  ==  0))
       {
        break;
       }
       //Player selected third option
         if((strcmp(input,"market")  ==  0))
         {
             in_market = true;

             while(in_market)
             {


              player.get_stats(temp1);
              std::cout <<"Available items(3 for exit):\n1:Sword of Fury(+10 dmg) = 50 gold\n2:Gun of lolita(+15 dmg) = 75 gold";
              std::cin.getline(input, 9);
              if(strcmp(input,"3") == 0) // exit
              {
                  in_market = false;
              }
              if(strcmp(input,"1") == 0) // selected first item
              {
                  if(gold >= 50)
                  {
                  gold = gold - 50;

                  std::cout << "Successfully purchased Sword of Fury(+10 dmg)!" << std::endl;
                  std::cout << "Your gold: " << gold << std::endl;
                  player.set_status_d(0,10,0); // upgrade damage
                  }

              }

              if(strcmp(input,"2") == 0) // selected second item
              {
                  if(gold >= 50)
                  {
                  gold = gold - 75;
                  system("cls");
                  std::cout << "Successfully purchased Gun of lolita(+15 dmg)!" << std::endl;
                  std::cout << "Your gold: " << gold << std::endl;
                  player.set_status_d(0,15,0); // upgrade damage
                  }

              }


             }

         }


       system("cls");
       if(player_special > 0 && player_special_active) // use specials at the start
       {
           player.set_status_d(2,0,0);
           std::cout << name << "'s special used! " << name << " gained 2hp." << std::endl;
           player_special--;

       }
       if(player_special == 0)
       {
           std::cout << name << "'s special expired! " << std::endl;
           player_special_active = false;
       }

       if(computer_special > 0 && computer_special_active)
       {
           player.set_status_r(5,0,0);
           std::cout << "Creature special used! " << name << " lost 5hp." << std::endl;
           computer_special--;

       }
       if(computer_special == 0)
       {
           std::cout << "Creature special expired! " << std::endl;
           computer_special_active = false;
       }


       //end of specials

       check_rating(&player, &creature); // sets fight at the beginning

       std::cout << "Level: " << set_level << std::endl;
       std::cout << "\n\n\n";
       creature.get_stats(temp2);
       std::cout << "\n\n\n";
       player.get_stats(temp1);
       std::cout << "Choose what you wanna do: " << std::endl;
       std::cout << "1: Attack(" << player.get_damage() << ")" << std::endl;
       std::cout << "2: Defense(Next turn you block 50% of enemy damage)" << std::endl;
       std::cout << "3: Use special ability" << std::endl;
       std::cin.getline(input, 9);
       player_damage = player.get_damage();
       if(strcmp(input, "1")==0) // player selected first option
       {

           if(computer_defense_active)
           {
               player_damage = player_damage / 2;
               computer_defense_active = false;
           }
           system("cls");
           creature.set_status_r(player_damage, 0, 0);
           std::cout << name << " used Attack it was effective.";
           std::cout <<"Enemy lost " << player_damage << "hp" << std::endl;
       }
        if(strcmp(input, "2")==0) // player selected second option
       {


           system("cls");
           player_defense_active = true;
           std::cout << name << " used Defense.";
           std::cout <<"Enemy will do now 50% less damage " << std::endl;
       }
        if(strcmp(input, "3")==0) // player selected third option
       {


           system("cls");
           player_special_active = true;
           std::cout << name << " used Special ability.";
           std::cout <<name<< " will now get 2 hp every round." << std::endl;

       }
       if(creature.get_health() <= 0)
       {
           gold = gold + 2;
           std::cout << "Player won!" << std::endl;
           std::cout << "Gold recieved +2 now you have " << gold << std::endl;
           std::cin.get();
           alive = true;

       }
       if(strcmp(input, "market")!= 0)
       {


       computer_decision(&player, &creature, input); // COMPUTER TURN
       computer_damage = creature.get_damage();
       if(computer_selected == 1)
       {
           if(player_defense_active)
           {
               computer_damage = computer_damage / 2;
               player_defense_active = false;
           }

           player.set_status_r(computer_damage, 0, 0);
       }
        if(computer_selected == 2)
       {
           computer_defense_active = true;
       }

       if(computer_selected == 3)
       {
           computer_special_active = true;
       }


       //END OF COMPUTER TURN
       if(player.get_health() <= 0 && alive == false)
       {
           std::cout << "Computer won!" << std::endl;
           break;
       }
       }



      }//end of main game




      break;


    }


    //at the end we free the memory and close files in use


    delete [] name;
    delete [] input;


    return 0;
}



void computer_decision(Player *p, Creatures *c, char *i)
{




          int choose = random_number(3) + 1; //50/50

          computer_selected = choose;
          if(computer_selected == 1)
          {
              std::cout << "Computer attacked player and player lost " << c->get_damage() << std::endl;
              return;
          }
          else if(computer_selected == 2)
          {
              std::cout << "Computer changed to defensive position " <<std::endl;
              return;
          }
          else
          {
              if(computer_special <= 0) // choose again in case he already used specials
              {
                  int choose_again = random_number(2) + 1;

                  computer_selected = choose_again;

                      if(computer_selected == 1)
                      {
                       std::cout << "CHComputer attacked player and player lost " << c->get_damage() << std::endl;

                      }
                      else if(computer_selected == 2)
                      {
                      std::cout << "CHComputer changed to defensive position " <<std::endl;

                      }


                  return;

              }

              std::cout << "I used my special ability! You will now loose 5 hp every three rounds" << std::endl;
              return;



  }



}

int random_number(int x) // iot returns from 1 to x
{
    return rand() % x;
}

void check_rating(Player *p, Creatures *c)
{

  //check the difference
  int difference = abs(p->get_rating() - c->get_rating());
  std::cout << "Difference: " << difference << std::endl;
  if(alive)
  {



   new_playerhp = new_playerhp + 5;
   new_playerdmg = new_playerdmg + 5;
   new_playerrating = new_playerrating + 5;



  if(difference == 0 || p->get_rating() > c->get_rating())
  {
       new_computerhp = new_computerhp + 20;
   new_computerdmg = new_computerdmg + 15;
   new_computerrating = new_computerrating + 10;

   c->set_damage(new_computerdmg);
   c->set_health(new_computerhp);
   c->set_rating(new_computerrating);
  }

  if(p->get_rating() < c->get_rating())
  {
      set_level++;
       c->set_damage(new_computerdmg);
   c->set_health(new_computerhp);
   c->set_rating(new_computerrating);
   p->set_damage(new_playerdmg);
   p->set_health(new_playerhp);
   p->set_rating(new_playerrating);

  }

  }

  alive = false;
}
