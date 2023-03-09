/*
void mousefunctionality(ALLEGRO_EVENT_QUEUE* event_queue)
{
    ALLEGRO_EVENT ev;

    al_wait_for_event(event_queue, &ev);

    if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        pos_x = ev.mouse.x;
        pos_y = ev.mouse.y;
    }

    if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        if (pos_x >= 250 && pos_x <= 551 && pos_y >= 155 && pos_y <= 169)
        {
            if (ev.mouse.button & 1)
                main_menu = true;
            main_boss_menu = true;
        }

        if (pos_x >= 758 && pos_x <= 793 && pos_y >= 11 && pos_y <= 38)
        {
            if (ev.mouse.button & 1)
                main_menu = false;
            main_boss_menu = false;
        }
    }
}
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <Windows.h>
#include "BossNames.h"

#define SCREEN_WIDTH 395
#define SCREEN_HEIGHT 355
#define BLACK 0, 0, 0
#define WHITE 255, 255, 255
#define RED 255, 0, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255
#define GREY 105, 105, 105

bool running = false;

int radahn_increment = 0;
int margit_increment = 0;
int godrick_increment = 0;
int redwolf_increment = 0;
int renalla_increment = 0;
int godskin_increment = 0;
int rykard_increment = 0;
int draconic_increment = 0;
int godfrey_increment = 0;
int morgott_increment = 0;
int firegiant_increment = 0;
int godskinduo_increment = 0;
int maliketh_increment = 0;
int sirgideon_increment = 0;
int godfrey2_increment = 0;
int hoarah_increment = 0;
int radagon_increment = 0;
int eldenbeast_increment = 0;

class KeyLogic
{
public:
    enum KEYS {A, B, C, D, E, F, G,
               H, I, J, K, L, M, N,
               O, P, Q, R, S, BACKSPACE, 
               ESCAPE, ENTER, CTRL};
    
    bool Keys[23] = { false, false, false,
                      false, false, false, 
                      false, false, false,
                      false, false, false,
                      false, false, false,
                      false, false, false,
                      false, false, false,
                      false, false };
};

class Timing
{
public:
    int ms = 0;
    int ms2 = 0;
    int ms3 = 0;
    int ms4 = 0;
    int ms5 = 0;
    int ms6 = 0;
    int ms7 = 0; 
    int ms8 = 0;
    int ms9 = 0;
    int ms10 = 0;
    int ms11 = 0;
    int ms12 = 0;
    int ms13 = 0;
    int ms14 = 0;
    int ms15 = 0;
    int ms16 = 0;
    int ms17 = 0;
    int ms18 = 0;

    enum Seconds 
    {
        s_1, s_2 = 0, s_3 = 0,
        s_4 = 0, s_5 = 0, s_6 = 0,
        s_7 = 0, s_8 = 0, s_9 = 0,
        s_10 = 0, s_11 = 0, s_12 = 0,
        s_13 = 0, s_14 = 0, s_15 = 0,
        s_16 = 0, s_17 = 0, s_18 = 0
    };


    enum Minutes 
    {
        m_1, m_2 = 0, m_3 = 0,
        m_4 = 0, m_5 = 0, m_6 = 0,
        m_7 = 0, m_8 = 0, m_9 = 0,
        m_10 = 0, m_11 = 0, m_12 = 0,
        m_13 = 0, m_14 = 0, m_15 = 0,
        m_16 = 0, m_17 = 0, m_18 = 0
    };

    enum Hours 
    {
        h_1, h_2 = 0, h_3 = 0,
        h_4 = 0, h_5 = 0, h_6 = 0,
        h_7 = 0, h_8 = 0, h_9 = 0,
        h_10 = 0, h_11 = 0, h_12 = 0,
        h_13 = 0, h_14 = 0, h_15 = 0,
        h_16 = 0, h_17 = 0, h_18 = 0
    };

    int margit_time[3] = { s_1, m_1, h_1 };
    int godrick_time[3] = { s_2, m_2, h_2 };
    int redwolf_time[3] = { s_3, m_3, h_3 };
    int renalla_time[3] = { s_4, m_4, h_4 };
    int radahn_time[3] = { s_5, m_5, h_5 };
    int godskin_time[3] = { s_6, m_6, h_6 };
    int rykard_time[3] = { s_7, m_7, h_7 };
    int draconic_time[3] = { s_8, m_8, h_8 };
    int godfrey_time[3] = { s_9, m_9, h_9 };
    int morgott_time[3] = { s_10, m_10, h_10 };
    int firegiant_time[3] = { s_11, m_11, h_11 };
    int godskinduo_time[3] = { s_12, m_12, h_12 };
    int maliketh_time[3] = { s_13, m_13, h_13 };
    int sirgideon_time[3] = { s_14, m_14, h_14 };
    int godfrey2_time[3] = { s_15, m_15, h_15 };
    int hoarah_time[3] = { s_16, m_16, h_16 };
    int radagon_time[3] = { s_17, m_17, h_17 };
    int eldenbeast_time[3] = { s_18, m_18, h_18 };

public:
};

int main()
{
    al_init();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_install_mouse();

    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    ALLEGRO_BITMAP* mainmenu_Bg = al_load_bitmap("eldenring_mainmenu.png");
    ALLEGRO_BITMAP* back_Arrow = al_load_bitmap("arrowLeft.png");
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
    ALLEGRO_FONT* font15 = al_load_font("slkscr.ttf", 15, 0);
    ALLEGRO_FONT* font40 = al_load_font("slkscr.ttf", 40, 0);

    MainBossList* mainboss_Name = new MainBossList();
    MainBossList* radahn = new MainBossList();
    MainBossList* margit = new MainBossList();
    MainBossList* godrick = new MainBossList();
    MainBossList* redwolf = new MainBossList();
    MainBossList* renalla = new MainBossList();
    MainBossList* godskin = new MainBossList();
    MainBossList* rykard = new MainBossList();
    MainBossList* draconic = new MainBossList();
    MainBossList* godfrey = new MainBossList();
    MainBossList* morgott = new MainBossList();
    MainBossList* firegiant = new MainBossList();
    MainBossList* godskinduo = new MainBossList();
    MainBossList* maliketh = new MainBossList();
    MainBossList* gideon = new MainBossList();
    MainBossList* godfrey_2 = new MainBossList();
    MainBossList* hoarah = new MainBossList();
    MainBossList* radagon = new MainBossList();
    MainBossList* eldenbeast = new MainBossList();

    Timing t;
    KeyLogic k; 
    //enable event queues
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));

    mainboss_Name->createNode(radahn, margit, nullptr, "Radahn");
    mainboss_Name->createNode(margit, godrick, radahn, "Margit the Fell Omen");
    mainboss_Name->createNode(godrick, redwolf, margit, "Godrick the Grafted");
    mainboss_Name->createNode(redwolf, renalla, godrick, "Red Wolf of Radagon");
    mainboss_Name->createNode(renalla, godskin, redwolf, "Renalla, Queen of the Full Moon");
    mainboss_Name->createNode(godskin, rykard, renalla, "Godskin Noble");
    mainboss_Name->createNode(rykard, draconic, godskin, "Rykard, Lord of Blasphemy");
    mainboss_Name->createNode(draconic, godfrey, rykard, "Draconic Tree Sentinel");
    mainboss_Name->createNode(godfrey, morgott, draconic, "Godfrey, First Elden Lord");
    mainboss_Name->createNode(morgott, firegiant, godfrey, "Morgott, the Omen King");
    mainboss_Name->createNode(firegiant, godskinduo, morgott, "Fire Giant");
    mainboss_Name->createNode(godskinduo, maliketh, firegiant, "Godskin Duo");
    mainboss_Name->createNode(maliketh, gideon, godskinduo, "Maliketh, the Black Blade");
    mainboss_Name->createNode(gideon, godfrey_2, maliketh, "Sir Gideon Ofnir");
    mainboss_Name->createNode(godfrey_2, hoarah, gideon, "Godfrey, First Elden Lord (2)");
    mainboss_Name->createNode(hoarah, radagon, godfrey_2, "Hoarah Loux");
    mainboss_Name->createNode(radagon, eldenbeast, hoarah, "Radagon of the Golden Order");
    mainboss_Name->createNode(eldenbeast, nullptr, radagon, "Elden Beast");

    al_start_timer(timer);

    while (!running)
    {
        ALLEGRO_EVENT ev;

        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ENTER:
                k.Keys[k.ENTER] = true;
                break;
            case ALLEGRO_KEY_ESCAPE:
                k.Keys[k.ESCAPE] = true;
                running = true;
                break;
            case ALLEGRO_KEY_LCTRL:
                k.Keys[k.CTRL] = true;
                break;
            case ALLEGRO_KEY_A:
                k.Keys[k.A] = true;
                ++margit_increment;
                if (margit_increment > 1)
                {
                    margit_increment = 0;
                }
                break;
            case ALLEGRO_KEY_B:
                k.Keys[k.B] = true;
                ++godrick_increment;
                if (godrick_increment > 1)
                {
                    godrick_increment = 0;
                }
                break;
            case ALLEGRO_KEY_C:
                k.Keys[k.C] = true;
                redwolf_increment++;
                if (redwolf_increment > 1)
                {
                    redwolf_increment = 0;
                }
                break;
            case ALLEGRO_KEY_D:
                k.Keys[k.D] = true;
                renalla_increment++;
                if (renalla_increment > 1)
                {
                    renalla_increment = 0;
                }
                break;
            case ALLEGRO_KEY_E:
                k.Keys[k.E] = true;
                godskin_increment++;
                if (godskin_increment > 1)
                {
                    godskin_increment = 0;
                }
                break;
            case ALLEGRO_KEY_F:
                k.Keys[k.F] = true;
                rykard_increment++;
                if (rykard_increment > 1)
                {
                    rykard_increment = 0;
                }
                break;
            case ALLEGRO_KEY_G:
                k.Keys[k.G] = true;
                draconic_increment++;
                if (draconic_increment > 1)
                {
                    draconic_increment = 0;
                }
                break;
            case ALLEGRO_KEY_H:
                k.Keys[k.H] = true;
                godfrey_increment++;
                if (godfrey_increment > 1)
                {
                    godfrey_increment = 0;
                }
                break;
            case ALLEGRO_KEY_I:
                k.Keys[k.I] = true;
                morgott_increment++;
                if (morgott_increment > 1)
                {
                    morgott_increment = 0;
                }
                break;
            case ALLEGRO_KEY_J:
                k.Keys[k.J] = true;
                radahn_increment++;
                if (radahn_increment > 1)
                {
                    radahn_increment = 0;
                }
                break;
            case ALLEGRO_KEY_K:
                k.Keys[k.K] = true;
                firegiant_increment++;
                if (firegiant_increment > 1)
                {
                    firegiant_increment = 0;
                }
                break;
            case ALLEGRO_KEY_L:
                k.Keys[k.L] = true;
                godskinduo_increment++;
                if (godskinduo_increment > 1)
                {
                    godskinduo_increment = 0;
                }
                break;
            case ALLEGRO_KEY_M:
                k.Keys[k.M] = true;
                maliketh_increment++;
                if (maliketh_increment > 1)
                {
                    maliketh_increment = 0;
                }
                break;
            case ALLEGRO_KEY_N:
                k.Keys[k.N] = true;
                sirgideon_increment++;
                if (sirgideon_increment > 1)
                {
                    sirgideon_increment = 0;
                }
                break;
            case ALLEGRO_KEY_O:
                k.Keys[k.O] = true;
                godfrey2_increment++;
                if (godfrey2_increment > 1)
                {
                    godfrey2_increment = 0;
                }
                break;
            case ALLEGRO_KEY_P:
                k.Keys[k.P] = true;
                hoarah_increment++;
                if (hoarah_increment > 1)
                {
                    hoarah_increment = 0;
                }
                break;
            case ALLEGRO_KEY_Q:
                k.Keys[k.Q] = true;
                radagon_increment++;
                if (radagon_increment > 1)
                {
                    radagon_increment = 0;
                }
                break;
            case ALLEGRO_KEY_R:
                k.Keys[k.R] = true;
                eldenbeast_increment++;
                if (eldenbeast_increment > 1)
                {
                    eldenbeast_increment = 0;
                }
                break;
            case ALLEGRO_KEY_S:
                k.Keys[k.S] = true;
                --margit_increment;
                --godrick_increment;
                --redwolf_increment;
                --renalla_increment;
                --godskin_increment;
                --rykard_increment;
                --draconic_increment;
                --godfrey_increment;
                --morgott_increment;
                --radahn_increment;
                --firegiant_increment;
                --godskinduo_increment;
                --maliketh_increment;
                --sirgideon_increment;
                --godfrey2_increment;
                --hoarah_increment;
                --radagon_increment;
                --eldenbeast_increment;
                if (margit_increment < 0)
                {
                    margit_increment = 0;
                }
                if (godrick_increment < 0)
                {
                    godrick_increment = 0;
                }
                if (redwolf_increment < 0)
                {
                    redwolf_increment = 0;
                }
                if (renalla_increment < 0)
                {
                    renalla_increment = 0;
                }
                if (godskin_increment < 0)
                {
                    godskin_increment = 0;
                }
                if (rykard_increment < 0)
                {
                    rykard_increment = 0;
                }
                if (draconic_increment < 0)
                {
                    draconic_increment = 0;
                }
                if (godfrey_increment < 0)
                {
                    godfrey_increment = 0;
                }
                if (morgott_increment < 0)
                {
                    morgott_increment = 0;
                }
                if (radahn_increment < 0)
                {
                    radahn_increment = 0;
                }
                if (firegiant_increment < 0)
                {
                    firegiant_increment = 0;
                }
                if (godskinduo_increment < 0)
                {
                    godskinduo_increment = 0;
                }
                if (maliketh_increment < 0)
                {
                    maliketh_increment = 0;
                }
                if (sirgideon_increment < 0)
                {
                    sirgideon_increment = 0;
                }
                if (godfrey2_increment < 0)
                {
                    godfrey2_increment = 0;
                }
                if (hoarah_increment < 0)
                {
                    hoarah_increment = 0;
                }
                if (radagon_increment < 0)
                {
                    radagon_increment = 0;
                }
                if (eldenbeast_increment < 0)
                {
                    eldenbeast_increment = 0;
                }
                break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ENTER:
                k.Keys[k.ENTER] = false;
                break;
            case ALLEGRO_KEY_LCTRL:
                k.Keys[k.CTRL] = false;
                break;
            case ALLEGRO_KEY_A:
                k.Keys[k.A] = false;
                break;
            case ALLEGRO_KEY_B:
                k.Keys[k.B] = false;
                break;
            case ALLEGRO_KEY_C:
                k.Keys[k.C] = false;
                break;
            case ALLEGRO_KEY_D:
                k.Keys[k.D] = false;
                break;
            case ALLEGRO_KEY_E:
                k.Keys[k.E] = false;
                break;
            case ALLEGRO_KEY_F:
                k.Keys[k.F] = false;
                break;
            case ALLEGRO_KEY_G:
                k.Keys[k.G] = false;
                break;
            case ALLEGRO_KEY_H:
                k.Keys[k.H] = false;
                break;
            case ALLEGRO_KEY_I:
                k.Keys[k.I] = false;
                break;
            case ALLEGRO_KEY_J:
                k.Keys[k.J] = false;
                break;
            case ALLEGRO_KEY_K:
                k.Keys[k.K] = false;
                break;
            case ALLEGRO_KEY_L:
                k.Keys[k.L] = false;
                break;
            case ALLEGRO_KEY_M:
                k.Keys[k.M] = false;
                break;
            case ALLEGRO_KEY_N:
                k.Keys[k.N] = false;
                break;
            case ALLEGRO_KEY_O:
                k.Keys[k.O] = false;
                break;
            case ALLEGRO_KEY_P:
                k.Keys[k.P] = false;
                break;
            case ALLEGRO_KEY_Q:
                k.Keys[k.Q] = false;
                break;
            case ALLEGRO_KEY_R:
                k.Keys[k.R] = false;
                break;
            case ALLEGRO_KEY_S:
                k.Keys[k.S] = false;
                break;
            }
        }

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            running = true;
        }

        if (margit_increment == 1)
        {
            t.ms++;

            if (t.ms >= 60)
            {
                t.ms = 0;

                t.margit_time[0]++;

                if (t.margit_time[0] >= 60)
                {
                    t.margit_time[0] = 0;
                    t.margit_time[1]++;

                    if (t.margit_time[1] >= 60)
                    {
                        t.margit_time[1] = 0;
                        t.margit_time[2]++;
                    }
                }
            }
        }

        if (godrick_increment == 1)
        {
            t.ms2++;

            if (t.ms2 >= 60)
            {
                t.ms2 = 0;

                t.godrick_time[0]++;

                if (t.godrick_time[0] >= 60)
                {
                    t.godrick_time[0] = 0;
                    t.godrick_time[1]++;

                    if (t.godrick_time[1] >= 60)
                    {
                        t.godrick_time[1] = 0;
                        t.godrick_time[2]++;
                    }
                }
            }
        }

        if (redwolf_increment == 1)
        {
            t.ms3++;

            if (t.ms3 >= 60)
            {
                t.ms3 = 0;

                t.redwolf_time[0]++;

                if (t.redwolf_time[0] >= 60)
                {
                    t.redwolf_time[0] = 0;
                    t.redwolf_time[1]++;

                    if (t.redwolf_time[1] >= 60)
                    {
                        t.redwolf_time[1] = 0;
                        t.redwolf_time[2]++;
                    }
                }
            }
        }

        if (renalla_increment == 1)
        {
            t.ms4++;

            if (t.ms4 >= 60)
            {
                t.ms4 = 0;

                t.renalla_time[0]++;

                if (t.renalla_time[0] >= 60)
                {
                    t.renalla_time[0] = 0;
                    t.renalla_time[1]++;

                    if (t.renalla_time[1] >= 60)
                    {
                        t.renalla_time[1] = 0;
                        t.renalla_time[2]++;
                    }
                }
            }
        }

        if (godskin_increment == 1)
        {
            t.ms5++;

            if (t.ms5 >= 60)
            {
                t.ms5 = 0;

                t.godskin_time[0]++;

                if (t.godskin_time[0] >= 60)
                {
                    t.godskin_time[0] = 0;
                    t.godskin_time[1]++;

                    if (t.godskin_time[1] >= 60)
                    {
                        t.godskin_time[1] = 0;
                        t.godskin_time[2]++;
                    }
                }
            }
        }

        if (rykard_increment == 1)
        {
            t.ms6++;

            if (t.ms6 >= 60)
            {
                t.ms6 = 0;

                t.rykard_time[0]++;

                if (t.rykard_time[0] >= 60)
                {
                    t.rykard_time[0] = 0;
                    t.rykard_time[1]++;

                    if (t.rykard_time[1] >= 60)
                    {
                        t.rykard_time[1] = 0;
                        t.rykard_time[2]++;
                    }
                }
            }
        }

        if (draconic_increment == 1)
        {
            t.ms7++;

            if (t.ms7 >= 60)
            {
                t.ms7 = 0;

                t.draconic_time[0]++;

                if (t.draconic_time[0] >= 60)
                {
                    t.draconic_time[0] = 0;
                    t.draconic_time[1]++;

                    if (t.draconic_time[1] >= 60)
                    {
                        t.draconic_time[1] = 0;
                        t.draconic_time[2]++;
                    }
                }
            }
        }

        if (godfrey_increment == 1)
        {
            t.ms8++;

            if (t.ms8 >= 60)
            {
                t.ms8 = 0;

                t.godfrey_time[0]++;

                if (t.godfrey_time[0] >= 60)
                {
                    t.godfrey_time[0] = 0;
                    t.godfrey_time[1]++;

                    if (t.godfrey_time[1] >= 60)
                    {
                        t.godfrey_time[1] = 0;
                        t.godfrey_time[2]++;
                    }
                }
            }
        }

        if (morgott_increment == 1)
        {
            t.ms9++;

            if (t.ms9 >= 60)
            {
                t.ms9 = 0;

                t.morgott_time[0]++;

                if (t.morgott_time[0] >= 60)
                {
                    t.morgott_time[0] = 0;
                    t.morgott_time[1]++;

                    if (t.morgott_time[1] >= 60)
                    {
                        t.morgott_time[1] = 0;
                        t.morgott_time[2]++;
                    }
                }
            }
        }

        if (radahn_increment == 1)
        {
            t.ms10++;

            if (t.ms10 >= 60)
            {
                t.ms10 = 0;

                t.radahn_time[0]++;

                if (t.radahn_time[0] >= 60)
                {
                    t.radahn_time[0] = 0;
                    t.radahn_time[1]++;

                    if (t.radahn_time[1] >= 60)
                    {
                        t.radahn_time[1] = 0;
                        t.radahn_time[2]++;
                    }
                }
            }
        }

        if (firegiant_increment == 1)
        {
            t.ms11++;

            if (t.ms11 >= 60)
            {
                t.ms11 = 0;

                t.firegiant_time[0]++;

                if (t.firegiant_time[0] >= 60)
                {
                    t.firegiant_time[0] = 0;
                    t.firegiant_time[1]++;

                    if (t.firegiant_time[1] >= 60)
                    {
                        t.firegiant_time[1] = 0;
                        t.firegiant_time[2]++;
                    }
                }
            }
        }

        if (godskinduo_increment == 1)
        {
            t.ms12++;

            if (t.ms12 >= 60)
            {
                t.ms12 = 0;

                t.godskinduo_time[0]++;

                if (t.godskinduo_time[0] >= 60)
                {
                    t.godskinduo_time[0] = 0;
                    t.godskinduo_time[1]++;

                    if (t.godskinduo_time[1] >= 60)
                    {
                        t.godskinduo_time[1] = 0;
                        t.godskinduo_time[2]++;
                    }
                }
            }
        }

        if (maliketh_increment == 1)
        {
            t.ms13++;

            if (t.ms13 >= 60)
            {
                t.ms13 = 0;

                t.maliketh_time[0]++;

                if (t.maliketh_time[0] >= 60)
                {
                    t.maliketh_time[0] = 0;
                    t.maliketh_time[1]++;

                    if (t.maliketh_time[1] >= 60)
                    {
                        t.maliketh_time[1] = 0;
                        t.maliketh_time[2]++;
                    }
                }
            }
        }

        if (sirgideon_increment == 1)
        {
            t.ms14++;

            if (t.ms14 >= 60)
            {
                t.ms14 = 0;

                t.sirgideon_time[0]++;

                if (t.sirgideon_time[0] >= 60)
                {
                    t.sirgideon_time[0] = 0;
                    t.sirgideon_time[1]++;

                    if (t.sirgideon_time[1] >= 60)
                    {
                        t.sirgideon_time[1] = 0;
                        t.sirgideon_time[2]++;
                    }
                }
            }
        }

        if (godfrey2_increment == 1)
        {
            t.ms15++;

            if (t.ms15 >= 60)
            {
                t.ms15 = 0;

                t.godfrey2_time[0]++;

                if (t.godfrey2_time[0] >= 60)
                {
                    t.godfrey2_time[0] = 0;
                    t.godfrey2_time[1]++;

                    if (t.margit_time[1] >= 60)
                    {
                        t.godfrey2_time[1] = 0;
                        t.godfrey2_time[2]++;
                    }
                }
            }
        }

        if (hoarah_increment == 1)
        {
            t.ms16++;

            if (t.ms16 >= 60)
            {
                t.ms16 = 0;

                t.hoarah_time[0]++;

                if (t.hoarah_time[0] >= 60)
                {
                    t.hoarah_time[0] = 0;
                    t.hoarah_time[1]++;

                    if (t.hoarah_time[1] >= 60)
                    {
                        t.hoarah_time[1] = 0;
                        t.hoarah_time[2]++;
                    }
                }
            }
        }

        if (radagon_increment == 1)
        {
            t.ms17++;

            if (t.ms17 >= 60)
            {
                t.ms17 = 0;

                t.radagon_time[0]++;

                if (t.radagon_time[0] >= 60)
                {
                    t.radagon_time[0] = 0;
                    t.radagon_time[1]++;

                    if (t.radagon_time[1] >= 60)
                    {
                        t.radagon_time[1] = 0;
                        t.radagon_time[2]++;
                    }
                }
            }
        }

        if (eldenbeast_increment == 1)
        {
            t.ms18++;

            if (t.ms18 >= 60)
            {
                t.ms18 = 0;

                t.eldenbeast_time[0]++;

                if (t.eldenbeast_time[0] >= 60)
                {
                    t.eldenbeast_time[0] = 0;
                    t.eldenbeast_time[1]++;

                    if (t.eldenbeast_time[1] >= 60)
                    {
                        t.eldenbeast_time[1] = 0;
                        t.eldenbeast_time[2]++;
                    }
                }
            }
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.A] == true)
        {
            t.margit_time[2] = 0;
            t.margit_time[1] = 0;
            t.margit_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.B] == true)
        {
            t.godrick_time[2] = 0;
            t.godrick_time[1] = 0;
            t.godrick_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.C] == true)
        {
            t.redwolf_time[2] = 0;
            t.redwolf_time[1] = 0;
            t.redwolf_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.D] == true)
        {
            t.renalla_time[2] = 0;
            t.renalla_time[1] = 0;
            t.renalla_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.E] == true)
        {
            t.godskin_time[2] = 0;
            t.godskin_time[1] = 0;
            t.godskin_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.F] == true)
        {
            t.rykard_time[2] = 0;
            t.rykard_time[1] = 0;
            t.rykard_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.G] == true)
        {
            t.draconic_time[2] = 0;
            t.draconic_time[1] = 0;
            t.draconic_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.H] == true)
        {
            t.godfrey_time[2] = 0;
            t.godfrey_time[1] = 0;
            t.godfrey_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.I] == true)
        {
            t.morgott_time[2] = 0;
            t.morgott_time[1] = 0;
            t.morgott_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.J] == true)
        {
            t.radahn_time[2] = 0;
            t.radahn_time[1] = 0;
            t.radahn_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.K] == true)
        {
            t.firegiant_time[2] = 0;
            t.firegiant_time[1] = 0;
            t.firegiant_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.L] == true)
        {
            t.godskinduo_time[2] = 0;
            t.godskinduo_time[1] = 0;
            t.godskinduo_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.M] == true)
        {
            t.maliketh_time[2] = 0;
            t.maliketh_time[1] = 0;
            t.maliketh_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.N] == true)
        {
            t.sirgideon_time[2] = 0;
            t.sirgideon_time[1] = 0;
            t.sirgideon_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.O] == true)
        {
            t.godfrey2_time[2] = 0;
            t.godfrey2_time[1] = 0;
            t.godfrey2_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.P] == true)
        {
            t.hoarah_time[2] = 0;
            t.hoarah_time[1] = 0;
            t.hoarah_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.Q] == true)
        {
            t.radagon_time[2] = 0;
            t.radagon_time[1] = 0;
            t.radagon_time[0] = 0;
        }

        if (k.Keys[k.CTRL] == true && k.Keys[k.R] == true)
        {
            t.eldenbeast_time[2] = 0;
            t.eldenbeast_time[1] = 0;
            t.eldenbeast_time[0] = 0;
        }

        al_clear_to_color(al_map_rgb(GREY));

        al_draw_text(font15, al_map_rgb(BLACK), 0, 0, 0, "A: Margit");
        al_draw_textf(font15, al_map_rgb(RED), 250, 0, 0, "H: %i", t.margit_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 0, 0, "M: %i", t.margit_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 0, 0, "S: %i", t.margit_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 20, 0, "B: Godrick");
        al_draw_textf(font15, al_map_rgb(RED), 250, 20, 0, "H: %i", t.godrick_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 20, 0, "M: %i", t.godrick_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 20, 0, "S: %i", t.godrick_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 40, 0, "C: Red Wolf");
        al_draw_textf(font15, al_map_rgb(RED), 250, 40, 0, "H: %i", t.redwolf_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 40, 0, "M: %i", t.redwolf_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 40, 0, "S: %i", t.redwolf_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 60, 0, "D: Renalla");
        al_draw_textf(font15, al_map_rgb(RED), 250, 60, 0, "H: %i", t.renalla_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 60, 0, "M: %i", t.renalla_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 60, 0, "S: %i", t.renalla_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 80, 0, "E: Godskin Noble");
        al_draw_textf(font15, al_map_rgb(RED), 250, 80, 0, "H: %i", t.godskin_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 80, 0, "M: %i", t.godskin_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 80, 0, "S: %i", t.godskin_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 100, 0, "F: Rykard");
        al_draw_textf(font15, al_map_rgb(RED), 250, 100, 0, "H: %i", t.rykard_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 100, 0, "M: %i", t.rykard_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 100, 0, "S: %i", t.rykard_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 120, 0, "G: Draconic Tree Sentinel");
        al_draw_textf(font15, al_map_rgb(RED), 250, 120, 0, "H: %i", t.draconic_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 120, 0, "M: %i", t.draconic_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 120, 0, "S: %i", t.draconic_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 140, 0, "H: Godfrey");
        al_draw_textf(font15, al_map_rgb(RED), 250, 140, 0, "H: %i", t.godfrey_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 140, 0, "M: %i", t.godfrey_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 140, 0, "S: %i", t.godfrey_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 160, 0, "I:  Morgott");
        al_draw_textf(font15, al_map_rgb(RED), 250, 160, 0, "H: %i", t.morgott_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 160, 0, "M: %i", t.morgott_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 160, 0, "S: %i", t.morgott_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 180, 0, "J: Radahn");
        al_draw_textf(font15, al_map_rgb(RED), 250, 180, 0, "H: %i", t.radahn_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 180, 0, "M: %i", t.radahn_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 180, 0, "S: %i", t.radahn_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 200, 0, "K: Fire Giant");
        al_draw_textf(font15, al_map_rgb(RED), 250, 200, 0, "H: %i", t.firegiant_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 200, 0, "M: %i", t.firegiant_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 200, 0, "S: %i", t.firegiant_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 220, 0, "L: Godskin Duo");
        al_draw_textf(font15, al_map_rgb(RED), 250, 220, 0, "H: %i", t.godskinduo_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 220, 0, "M: %i", t.godskinduo_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 220, 0, "S: %i", t.godskinduo_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 240, 0, "M: Maliketh");
        al_draw_textf(font15, al_map_rgb(RED), 250, 240, 0, "H: %i", t.maliketh_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 240, 0, "M: %i", t.maliketh_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 240, 0, "S: %i", t.maliketh_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 260, 0, "N: Sir Gideon Ofnir");
        al_draw_textf(font15, al_map_rgb(RED), 250, 260, 0, "H: %i", t.sirgideon_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 260, 0, "M: %i", t.sirgideon_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 260, 0, "S: %i", t.sirgideon_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 280, 0, "O: Godfrey Pt 2");
        al_draw_textf(font15, al_map_rgb(RED), 250, 280, 0, "H: %i", t.godfrey2_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 280, 0, "M: %i", t.godfrey2_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 280, 0, "S: %i", t.godfrey2_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 300, 0, "P: Hoarah");
        al_draw_textf(font15, al_map_rgb(RED), 250, 300, 0, "H: %i", t.hoarah_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 300, 0, "M: %i", t.hoarah_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 300, 0, "S: %i", t.hoarah_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 320, 0, "Q: Radagon");
        al_draw_textf(font15, al_map_rgb(RED), 250, 320, 0, "H: %i", t.radagon_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 320, 0, "M: %i", t.radagon_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 320, 0, "S: %i", t.radagon_time[0]);

        al_draw_text(font15, al_map_rgb(BLACK), 0, 340, 0, "R: Elden Beast");
        al_draw_textf(font15, al_map_rgb(RED), 250, 340, 0, "H: %i", t.eldenbeast_time[2]);
        al_draw_textf(font15, al_map_rgb(RED), 300, 340, 0, "M: %i", t.eldenbeast_time[1]);
        al_draw_textf(font15, al_map_rgb(RED), 350, 340, 0, "S: %i", t.eldenbeast_time[0]);

        al_flip_display();

    }
}
