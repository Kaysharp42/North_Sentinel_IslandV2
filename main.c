#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define True 1;
#define False 0;
int showmenu(SDL_Surface* screen, SDL_Surface* t[], SDL_Rect imagebg , TTF_Font* font)
{
        Uint32 time;
        int x,y,c=0;

        SDL_BlitSurface( t[0] ,NULL, screen, &imagebg );
        SDL_Flip(screen);
        SDL_Event event;
        while(1)
        {
                time = SDL_GetTicks();
                while(SDL_PollEvent(&event))
                {
                  SDL_WaitEvent(&event);

                  switch(event.type)
                          {
                                  case SDL_QUIT:


                                          return 0;
                                          break;
                                case SDL_MOUSEMOTION:
                                      x = event.motion.x;
                                        y = event.motion.y;
                                               if(x>=0 && x<=233 && y>=297 && y<=350)
                                                {

                                                  SDL_BlitSurface( t[1] ,NULL, screen, &imagebg );
                                                   c=1;
                                                }
                                                if(x>=0 && x<=233 && y>=365 && y<=425)
                                                {

                                                    SDL_BlitSurface( t[2] ,NULL, screen, &imagebg );

                                                     c=2;
                                                }
                                                if(x>=0 && x<=233 && y>=435 && y<=491)
                                                {

                                                    SDL_BlitSurface( t[3] ,NULL, screen, &imagebg );

                                                     c=3;
                                                }
                                              if(x>=0 && x<=233 && y>=504 && y<=560)
                                                {

                                                    SDL_BlitSurface( t[4] ,NULL, screen, &imagebg );

                                                     c=4;

                                                }
                                                break;
                                case SDL_MOUSEBUTTONDOWN:
                                          x = event.button.x;
                                        y = event.button.y;
                                        if (event.button.button == SDL_BUTTON_LEFT) {
                                if(x>=0 && x<=233 && y>=297 && y<=350)
                                {
                       return 1;
                                }
                                if(x>=0 && x<=233 && y>=365 && y<=425)
                                {
                                  return 2;
                                }
                                if(x>=0 && x<=233 && y>=435 && y<=491)
                                {
                                  return 3;
                                }
                                if(x>=0 && x<=233 && y>=504 && y<=560)
                                {
                                  return 0;
                                }
                                }
                                break;


    }

                    SDL_Flip(screen);
                    if(100/30 > (SDL_GetTicks()-time))
                            SDL_Delay(100/30 - (SDL_GetTicks()-time));

        }
}
}
int  main() {
  char pause;
  int l=0;

   SDL_Init(SDL_INIT_VIDEO);
   TTF_Init();

   TTF_Font *font = NULL;
   font =TTF_OpenFont("arial_narrow_7.ttf", 36);



   if (SDL_Init(SDL_INIT_VIDEO)!=0)
   {printf("unable to initialize SDL : %s\n",SDL_GetError());
   return 1;
   }
   SDL_Surface *screen, *image, *WinImg;
  screen = SDL_SetVideoMode(800, 600, 32,SDL_DOUBLEBUF |SDL_SWSURFACE);

  if(!screen)
  {
    printf("Unable to set 60*400 video : %s\n",SDL_GetError() );
    return (-1);
    }
        SDL_WM_SetCaption("test1", NULL);
        SDL_Rect positionecran ,posdetec,frame,positionwin;  // rect to describe the source desr region of our blit
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
        {
          printf("music error%s\n",Mix_GetError() );

        }
      Mix_Music *music;
        music = Mix_LoadMUS("Menu/intro.wav");
      //  Mix_VolumeChunk(music, MIX_MAX_VOLUME/4);

       Mix_PlayMusic(music,-1);
    // load the bit map into image surface & check
  image = SDL_LoadBMP("background.bmp");// or IMG_Load
  WinImg = IMG_Load("win.png");// or IMG_Load
  SDL_Surface* t[5];
  t[0]=IMG_Load("Menu/menu101.png");

  t[1]=IMG_Load("Menu/playon.png");

  t[2]=IMG_Load("Menu/Loadgameon.png");

  t[3]=IMG_Load("Menu/optionon.png");

  t[4]=IMG_Load("Menu/quiton.png");

  SDL_Rect imagebg;
  imagebg.x = 0;
  imagebg.y = 0;
  positionecran.x = 0;
  positionecran.y = 0;
  positionecran.w = 800;
  positionecran.h =image->h;


    SDL_BlitSurface(image, NULL, screen, &positionecran);
    SDL_Flip(screen);
     int CurFrame =0, MaxFrame = 8;
    SDL_Surface *caractere;

    caractere= IMG_Load("movements.png");
    if (caractere == NULL) {
      printf( " ERROR  caractere %s\n",SDL_GetError());
      return 1;
    }
        posdetec.x=0;
    posdetec.y=350;
    posdetec.h =32;
    posdetec.w =32;
    frame.x=0;
    frame.y=0;
    frame.w=32;
    frame.h=32;

   int r =showmenu(screen, t ,imagebg,font);
    SDL_Event event;
    while(r!=0)
    {
      SDL_BlitSurface(caractere,&frame,screen,&posdetec);
      SDL_Flip(screen);
      while(SDL_PollEvent(&event))
       {

SDL_WaitEvent(&event);
switch (event.type) {
  case SDL_QUIT  : r=0 ; break;
  case SDL_KEYDOWN :
  if (event.key.keysym.sym == SDLK_ESCAPE)
  {
    r=0;
    break;
  }
  if (event.key.keysym.sym == SDLK_RIGHT)
  {
    posdetec.x += 80;
    CurFrame ++ ;
    if (CurFrame > MaxFrame) {
      CurFrame =0;
    }
    frame.x=CurFrame * frame.w;

  }
  if (event.key.keysym.sym == SDLK_LEFT)
  {
    posdetec.x -= 80;

  }
  if (event.key.keysym.sym == SDLK_UP)
  {
    posdetec.y -= 80;

  }
  if (event.key.keysym.sym == SDLK_DOWN)
  {
    posdetec.y += 80;

  }
break;
}
if (posdetec.x > 800) {
  posdetec.x = 0;
  positionecran.x=positionecran.w;
}

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));

SDL_BlitSurface(caractere,&frame,screen,&posdetec);
SDL_BlitSurface(image, &positionecran, screen, NULL);
SDL_Flip(screen);




}

    }
SDL_FreeSurface(t[r]);
    SDL_FreeSurface(caractere);

    SDL_FreeSurface(image);

    //Mix_FreeMusic(music);
        TTF_Quit();
                SDL_Quit();
  return 0;
}
