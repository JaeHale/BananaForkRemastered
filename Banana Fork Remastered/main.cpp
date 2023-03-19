/******************************************************************************

Welcome to Banana Fork REMASTERED, the best way to play the Banana Fork Series.

*******************************************************************************/
#include <stdio.h>
#include <termios.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstring>
using namespace std;

int main()
{
  //Color Codes Setup
  const std::string lyellow("\033[38;5;228m");
  const std::string yellow("\033[38;5;11m");
  const std::string gold("\033[38;5;220m");
  const std::string green("\033[38;5;40m");
  const std::string blue("\033[38;5;69m");
  const std::string lgray("\033[38;5;252m");
  const std::string gray("\033[38;5;247m");
  const std::string dgray("\033[38;5;238m");
  const std::string reset("\033[38;5;15m");
  const std::string goodending("\033[38;5;47m");
  const std::string badending("\033[38;5;196m");
  std::string color("\033[38;5;15m");
  
  //Bonus Game Setup
  int passedChapter1 {};
  int passedChapter2 {};
  int passedChapter3 {};
  int trueChapter2 {};
  int trueChapter3 {};
  passedChapter1 = 0;
  passedChapter2 = 0;
  passedChapter3 = 0;
  
  //Banana Fork Logo
MainMenuChoice:
  system("clear");
  cout << gold << "8b" << yellow << "adPPYba," << endl;                             
  cout << gold << "88" << yellow << "P’    `8" << lyellow << "a" << endl;
  cout << gold << "88" << yellow << "       d" << lyellow << "8" << endl;
  cout << gold << "88" << yellow << "b,   ,a8" << lyellow << "'" << endl;
  cout << gold << "88" << yellow << "`YbbdP''" << lyellow << "   ,abYPPdab8 88,dPPYba,   ,abYPPdab8 88,dPPYba,   ,abYPPdab8" << endl;
  cout << gold << "88" << yellow << "P’    `8a a8`    ’P88 88      `8a a8`     ’P8 88’     `8a a8`    ’P88      " << endl;
  cout << gold << "88" << yellow << "       d8 8d       88 88       88 8d       88 88       88 8d       88      " << endl;
  cout << gold << "88" << yellow << "b,   ,a8' '8a,   ,b88 88       88 '8a,   ,b88 88       88 '8a,   ,b88      " << endl;
  cout << gold << "88`YbbdP''   ''PdbbY`88 88       88  ''PdbbY`88 88       88  ''PdbbY`88      " << endl;
  cout << dgray << "             8" << gray << "8YbbdPP’" << lgray << "’" << endl;
  cout << dgray << "             8" << gray << "8’                               " << lgray << "88   PP" << endl;
  cout << dgray << "             8" << gray << "8                                88  dPP" << endl;
  cout << dgray << "             8" << gray << "8YbbdPP’’                        88PP’’" << endl;
  cout << dgray << "             8" << gray << "8’          " << lgray << ",ad8ba,   88,dPPYba, " << gray << "88" << endl;
  cout << dgray << "             8" << gray << "8          d8'` ’'8b  88’        88PP,, " << endl;
  cout << dgray << "             8" << gray << "8         d8'     '8b 88         88  dPP" << endl;
  cout << dgray << "             8" << gray << "8          Y8a. .a8P  88         88   PP" << endl;
  cout << dgray << "             88           `'Y8Y''   88         88   PP" << endl;
  cout << reset << "" << endl;
  cout << "This is the REMASTERED Edition of Banana Fork, featuring all three chapters and so much more!" << endl;
  cout << reset << "" << endl;
  
  //Main Menu
  int Menu();
  {
    //Display Menu Options  
    string menuChoice, playString = "play", settingsString = "settings", creditsString = "credits", quitString = "quit";
    cout << lyellow << "[PLAY]" << endl;
    cout << yellow << "[SETTINGS]" << endl;
    cout << yellow << "[CREDITS]" << endl;
    cout << gold << "[QUIT]" << endl;
    cout << reset << "(Please type the Menu Option you wish to select)." << endl;
    getline (cin, menuChoice);
    system("clear");
    
    //Play Choice Functionality
    if (strcasecmp(playString.c_str(), menuChoice.c_str()) == 0)
    {
      //Code for Locking Chapters
    ChapterMenuChoice:
      int chapterChoice;
      string jesusString;
      chapterChoice = 0;
      if (passedChapter1 == 0 && passedChapter2 == 0)
      {
        //Beaten no Chapters
        cout << lyellow << "        PLAY THE GAME" << endl;  
        cout << green << "Chapter 1: The Banana [UNLOCKED]" << endl;
        cout << gray << "Chapter 2: The Family [LOCKED]" << endl;
        cout << gray << "Chapter 3: The Conclusion [LOCKED]" << reset << endl;
      }
      else if (passedChapter1 == 1 && passedChapter2 == 0)
      {
        //Beaten Chapter 1  
        cout << yellow << "        PLAY THE GAME" << endl;  
        cout << green << "Chapter 1: The Banana [UNLOCKED]" << endl;
        cout << green << "Chapter 2: The Family [UNLOCKED]" << endl;
        cout << gray << "Chapter 3: The Conclusion [LOCKED]" << reset << endl;
      }
      else if (passedChapter1 == 1 && passedChapter2 == 1 && passedChapter3 == 0)
      {
        //Beaten Chapter 2
        cout << gold << "        PLAY THE GAME" << endl;  
        cout << green << "Chapter 1: The Banana [UNLOCKED]" << endl;
        cout << green << "Chapter 2: The Family [UNLOCKED]" << endl;
        cout << green << "Chapter 3: The Conclusion [UNLOCKED]" << reset << endl;
      }
      else if (passedChapter1 == 1 && passedChapter2 == 1 && passedChapter3 == 1 && trueChapter2 == 1 && trueChapter3 == 1)
      {
        //Gotten Both True Endings (Bonus Game Unlocked)
        cout << gold << "        PLAY THE GAME" << endl;  
        cout << green << "Chapter 1: The Banana [UNLOCKED]" << endl;
        cout << green << "Chapter 2: The Family [UNLOCKED]" << endl;
        cout << green << "Chapter 3: The Conclusion [UNLOCKED]" << endl;
        cout << yellow << "Chapter 4: The Aftermath [UNLOCKED]" << reset << endl;
      }
      
      //Choose a chapter
      cin >> chapterChoice;
      
      //I'm not a religious person at all but without this string the game wouldn't work.
      getline (cin, jesusString);
      
      //Go to said chapter
      if (chapterChoice == 1)
      {
        //Chapter 1
        int theBanana();
        {
        RestartChapter1:
          system("clear");
          
          //Set up for choices
          string bananaChoice, dudeChoice, confrontChoice, foodType, spellName;
          int spellLevel, endingNumber;
          foodType = "banana";
          spellLevel = 0;
          
          //Beginning Text
          cout << color << "Welcome to the game. You will have to make choices or something." << endl;
          cout << "" << endl;
        EatIgnoreMagicChoice:
          cout << "You wake up in a bed and look around. You are in a room in a motel." << endl;
          cout << "On the dresser of the room, you see a " << foodType << "." << endl;
          cout << "" << endl;
          
          if (foodType == "gun")
          {
          //First choice (Gun)
          cout << "Do you shoot it, ignore it, or magic it?" << endl;
          getline (cin, bananaChoice);
          system("clear");
          }
          
          else
          {
          //First choice (Normal)
          cout << "Do you eat it, ignore it, or magic it?" << endl;
          getline (cin, bananaChoice);
          system("clear");  
          }
          
          //Setup options
          string magicString = "magic", eatString = "eat", shootString = "shoot", ignoreString = "ignore", yesString = "yes", noString = "no", fightString = "fight", runString = "run";
          string eatAnswer, shootAnswer, ignoreAnswer, fightAnswer;
          
          //Magic option
          if (strcasecmp(magicString.c_str(), bananaChoice.c_str()) == 0)
          {
            if (spellLevel == 0)
            {
              //Level 0
              cout << "" << endl;
              cout << "Sorry, you are not a high enough level to do magic." << endl;
              spellLevel += 1;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto EatIgnoreMagicChoice;
            }
            else if (spellLevel < 5)
            {
              //Level 1-4
              cout << "" << endl;
              cout << "Sorry, you are not a high enough level to do magic." << endl;
              cout << "(Keep training your magic to level up.)" << endl;
              spellLevel += 1;
              std::this_thread::sleep_for(std::chrono::milliseconds(1000));
              system("clear");
              goto EatIgnoreMagicChoice;
            }
            else if (spellLevel == 5)
            {
              //Level 5
              cout << "" << endl;
              cout << "Congrats! You are a high enough level to do magic." << endl;
              spellLevel += 1;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto EatIgnoreMagicChoice;
            }
            else if (spellLevel > 5)
            {
              //Higher Levels
              cout << "" << endl;
              cout << "You use your magic to transform the banana into..." << endl;
              getline (cin, spellName);
              system("clear");
              
              string pineappleString = "pineapple", appleString = "apple", gunString = "gun", bombString = "bomb";
              if (strcasecmp(pineappleString.c_str(), spellName.c_str()) == 0)
              {
                //Pineapple
                cout << "" << endl;
                cout << "There's not even a pineapple in this game but okay." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                foodType = "pineapple";
                goto EatIgnoreMagicChoice;
              }
              else if (strcasecmp(appleString.c_str(), spellName.c_str()) == 0)
              {
                //Apple
                cout << "" << endl;
                cout << "An apple? Sure, why not." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                foodType = "apple";
                goto EatIgnoreMagicChoice;
              }
              else if (strcasecmp(gunString.c_str(), spellName.c_str()) == 0)
              {
                //Gun
                cout << "" << endl;
                cout << "No need to flaunt your nationality." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                foodType = "gun";
                goto EatIgnoreMagicChoice;
              }
              else if (strcasecmp(bombString.c_str(), spellName.c_str()) == 0)
              {
                //Bomb
                cout << "" << endl;
                cout << "Oh man, that sucks for you..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 5;
                goto Ending1;
              }
              else
              {
                //Other food
                foodType = spellName;
                cout << "" << endl;
                cout << "1...2...3... Poof! The banana turns into a: " << foodType << "." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                goto EatIgnoreMagicChoice;
              }
            }
          }
          
          //Eat option
          else if ((strcasecmp(eatString.c_str(), bananaChoice.c_str()) == 0) && foodType != "gun") 
          {
          EatYesNoChoice:
            cout << "You pick up the " << foodType << " and eat it." << endl;
            cout << "You look to your right and see someone standing in the doorway of the motel room." << endl;
            cout << "The person steps into the room and asks you, 'Dude did you eat my " << foodType << "?'" << endl;
            cout << "" << endl;
            cout << "Do you tell him yes or no?" << endl;
            getline (cin, eatAnswer);
            system("clear");
            
            //Eat and yes
            if ((strcasecmp(eatString.c_str(), bananaChoice.c_str()) == 0) && (strcasecmp(yesString.c_str(), eatAnswer.c_str()) == 0))
            {
            EatYesFightChoice:
              cout << color << "The person shrieks." << endl;
              cout << "'WHY WOULD YOU EAT MY PRICELESS FAMILY HEIRLOOM!? I'M GOING TO KILL YOU!!'" << endl;
              cout << "" << endl;
              cout << "Do you fight him or run?" << endl;
              getline (cin, fightAnswer);
              
              //Eat, yes, and fight
              if ((strcasecmp(yesString.c_str(), eatAnswer.c_str()) == 0) && (strcasecmp(fightString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to fight the person..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 4;
                goto Ending1;
              }
              
              //Eat, yes, and run
              else if ((strcasecmp(yesString.c_str(), eatAnswer.c_str()) == 0) && (strcasecmp(runString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to run away..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 2;
                goto Ending1;
              }
              
              //Incorrect input
              else
              {
                system("clear");
                cout << "" << endl;
                cout << reset << "That is not an option, please try again." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                goto EatYesFightChoice;
              }
            }
            
            //Eat and no
            else if ((strcasecmp(eatString.c_str(), bananaChoice.c_str()) == 0) && (strcasecmp(noString.c_str(), eatAnswer.c_str()) == 0))
            {
            EatNoFightChoice:
              cout << color << "The person shrieks." << endl;
              cout << "'Why are you lying? I saw you eat it. I'M GOING TO KILL YOU!!'" << endl;
              cout << "" << endl;
              cout << "Do you fight him or run?" << endl;
              getline (cin, fightAnswer);
              
              //Eat, no, and fight
              if ((strcasecmp(noString.c_str(), eatAnswer.c_str()) == 0) && (strcasecmp(fightString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to fight the person..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 4;
                goto Ending1;
              }
              
              //Eat, no, and run
              else if ((strcasecmp(noString.c_str(), eatAnswer.c_str()) == 0) && (strcasecmp(runString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to run away..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 2;
                goto Ending1;
              }
              
              //Incorrect input
              else
              {
                system("clear");
                cout << "" << endl;
                cout << reset << "That is not an option, please try again." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                goto EatNoFightChoice;
              }
            }
            
            //Incorrect input
            else
            {
              system("clear");
              cout << "" << endl;
              cout << reset << "That is not an option, please try again." << endl;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto EatYesNoChoice;
            }
          }
          
          //Shoot option
          else if ((strcasecmp(shootString.c_str(), bananaChoice.c_str()) == 0) && foodType == "gun") 
          {
          ShootYesNoChoice:
            cout << "You pick up the " << foodType << " and shoot it." << endl;
            cout << "You look to your right and see someone standing in the doorway of the motel room." << endl;
            cout << "The person steps into the room and asks you, 'Dude did you shoot my " << foodType << "?'" << endl;
            cout << "" << endl;
            cout << "Do you tell him yes or no?" << endl;
            getline (cin, shootAnswer);
            system("clear");
            
            //Shoot and yes
            if ((strcasecmp(shootString.c_str(), bananaChoice.c_str()) == 0) && (strcasecmp(yesString.c_str(), shootAnswer.c_str()) == 0))
            {
            ShootYesFightChoice:
              cout << "The person shrieks." << endl;
              cout << "'WHY WOULD YOU SHOOT MY PRICELESS FAMILY GUN!? I'M GOING TO KILL YOU!!'" << endl;
              cout << "" << endl;
              cout << "Do you fight him or run?" << endl;
              getline (cin, fightAnswer);
              
              //Shoot, yes, and fight
              if ((strcasecmp(yesString.c_str(), shootAnswer.c_str()) == 0) && (strcasecmp(fightString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to fight the person..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 4;
                goto Ending1;
              }
              
              //Shoot, yes, and run
              else if ((strcasecmp(yesString.c_str(), shootAnswer.c_str()) == 0) && (strcasecmp(runString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to run away..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 2;
                goto Ending1;
              }
              
              //Incorrect input
              else
              {
                system("clear");
                cout << "" << endl;
                cout << reset << "That is not an option, please try again." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                goto ShootYesFightChoice;
              }
            }
            
            //Shoot and no
            else if ((strcasecmp(shootString.c_str(), bananaChoice.c_str()) == 0) && (strcasecmp(noString.c_str(), shootAnswer.c_str()) == 0))
            {
            ShootNoFightChoice:  
              cout << color << "The person shrieks." << endl;
              cout << "'Why are you lying? I saw you shoot it. I'M GOING TO KILL YOU!!'" << endl;
              cout << "" << endl;
              cout << "Do you fight him or run?" << endl;
              getline (cin, fightAnswer);
              
              //Shoot, no, and fight
              if ((strcasecmp(yesString.c_str(), shootAnswer.c_str()) == 0) && (strcasecmp(fightString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to fight the person..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 4;
                goto Ending1;
              }
              
              //Shoot, no, and run
              else if ((strcasecmp(yesString.c_str(), shootAnswer.c_str()) == 0) && (strcasecmp(runString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to run away..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 2;
                goto Ending1;
              }
              
              //Incorrect input
              else
              {
                system("clear");
                cout << "" << endl;
                cout << reset << "That is not an option, please try again." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                goto ShootNoFightChoice;
              }
            }
            
            //Incorrect input
            else
            {
              system("clear");
              cout << "" << endl;
              cout << reset << "That is not an option, please try again." << endl;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto ShootYesNoChoice;
            }
          }
          
          //Ignore option
          else if ((strcasecmp(ignoreString.c_str(), bananaChoice.c_str()) == 0) && foodType != "gun") 
          {
          IgnoreYesNoChoice:
            cout << "You stare at the " << foodType << " instead of eating it." << endl;
            cout << "You look to your right and see someone standing in the doorway of the motel room." << endl;
            cout << "The person steps into the room and asks you, 'Dude did you eat my " << foodType << "?'" << endl;
            cout << "" << endl;
            cout << "Do you tell him yes or no?" << endl;
            getline (cin, ignoreAnswer);
            system("clear");
            
            //Ignore and yes
            if ((strcasecmp(ignoreString.c_str(), bananaChoice.c_str()) == 0) && (strcasecmp(yesString.c_str(), ignoreAnswer.c_str()) == 0))
            {
              cout << "" << endl;
              cout << "'I can see you haven't eaten it, are you blind or something?' the person asks." << endl;
              std::this_thread::sleep_for(std::chrono::milliseconds(4000));
              system("clear");
              endingNumber = 1;
              goto Ending1;
            }
            
            //Ignore and no
            else if ((strcasecmp(ignoreString.c_str(), bananaChoice.c_str()) == 0) && (strcasecmp(noString.c_str(), ignoreAnswer.c_str()) == 0))
            {
            IgnoreNoFightChoice:
              cout << "The person relaxes." << endl;
              cout << "'Oh thanks for telling me. I'm blind so I couldn't tell.'" << endl;
              cout << "" << endl;
              cout << "Do you fight him or run?" << endl;
              getline (cin, fightAnswer);
              
              //Ignore, no, and fight
              if ((strcasecmp(noString.c_str(), ignoreAnswer.c_str()) == 0) && (strcasecmp(fightString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to fight the person..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 6;
                goto Ending1;
              }
              
              //Ignore, no, and run
              else if ((strcasecmp(noString.c_str(), ignoreAnswer.c_str()) == 0) && (strcasecmp(runString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to run away..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 3;
                goto Ending1;
              }
              
              //Incorrect input
              else
              {
                system("clear");
                cout << "" << endl;
                cout << reset << "That is not an option, please try again." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                goto IgnoreNoFightChoice;
              }
            }
            
            //Incorrect input
            else
            {
              system("clear");
              cout << "" << endl;
              cout << reset << "That is not an option, please try again." << endl;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto IgnoreYesNoChoice;
            }
          }
          
          //Ignore option (Gun)
          else if ((strcasecmp(ignoreString.c_str(), bananaChoice.c_str()) == 0) && foodType == "gun") 
          {
          IgnoreYesNoGunChoice:
            cout << "You stare at the " << foodType << " instead of shooting it." << endl;
            cout << "You look to your right and see someone standing in the doorway of the motel room." << endl;
            cout << "The person steps into the room and asks you, 'Dude did you shoot my " << foodType << "?'" << endl;
            cout << "" << endl;
            cout << "Do you tell him yes or no?" << endl;
            getline (cin, ignoreAnswer);
            system("clear");
            
            //Ignore and yes
            if ((strcasecmp(ignoreString.c_str(), bananaChoice.c_str()) == 0) && (strcasecmp(yesString.c_str(), ignoreAnswer.c_str()) == 0))
            {
              cout << "" << endl;
              cout << "'I can see you haven't shot it, are you blind or something?' the person asks." << endl;
              std::this_thread::sleep_for(std::chrono::milliseconds(4000));
              system("clear");
              endingNumber = 1;
              goto Ending1;
            }
            
            //Ignore and no
            else if ((strcasecmp(ignoreString.c_str(), bananaChoice.c_str()) == 0) && (strcasecmp(noString.c_str(), ignoreAnswer.c_str()) == 0))
            {
            IgnoreNoFightGunChoice:
              cout << "The person relaxes." << endl;
              cout << "'Oh thanks for telling me. I'm blind so I couldn't tell.'" << endl;
              cout << "" << endl;
              cout << "Do you fight him or run?" << endl;
              getline (cin, fightAnswer);
              
              //Ignore, no, and fight
              if ((strcasecmp(noString.c_str(), ignoreAnswer.c_str()) == 0) && (strcasecmp(fightString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to fight the person..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 6;
                goto Ending1;
              }
              
              //Ignore, no, and run
              else if ((strcasecmp(noString.c_str(), ignoreAnswer.c_str()) == 0) && (strcasecmp(runString.c_str(), fightAnswer.c_str()) == 0))
              {
                cout << "" << endl;
                cout << "You tried to run away..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 3;
                goto Ending1;
              }
              
              //Incorrect input
              else
              {
                system("clear");
                cout << "" << endl;
                cout << reset << "That is not an option, please try again." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                goto IgnoreNoFightGunChoice;
              }
            }
            
            //Incorrect input
            else
            {
              system("clear");
              cout << "" << endl;
              cout << reset << "That is not an option, please try again." << endl;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto IgnoreYesNoGunChoice;
            }
          }
          
          //Incorrect input
            else
            {
              system("clear");
              cout << "" << endl;
              cout << reset << "That is not an option, please try again." << endl;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto EatIgnoreMagicChoice;
            }
            
          //The end of the chapter
        Ending1:
          string endingChoice, restartString = "restart", quitString = "quit";
          if (endingNumber == 1)
          {
            //Ignore and yes ending
            cout << badending << "" << endl;
            cout << "You go home depressed because you are blind." << endl;
            cout << "BAD ENDING 1" << endl;
          }
          else if (endingNumber == 2)
          {
            //Eat (or shoot), yes, and run ending
            cout << badending << "" << endl;
            cout << "...But you tripped and died." << endl;
            cout << "BAD ENDING 2" << endl;
          }
          else if (endingNumber == 3)
          {
            //Ignore, no, and run ending
            cout << badending << "" << endl;
            cout << "...'Why are you running away, you didn't do anything.' As the person calls after you you trip and die." << endl;
            cout << "BAD ENDING 3" << endl;
          }
          else if (endingNumber == 4)
          {
            //Eat (or shoot), yes, and fight ending
            cout << badending << "" << endl;
            cout << "...But they got so mad they killed you." << endl;
            cout << "BAD ENDING 4" << endl;
          }
          else if (endingNumber == 5)
          {
            //Bomb ending
            cout << badending << "" << endl;
            cout << "The banana transforms into a bomb which promptly blows up, killing you instantly." << endl;
            cout << "BAD ENDING 5" << endl;
          }
          else if (endingNumber == 6)
          {
            //Ignore, no, fight ending
            passedChapter1 = 1;
            cout << goodending << "" << endl;
            cout << "...And win because the person was so confused as to why you were fighting them." << endl;
            cout << "GOOD ENDING" << endl;
          }
          
          //Restart or quit
        RestartChoice1:
          cout << reset << "" << endl;
          cout << "Would you like to restart or quit?" << endl;
          getline (cin, endingChoice);
          
          if (strcasecmp(restartString.c_str(), endingChoice.c_str()) == 0)
          {
            //Restart
            goto RestartChapter1;
          }
          else if (strcasecmp(quitString.c_str(), endingChoice.c_str()) == 0)
          {
            //Quit
            goto MainMenuChoice;
          }
          else
          {
            //Incorrect input
            system("clear");
            cout << "" << endl;
            cout << reset << "That is not an option, please try again." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            system("clear");
            goto RestartChoice1;
          }
        }
      }
      else if (chapterChoice == 2 && passedChapter1 == 1)
      {
        //Chapter 2
        int theFamily();
        {
        RestartChapter2:
          system("clear");
          
          //Set up for choices
          string bodyChoice, spellName, bodyPlace, knowPlace, carabinerChoice2;
          int spellLevel, endingNumber;
          spellLevel = 0;
          
          //Beginning Text
          cout << color << "Welcome to the game. You will have to make choices or something." << endl;
          cout << "" << endl;
        BodyPlaceChoice:
          cout << "You wake up in a bed and look around. You are in a room in a motel." << endl;
          cout << "On the dresser of the room you see a banana, and on the floor of the room there is a dead body." << endl;
          cout << "You wonder why there is a dead body on the floor, and then you remember..." << endl;
          cout << "the magic... The person... The Banana..." << endl;
          cout << "" << endl;
          
          //First choice
          cout << "Do you hide it, ignore it, or magic it?" << endl;
          getline (cin, bodyChoice);
          system("clear");
          
          //Setup options
          string magicString = "magic", hideString = "hide", ignoreString = "ignore", bedString = "bed", bathroomString = "bathroom", closetString = "closet", knowString = "know", don_tKnowString = "don't know", dontKnowString = "dont know";
          string carabinerString = "carabiner";
          
          //Magic option
          if (strcasecmp(magicString.c_str(), bodyChoice.c_str()) == 0)
          {
            if (spellLevel == 0)
            {
              //Level 0
              cout << "" << endl;
              cout << "Sorry, you are not a high enough level to do magic." << endl;
              spellLevel += 1;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto BodyPlaceChoice;
            }
            else if (spellLevel < 5)
            {
              //Level 1-4
              cout << "" << endl;
              cout << "Sorry, you are not a high enough level to do magic." << endl;
              cout << "(Keep training your magic to level up.)" << endl;
              spellLevel += 1;
              std::this_thread::sleep_for(std::chrono::milliseconds(1000));
              system("clear");
              goto BodyPlaceChoice;
            }
            else if (spellLevel == 5)
            {
              //Level 5
              cout << "" << endl;
              cout << "Congrats! You are a high enough level to do magic." << endl;
              spellLevel += 1;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto BodyPlaceChoice;
            }
            else if (spellLevel > 5)
            {
              //Higher Levels
              cout << "" << endl;
              cout << "You use your magic to teleport the body to..." << endl;
              getline (cin, spellName);
              system("clear");
              
              string grandCanyonString = "the grand canyon", spaceString = "space";
              if (strcasecmp(grandCanyonString.c_str(), spellName.c_str()) == 0)
              {
                //The Grand Canyon
                cout << "" << endl;
                cout << "You teleport the body above the Grand Canyon, and it hits several rocks on the way down." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                bodyPlace = "the Grand Canyon";
              }
              else if (strcasecmp(spaceString.c_str(), spellName.c_str()) == 0)
              {
                //Space
                cout << "" << endl;
                cout << "You teleport the body into the vacuum of space. It will be found in 300 years." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                bodyPlace = "Space";
              }
              else
              {
                //Other place
                bodyPlace = spellName;
                cout << "" << endl;
                cout << "1...2...3... Poof! The body is teleported to: " << bodyPlace << "." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
              }
            }
          }
          
          //Hide option
          else if (strcasecmp(hideString.c_str(), bodyChoice.c_str()) == 0)
          {
          HideChoice:
            cout << "Do you hide the body in the closet, the bed, or the bathroom?" << endl;
            getline(cin, bodyPlace);
            if (strcasecmp(closetString.c_str(), bodyPlace.c_str()) == 0)
            {
              //Closet
              system("clear");
              cout << "You decide to place the body in the closet because why not." << endl;
              bodyPlace = "closet";
            }
            else if (strcasecmp(bedString.c_str(), bodyPlace.c_str()) == 0)
            {
              //Bed
              system("clear");
              cout << "You decide to place the body in the bed because why not." << endl;
              bodyPlace = "bed";
            }
            else if (strcasecmp(bathroomString.c_str(), bodyPlace.c_str()) == 0)
            {
              //Bathroom
              system("clear");
              cout << "You decide to place the body in the bathroom because why not." << endl;
              bodyPlace = "bathroom";
            }
            else
            {
              //Incorrect input
              system("clear");
              cout << "" << endl;
              cout << reset << "That is not an option, please try again." << endl;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto HideChoice;
            }
          }
          
          //Ignore option
          else if (strcasecmp(ignoreString.c_str(), bodyChoice.c_str()) == 0)
          {
            system("clear");
            cout << "You decide to ignore the body because magicking or moving the body is too much work." << endl;
            bodyPlace = "floor";
          }
          
          //Incorrect inupt
          else
          {
            system("clear");
            cout << "" << endl;
            cout << reset << "That is not an option, please try again." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            system("clear");
            goto BodyPlaceChoice;
          }
          
          //Woman Choice
        WomanKnowChoice:
          cout << "There is a knock on the door. You open it and let a woman in." << endl;
          cout << "'Have you seen my brother?' she asks, 'He went missing on this floor of the motel last night.'" << endl;
          cout << "" << endl;
          cout << "Do you tell her you know or you don't know where her brother is?" << endl;
          getline (cin, knowPlace);
          
          if (strcasecmp(knowString.c_str(), knowPlace.c_str()) == 0)
          {
            //Know
            system("clear");
            cout << "You tell the woman you know where her brother is." << endl;
            
            if (strcasecmp(ignoreString.c_str(), bodyChoice.c_str()) == 0)
            {
              //Know and ignore
              cout << "You let the woman in and she immediately sees the body that you left on the ground." << endl;
              cout << "'Why is my brother laying dead on the floor?' she asks. 'Did you kill him?!'" << endl;
              cout << "" << endl;
              cout << "The woman pulls out a gun..." << endl;
              endingNumber = 1;
              
              //Carabiner option
              getline (cin, carabinerChoice2);
              if (strcasecmp(carabinerString.c_str(), carabinerChoice2.c_str()) == 0)
              {
                //Carabiner
                system("clear");
                endingNumber = 7;
                goto Ending2;
              }
              else
              {
                //Other
                system("clear");
                goto Ending2;
              }
            }
            
            else if ((strcasecmp(hideString.c_str(), bodyChoice.c_str()) == 0) || (strcasecmp(magicString.c_str(), bodyChoice.c_str()) == 0))
            {
              //Know and move
              cout << "You let the woman in and she starts searching." << endl;
              
              if (bodyPlace == "closet")
              {
                //Know and move to closet
                cout << "The woman checks the closet first, and of course finds her brother's body." << endl;
                cout << "'Why is my brother dead in the closet?' she asks. 'Did you kill him?!'" << endl;
                cout << "" << endl;
                cout << "The woman pulls out a gun..." << endl;
                endingNumber = 2;
              }
              else if (bodyPlace == "bed")
              {
                //Know and move to bed
                cout << "The woman checks the closet first, but doesn't find her brother's body." << endl;
                cout << "The woman checks the bed next, and of course finds her brother's body." << endl;
                cout << "'Why is my brother dead in the bed?' she asks. 'Did you kill him?!'" << endl;
                cout << "" << endl;
                cout << "The woman pulls out a gun..." << endl;
                endingNumber = 3;
              }
              else if (bodyPlace == "bathroom")
              {
                //Know and move to bathroom
                cout << "The woman checks the closet first, but doesn't find her brother's body." << endl;
                cout << "The woman checks the bed next, but doesn't find her brother's body." << endl;
                cout << "Finally the woman checks the bathroom, and of course finds her brother's body." << endl;
                cout << "'Why is my brother dead in the bathroom?' she asks. 'Did you kill him?!'" << endl;
                cout << "" << endl;
                cout << "The woman pulls out a gun..." << endl;
                endingNumber = 4;
              }
              else if ((bodyPlace != "closet") && (bodyPlace != "bed") && (bodyPlace != "bathroom"))
              {
                //Know and magic
                cout << "The woman checks the closet first, but doesn't find her brother's body." << endl;
                cout << "The woman checks the bed next, but doesn't find her brother's body." << endl;
                cout << "Finally the woman checks the bathroom, but doesn't find her brother's body." << endl;
                cout << "This is because her brother's body is in " << bodyPlace << "." << endl;
                cout << "" << endl;
                cout << "The woman thanks you for your help and as she leaves..." << endl;
                endingNumber = 6;
              }
              
              //Carabiner option
              getline (cin, carabinerChoice2);
              if (strcasecmp(carabinerString.c_str(), carabinerChoice2.c_str()) == 0)
              {
                //Carabiner
                system("clear");
                endingNumber = 7;
                goto Ending2;
              }
              else
              {
                //Other
                system("clear");
                goto Ending2;
              }
            }
          }
          
          else if ((strcasecmp(dontKnowString.c_str(), knowPlace.c_str()) == 0) || (strcasecmp(don_tKnowString.c_str(), knowPlace.c_str()) == 0))
          {
            //Don't Know
            system("clear");
            cout << "You tell the woman you don't know where her brother is." << endl;
            cout << "" << endl;
            cout << "The woman's eyes narrow. 'Why are you lying to me?' she asks, 'This is the last room on the floor, and I know he was on this floor.'" << endl;
            cout << "" << endl;
            cout << "The woman pulls out a gun..." << endl;
            endingNumber = 5;
            
            //Carabiner option
            getline (cin, carabinerChoice2);
            if (strcasecmp(carabinerString.c_str(), carabinerChoice2.c_str()) == 0)
            {
              //Carabiner
              system("clear");
              endingNumber = 7;
              goto Ending2;
            }
            else
            {
              //Other
              system("clear");
              goto Ending2;
            }
          }
          
          //Incorrect inupt
          else
          {
            system("clear");
            cout << "" << endl;
            cout << reset << "That is not an option, please try again." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            system("clear");
            goto WomanKnowChoice;
          }
          
          //The end of the chapter
        Ending2:
          string endingChoice, restartString = "restart", quitString = "quit";
          if (endingNumber == 1)
          {
            //Know and ignore ending
            cout << badending << "...And kills you, your body falls on the floor next to the woman's brother." << endl;
            cout << "BAD ENDING 1" << endl;
          }
          else if (endingNumber == 2)
          {
            //Know and move to closet ending
            cout << badending << "...And kills you, your body falls on the floor, with the woman's brother in the closet." << endl;
            cout << "BAD ENDING 2" << endl;
          }
          else if (endingNumber == 3)
          {
            //Know and move to bed ending
            cout << badending << "...And kills you, your body falls on the floor, with the woman's brother in the bed." << endl;
            cout << "BAD ENDING 3" << endl;
          }
          else if (endingNumber == 4)
          {
            //Know and move to bathroom ending
            cout << badending << "...And kills you, your body falls on the floor, with the woman's brother in the bathroom." << endl;
            cout << "BAD ENDING 4" << endl;
          }
          else if (endingNumber == 5)
          {
            //Don't know ending
            cout << badending << "...And kills you, your body falls on the floor, as the woman searches your room." << endl;
            cout << "BAD ENDING 5" << endl;
          }
          else if (endingNumber == 6)
          {
            //Know and magic ending
            cout << goodending << "...You stab her in the back, putting her body with her brother in " << bodyPlace << "." << endl;
            cout << "GOOD ENDING" << endl;
          }
          else if (endingNumber == 7)
          {
            //Carabiner ending
            passedChapter2 = 1;
            trueChapter2 = 1;
            cout << gold << "You reach into your pocket and pull out a carabiner. It has the words 'Fullersberg Woods' enscribed on it." << endl;
            cout << "The carabiner is gold, but when you look closer the air around it shimmers, and you see some sort of green text on a black background instead of your hand." << endl;
            cout << "You move your face closer to the green text and suddenly the woman is dead, next to her brother in the " << bodyPlace << "." << endl;
            cout << "You check out of the motel." << endl;
            cout << "TRUE ENDING" << endl;
          }
          
          //Restart or quit
        RestartChoice2:
          cout << reset << "" << endl;
          cout << "Would you like to restart or quit?" << endl;
          getline (cin, endingChoice);
          
          if (strcasecmp(restartString.c_str(), endingChoice.c_str()) == 0)
          {
            //Restart
            goto RestartChapter2;
          }
          else if (strcasecmp(quitString.c_str(), endingChoice.c_str()) == 0)
          {
            //Quit
            goto MainMenuChoice;
          }
          else
          {
            //Incorrect input
            system("clear");
            cout << "" << endl;
            cout << reset << "That is not an option, please try again." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            system("clear");
            goto RestartChoice2;
          }
        }  
      }
      else if (chapterChoice == 2 && passedChapter1 != 1)
      {
        //Chapter 2 Locked
        system("clear");
        goto ChapterMenuChoice;
      }
      else if (chapterChoice == 3 && passedChapter1 == 1 && passedChapter2 == 1)
      {
        //Chapter 3
        int theConclusion();
        {
        RestartChapter3:
          system("clear");
          
          //Set up for choices
          string spellName, movementChoice, hidingPlace, stabObject, carabinerChoice3, stabChoice;
          int spellLevel, endingNumber, Hidden;
          spellLevel = 0, Hidden = 0;
          
          //Beginning Text
          cout << color << "Welcome to the game. You will have to make choices or something." << endl;
          cout << "" << endl;
        MovementChoiceChoice:
          cout << "You wake up on the floor and look around. You are the basement of a house." << endl;
          cout << "In the room you see a door, a small window that you cannot fit through, and an armoire." << endl;
          cout << "You wonder why you are in a basemet, and then you remember..." << endl;
          cout << "the magic... The sister... The Carabiner..." << endl;
          cout << "" << endl;
          cout << "You remember the police are outside of the basement and will break the door down." << endl;
          cout << "You estimate you have about 10 minutes before the door is down." << endl;
          cout << "" << endl;
          
          //First choice
          cout << "Do you hide, wait, or use magic?" << endl;
        MovementChoiceGetline:
          getline (cin, movementChoice);
          system("clear");
          
          //Setup options
          string magicString = "magic", hideString = "hide", waitString = "wait", doorString = "door", windowString = "window", armoireString = "armoire", yesString = "yes", noString = "no";
          string carabinerString = "carabiner";
          
          //Magic option
          if (strcasecmp(magicString.c_str(), movementChoice.c_str()) == 0)
          {
            if (spellLevel == 0)
            {
              //Level 0
              cout << "" << endl;
              cout << "Sorry, you are not a high enough level to do magic." << endl;
              spellLevel += 1;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto MovementChoiceChoice;
            }
            else if (spellLevel < 5)
            {
              //Level 1-4
              cout << "" << endl;
              cout << "Sorry, you are not a high enough level to do magic." << endl;
              cout << "(Keep training your magic to level up.)" << endl;
              spellLevel += 1;
              std::this_thread::sleep_for(std::chrono::milliseconds(1000));
              system("clear");
              goto MovementChoiceChoice;
            }
            else if (spellLevel == 5)
            {
              //Level 5
              cout << "" << endl;
              cout << "Congrats! You are a high enough level to do magic." << endl;
              spellLevel += 1;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto MovementChoiceChoice;
            }
            else if (spellLevel > 5)
            {
              //Higher Levels
              cout << "" << endl;
              cout << "You use your magic to teleport to..." << endl;
              getline (cin, spellName);
              system("clear");
              
              string grandCanyonString = "the grand canyon", spaceString = "space";
              if (strcasecmp(grandCanyonString.c_str(), spellName.c_str()) == 0)
              {
                //The Grand Canyon
                cout << "" << endl;
                cout << "You teleport yourself above the Grand Canyon..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 1;
                goto Ending3;
              }
              else if (strcasecmp(spaceString.c_str(), spellName.c_str()) == 0)
              {
                //Space
                cout << "" << endl;
                cout << "You teleport into the vacuum of space..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                endingNumber = 2;
                goto Ending3;
              }
              else
              {
                //Other place
                cout << "" << endl;
                cout << "1...2...3... Poof! You are teleported to: " << spellName << "." << endl;
                cout << "You realize however, that you will forever be on the run..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                system("clear");
                endingNumber = 3;
                goto Ending3;
              }
            }
          }
          
          //Wait option
          else if (strcasecmp(waitString.c_str(), movementChoice.c_str()) == 0)
          {
            if (stabObject == "")
            {
              //No Hide
              cout << "You decide to wait for the police to come." << endl;
              cout << "There is a clock on the wall and you watch the minutes pass." << endl;
              cout << "1...2...3...4...5...6...7...8...9...10." << endl;
              cout << "At 10 minutes and 35 seconds the door is broken." << endl;
              cout << "The police pour in..." << endl;
            
              //Carabiner option
              getline (cin, carabinerChoice3);
              if (strcasecmp(carabinerString.c_str(), carabinerChoice3.c_str()) == 0)
              {
                //Carabiner
                system("clear");
                endingNumber = 8;
                goto Ending3;
              }
              else
              {
                //Other
                system("clear");
                endingNumber = 7;
               goto Ending3;
              }
            }
            
            else if (stabObject != "")
            {
              //Hide
              cout << "You decide to wait for the police to come." << endl;
              cout << "There is a clock on the wall and you watch the minutes pass." << endl;
              cout << "1...2...3...4...5...6...7...8...9...10." << endl;
              cout << "You realize you must only have a few seconds before the police are in." << endl;
            stabObjectChoice:
              cout << "Do you use the " << stabObject << "?" << endl;
              
              //Stab yes or no
              getline (cin, stabChoice);
              if (strcasecmp(yesString.c_str(), stabChoice.c_str()) == 0)
              {
                system("clear");
                cout << "You decide, after much hesitation, to stab yourself with the " << stabObject << "..."<< endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                if (stabObject == "wood")
                {
                  endingNumber = 4;
                }
                else if (stabObject == "glass")
                {
                  endingNumber = 5;
                }
                else if (stabObject == "nail")
                {
                  endingNumber = 6;
                }
                goto Ending3;
              }
              else if (strcasecmp(noString.c_str(), stabChoice.c_str()) == 0)
              {
                //Carabiner option
                getline (cin, carabinerChoice3);
                if (strcasecmp(carabinerString.c_str(), carabinerChoice3.c_str()) == 0)
                {
                  //Carabiner
                  system("clear");
                  endingNumber = 8;
                  goto Ending3;
                }
                else
                {
                  //Other
                  system("clear");
                  endingNumber = 7;
                  goto Ending3;
                }
              }
              else
              {
                //Incorrect input
                system("clear");
                cout << "" << endl;
                cout << reset << "That is not an option, please try again." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("clear");
                goto stabObjectChoice;
              }
            }
          }
          
          //Hide option
          else if ((strcasecmp(hideString.c_str(), movementChoice.c_str()) == 0) && Hidden == 0)
          {
          HidePlaceChoice:
            cout << "You decide to hide so the police will not find you." << endl;
            cout << "Do you hide by the door, the window, or in the armoire?" << endl;
            getline (cin, hidingPlace);
            system("clear");
            
            if (strcasecmp(doorString.c_str(), hidingPlace.c_str()) == 0)
            {
              cout << "You decide to hide behind the door." << endl;
              cout << "While you are crouched behind the door, you notice a piece of wood that could be used as a stake hanging off the door." << endl;
              cout << "You rip the stake-like peice of wood off the door and put it in your pocket." << endl;
              stabObject = "wood";
            }
            else if (strcasecmp(windowString.c_str(), hidingPlace.c_str()) == 0)
            {
              cout << "You decide to hide by the window." << endl;
              cout << "While you are next to the window, you notice a shard of glass that could be used to stab someone." << endl;
              cout << "You take the shard of glass and put it in your pocket." << endl;
              stabObject = "glass";
            }
            else if (strcasecmp(armoireString.c_str(), hidingPlace.c_str()) == 0)
            {
              cout << "You decide to hide in the armoire." << endl;
              cout << "While you are in the armoire, you notice an unusually sharp nail." << endl;
              cout << "You take the nail and put it in your pocket." << endl;
              stabObject = "nail";
            }
            else
            {
              //Incorrect input
              system("clear");
              cout << "" << endl;
              cout << reset << "That is not an option, please try again." << endl;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto HidePlaceChoice;
            }
            
            //First choice (Other)
            cout << "Do you wait or use magic?" << endl;
            Hidden = 1;
            goto MovementChoiceGetline;
          }
          
          else
            {
              //Incorrect input
              system("clear");
              cout << "" << endl;
              cout << reset << "That is not an option, please try again." << endl;
              std::this_thread::sleep_for(std::chrono::milliseconds(2000));
              system("clear");
              goto HidePlaceChoice;
            }
          
          //The end of the chapter
        Ending3:
          string endingChoice, restartString = "restart", quitString = "quit";
          if (endingNumber == 1)
          {
            //Grand Canyon ending
            cout << badending << "...And you fall into it, dying from the fall." << endl;
            cout << "BAD ENDING 1" << endl;
          }
          else if (endingNumber == 2)
          {
            //Space ending
            cout << badending << "...And you die, you will be found in 300 years, but you will not be saved." << endl;
            cout << "BAD ENDING 2" << endl;
          }
          else if (endingNumber == 3)
          {
            //Other place ending
            cout << badending << "...And you begin to cry, in a place you do not know, with no one to save you." << endl;
            cout << "BAD ENDING 3" << endl;
          }
          else if (endingNumber == 4)
          {
            //Die to stake
            cout << badending << "...And just before the police break in, you bleed out. The police swarm your body, but you are already gone." << endl;
            cout << "BAD ENDING 4" << endl;
          }
          else if (endingNumber == 5)
          {
            //Die to glass
            cout << badending << "...And just before the police break in, you bleed out. The police swarm your body, but you are already gone." << endl;
            cout << "BAD ENDING 5" << endl;
          }
          else if (endingNumber == 6)
          {
            //Die to nail
            cout << badending << "...And just before the police break in, you bleed out. The police swarm your body, but you are already gone." << endl;
            cout << "BAD ENDING 6" << endl;
          }
          else if (endingNumber == 7)
          {
            //Know and magic ending
            cout << goodending << "...And arrest you and send you to jail." << endl;
            cout << "GOOD ENDING" << endl;
          }
          else if (endingNumber == 8)
          {
            //Carabiner ending
            passedChapter3 = 1;
            trueChapter3 = 1;
            cout << gold << "You reach into your pocket and pull out a carabiner. It has the words 'Fullersberg Woods' enscribed on it." << endl;
            cout << "You remember that you have used this carabiner before, to kill the person's sister. You realize the carabiner has been used for evil." << endl;
            cout << "You throw the carabiner at the wall, and the wall shatters like glass. You see the hazy outlines of people in a scientific-looking room start running around." << endl;
            cout << "The white room disappears and is replaced once more with the basement." << endl;
            cout << "The cycle starts anew." << endl;
            cout << "TRUE ENDING" << endl;
          }
          
          //Restart or quit
        RestartChoice3:
          cout << reset << "" << endl;
          cout << "Would you like to restart or quit?" << endl;
          getline (cin, endingChoice);
          
          if (strcasecmp(restartString.c_str(), endingChoice.c_str()) == 0)
          {
            //Restart
            goto RestartChapter3;
          }
          else if (strcasecmp(quitString.c_str(), endingChoice.c_str()) == 0)
          {
            //Quit
            goto MainMenuChoice;
          }
          else
          {
            //Incorrect input
            system("clear");
            cout << "" << endl;
            cout << reset << "That is not an option, please try again." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            system("clear");
            goto RestartChoice3;
          }
        }
      }
      else if (chapterChoice == 3 && passedChapter1 != 1 || passedChapter2 != 1)
      {
        //Chapter 3 Locked
        system("clear");
        goto ChapterMenuChoice;
      }
      else if (chapterChoice == 4 && trueChapter2 == 1)
      {
        //Bonus Chapter/Chapter 4
        system("clear");
        cout << "" << endl;
        cout << gold << "Hey nice you must have played the origninal (or been lucky/looked at the code)" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        system("clear");
        goto MainMenuChoice;
      }
      else if (chapterChoice == 4 && trueChapter2 != 1)
      {
        //Bonus Chapter/Chapter 4 Locked
        system("clear");
        goto ChapterMenuChoice;
      }
      else
      {
        //Incorrect input
        system("clear");
        cout << "" << endl;
        cout << reset << "That is not an option, please try again." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        system("clear");
        goto MainMenuChoice;
      }
    }
    //Settings Choice Functionality
    else if (strcasecmp(settingsString.c_str(), menuChoice.c_str()) == 0)
    {
      //Change text color in-game
      string apply, colorChoose;
    SettingsMenuChoice:
      system("clear");
      cout << reset << "What color would you like text to appear as in-game?" << endl;
      cout << reset << "[White]" << endl;
      cout << yellow << "[Yellow]" << endl;
      cout << green << "[Green]" << endl;
      cout << blue << "[Blue]" << reset << endl;
      getline (cin, colorChoose);
      
      //Colors
      string whiteString = "white", yellowString = "yellow", greenString = "green", blueString = "blue";
      if (strcasecmp(whiteString.c_str(), colorChoose.c_str()) == 0)
      {
        //White text  
        color = "\033[38;5;15m";
      }
      else if (strcasecmp(yellowString.c_str(), colorChoose.c_str()) == 0)
      {
        //Yellow Text
        color = "\033[38;5;11m";
      }
      else if (strcasecmp(greenString.c_str(), colorChoose.c_str()) == 0)
      {
        //Green Text
        color = "\033[38;5;40m";
      }
      else if (strcasecmp(blueString.c_str(), colorChoose.c_str()) == 0)
      {
        //Blue Text
        color = "\033[38;5;69m";
      }
      else
      {
        //Incorrect input
        system("clear");
        cout << "" << endl;
        cout << reset << "That is not an option, please try again." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        goto SettingsMenuChoice;
      }
      
      //Display weather setting
      system("clear");
      cout << reset << "Display weather?" << endl;
      cout << reset << "y/n" << endl;
      getline (cin, apply);
        
      if (apply == "y")
      {
        //Weather on
        cout << reset << "Your settings choices are: " << color << "This " << reset << "color text and weather on." << endl;
        cout << reset << "Save and quit to menu?" << endl;
        getline (cin, apply);
          
        if (apply == "y")
        {
          //Finish and go to main menu
          goto MainMenuChoice;  
        }
        else if (apply == "n")
        {
          //Go back to start of settings menu
          goto SettingsMenuChoice;
        }
        else
        {
          //Incorrect input
          system("clear");
          cout << "" << endl;
          cout << reset << "That is not an option, please try again." << endl;
          std::this_thread::sleep_for(std::chrono::milliseconds(2000));
          goto SettingsMenuChoice;
        }
      }
      else if (apply == "n")
      {
        //Weather off
        cout << reset << "Your settings choices are: " << color << "This " << reset << "color text and weather off." << endl;
        cout << reset << "Save and quit to menu?" << endl;
        cout << reset << "(y/n)" << endl;
        getline (cin, apply);
          
        if (apply == "y")
        {
          //Finish and go to main menu
          goto MainMenuChoice;  
        }
        else if (apply == "n")
        {
          //Go back to start of settings menu
          goto SettingsMenuChoice;
        }
        else
        {
          //Incorrect input
          system("clear");
          cout << "" << endl;
          cout << reset << "That is not an option, please try again." << endl;
          std::this_thread::sleep_for(std::chrono::milliseconds(2000));
          goto SettingsMenuChoice;
        }
      }
    }
    //Credits Choice Functionality
    else if (strcasecmp(creditsString.c_str(), menuChoice.c_str()) == 0)
    {
      string quit;
      system("clear");
      cout << lgray << "+--------------------------------+" << endl;
      cout << lgray << "|" << reset << "           CREDITS              " << lgray << "|" << endl;
      cout << gray << "|                                |" << endl;
      cout << gray << "|" << reset << "Banana.cpp originally created by" << gray << "|" << endl;
      cout << gray << "|" << reset << "           Jack McComb          " << gray << "|" << endl;
      cout << gray << "|                                |" << endl;
      cout << gray << "|" << reset << "    Banana Fork by Peter Frost  " << gray << "|" << endl;
      cout << gray << "|                                |" << endl;
      cout << dgray << "|                                |" << endl;
      cout << dgray << "|" << reset << "      (Press Enter to exit)     " << dgray << "|" << endl;
      cout << dgray << "+--------------------------------+" << endl;
      getline (cin, quit);
      if (std::cin.get() == '\n');
      {
        goto MainMenuChoice;
      }
    }
    //Quit Choice Functionality
    else if (strcasecmp(quitString.c_str(), menuChoice.c_str()) == 0)
    {
      return 0;
    }
    //Incorrect input
    else
    {
      cout << "" << endl;
      cout << reset << "That is not an option, please try again." << endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
      goto MainMenuChoice;
    }
  }
}



