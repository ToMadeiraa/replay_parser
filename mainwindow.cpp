#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   QString str = QFileDialog::getOpenFileName(this, "Выбрать файл");
   QFile file(str);
   QString s;
   if(file.open(QIODevice::ReadOnly)) {
       QByteArray block = file.read(200000);
       int i = block.indexOf("mapsize");
       int j = block.indexOf("PatternList");
       block.remove(j, block.size());
       block.remove(0, i);
       qDebug() << "find settings";
       QVector<QString> settings = findSettings(block);
       qDebug() << "find players";
       QVector<QVector<QString>> players = findPlayers(block);
       qDebug() << "filter settings";
       filterSettings(settings);
       qDebug() << "find colors nations";
       findNationColor(players);
       qDebug() << "find players info";
       QVector<QVector<QString>> playersInfo = findPlayersInfo(block);

       //settings
       ui->Settings_1->setText(settings[5]);
       ui->Settings_2->setText(settings[1]);
       ui->Settings_3->setText(settings[2]);
       ui->Settings_4->setText(settings[3]);
       ui->Settings_5->setText(settings[4]);
       ui->Settings_6->setText(settings[0]);

       ui->comboBox->clear();
       for (int i = 7; i < 18;i++) {
            ui->comboBox->addItem(settings[i]);
       }

       for (auto x : {ui->Nick_2, ui->Nick_3, ui->Nick_4, ui->Nick_5, ui->Nick_6, ui->Nick_7,
                      ui->Nick_8, ui->Nick_9, ui->Nick_10, ui->Nick_11, ui->Nick_12,
                      ui->Nation_2, ui->Nation_3,ui->Nation_4,ui->Nation_5,ui->Nation_6,ui->Nation_7,
                      ui->Nation_8,ui->Nation_9,ui->Nation_10,ui->Nation_11,ui->Nation_12,
                      ui->Team_2, ui->Team_3, ui->Team_4, ui->Team_5, ui->Team_6, ui->Team_7,
                      ui->Team_8, ui->Team_9, ui->Team_10, ui->Team_11, ui->Team_12,
                      ui->LanID_2, ui->LanID_3,ui->LanID_4,ui->LanID_5,ui->LanID_6,ui->LanID_7,ui->LanID_8,
                      ui->LanID_9,ui->LanID_10,ui->LanID_11,ui->LanID_12,
                      ui->Steam1_2, ui->Steam1_3, ui->Steam1_4, ui->Steam1_5, ui->Steam1_6, ui->Steam1_7, ui->Steam1_8,
                      ui->Steam1_9, ui->Steam1_10, ui->Steam1_11, ui->Steam1_12,
                      ui->Steam2_2, ui->Steam2_3, ui->Steam2_4, ui->Steam2_5, ui->Steam2_6, ui->Steam2_7, ui->Steam2_8,
                      ui->Steam2_9, ui->Steam2_10, ui->Steam2_11, ui->Steam2_12,
                      ui->Steam3_2, ui->Steam3_3, ui->Steam3_4, ui->Steam3_5, ui->Steam3_6, ui->Steam3_7, ui->Steam3_8,
            ui->Steam3_9, ui->Steam3_10, ui->Steam3_11, ui->Steam3_12}) {
           x->setText(" ");
       }
       for (auto x : {ui->Color_2, ui->Color_3,ui->Color_4,ui->Color_5,ui->Color_6,ui->Color_7,ui->Color_8,
            ui->Color_9,ui->Color_10,ui->Color_11,ui->Color_12}) {
            x->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgba(0,0,0,0)}");
       }

       //player 1

           ui->Nick_2->setText(players[0][2]);

       if (ui->Nick_2->text() != "") {
           ui->Nation_2->setText(players[0][0]);
           ui->Team_2->setText(players[0][3]);
           ui->Color_2->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[0][4] + ")}");
           ui->LanID_2->setText(players[0][5]);
           if (playersInfo[0][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[0][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[0][4] +"</a>";
               ui->Steam1_2->setText(s);
               ui->Steam1_2->setOpenExternalLinks(true);
           }
            if (playersInfo[0][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[0][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[0][6] +"</a>";
               ui->Steam2_2->setText(s);
               ui->Steam2_2->setOpenExternalLinks(true);
            }

            if (playersInfo[0][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[0][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[0][7] +"</a>";
               ui->Steam3_2->setText(s);
               ui->Steam3_2->setOpenExternalLinks(true);
            }
       }

        //player 2

           ui->Nick_3->setText(players[1][2]);
      if (ui->Nick_3->text() != "") {
           ui->Nation_3->setText(players[1][0]);
           ui->Team_3->setText(players[1][3]);
           ui->Color_3->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[1][4] + ")}");
           ui->LanID_3->setText(players[1][5]);
           if (playersInfo[1][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[1][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[1][4] +"</a>";
               ui->Steam1_3->setText(s);
               ui->Steam1_3->setOpenExternalLinks(true);
           }
            if (playersInfo[1][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[1][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[1][6] +"</a>";
               ui->Steam2_3->setText(s);
               ui->Steam2_3->setOpenExternalLinks(true);
            }

            if (playersInfo[1][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[1][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[1][7] +"</a>";
               ui->Steam3_3->setText(s);
               ui->Steam3_3->setOpenExternalLinks(true);
            }
       }

        //player 3

           ui->Nick_4->setText(players[2][2]);
       if (ui->Nick_4->text() != "") {
           ui->Nation_4->setText(players[2][0]);
           ui->Team_4->setText(players[2][3]);
           ui->Color_4->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[2][4] + ")}");
           ui->LanID_4->setText(players[2][5]);
           if (playersInfo[2][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[2][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[2][4] +"</a>";
               ui->Steam1_4->setText(s);
               ui->Steam1_4->setOpenExternalLinks(true);
           }
            if (playersInfo[2][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[2][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[2][6] +"</a>";
               ui->Steam2_4->setText(s);
               ui->Steam2_4->setOpenExternalLinks(true);
            }

            if (playersInfo[2][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[2][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[2][7] +"</a>";
               ui->Steam3_4->setText(s);
               ui->Steam3_4->setOpenExternalLinks(true);
            }
       }

        //player 4

           ui->Nick_5->setText(players[3][2]);
       if (ui->Nick_5->text() != "") {
           ui->Nation_5->setText(players[3][0]);
           ui->Team_5->setText(players[3][3]);
           ui->Color_5->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[3][4] + ")}");
           ui->LanID_5->setText(players[3][5]);
           if (playersInfo[3][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[3][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[3][4] +"</a>";
               ui->Steam1_5->setText(s);
               ui->Steam1_5->setOpenExternalLinks(true);
           }
            if (playersInfo[3][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[3][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[3][6] +"</a>";
               ui->Steam2_5->setText(s);
               ui->Steam2_5->setOpenExternalLinks(true);
            }

            if (playersInfo[3][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[3][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[3][7] +"</a>";
               ui->Steam3_5->setText(s);
               ui->Steam3_5->setOpenExternalLinks(true);
            }
       }

         //player 5

           ui->Nick_6->setText(players[4][2]);
       if (ui->Nick_6->text() != "") {
           ui->Nation_6->setText(players[4][0]);
           ui->Team_6->setText(players[4][3]);
           ui->Color_6->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[4][4] + ")}");
           ui->LanID_6->setText(players[4][5]);
           if (playersInfo[4][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[4][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[4][4] +"</a>";
               ui->Steam1_6->setText(s);
               ui->Steam1_6->setOpenExternalLinks(true);
           }
            if (playersInfo[4][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[4][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[4][6] +"</a>";
               ui->Steam2_6->setText(s);
               ui->Steam2_6->setOpenExternalLinks(true);
            }

            if (playersInfo[4][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[4][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[4][7] +"</a>";
               ui->Steam3_6->setText(s);
               ui->Steam3_6->setOpenExternalLinks(true);
            }
       }

        //player 6

           ui->Nick_7->setText(players[5][2]);
       if (ui->Nick_7->text() != "") {
           ui->Nation_7->setText(players[5][0]);
           ui->Team_7->setText(players[5][3]);
           ui->Color_7->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[5][4] + ")}");
           ui->LanID_7->setText(players[5][5]);
           if (playersInfo[5][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[5][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[5][4] +"</a>";
               ui->Steam1_7->setText(s);
               ui->Steam1_7->setOpenExternalLinks(true);
           }
            if (playersInfo[5][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[5][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[5][6] +"</a>";
               ui->Steam2_7->setText(s);
               ui->Steam2_7->setOpenExternalLinks(true);
            }

            if (playersInfo[5][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[5][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[5][7] +"</a>";
               ui->Steam3_7->setText(s);
               ui->Steam3_7->setOpenExternalLinks(true);
            }
       }

          //player 7
       ui->Nick_8->setText(players[6][2]);
       if (ui->Nick_8->text() != "") {
           ui->Nation_8->setText(players[6][0]);
           ui->Team_8->setText(players[6][3]);
           ui->Color_8->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[6][4] + ")}");
           ui->LanID_8->setText(players[6][5]);
           if (playersInfo[6][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[6][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[6][4] +"</a>";
               ui->Steam1_8->setText(s);
               ui->Steam1_8->setOpenExternalLinks(true);
           }
            if (playersInfo[6][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[6][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[6][6] +"</a>";
               ui->Steam2_8->setText(s);
               ui->Steam2_8->setOpenExternalLinks(true);
            }

            if (playersInfo[6][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[6][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[6][7] +"</a>";
               ui->Steam3_8->setText(s);
               ui->Steam3_8->setOpenExternalLinks(true);
            }
       }

         //player 8
       ui->Nick_9->setText(players[7][2]);
       if (ui->Nick_9->text() != "") {
           ui->Nation_9->setText(players[7][0]);
           ui->Team_9->setText(players[7][3]);
           ui->Color_9->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[7][4] + ")}");
           ui->LanID_9->setText(players[7][5]);
           if (playersInfo[7][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[7][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[7][4] +"</a>";
               ui->Steam1_9->setText(s);
               ui->Steam1_9->setOpenExternalLinks(true);
           }
            if (playersInfo[7][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[7][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[7][6] +"</a>";
               ui->Steam2_9->setText(s);
               ui->Steam2_9->setOpenExternalLinks(true);
            }

            if (playersInfo[7][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[7][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[7][7] +"</a>";
               ui->Steam3_9->setText(s);
               ui->Steam3_9->setOpenExternalLinks(true);
            }
        }
         //player 9
       ui->Nick_10->setText(players[8][2]);
       if (ui->Nick_10->text() != "") {
           ui->Nation_10->setText(players[8][0]);
           ui->Team_10->setText(players[8][3]);
           ui->Color_10->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[8][4] + ")}");
           ui->LanID_10->setText(players[8][5]);
           if (playersInfo[8][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[8][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[8][4] +"</a>";
               ui->Steam1_10->setText(s);
               ui->Steam1_10->setOpenExternalLinks(true);
           }
            if (playersInfo[8][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[8][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[8][6] +"</a>";
               ui->Steam2_10->setText(s);
               ui->Steam2_10->setOpenExternalLinks(true);
            }

            if (playersInfo[8][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[8][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[8][7] +"</a>";
               ui->Steam3_10->setText(s);
               ui->Steam3_10->setOpenExternalLinks(true);
            }
       }

        //player 10
       ui->Nick_11->setText(players[9][2]);
       if (ui->Nick_11->text() != "") {
           ui->Nation_11->setText(players[9][0]);
           ui->Team_11->setText(players[9][3]);
           ui->Color_11->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[9][4] + ")}");
           ui->LanID_11->setText(players[9][5]);
           if (playersInfo[9][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[9][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[9][4] +"</a>";
               ui->Steam1_11->setText(s);
               ui->Steam1_11->setOpenExternalLinks(true);
           }
            if (playersInfo[9][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[9][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[9][6] +"</a>";
               ui->Steam2_11->setText(s);
               ui->Steam2_11->setOpenExternalLinks(true);
            }

            if (playersInfo[9][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[9][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[9][7] +"</a>";
               ui->Steam3_11->setText(s);
               ui->Steam3_11->setOpenExternalLinks(true);
            }
       }

        //player 11
       ui->Nick_12->setText(players[10][2]);
       if (ui->Nick_12->text() != "") {
           ui->Nation_12->setText(players[10][0]);
           ui->Team_12->setText(players[10][3]);
           ui->Color_12->setStyleSheet("QLabel { background-image: url(:/Desktop/fon2.png); background-color : rgb(" + players[10][4] + ")}");
           ui->LanID_12->setText(players[10][5]);
           if (playersInfo[10][1] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[10][1] + "]\" style=\"color: #fff5d9\">"+ playersInfo[10][4] +"</a>";
               ui->Steam1_12->setText(s);
               ui->Steam1_12->setOpenExternalLinks(true);
           }
            if (playersInfo[10][2] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[10][2] + "]\" style=\"color: #fff5d9\">"+ playersInfo[10][6] +"</a>";
               ui->Steam2_12->setText(s);
               ui->Steam2_12->setOpenExternalLinks(true);
            }

            if (playersInfo[10][3] != "0") {
               s ="<a href=\"https://steamcommunity.com/profiles/[U:1:" + playersInfo[10][3] + "]\" style=\"color: #fff5d9\">"+ playersInfo[10][7] +"</a>";
               ui->Steam3_12->setText(s);
               ui->Steam3_12->setOpenExternalLinks(true);
            }
       }

   }
}

QVector<QString> MainWindow::findSettings(QByteArray arr) {
    QVector<QString> result;
    QVector<QString> settings = {"mapsize", "terraintype", "relieftype", "resourcestart", "resourcemines", "season",
                                 "activeoption","startingunits","balloon","cannons","peacetime","century18","capture"
                                 , "marketdip", "teams", "limit", "gamespeed", "adviserassistant"};
    int j = arr.indexOf("players");
    arr.remove(j, arr.size());
    //qDebug() << arr;
    for (int k = 0; k < settings.size(); k++) {
        int i = arr.indexOf(settings[k].toStdString());
        arr.remove(0, i);
        QString str = "";
        arr.remove(0, settings[k].size() + 4);
        while (int(*arr.begin()) > 32) {
            str+=arr.begin();
            while (int(*arr.begin()) > 32) {
                arr.remove(0,1);
            }
        }
        //qDebug() << str;
        result.push_back(str);
    }
    return result;
}

void filterSettings (QVector<QString>& settings) {

    QVector<QString> maps = {"Маленький", "Нормальный", "Большой х2", "Маленький"};
    QVector<QString> terrains = {"Суша", "Средиземное море", "Полуострова", "Острова",
                                 "Континенты","Континент","Побережье","Озера","Реки","Случайно"};
    QVector<QString> reliefs = {"Равнина","Холмы","Горы","Высокогорье","Плато","Случайно"};
    QVector<QString> start_res = {"Обычные","Богатые","Много","Миллионы","Случайно"};
    QVector<QString> resources = {"Мало","Средне","Много","Случайно"};
    QVector<QString> seasons = {"Лето", "Зима", "Пустыня", "Случайно"};

    QVector<QString> global_names = {"Стартовые опции", "Опции монгольфьера","Пушки","Время мира","Опции 18 века",
                                    "Захват", "Дип. центр и рынок", "Союзники", "Лимит населения", "Скорость игры", "Помощник"};
    QVector<QString> starting_units = {"По умолчанию", "Армия", "Большая армия", "Огромная армия",
                                       "Множество крестьян","Разные нации","Башни",
                                       "Пушки","Пушки и гаубицы","Казармы 18 века",
                                       "Казармы 17 века","Деревня","Блокгаузы","Союз"};
    QVector<QString> balloons = {"По умолчанию", "Без монгольфьера", "С монгольфьером"};
    QVector<QString> cannons = {"По умолчанию", "Без пушек, башен и стен", "Дорогие пушки"};
    QVector<QString> PTs = {"Без времени мира", "10 минут", "15 минут", "20 минут",
                            "30 минут","45 минут","60 минут",
                            "90 минут","2 часа","3 часа","4 часа", "15 минут"};
    QVector<QString> centuries = {"По умолчанию", "Никогда", "Сразу"};
    QVector<QString> captures = {"По умолчанию", "Без захвата крестьян", "Без захвата крестьян и центров", "Только пушки"};
    QVector<QString> markets = {"По умолчанию", "Без дип. центра", "Без рынка", "Недоступны", "Дорогие наемники"};
    QVector<QString> teams = {"По умолчанию", "Рядом"};
    QVector<QString> limits = {"Без ограничения", "500 юнитов", "750 юнитов", "1000 юнитов", "1500 юнитов", "2200 юнитов",
                              "3000 юнитов","5000 юнитов","8000 юнитов"};
    QVector<QString> gamespeeds = {"Обычная", "Быстрая", "Очень быстрая"};
    QVector<QString> adviserassistants = {"По умолчанию","Без помощника"};
    qDebug() << "a";
    settings[0] = maps[settings[0].toInt()];
    settings[1] = terrains[settings[1].toInt()];
    settings[2] = reliefs[settings[2].toInt()];
    settings[3] = start_res[settings[3].toInt()];
    settings[4] = resources[settings[4].toInt()];
    settings[5] = seasons[settings[5].toInt()];
    qDebug() << "b";
    settings[7] = global_names[0] + ": " + starting_units[settings[7].toInt()];
    settings[8] = global_names[1] + ": " + balloons[settings[8].toInt()];
    qDebug() << "e";
    settings[9] = global_names[2] + ": " + cannons[settings[9].toInt()];
    qDebug() << "f";
    settings[10] = global_names[3] + ": " + PTs[settings[10].toInt()];
    qDebug() << "d";
    settings[11] = global_names[4] + ": " + centuries[settings[11].toInt()];
    settings[12] = global_names[5] + ": " + captures[settings[12].toInt()];
    settings[13] = global_names[6] + ": " + markets[settings[13].toInt()];
    qDebug() << "c";
    settings[14] = global_names[7] + ": " + teams[settings[14].toInt()];
    settings[15] = global_names[8] + ": " + limits[settings[15].toInt()];
    settings[16] = global_names[9] + ": " + gamespeeds[settings[16].toInt()];
    settings[17] = global_names[10] + ": " + adviserassistants[settings[17].toInt()];

}


QVector<QVector<QString>> MainWindow::findPlayers(QByteArray arr) {
    QVector<QVector<QString>> result(11, QVector<QString>(0,""));
    QVector<QString> settings = {"cid","csid","name","team","color","lanid","startx","starty",
                                 "aidifficulty","bexists","bai","bhuman","bclosed","bready", "bloaded",
                                "bleave"};
    int i = arr.indexOf("players");
    arr.remove(0, i);
    //qDebug() << arr;
    for (int k = 0; k < 11; k++) {
        for (int j = 0; j < settings.size(); j++) {
            i = arr.indexOf(settings[j].toStdString());
            arr.remove(0, i);
            QString str = "";
            arr.remove(0, settings[j].size() + 4);
            while (int(*arr.begin()) > 32) {
                str+=arr.begin();
                while (int(*arr.begin()) > 32) {
                    arr.remove(0,1);
                }
            }
            //qDebug() << str;
            result[k].push_back(str);
        }
        arr.remove(0,14);
    }
    for (int i = 0; i < 11; i++) {
        if (result[i][3] == "0") result[i][3] = "-";
    }
    return result;
}

void findNationColor(QVector<QVector<QString>> &plrs) {
    QVector<QString> nations = {"Случайно", "Австрия", "Франция", "Англия", "Испания","Россия","Украина","Польша",
                                "Швеция","Пруссия","Венеция","Турция","Алжир","Нидерланды","Дания","Португалия",
                                "Пьемонт","Саксония","Бавария","Венгрия","Швейцария","Шотландия","SPECTATOR"};
    QVector<QString> colors = {"252, 3, 3", "11, 3, 252", "3, 244, 252", "175, 0, 250", "245, 113, 12", "47, 217, 4", "252, 250, 250",
                               "247, 65, 250", "238, 255, 0", "56, 35, 176", "145, 255, 149", "99, 53, 7"};
    for (int i = 0; i < plrs.size();i++) {
        int nation_num = plrs[i][0].toInt();
        qDebug() << nation_num;
        if (nation_num == -2) {
            plrs[i][0] = "SPECTATOR";
        }  else if (nation_num == 24) {
            plrs[i][0] = "Случайно";
        }
        else if (nation_num>=0) {
           plrs[i][0] = nations[nation_num];
        } else {
           plrs[i][0] = " ";
        }
        int color_num = plrs[i][4].toInt();
        qDebug() << color_num;
        plrs[i][4] = colors[color_num];
    }
    qDebug() << "end filter settings";
}

QVector<QVector<QString>> MainWindow::findPlayersInfo(QByteArray arr) {
    QVector<QVector<QString>> result(11, QVector<QString>(0,""));
    QVector<QString> settings = {"sic","si1","si2","si3","snc","sn1","sn2","sn3"};
    int i = arr.indexOf("playersinfo");
    arr.remove(0, i);
    //qDebug() << arr;
    for (int k = 0; k < 11; k++) {
        for (int j = 0; j < settings.size(); j++) {
            i = arr.indexOf(settings[j].toStdString());
            arr.remove(0, i);
            QString str = "";
            arr.remove(0, settings[j].size() + 4);
            while (int(*arr.begin()) > 32) {
                str+=arr.begin();
                while (int(*arr.begin()) > 32) {
                    arr.remove(0,1);
                }
            }
            //qDebug() << str;
            result[k].push_back(str);
        }
        arr.remove(0,14);
    }
    return result;
}




